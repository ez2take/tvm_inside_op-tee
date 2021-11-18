#include <tee_internal_api.h>
#include <tee_internal_api_extensions.h>

#include <ml_with_tee_ta.h>
//#include "tvm/runtime/crt/crt.h"
//#include "tvm/runtime/crt/packed_func.h"
#include "tvm/runtime/crt/graph_executor.h"
//#include "tvm/runtime/crt/module.h"

typedef struct {
    int timer_running;
    TEE_Time start_time;
    unsigned int random_seed;

    TVMModuleHandle system_lib_handle;
    TVMGraphExecutor* graph_executor;
}TrustedApplicationGlobalVariables;

static TrustedApplicationGlobalVariables GVars = { 0 };

size_t TVMPlatformFormatMessage
    (char* out_buf, size_t out_buf_size_bytes, const char* fmt, va_list args) {
    return vsnprintf(out_buf, out_buf_size_bytes, fmt, args);
}

void TVMPlatformAbort(tvm_crt_error_t error_code) {
    DMSG("TVMPlatformAbort. error_code: %d",error_code);
}

//MemoryManagerInterface* memory_manager;
tvm_crt_error_t TVMPlatformMemoryAllocate(size_t num_bytes, DLDevice dev, void** out_ptr) {
    *out_ptr = malloc(num_bytes);//memory_manager->Allocate(memory_manager, num_bytes, dev, out_ptr); //new　に差し替えてもtest on side_linuxでは大丈夫かも
    if(out_ptr == NULL){
        return kTvmErrorPlatformNoMemory;
    }
    return kTvmErrorNoError;
}

tvm_crt_error_t TVMPlatformMemoryFree(void* ptr, DLDevice dev) {
    free(ptr);
    return kTvmErrorNoError;
}
/*tvm_crt_error_t TVMPlatformMemoryAllocate(size_t num_bytes, DLDevice dev, void** out_ptr) {
  return memory_manager->Allocate(memory_manager, num_bytes, dev, out_ptr); //new　に差し替えてもtest on side_linuxでは大丈夫かも
}

tvm_crt_error_t TVMPlatformMemoryFree(void* ptr, DLDevice dev) {
  return memory_manager->Free(memory_manager, ptr, dev);
}
*/

tvm_crt_error_t TVMPlatformTimerStart() {
    if (GVars.timer_running) {
        DMSG("timer already running");
        return kTvmErrorPlatformTimerBadState;
    }
    TEE_GetSystemTime(&(GVars.start_time));
    GVars.timer_running = 1;
    return kTvmErrorNoError;
}

tvm_crt_error_t TVMPlatformTimerStop(double* elapsed_time_seconds) {
    if (!GVars.timer_running) {
        DMSG("tvm platform timer not running");
        return kTvmErrorPlatformTimerBadState;
    }
    TEE_Time stop_time = { 0 };
    TEE_GetSystemTime(&stop_time);
    uint32_t elapsed_time_s = stop_time.seconds - GVars.start_time.seconds;
    uint32_t elapsed_time_m = stop_time.millis - GVars.start_time.millis;
    *elapsed_time_seconds = (double)(elapsed_time_s + elapsed_time_m);
    GVars.timer_running = 0;
    return kTvmErrorNoError;
}
/*
//static_assert(RAND_MAX >= (1 << 8), "RAND_MAX is smaller than acceptable");
tvm_crt_error_t TVMPlatformGenerateRandom(uint8_t* buffer, size_t num_bytes) {
    if (GVars.random_seed == 0) {
        TEE_Time time = {0};
        TEE_GetSystemTime(&time);
        GVars.random_seed = time.millis;
    }
    for (size_t i = 0; i < num_bytes; ++i) {
        int random = rand(&GVars.random_seed);
        buffer[i] = (uint8_t)random;
    }
    return kTvmErrorNoError;
}
*/

void TVMLogf(const char* fmt, ...) {
    va_list args;
    char log_buf[1024];
    va_start(args, fmt);
    int ret = vsnprintf(log_buf, sizeof(log_buf), fmt, args);
    va_end(args);

    if (ret < 0) {
        DMSG("TVMLogf: error formatting: %s",fmt);
    } else {
        DMSG("TVMLogf: %s", log_buf);
    }
}

TEE_Result TVMModCreateFromCModuleWrapper(uint32_t param_types,
	TEE_Param params[4]) {
    uint32_t exp_param_types = TEE_PARAM_TYPES(TEE_PARAM_TYPE_NONE,
                            TEE_PARAM_TYPE_NONE,
                            TEE_PARAM_TYPE_NONE,
                            TEE_PARAM_TYPE_NONE);  
    params;
    DMSG("has been called");  
    if (param_types != exp_param_types)
        return TEE_ERROR_BAD_PARAMETERS;

    if (TVMModCreateFromCModule(TVMSystemLibEntryPoint(), &(GVars.system_lib_handle) ) != 0){
        DMSG("faild to create tvm module from c module");
        TVMPlatformAbort(kTvmErrorNoError);
        return TEE_ERROR_GENERIC;
    }
    return TEE_SUCCESS;
}
TEE_Result TVMGraphExecutor_CreateWrapper(uint32_t param_types,
	TEE_Param params[4]) {
    uint32_t exp_param_types = TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT,
                            TEE_PARAM_TYPE_NONE,
                            TEE_PARAM_TYPE_NONE,
                            TEE_PARAM_TYPE_NONE);  
    DMSG("has been called");  
    if (param_types != exp_param_types)
        return TEE_ERROR_BAD_PARAMETERS;

    const char *graph_json = (char*)params[0].memref.buffer;
    const DLDevice dev = {kDLCPU, 0};
    int res = TVMGraphExecutor_Create(graph_json, GVars.system_lib_handle,
                            &dev, &(GVars.graph_executor) );
    if(res != 0){
        DMSG("faild to create tvm graph executor from json");
        TVMPlatformAbort(res);
        return TEE_ERROR_GENERIC;
    }
    return TEE_SUCCESS;
}
TEE_Result TVMGraphExecutor_LoadParamsWrapper(uint32_t param_types,
	TEE_Param params[4]) {
    uint32_t exp_param_types = TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT,
                            TEE_PARAM_TYPE_NONE,
                            TEE_PARAM_TYPE_NONE,
                            TEE_PARAM_TYPE_NONE);  
    DMSG("has been called");  
    if (param_types != exp_param_types)
        return TEE_ERROR_BAD_PARAMETERS;
    
    const uint32_t blob_size = params[0].memref.size;
    const void* blob = params[0].memref.buffer;
    int res = TVMGraphExecutor_LoadParams(GVars.graph_executor, blob, blob_size);
    if(res != 0){
        DMSG("faild to load params blob");
        TVMPlatformAbort(res);
        return TEE_ERROR_GENERIC;
    }
    return TEE_SUCCESS;
}
TEE_Result TVMGraphExecutor_RunWrapper(uint32_t param_types,
	TEE_Param params[4]) {
    uint32_t exp_param_types = TEE_PARAM_TYPES(TEE_PARAM_TYPE_VALUE_OUTPUT,
                            TEE_PARAM_TYPE_NONE,
                            TEE_PARAM_TYPE_NONE,
                            TEE_PARAM_TYPE_NONE);  
    DMSG("has been called");  
    if (param_types != exp_param_types)
        return TEE_ERROR_BAD_PARAMETERS;
    
    int res = TVMPlatformTimerStart();
    if(res != 0){
        DMSG("faild to start tvm platform timer");
        TVMPlatformAbort(res);
        return TEE_ERROR_GENERIC;
    }

    TVMGraphExecutor_Run(GVars.graph_executor);

    double elapsed_time_seconds;
    res = TVMPlatformTimerStop(&elapsed_time_seconds);
    if(res != 0){
        DMSG("faild to stop tvm platform timer");
        TVMPlatformAbort(res);
        return TEE_ERROR_GENERIC;
    }
    DMSG("  Inference Time: %lfs",elapsed_time_seconds);
    return TEE_SUCCESS;
}
TEE_Result TVMGraphExecutor_GetOutputWrapper(uint32_t param_types,
	TEE_Param params[4]) {
    uint32_t exp_param_types = TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_OUTPUT,
                            TEE_PARAM_TYPE_NONE,
                            TEE_PARAM_TYPE_NONE,
                            TEE_PARAM_TYPE_NONE);  
    DMSG("has been called");  
    const int32_t kImagenetLabelsNum = 1001;
    const int64_t shape[2] = {1,kImagenetLabelsNum};
    //?? size of params buffer is pre determined by ree?? 
    if (param_types != exp_param_types && params[0].memref.size == kImagenetLabelsNum*4)
        return TEE_ERROR_BAD_PARAMETERS;
    DLTensor output_tensor;
    output_tensor.data = params[0].memref.buffer;
    const DLDevice dev = {kDLCPU,0};
    output_tensor.device = dev;
    output_tensor.ndim = 2;
    const DLDataType dtype = {kDLFloat,32,1};
    output_tensor.dtype = dtype;
    output_tensor.shape = shape;
    output_tensor.strides = NULL;
    output_tensor.byte_offset = 0;
    int res = TVMGraphExecutor_GetOutput(GVars.graph_executor, 0, &output_tensor);
    if(res != 0){
        DMSG("faild to get output from tvm graph executor");
        TVMPlatformAbort(res);
        return TEE_ERROR_GENERIC;
    }
    return TEE_SUCCESS;
}
TEE_Result TVMGraphExecutor_ReleaseWrapper(uint32_t param_types,
	TEE_Param params[4]) {
    uint32_t exp_param_types = TEE_PARAM_TYPES(TEE_PARAM_TYPE_NONE,
                            TEE_PARAM_TYPE_NONE,
                            TEE_PARAM_TYPE_NONE,
                            TEE_PARAM_TYPE_NONE);  
    params;
    DMSG("has been called");  
    if (param_types != exp_param_types)
        return TEE_ERROR_BAD_PARAMETERS;

    if (TVMGraphExecutor_Release(&(GVars.graph_executor)) != 0){
        DMSG("faild to release tvm graph executor");
        TVMPlatformAbort(kTvmErrorNoError);
        return TEE_ERROR_GENERIC;
    }
    return TEE_SUCCESS;
}
/*
 * Called when the instance of the TA is created. This is the first call in
 * the TA.
 */
TEE_Result TA_CreateEntryPoint(void)
{
	DMSG("has been called");

	return TEE_SUCCESS;
}

/*
 * Called when the instance of the TA is destroyed if the TA has not
 * crashed or panicked. This is the last call in the TA.
 */
void TA_DestroyEntryPoint(void)
{
	DMSG("has been called");
}

/*
 * Called when a new session is opened to the TA. *sess_ctx can be updated
 * with a value to be able to identify this session in subsequent calls to the
 * TA. In this function you will normally do the global initialization for the
 * TA.
 */
TEE_Result TA_OpenSessionEntryPoint(uint32_t param_types,
		TEE_Param __maybe_unused params[4],
		void __maybe_unused **sess_ctx)
{
	uint32_t exp_param_types = TEE_PARAM_TYPES(TEE_PARAM_TYPE_NONE,
						   TEE_PARAM_TYPE_NONE,
						   TEE_PARAM_TYPE_NONE,
						   TEE_PARAM_TYPE_NONE);

	DMSG("has been called");

	if (param_types != exp_param_types)
		return TEE_ERROR_BAD_PARAMETERS;

	/* Unused parameters */
	(void)&params;
	(void)&sess_ctx;

	/*
	 * The DMSG() macro is non-standard, TEE Internal API doesn't
	 * specify any means to logging from a TA.
	 */
	IMSG("Open Session with ML_WITH_TEE Trusted Application\n");

	/* If return value != TEE_SUCCESS the session will not be created. */
	return TEE_SUCCESS;
}

/*
 * Called when a session is closed, sess_ctx hold the value that was
 * assigned by TA_OpenSessionEntryPoint().
 */
void TA_CloseSessionEntryPoint(void __maybe_unused *sess_ctx)
{
	(void)&sess_ctx; /* Unused parameter */
	IMSG("Goodbye!\n");
}

/*
 * Called when a TA is invoked. sess_ctx hold that value that was
 * assigned by TA_OpenSessionEntryPoint(). The rest of the paramters
 * comes from normal world.
 */
TEE_Result TA_InvokeCommandEntryPoint(void __maybe_unused *sess_ctx,
			uint32_t cmd_id,
			uint32_t param_types, TEE_Param params[4])
{
	(void)&sess_ctx; /* Unused parameter */

	switch (cmd_id) {
	case TA_ML_WITH_TEE_CMD_TVMModCreateFromCModule:
		return TVMModCreateFromCModuleWrapper(param_types, params);
	case TA_ML_WITH_TEE_CMD_LoadModelGraphJson:
		return TVMGraphExecutor_CreateWrapper(param_types, params);
	case TA_ML_WITH_TEE_CMD_LoadModelParamBlob:
		return TVMGraphExecutor_LoadParamsWrapper(param_types, params);
	case TA_ML_WITH_TEE_CMD_TVMGraphExecutor_Run:
		return TVMGraphExecutor_RunWrapper(param_types, params);
	case TA_ML_WITH_TEE_CMD_TVMGraphExecutor_GetOutput:
		return TVMGraphExecutor_GetOutputWrapper(param_types, params);
    case TA_ML_WITH_TEE_CMD_TVMGraphExecutor_Release:
        return TVMGraphExecutor_ReleaseWrapper(param_types, params);
	default:
		return TEE_ERROR_BAD_PARAMETERS;
	}
}
