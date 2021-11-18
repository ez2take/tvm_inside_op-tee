
#include <string>

#include <inttypes.h>
#include <time.h>
#include <unistd.h>

#include <chrono>
#include <iostream>
#include <filesystem>
//#include "systemlib.h"
#include <stdio.h>
#include <string.h>
#include <dirent.h>

#include <stdlib.h>
//sort
#include <vector>
#include <algorithm>

#include <convert_image_to_tensor.h>
#include <dlpack/dlpack.h>
#include <tee_client/tee_client_api.h>
#include <ml_with_tee_ta.h>

using namespace std::chrono;

steady_clock::time_point g_microtvm_start_time;
int g_microtvm_timer_running = 0;

int TVMPlatformTimerStart() {
  if (g_microtvm_timer_running) {
    std::cerr << "timer already running" << std::endl;
    return -1;
  }
  g_microtvm_start_time = std::chrono::steady_clock::now();
  g_microtvm_timer_running = 1;
  return 0;
}

int TVMPlatformTimerStop(double* elapsed_time_seconds) {
  if (!g_microtvm_timer_running) {
    std::cerr << "timer not running" << std::endl;
    return -1;
  }
  auto microtvm_stop_time = std::chrono::steady_clock::now();
  std::chrono::microseconds time_span = std::chrono::duration_cast<std::chrono::microseconds>(
      microtvm_stop_time - g_microtvm_start_time);
  *elapsed_time_seconds = static_cast<double>(time_span.count()) / 1e6;
  g_microtvm_timer_running = 0;
  return 0;
}



namespace{

  char* LoadFile(const std::string& path, size_t* size=nullptr) {
    FILE* file_ptr = fopen(path.c_str(), "r");
    if(file_ptr == nullptr){
        printf("no such file or directory: %s",path.c_str());
        exit(1);
    }
    fseek(file_ptr, 0l , SEEK_END);
    long int file_len = ftell(file_ptr);
    rewind(file_ptr);
    char* buffer = new char[file_len];
    fread(buffer, file_len, 1, file_ptr);
    fclose(file_ptr);
    if(size) *size = (size_t)file_len;
    return buffer;
  }

  char** LoadImagenetLabelsTxt(const std::string& path, int64_t num_labels){
    char* buf = LoadFile(path);
    char** imagenet_labels = new char*[num_labels];
    char* iter = buf;
    for (int i = 0; i < num_labels; i++) {
      imagenet_labels[i] = iter;
      while(*iter != '\n' && *iter != '\0') { 
        if(*iter == ' ') *iter = '_';
        ++iter;
      }
      *iter = '\0';
      ++iter;
    }
    return imagenet_labels;
  }
}


static char** g_argv = NULL;

namespace{
DLTensor input_tensor;
int64_t input_shape[4] = {1,224,224,3}; //from graph.json

void SetRandomData(DLTensor* tensor, size_t size){
  float* storage = reinterpret_cast<float*>(tensor->data);
  for(int i=0; i < size; ++i) {
    storage[i] = (static_cast<float>(rand()) / RAND_MAX) * 2.0 - 1.0 ;
    if(storage[i] > 1.0 || storage[i] < -1.0) printf("invalid range.\n");
  }
}
}

DLTensor* MicroTVMRuntimeSetRandomTensor(void) {
  uint64_t size = 1;
  for (int i = 0; i < 4; ++i) {
    size *= (input_shape[i]);
  }
  size *= 4;//4bytes
  input_tensor.data = new char[size];
  input_tensor.dtype = DLDataType{kDLFloat,32,1};
  input_tensor.ndim = 4;
  input_tensor.device = DLDevice{kDLCPU,0};
  input_tensor.shape = input_shape;
  input_tensor.strides = nullptr;
  input_tensor.byte_offset = 0;

  SetRandomData(&input_tensor, size/4);
  return &input_tensor;
}



static inline size_t getdatasize(const DLTensor* t) {
  size_t size = 1;
  for (int i = 0; i < t->ndim; ++i) {
    size *= t->shape[i];
  }
  size *= (t->dtype.bits * t->dtype.lanes + 7) / 8;
  return size;
}

static void errx(const char *msg, TEEC_Result res, uint32_t orig)
{
  fprintf(stderr, msg, res, orig);
  exit (1);
}


struct optee_ctx{
    TEEC_Context ctx;
    TEEC_Session sess;
};

void optee_init_ta(struct optee_ctx *ctx)
{
  TEEC_UUID uuid = TA_ML_WITH_TEE_UUID;
  uint32_t origin;
  TEEC_Result res;

  /* Initialize a context connecting us to the TEE */
  res = TEEC_InitializeContext(NULL, &ctx->ctx);
  if (res != TEEC_SUCCESS)
    errx( "TEEC_InitializeContext failed with code 0x%x origin 0x%x", res, 0);
  /* Open a session with the TA */
  res = TEEC_OpenSession(&ctx->ctx, &ctx->sess, &uuid,
            TEEC_LOGIN_PUBLIC, NULL, NULL, &origin);
  if (res != TEEC_SUCCESS)
  errx( "TEEC_Opensession failed with code 0x%x origin 0x%x",
      res, origin);
}

void optee_terminate_ta(struct optee_ctx *ctx){
  TEEC_CloseSession(&ctx->sess);
  TEEC_FinalizeContext(&ctx->ctx);
}

void optee_cmd_TVMModCreateFromCModule(struct optee_ctx *ctx){
  TEEC_Operation op;
  uint32_t origin;
  TEEC_Result res;

  memset(&op, 0, sizeof(op));
  op.paramTypes = TEEC_PARAM_TYPES(TEEC_NONE,
           TEEC_NONE,
           TEEC_NONE,
           TEEC_NONE);

  res = TEEC_InvokeCommand(&ctx->sess, TA_ML_WITH_TEE_CMD_TVMModCreateFromCModule,
         &op, &origin);
  if (res != TEEC_SUCCESS)
    errx( "TEEC_InvokeCommand(TVMModCreateFromCModule) failed 0x%x origin 0x%x",
      res, origin);
}

void optee_cmd_LoadModelGraphJson(struct optee_ctx *ctx ,char* graph_json, size_t graph_json_size){
  TEEC_Operation op;
  TEEC_SharedMemory mem;
  uint32_t origin;
  TEEC_Result res;

  memset(&op, 0, sizeof(op));
  op.paramTypes = TEEC_PARAM_TYPES(TEEC_MEMREF_WHOLE,
           TEEC_NONE,
           TEEC_NONE,
           TEEC_NONE);
  memset(&mem, 0, sizeof(mem));
  mem.buffer = (void*)graph_json;
  mem.size   =  graph_json_size;
  mem.flags  =  TEEC_MEM_INPUT;
  TEEC_RegisterSharedMemory(&ctx->ctx, &mem);
  op.params[0].memref.parent = &mem;
  op.params[0].memref.size   = mem.size;
  op.params[0].memref.offset = 0;

  res = TEEC_InvokeCommand(&ctx->sess, TA_ML_WITH_TEE_CMD_LoadModelGraphJson,
         &op, &origin);
  if (res != TEEC_SUCCESS)
    errx( "TEEC_InvokeCommand(LoadModelGraphJson) failed 0x%x origin 0x%x",
      res, origin);
}

void optee_cmd_LoadModelParamBlob(struct optee_ctx *ctx ,char* param_blob, size_t param_blob_size){
  TEEC_Operation op;
  TEEC_SharedMemory mem;
  uint32_t origin;
  TEEC_Result res;

  memset(&op, 0, sizeof(op));
  op.paramTypes = TEEC_PARAM_TYPES(TEEC_MEMREF_WHOLE,
           TEEC_NONE,
           TEEC_NONE,
           TEEC_NONE);
  memset(&mem, 0, sizeof(mem));
  mem.buffer = (void*)param_blob;
  mem.size   =  param_blob_size;
  mem.flags  =  TEEC_MEM_INPUT;
  TEEC_RegisterSharedMemory(&ctx->ctx, &mem);
  op.params[0].memref.parent = &mem;
  op.params[0].memref.size   = mem.size;
  op.params[0].memref.offset = 0;

 res = TEEC_InvokeCommand(&ctx->sess ,TA_ML_WITH_TEE_CMD_LoadModelParamBlob,
         &op, &origin);
  if (res != TEEC_SUCCESS)
    errx( "TEEC_InvokeCommand(LoadModelParamBlob) failed 0x%x origin 0x%x",
      res, origin);
}


void optee_cmd_TVMGraphExecutor_SetInput(struct optee_ctx *ctx ,DLTensor* tensor){
  TEEC_Operation op;
  TEEC_SharedMemory mem;
  uint32_t origin;
  TEEC_Result res;

  memset(&op, 0, sizeof(op));
  op.paramTypes = TEEC_PARAM_TYPES(TEEC_MEMREF_WHOLE,
           TEEC_NONE,
           TEEC_NONE,
           TEEC_NONE);
  memset(&mem, 0, sizeof(mem));
  mem.buffer = (void*)tensor;
  mem.size   =  getdatasize(tensor);
  mem.flags  =  TEEC_MEM_INPUT;
  TEEC_RegisterSharedMemory(&ctx->ctx, &mem);
  op.params[0].memref.parent = &mem;
  op.params[0].memref.size   = mem.size;
  op.params[0].memref.offset = 0;

 res = TEEC_InvokeCommand(&ctx->sess, TA_ML_WITH_TEE_CMD_TVMGraphExecutor_SetInput,
         &op, &origin);
  if (res != TEEC_SUCCESS)
    errx( "TEEC_InvokeCommand(TVMGraphExecutor_SetInput) failed 0x%x origin 0x%x",
      res, origin);
}


void optee_cmd_TVMGraphExecutor_Run(struct optee_ctx *ctx){
  TEEC_Operation op;
  uint32_t origin;
  TEEC_Result res;

  memset(&op, 0, sizeof(op));
  op.paramTypes = TEEC_PARAM_TYPES(TEEC_NONE,
           TEEC_NONE,
           TEEC_NONE,
           TEEC_NONE);
  res = TEEC_InvokeCommand(&ctx->sess, TA_ML_WITH_TEE_CMD_TVMGraphExecutor_Run,
         &op, &origin);
  if (res != TEEC_SUCCESS)
    errx( "TEEC_InvokeCommand(TVMGraphExecutor_Run) failed 0x%x origin 0x%x",
      res, origin);
}


void optee_cmd_TVMGraphExecutor_GetOutput(struct optee_ctx *ctx ,DLTensor* tensor){
  TEEC_Operation op;
  TEEC_SharedMemory mem;
  uint32_t origin;
  TEEC_Result res;

  memset(&op, 0, sizeof(op));
  op.paramTypes = TEEC_PARAM_TYPES(TEEC_MEMREF_WHOLE,
           TEEC_NONE,
           TEEC_NONE,
           TEEC_NONE);
  memset(&mem, 0, sizeof(mem));
  mem.buffer = (void*)tensor;
  mem.size   =  getdatasize(tensor);
  mem.flags  =  TEEC_MEM_OUTPUT;
  TEEC_RegisterSharedMemory(&ctx->ctx, &mem);
  op.params[0].memref.parent = &mem;
  op.params[0].memref.size   = mem.size;
  op.params[0].memref.offset = 0;

 res = TEEC_InvokeCommand(&ctx->sess, TA_ML_WITH_TEE_CMD_TVMGraphExecutor_GetOutput,
         &op, &origin);

  if (res != TEEC_SUCCESS)
    errx( "TEEC_InvokeCommand(TVMGraphExecutor_GetOutput) failed 0x%x origin 0x%x",
      res, origin);
}


void optee_cmd_TVMGraphExecutor_Release(struct optee_ctx *ctx){
  TEEC_Operation op;
  uint32_t origin;
  TEEC_Result res;

  memset(&op, 0, sizeof(op));
  op.paramTypes = TEEC_PARAM_TYPES(TEEC_VALUE_INPUT,
           TEEC_NONE,
           TEEC_NONE,
           TEEC_NONE);
  res = TEEC_InvokeCommand(&ctx->sess, TA_ML_WITH_TEE_CMD_TVMGraphExecutor_Release,
         &op, &origin);
  if (res != TEEC_SUCCESS)
    errx( "TEEC_InvokeCommand(TVMGraphExecutor_Release) failed 0x%x origin 0x%x",
      res, origin);
}

int main(int argc, char** argv) {

  const std::string homepath = "/root/mlf/side_linux/";
  const std::string json_path = homepath + "tmp_no_simd/executor-config/graph/graph.json";
  const std::string params_path = homepath + "tmp_no_simd/parameters/default.params";
  const std::string labels_all_path =  homepath + "ILSVRC-2012-CLS_1001_labels.txt";
  const std::string labels_selected_path =  homepath + "selected_labels.txt";
  struct result_t{
    float result;
    int index;
    bool operator>(const result_t& right) const {
      return (result > right.result);
    }
  };
  struct optee_ctx ctx;
  memset(&ctx, 0 , sizeof(optee_ctx));
  optee_init_ta(&ctx);
  optee_cmd_TVMModCreateFromCModule(&ctx);
  // Load json which determins the model graph structure
  size_t json_bytes;
  char* graph_json = LoadFile(json_path, &json_bytes);
  optee_cmd_LoadModelGraphJson(&ctx, graph_json, json_bytes);
  // Load parameters of model matrixies 
  size_t params_bytes;
  char* parameter_blob = LoadFile(params_path, &params_bytes);
  optee_cmd_LoadModelParamBlob(&ctx, parameter_blob, params_bytes);

  // Execute inference at each image input and Evaluate the elapsed time 
  const int32_t kImagenetLabelsNum = 1001;
  const int32_t kSelectedLabelsNum = 3;
  const int32_t kImagesNumPerSelectedLabel = 3;
  // Load imagenet labels
  char** labels_all = LoadImagenetLabelsTxt(labels_all_path, kImagenetLabelsNum);
  char** labels_selected = LoadImagenetLabelsTxt(labels_selected_path, kSelectedLabelsNum);
  int selected_indices[kSelectedLabelsNum];
  for (int i = 0; i < kSelectedLabelsNum; i++){
    for (int j = 0; j < kImagenetLabelsNum; j++){
      if(!strcmp(labels_selected[i], labels_all[j])){
        selected_indices[i] = j;
      }
    }
  }
  double avg_elapsed_time = 0;
  double avg_topfive = 0;
  const int kNumOfInferences = kSelectedLabelsNum*kImagesNumPerSelectedLabel;

  for (int i = 0; i < kSelectedLabelsNum; i++) {
    const std::string images_dir_path = homepath + "imagenet_images/" + labels_selected[i] + "/";

    struct dirent *entry = nullptr;
    DIR *dp = nullptr;
    dp = opendir(images_dir_path.c_str());
    if (dp != nullptr) {

      int count_topfive_per_category = 0;

      for (int j = 0; j < kImagesNumPerSelectedLabel; j++) {
        entry = readdir(dp);
        if(!entry) {
          printf("[%d]category \"%s\": not having enough(%d) valid images.\n", i, labels_selected[i], kImagesNumPerSelectedLabel);
          break;
        }
        if(!strstr(entry->d_name,"jpg")){
          --j;continue;
        }
        
        const std::string image_path = images_dir_path + entry->d_name;
        DLTensor* image_tensor = nullptr;
        //image_tensor = MicroTVMRuntimeSetRandomTensor();
        int32_t err = ConvertImageToTensor(image_path, &image_tensor);
        if(err){
          //printf("  \"%s/%s\" is invalid for converting to tensor. maybe too small or so.\n", labels_selected[i] ,entry->d_name);
          --j;continue;
        }
        optee_cmd_TVMGraphExecutor_SetInput(&ctx, image_tensor);
        double elapsed_time_seconds;
        TVMPlatformTimerStart();
        optee_cmd_TVMGraphExecutor_Run(&ctx);
        TVMPlatformTimerStop(&elapsed_time_seconds);
        DLTensor output_tensor;
        output_tensor.data = new char[1001*4];
        output_tensor.device = DLDevice{kDLCPU,0};
        output_tensor.ndim = 2;
        output_tensor.dtype = DLDataType{kDLFloat,32,1};
        output_tensor.shape = new int64_t[2]{1, 1001};
        output_tensor.strides = nullptr;
        output_tensor.byte_offset = 0;
        optee_cmd_TVMGraphExecutor_GetOutput(&ctx, &output_tensor);
        float* data = reinterpret_cast<float*>(output_tensor.data);
        std::vector<result_t> results(kImagenetLabelsNum);
        for (int k = 0; k < kImagenetLabelsNum; k++){
          results[k].result = data[k];
          results[k].index  = k;
        }
        
        float max = 0;
        int index_of_max = -1;
        std::sort(results.begin(), results.end(),std::greater<result_t>());
        for (int k = 0; k < 5; k++){
          if (results[k].index == selected_indices[i]){
            count_topfive_per_category += 1;
          }
        }
        avg_elapsed_time += elapsed_time_seconds / (kSelectedLabelsNum * kImagesNumPerSelectedLabel);

        //for(int k = 0; k < 1001; ++k) {
        //  if(results[k] < -1.0 && results[k] > 1.0) printf("invalid result    [%d-%d]:%f\n",j,k,results[k]);
        //}
        
        //printf("%d of %s ... result: %f time(s): %lf\n",j , labels_selected[i], results[selected_indices[i]], elapsed_time_seconds);
        delete (float*)image_tensor->data;
        delete image_tensor->shape;
        delete (float*)output_tensor.data;
        delete output_tensor.shape;
      }
      //printf("[%d]category \"%s\" ... avg_time: %lf s, avg_result: %f %, avg_max: %f %\n", 
      //         i, labels_selected[i],avg_elapsed_time, avg_result*100, avg_max_result*100);
      printf("[%d]category \"%s\" ... top five:%d\n",i, labels_selected[i], count_topfive_per_category);
      avg_topfive += static_cast<double>(count_topfive_per_category) / kNumOfInferences;
    }
    closedir(dp);
  }
  printf("%d inferences done! ... average time: %lfs   top five: %f%\n",kNumOfInferences,avg_elapsed_time,avg_topfive * 100 );
  optee_cmd_TVMGraphExecutor_Release(&ctx);
  delete labels_selected[0];
  delete labels_selected;
  delete labels_all[0];
  delete labels_all;
  delete parameter_blob;
}
