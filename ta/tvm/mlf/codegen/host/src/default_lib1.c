// tvm target: c -keys=cpu -link-params=0 -runtime=c -system-lib=1
#define TVM_EXPORTS
#include "tvm/runtime/c_runtime_api.h"
#include "tvm/runtime/c_backend_api.h"
#include <math.h>
#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_avg_pool2d(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* tensor = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  void* tensor1 = TVMBackendAllocWorkspace(1, dev_id, (uint64_t)5120, 2, 32);
  if (tensor1 == NULL) {
    return -1;
  }
  for (int32_t ax0_ax1_fused_ax2_fused = 0; ax0_ax1_fused_ax2_fused < 320; ++ax0_ax1_fused_ax2_fused) {
    for (int32_t ax4_init = 0; ax4_init < 4; ++ax4_init) {
      ((float*)tensor1)[(((ax0_ax1_fused_ax2_fused * 4) + ax4_init))] = 0.000000e+00f;
    }
    for (int32_t rv0_rv1_fused = 0; rv0_rv1_fused < 49; ++rv0_rv1_fused) {
      for (int32_t ax4 = 0; ax4 < 4; ++ax4) {
        ((float*)tensor1)[(((ax0_ax1_fused_ax2_fused * 4) + ax4))] = (((float*)tensor1)[(((ax0_ax1_fused_ax2_fused * 4) + ax4))] + ((float*)placeholder)[((((ax0_ax1_fused_ax2_fused * 196) + (rv0_rv1_fused * 4)) + ax4))]);
      }
    }
  }
  for (int32_t ax0_ax1_fused = 0; ax0_ax1_fused < 320; ++ax0_ax1_fused) {
    for (int32_t ax41 = 0; ax41 < 4; ++ax41) {
      ((float*)tensor)[(((ax0_ax1_fused * 4) + ax41))] = (((float*)tensor1)[(((ax0_ax1_fused * 4) + ax41))] * 2.040816e-02f);
    }
  }
  if (TVMBackendFreeWorkspace(1, dev_id, tensor1) != 0) {
    return -1;
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_contrib_conv2d_NCHWc_add_clip_6(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int32_t arg2_code = ((int32_t*)arg_type_ids)[(2)];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int32_t arg3_code = ((int32_t*)arg_type_ids)[(3)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* placeholder1 = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  void* placeholder2 = (((DLTensor*)arg2)[0].data);
  void* arg2_shape = (((DLTensor*)arg2)[0].shape);
  void* arg2_strides = (((DLTensor*)arg2)[0].strides);
  void* compute = (((DLTensor*)arg3)[0].data);
  void* arg3_shape = (((DLTensor*)arg3)[0].shape);
  void* arg3_strides = (((DLTensor*)arg3)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  if (!(arg2_strides == NULL)) {
  }
  if (!(arg3_strides == NULL)) {
  }
  for (int32_t i0_i1_fused_i2_outer_fused = 0; i0_i1_fused_i2_outer_fused < 2688; ++i0_i1_fused_i2_outer_fused) {
    void* conv2d_NCHWc_global = TVMBackendAllocWorkspace(1, dev_id, (uint64_t)1792, 2, 32);
    if (conv2d_NCHWc_global == NULL) {
      return -1;
    }
    for (int32_t ow_c_outer = 0; ow_c_outer < 4; ++ow_c_outer) {
      for (int32_t oc_block_c_init = 0; oc_block_c_init < 4; ++oc_block_c_init) {
        ((float*)conv2d_NCHWc_global)[(((ow_c_outer * 112) + oc_block_c_init))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init1 = 0; oc_block_c_init1 < 4; ++oc_block_c_init1) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init1) + 4))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init2 = 0; oc_block_c_init2 < 4; ++oc_block_c_init2) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init2) + 8))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init3 = 0; oc_block_c_init3 < 4; ++oc_block_c_init3) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init3) + 12))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init4 = 0; oc_block_c_init4 < 4; ++oc_block_c_init4) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init4) + 16))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init5 = 0; oc_block_c_init5 < 4; ++oc_block_c_init5) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init5) + 20))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init6 = 0; oc_block_c_init6 < 4; ++oc_block_c_init6) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init6) + 24))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init7 = 0; oc_block_c_init7 < 4; ++oc_block_c_init7) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init7) + 28))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init8 = 0; oc_block_c_init8 < 4; ++oc_block_c_init8) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init8) + 32))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init9 = 0; oc_block_c_init9 < 4; ++oc_block_c_init9) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init9) + 36))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init10 = 0; oc_block_c_init10 < 4; ++oc_block_c_init10) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init10) + 40))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init11 = 0; oc_block_c_init11 < 4; ++oc_block_c_init11) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init11) + 44))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init12 = 0; oc_block_c_init12 < 4; ++oc_block_c_init12) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init12) + 48))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init13 = 0; oc_block_c_init13 < 4; ++oc_block_c_init13) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init13) + 52))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init14 = 0; oc_block_c_init14 < 4; ++oc_block_c_init14) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init14) + 56))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init15 = 0; oc_block_c_init15 < 4; ++oc_block_c_init15) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init15) + 60))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init16 = 0; oc_block_c_init16 < 4; ++oc_block_c_init16) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init16) + 64))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init17 = 0; oc_block_c_init17 < 4; ++oc_block_c_init17) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init17) + 68))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init18 = 0; oc_block_c_init18 < 4; ++oc_block_c_init18) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init18) + 72))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init19 = 0; oc_block_c_init19 < 4; ++oc_block_c_init19) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init19) + 76))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init20 = 0; oc_block_c_init20 < 4; ++oc_block_c_init20) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init20) + 80))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init21 = 0; oc_block_c_init21 < 4; ++oc_block_c_init21) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init21) + 84))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init22 = 0; oc_block_c_init22 < 4; ++oc_block_c_init22) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init22) + 88))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init23 = 0; oc_block_c_init23 < 4; ++oc_block_c_init23) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init23) + 92))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init24 = 0; oc_block_c_init24 < 4; ++oc_block_c_init24) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init24) + 96))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init25 = 0; oc_block_c_init25 < 4; ++oc_block_c_init25) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init25) + 100))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init26 = 0; oc_block_c_init26 < 4; ++oc_block_c_init26) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init26) + 104))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init27 = 0; oc_block_c_init27 < 4; ++oc_block_c_init27) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init27) + 108))] = 0.000000e+00f;
      }
      for (int32_t ic_outer = 0; ic_outer < 4; ++ic_outer) {
        for (int32_t ic_inner = 0; ic_inner < 4; ++ic_inner) {
          for (int32_t oc_block_c = 0; oc_block_c < 4; ++oc_block_c) {
            ((float*)conv2d_NCHWc_global)[(((ow_c_outer * 112) + oc_block_c))] = (((float*)conv2d_NCHWc_global)[(((ow_c_outer * 112) + oc_block_c))] + (((float*)placeholder)[(((((ic_outer * 50176) + ((i0_i1_fused_i2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 112) * 64) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c))]));
          }
          for (int32_t oc_block_c1 = 0; oc_block_c1 < 4; ++oc_block_c1) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c1) + 4))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c1) + 4))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((i0_i1_fused_i2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 4))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 112) * 64) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c1))]));
          }
          for (int32_t oc_block_c2 = 0; oc_block_c2 < 4; ++oc_block_c2) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c2) + 8))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c2) + 8))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((i0_i1_fused_i2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 8))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 112) * 64) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c2))]));
          }
          for (int32_t oc_block_c3 = 0; oc_block_c3 < 4; ++oc_block_c3) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c3) + 12))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c3) + 12))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((i0_i1_fused_i2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 12))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 112) * 64) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c3))]));
          }
          for (int32_t oc_block_c4 = 0; oc_block_c4 < 4; ++oc_block_c4) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c4) + 16))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c4) + 16))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((i0_i1_fused_i2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 16))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 112) * 64) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c4))]));
          }
          for (int32_t oc_block_c5 = 0; oc_block_c5 < 4; ++oc_block_c5) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c5) + 20))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c5) + 20))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((i0_i1_fused_i2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 20))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 112) * 64) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c5))]));
          }
          for (int32_t oc_block_c6 = 0; oc_block_c6 < 4; ++oc_block_c6) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c6) + 24))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c6) + 24))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((i0_i1_fused_i2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 24))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 112) * 64) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c6))]));
          }
          for (int32_t oc_block_c7 = 0; oc_block_c7 < 4; ++oc_block_c7) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c7) + 28))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c7) + 28))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((i0_i1_fused_i2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 28))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 112) * 64) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c7))]));
          }
          for (int32_t oc_block_c8 = 0; oc_block_c8 < 4; ++oc_block_c8) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c8) + 32))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c8) + 32))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((i0_i1_fused_i2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 32))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 112) * 64) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c8))]));
          }
          for (int32_t oc_block_c9 = 0; oc_block_c9 < 4; ++oc_block_c9) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c9) + 36))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c9) + 36))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((i0_i1_fused_i2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 36))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 112) * 64) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c9))]));
          }
          for (int32_t oc_block_c10 = 0; oc_block_c10 < 4; ++oc_block_c10) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c10) + 40))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c10) + 40))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((i0_i1_fused_i2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 40))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 112) * 64) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c10))]));
          }
          for (int32_t oc_block_c11 = 0; oc_block_c11 < 4; ++oc_block_c11) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c11) + 44))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c11) + 44))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((i0_i1_fused_i2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 44))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 112) * 64) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c11))]));
          }
          for (int32_t oc_block_c12 = 0; oc_block_c12 < 4; ++oc_block_c12) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c12) + 48))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c12) + 48))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((i0_i1_fused_i2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 48))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 112) * 64) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c12))]));
          }
          for (int32_t oc_block_c13 = 0; oc_block_c13 < 4; ++oc_block_c13) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c13) + 52))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c13) + 52))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((i0_i1_fused_i2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 52))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 112) * 64) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c13))]));
          }
          for (int32_t oc_block_c14 = 0; oc_block_c14 < 4; ++oc_block_c14) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c14) + 56))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c14) + 56))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((i0_i1_fused_i2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 56))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 112) * 64) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c14))]));
          }
          for (int32_t oc_block_c15 = 0; oc_block_c15 < 4; ++oc_block_c15) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c15) + 60))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c15) + 60))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((i0_i1_fused_i2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 60))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 112) * 64) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c15))]));
          }
          for (int32_t oc_block_c16 = 0; oc_block_c16 < 4; ++oc_block_c16) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c16) + 64))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c16) + 64))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((i0_i1_fused_i2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 64))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 112) * 64) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c16))]));
          }
          for (int32_t oc_block_c17 = 0; oc_block_c17 < 4; ++oc_block_c17) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c17) + 68))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c17) + 68))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((i0_i1_fused_i2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 68))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 112) * 64) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c17))]));
          }
          for (int32_t oc_block_c18 = 0; oc_block_c18 < 4; ++oc_block_c18) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c18) + 72))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c18) + 72))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((i0_i1_fused_i2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 72))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 112) * 64) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c18))]));
          }
          for (int32_t oc_block_c19 = 0; oc_block_c19 < 4; ++oc_block_c19) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c19) + 76))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c19) + 76))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((i0_i1_fused_i2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 76))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 112) * 64) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c19))]));
          }
          for (int32_t oc_block_c20 = 0; oc_block_c20 < 4; ++oc_block_c20) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c20) + 80))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c20) + 80))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((i0_i1_fused_i2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 80))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 112) * 64) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c20))]));
          }
          for (int32_t oc_block_c21 = 0; oc_block_c21 < 4; ++oc_block_c21) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c21) + 84))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c21) + 84))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((i0_i1_fused_i2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 84))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 112) * 64) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c21))]));
          }
          for (int32_t oc_block_c22 = 0; oc_block_c22 < 4; ++oc_block_c22) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c22) + 88))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c22) + 88))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((i0_i1_fused_i2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 88))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 112) * 64) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c22))]));
          }
          for (int32_t oc_block_c23 = 0; oc_block_c23 < 4; ++oc_block_c23) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c23) + 92))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c23) + 92))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((i0_i1_fused_i2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 92))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 112) * 64) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c23))]));
          }
          for (int32_t oc_block_c24 = 0; oc_block_c24 < 4; ++oc_block_c24) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c24) + 96))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c24) + 96))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((i0_i1_fused_i2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 96))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 112) * 64) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c24))]));
          }
          for (int32_t oc_block_c25 = 0; oc_block_c25 < 4; ++oc_block_c25) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c25) + 100))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c25) + 100))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((i0_i1_fused_i2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 100))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 112) * 64) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c25))]));
          }
          for (int32_t oc_block_c26 = 0; oc_block_c26 < 4; ++oc_block_c26) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c26) + 104))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c26) + 104))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((i0_i1_fused_i2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 104))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 112) * 64) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c26))]));
          }
          for (int32_t oc_block_c27 = 0; oc_block_c27 < 4; ++oc_block_c27) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c27) + 108))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c27) + 108))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((i0_i1_fused_i2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 108))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 112) * 64) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c27))]));
          }
        }
      }
    }
    for (int32_t i3_outer = 0; i3_outer < 4; ++i3_outer) {
      for (int32_t i3_inner = 0; i3_inner < 28; ++i3_inner) {
        for (int32_t i4 = 0; i4 < 4; ++i4) {
          float _1 = ((float*)conv2d_NCHWc_global)[((((i3_outer * 112) + (i3_inner * 4)) + i4))] + ((float*)placeholder2)[((((i0_i1_fused_i2_outer_fused / 112) * 4) + i4))];
          float _2 = (_1) < (6.000000e+00f) ? (_1) : (6.000000e+00f);
          ((float*)compute)[(((((i0_i1_fused_i2_outer_fused * 448) + (i3_outer * 112)) + (i3_inner * 4)) + i4))] = ((_2) > (0.000000e+00f) ? (_2) : (0.000000e+00f));
        }
      }
    }
    if (TVMBackendFreeWorkspace(1, dev_id, conv2d_NCHWc_global) != 0) {
      return -1;
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_contrib_conv2d_NCHWc_add_add_3(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int32_t arg2_code = ((int32_t*)arg_type_ids)[(2)];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int32_t arg3_code = ((int32_t*)arg_type_ids)[(3)];
  void* arg4 = (((TVMValue*)args)[4].v_handle);
  int32_t arg4_code = ((int32_t*)arg_type_ids)[(4)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* placeholder1 = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  void* placeholder2 = (((DLTensor*)arg2)[0].data);
  void* arg2_shape = (((DLTensor*)arg2)[0].shape);
  void* arg2_strides = (((DLTensor*)arg2)[0].strides);
  void* placeholder3 = (((DLTensor*)arg3)[0].data);
  void* arg3_shape = (((DLTensor*)arg3)[0].shape);
  void* arg3_strides = (((DLTensor*)arg3)[0].strides);
  void* T_add = (((DLTensor*)arg4)[0].data);
  void* arg4_shape = (((DLTensor*)arg4)[0].shape);
  void* arg4_strides = (((DLTensor*)arg4)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  if (!(arg2_strides == NULL)) {
  }
  if (!(arg3_strides == NULL)) {
  }
  if (!(arg4_strides == NULL)) {
  }
  for (int32_t ax0_ax1_fused_ax2_outer_fused = 0; ax0_ax1_fused_ax2_outer_fused < 224; ++ax0_ax1_fused_ax2_outer_fused) {
    float conv2d_NCHWc_global[112];
    for (int32_t oc_block_c_init = 0; oc_block_c_init < 4; ++oc_block_c_init) {
      conv2d_NCHWc_global[(oc_block_c_init)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init1 = 0; oc_block_c_init1 < 4; ++oc_block_c_init1) {
      conv2d_NCHWc_global[((oc_block_c_init1 + 4))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init2 = 0; oc_block_c_init2 < 4; ++oc_block_c_init2) {
      conv2d_NCHWc_global[((oc_block_c_init2 + 8))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init3 = 0; oc_block_c_init3 < 4; ++oc_block_c_init3) {
      conv2d_NCHWc_global[((oc_block_c_init3 + 12))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init4 = 0; oc_block_c_init4 < 4; ++oc_block_c_init4) {
      conv2d_NCHWc_global[((oc_block_c_init4 + 16))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init5 = 0; oc_block_c_init5 < 4; ++oc_block_c_init5) {
      conv2d_NCHWc_global[((oc_block_c_init5 + 20))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init6 = 0; oc_block_c_init6 < 4; ++oc_block_c_init6) {
      conv2d_NCHWc_global[((oc_block_c_init6 + 24))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init7 = 0; oc_block_c_init7 < 4; ++oc_block_c_init7) {
      conv2d_NCHWc_global[((oc_block_c_init7 + 28))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init8 = 0; oc_block_c_init8 < 4; ++oc_block_c_init8) {
      conv2d_NCHWc_global[((oc_block_c_init8 + 32))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init9 = 0; oc_block_c_init9 < 4; ++oc_block_c_init9) {
      conv2d_NCHWc_global[((oc_block_c_init9 + 36))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init10 = 0; oc_block_c_init10 < 4; ++oc_block_c_init10) {
      conv2d_NCHWc_global[((oc_block_c_init10 + 40))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init11 = 0; oc_block_c_init11 < 4; ++oc_block_c_init11) {
      conv2d_NCHWc_global[((oc_block_c_init11 + 44))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init12 = 0; oc_block_c_init12 < 4; ++oc_block_c_init12) {
      conv2d_NCHWc_global[((oc_block_c_init12 + 48))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init13 = 0; oc_block_c_init13 < 4; ++oc_block_c_init13) {
      conv2d_NCHWc_global[((oc_block_c_init13 + 52))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init14 = 0; oc_block_c_init14 < 4; ++oc_block_c_init14) {
      conv2d_NCHWc_global[((oc_block_c_init14 + 56))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init15 = 0; oc_block_c_init15 < 4; ++oc_block_c_init15) {
      conv2d_NCHWc_global[((oc_block_c_init15 + 60))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init16 = 0; oc_block_c_init16 < 4; ++oc_block_c_init16) {
      conv2d_NCHWc_global[((oc_block_c_init16 + 64))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init17 = 0; oc_block_c_init17 < 4; ++oc_block_c_init17) {
      conv2d_NCHWc_global[((oc_block_c_init17 + 68))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init18 = 0; oc_block_c_init18 < 4; ++oc_block_c_init18) {
      conv2d_NCHWc_global[((oc_block_c_init18 + 72))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init19 = 0; oc_block_c_init19 < 4; ++oc_block_c_init19) {
      conv2d_NCHWc_global[((oc_block_c_init19 + 76))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init20 = 0; oc_block_c_init20 < 4; ++oc_block_c_init20) {
      conv2d_NCHWc_global[((oc_block_c_init20 + 80))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init21 = 0; oc_block_c_init21 < 4; ++oc_block_c_init21) {
      conv2d_NCHWc_global[((oc_block_c_init21 + 84))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init22 = 0; oc_block_c_init22 < 4; ++oc_block_c_init22) {
      conv2d_NCHWc_global[((oc_block_c_init22 + 88))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init23 = 0; oc_block_c_init23 < 4; ++oc_block_c_init23) {
      conv2d_NCHWc_global[((oc_block_c_init23 + 92))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init24 = 0; oc_block_c_init24 < 4; ++oc_block_c_init24) {
      conv2d_NCHWc_global[((oc_block_c_init24 + 96))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init25 = 0; oc_block_c_init25 < 4; ++oc_block_c_init25) {
      conv2d_NCHWc_global[((oc_block_c_init25 + 100))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init26 = 0; oc_block_c_init26 < 4; ++oc_block_c_init26) {
      conv2d_NCHWc_global[((oc_block_c_init26 + 104))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init27 = 0; oc_block_c_init27 < 4; ++oc_block_c_init27) {
      conv2d_NCHWc_global[((oc_block_c_init27 + 108))] = 0.000000e+00f;
    }
    for (int32_t ic_outer = 0; ic_outer < 48; ++ic_outer) {
      for (int32_t ic_inner = 0; ic_inner < 4; ++ic_inner) {
        for (int32_t oc_block_c = 0; oc_block_c < 4; ++oc_block_c) {
          conv2d_NCHWc_global[(oc_block_c)] = (conv2d_NCHWc_global[(oc_block_c)] + (((float*)placeholder)[((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c))]));
        }
        for (int32_t oc_block_c1 = 0; oc_block_c1 < 4; ++oc_block_c1) {
          conv2d_NCHWc_global[((oc_block_c1 + 4))] = (conv2d_NCHWc_global[((oc_block_c1 + 4))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 4))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c1))]));
        }
        for (int32_t oc_block_c2 = 0; oc_block_c2 < 4; ++oc_block_c2) {
          conv2d_NCHWc_global[((oc_block_c2 + 8))] = (conv2d_NCHWc_global[((oc_block_c2 + 8))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 8))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c2))]));
        }
        for (int32_t oc_block_c3 = 0; oc_block_c3 < 4; ++oc_block_c3) {
          conv2d_NCHWc_global[((oc_block_c3 + 12))] = (conv2d_NCHWc_global[((oc_block_c3 + 12))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 12))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c3))]));
        }
        for (int32_t oc_block_c4 = 0; oc_block_c4 < 4; ++oc_block_c4) {
          conv2d_NCHWc_global[((oc_block_c4 + 16))] = (conv2d_NCHWc_global[((oc_block_c4 + 16))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 16))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c4))]));
        }
        for (int32_t oc_block_c5 = 0; oc_block_c5 < 4; ++oc_block_c5) {
          conv2d_NCHWc_global[((oc_block_c5 + 20))] = (conv2d_NCHWc_global[((oc_block_c5 + 20))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 20))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c5))]));
        }
        for (int32_t oc_block_c6 = 0; oc_block_c6 < 4; ++oc_block_c6) {
          conv2d_NCHWc_global[((oc_block_c6 + 24))] = (conv2d_NCHWc_global[((oc_block_c6 + 24))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 24))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c6))]));
        }
        for (int32_t oc_block_c7 = 0; oc_block_c7 < 4; ++oc_block_c7) {
          conv2d_NCHWc_global[((oc_block_c7 + 28))] = (conv2d_NCHWc_global[((oc_block_c7 + 28))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 28))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c7))]));
        }
        for (int32_t oc_block_c8 = 0; oc_block_c8 < 4; ++oc_block_c8) {
          conv2d_NCHWc_global[((oc_block_c8 + 32))] = (conv2d_NCHWc_global[((oc_block_c8 + 32))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 32))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c8))]));
        }
        for (int32_t oc_block_c9 = 0; oc_block_c9 < 4; ++oc_block_c9) {
          conv2d_NCHWc_global[((oc_block_c9 + 36))] = (conv2d_NCHWc_global[((oc_block_c9 + 36))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 36))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c9))]));
        }
        for (int32_t oc_block_c10 = 0; oc_block_c10 < 4; ++oc_block_c10) {
          conv2d_NCHWc_global[((oc_block_c10 + 40))] = (conv2d_NCHWc_global[((oc_block_c10 + 40))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 40))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c10))]));
        }
        for (int32_t oc_block_c11 = 0; oc_block_c11 < 4; ++oc_block_c11) {
          conv2d_NCHWc_global[((oc_block_c11 + 44))] = (conv2d_NCHWc_global[((oc_block_c11 + 44))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 44))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c11))]));
        }
        for (int32_t oc_block_c12 = 0; oc_block_c12 < 4; ++oc_block_c12) {
          conv2d_NCHWc_global[((oc_block_c12 + 48))] = (conv2d_NCHWc_global[((oc_block_c12 + 48))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 48))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c12))]));
        }
        for (int32_t oc_block_c13 = 0; oc_block_c13 < 4; ++oc_block_c13) {
          conv2d_NCHWc_global[((oc_block_c13 + 52))] = (conv2d_NCHWc_global[((oc_block_c13 + 52))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 52))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c13))]));
        }
        for (int32_t oc_block_c14 = 0; oc_block_c14 < 4; ++oc_block_c14) {
          conv2d_NCHWc_global[((oc_block_c14 + 56))] = (conv2d_NCHWc_global[((oc_block_c14 + 56))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 56))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c14))]));
        }
        for (int32_t oc_block_c15 = 0; oc_block_c15 < 4; ++oc_block_c15) {
          conv2d_NCHWc_global[((oc_block_c15 + 60))] = (conv2d_NCHWc_global[((oc_block_c15 + 60))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 60))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c15))]));
        }
        for (int32_t oc_block_c16 = 0; oc_block_c16 < 4; ++oc_block_c16) {
          conv2d_NCHWc_global[((oc_block_c16 + 64))] = (conv2d_NCHWc_global[((oc_block_c16 + 64))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 64))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c16))]));
        }
        for (int32_t oc_block_c17 = 0; oc_block_c17 < 4; ++oc_block_c17) {
          conv2d_NCHWc_global[((oc_block_c17 + 68))] = (conv2d_NCHWc_global[((oc_block_c17 + 68))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 68))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c17))]));
        }
        for (int32_t oc_block_c18 = 0; oc_block_c18 < 4; ++oc_block_c18) {
          conv2d_NCHWc_global[((oc_block_c18 + 72))] = (conv2d_NCHWc_global[((oc_block_c18 + 72))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 72))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c18))]));
        }
        for (int32_t oc_block_c19 = 0; oc_block_c19 < 4; ++oc_block_c19) {
          conv2d_NCHWc_global[((oc_block_c19 + 76))] = (conv2d_NCHWc_global[((oc_block_c19 + 76))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 76))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c19))]));
        }
        for (int32_t oc_block_c20 = 0; oc_block_c20 < 4; ++oc_block_c20) {
          conv2d_NCHWc_global[((oc_block_c20 + 80))] = (conv2d_NCHWc_global[((oc_block_c20 + 80))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 80))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c20))]));
        }
        for (int32_t oc_block_c21 = 0; oc_block_c21 < 4; ++oc_block_c21) {
          conv2d_NCHWc_global[((oc_block_c21 + 84))] = (conv2d_NCHWc_global[((oc_block_c21 + 84))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 84))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c21))]));
        }
        for (int32_t oc_block_c22 = 0; oc_block_c22 < 4; ++oc_block_c22) {
          conv2d_NCHWc_global[((oc_block_c22 + 88))] = (conv2d_NCHWc_global[((oc_block_c22 + 88))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 88))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c22))]));
        }
        for (int32_t oc_block_c23 = 0; oc_block_c23 < 4; ++oc_block_c23) {
          conv2d_NCHWc_global[((oc_block_c23 + 92))] = (conv2d_NCHWc_global[((oc_block_c23 + 92))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 92))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c23))]));
        }
        for (int32_t oc_block_c24 = 0; oc_block_c24 < 4; ++oc_block_c24) {
          conv2d_NCHWc_global[((oc_block_c24 + 96))] = (conv2d_NCHWc_global[((oc_block_c24 + 96))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 96))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c24))]));
        }
        for (int32_t oc_block_c25 = 0; oc_block_c25 < 4; ++oc_block_c25) {
          conv2d_NCHWc_global[((oc_block_c25 + 100))] = (conv2d_NCHWc_global[((oc_block_c25 + 100))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 100))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c25))]));
        }
        for (int32_t oc_block_c26 = 0; oc_block_c26 < 4; ++oc_block_c26) {
          conv2d_NCHWc_global[((oc_block_c26 + 104))] = (conv2d_NCHWc_global[((oc_block_c26 + 104))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 104))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c26))]));
        }
        for (int32_t oc_block_c27 = 0; oc_block_c27 < 4; ++oc_block_c27) {
          conv2d_NCHWc_global[((oc_block_c27 + 108))] = (conv2d_NCHWc_global[((oc_block_c27 + 108))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 108))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c27))]));
        }
      }
    }
    for (int32_t ax3_inner = 0; ax3_inner < 28; ++ax3_inner) {
      for (int32_t ax4 = 0; ax4 < 4; ++ax4) {
        ((float*)T_add)[((((ax0_ax1_fused_ax2_outer_fused * 112) + (ax3_inner * 4)) + ax4))] = ((conv2d_NCHWc_global[(((ax3_inner * 4) + ax4))] + ((float*)placeholder2)[((((ax0_ax1_fused_ax2_outer_fused / 28) * 4) + ax4))]) + ((float*)placeholder3)[((((ax0_ax1_fused_ax2_outer_fused * 112) + (ax3_inner * 4)) + ax4))]);
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_contrib_conv2d_NCHWc_add_clip_5(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int32_t arg2_code = ((int32_t*)arg_type_ids)[(2)];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int32_t arg3_code = ((int32_t*)arg_type_ids)[(3)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* placeholder1 = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  void* placeholder2 = (((DLTensor*)arg2)[0].data);
  void* arg2_shape = (((DLTensor*)arg2)[0].shape);
  void* arg2_strides = (((DLTensor*)arg2)[0].strides);
  void* compute = (((DLTensor*)arg3)[0].data);
  void* arg3_shape = (((DLTensor*)arg3)[0].shape);
  void* arg3_strides = (((DLTensor*)arg3)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  if (!(arg2_strides == NULL)) {
  }
  if (!(arg3_strides == NULL)) {
  }
  for (int32_t i0_i1_fused_i2_outer_fused = 0; i0_i1_fused_i2_outer_fused < 2016; ++i0_i1_fused_i2_outer_fused) {
    float conv2d_NCHWc_global[224];
    for (int32_t ow_c_outer = 0; ow_c_outer < 2; ++ow_c_outer) {
      for (int32_t oc_block_c_init = 0; oc_block_c_init < 4; ++oc_block_c_init) {
        conv2d_NCHWc_global[(((ow_c_outer * 112) + oc_block_c_init))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init1 = 0; oc_block_c_init1 < 4; ++oc_block_c_init1) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init1) + 4))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init2 = 0; oc_block_c_init2 < 4; ++oc_block_c_init2) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init2) + 8))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init3 = 0; oc_block_c_init3 < 4; ++oc_block_c_init3) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init3) + 12))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init4 = 0; oc_block_c_init4 < 4; ++oc_block_c_init4) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init4) + 16))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init5 = 0; oc_block_c_init5 < 4; ++oc_block_c_init5) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init5) + 20))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init6 = 0; oc_block_c_init6 < 4; ++oc_block_c_init6) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init6) + 24))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init7 = 0; oc_block_c_init7 < 4; ++oc_block_c_init7) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init7) + 28))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init8 = 0; oc_block_c_init8 < 4; ++oc_block_c_init8) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init8) + 32))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init9 = 0; oc_block_c_init9 < 4; ++oc_block_c_init9) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init9) + 36))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init10 = 0; oc_block_c_init10 < 4; ++oc_block_c_init10) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init10) + 40))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init11 = 0; oc_block_c_init11 < 4; ++oc_block_c_init11) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init11) + 44))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init12 = 0; oc_block_c_init12 < 4; ++oc_block_c_init12) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init12) + 48))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init13 = 0; oc_block_c_init13 < 4; ++oc_block_c_init13) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init13) + 52))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init14 = 0; oc_block_c_init14 < 4; ++oc_block_c_init14) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init14) + 56))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init15 = 0; oc_block_c_init15 < 4; ++oc_block_c_init15) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init15) + 60))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init16 = 0; oc_block_c_init16 < 4; ++oc_block_c_init16) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init16) + 64))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init17 = 0; oc_block_c_init17 < 4; ++oc_block_c_init17) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init17) + 68))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init18 = 0; oc_block_c_init18 < 4; ++oc_block_c_init18) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init18) + 72))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init19 = 0; oc_block_c_init19 < 4; ++oc_block_c_init19) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init19) + 76))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init20 = 0; oc_block_c_init20 < 4; ++oc_block_c_init20) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init20) + 80))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init21 = 0; oc_block_c_init21 < 4; ++oc_block_c_init21) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init21) + 84))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init22 = 0; oc_block_c_init22 < 4; ++oc_block_c_init22) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init22) + 88))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init23 = 0; oc_block_c_init23 < 4; ++oc_block_c_init23) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init23) + 92))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init24 = 0; oc_block_c_init24 < 4; ++oc_block_c_init24) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init24) + 96))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init25 = 0; oc_block_c_init25 < 4; ++oc_block_c_init25) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init25) + 100))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init26 = 0; oc_block_c_init26 < 4; ++oc_block_c_init26) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init26) + 104))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init27 = 0; oc_block_c_init27 < 4; ++oc_block_c_init27) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init27) + 108))] = 0.000000e+00f;
      }
      for (int32_t ic_outer = 0; ic_outer < 6; ++ic_outer) {
        for (int32_t ic_inner = 0; ic_inner < 4; ++ic_inner) {
          for (int32_t oc_block_c = 0; oc_block_c < 4; ++oc_block_c) {
            conv2d_NCHWc_global[(((ow_c_outer * 112) + oc_block_c))] = (conv2d_NCHWc_global[(((ow_c_outer * 112) + oc_block_c))] + (((float*)placeholder)[(((((ic_outer * 12544) + ((i0_i1_fused_i2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 56) * 96) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c))]));
          }
          for (int32_t oc_block_c1 = 0; oc_block_c1 < 4; ++oc_block_c1) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c1) + 4))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c1) + 4))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((i0_i1_fused_i2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 4))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 56) * 96) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c1))]));
          }
          for (int32_t oc_block_c2 = 0; oc_block_c2 < 4; ++oc_block_c2) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c2) + 8))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c2) + 8))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((i0_i1_fused_i2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 8))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 56) * 96) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c2))]));
          }
          for (int32_t oc_block_c3 = 0; oc_block_c3 < 4; ++oc_block_c3) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c3) + 12))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c3) + 12))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((i0_i1_fused_i2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 12))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 56) * 96) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c3))]));
          }
          for (int32_t oc_block_c4 = 0; oc_block_c4 < 4; ++oc_block_c4) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c4) + 16))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c4) + 16))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((i0_i1_fused_i2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 16))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 56) * 96) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c4))]));
          }
          for (int32_t oc_block_c5 = 0; oc_block_c5 < 4; ++oc_block_c5) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c5) + 20))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c5) + 20))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((i0_i1_fused_i2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 20))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 56) * 96) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c5))]));
          }
          for (int32_t oc_block_c6 = 0; oc_block_c6 < 4; ++oc_block_c6) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c6) + 24))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c6) + 24))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((i0_i1_fused_i2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 24))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 56) * 96) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c6))]));
          }
          for (int32_t oc_block_c7 = 0; oc_block_c7 < 4; ++oc_block_c7) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c7) + 28))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c7) + 28))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((i0_i1_fused_i2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 28))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 56) * 96) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c7))]));
          }
          for (int32_t oc_block_c8 = 0; oc_block_c8 < 4; ++oc_block_c8) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c8) + 32))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c8) + 32))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((i0_i1_fused_i2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 32))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 56) * 96) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c8))]));
          }
          for (int32_t oc_block_c9 = 0; oc_block_c9 < 4; ++oc_block_c9) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c9) + 36))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c9) + 36))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((i0_i1_fused_i2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 36))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 56) * 96) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c9))]));
          }
          for (int32_t oc_block_c10 = 0; oc_block_c10 < 4; ++oc_block_c10) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c10) + 40))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c10) + 40))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((i0_i1_fused_i2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 40))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 56) * 96) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c10))]));
          }
          for (int32_t oc_block_c11 = 0; oc_block_c11 < 4; ++oc_block_c11) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c11) + 44))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c11) + 44))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((i0_i1_fused_i2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 44))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 56) * 96) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c11))]));
          }
          for (int32_t oc_block_c12 = 0; oc_block_c12 < 4; ++oc_block_c12) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c12) + 48))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c12) + 48))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((i0_i1_fused_i2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 48))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 56) * 96) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c12))]));
          }
          for (int32_t oc_block_c13 = 0; oc_block_c13 < 4; ++oc_block_c13) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c13) + 52))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c13) + 52))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((i0_i1_fused_i2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 52))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 56) * 96) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c13))]));
          }
          for (int32_t oc_block_c14 = 0; oc_block_c14 < 4; ++oc_block_c14) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c14) + 56))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c14) + 56))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((i0_i1_fused_i2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 56))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 56) * 96) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c14))]));
          }
          for (int32_t oc_block_c15 = 0; oc_block_c15 < 4; ++oc_block_c15) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c15) + 60))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c15) + 60))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((i0_i1_fused_i2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 60))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 56) * 96) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c15))]));
          }
          for (int32_t oc_block_c16 = 0; oc_block_c16 < 4; ++oc_block_c16) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c16) + 64))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c16) + 64))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((i0_i1_fused_i2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 64))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 56) * 96) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c16))]));
          }
          for (int32_t oc_block_c17 = 0; oc_block_c17 < 4; ++oc_block_c17) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c17) + 68))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c17) + 68))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((i0_i1_fused_i2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 68))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 56) * 96) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c17))]));
          }
          for (int32_t oc_block_c18 = 0; oc_block_c18 < 4; ++oc_block_c18) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c18) + 72))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c18) + 72))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((i0_i1_fused_i2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 72))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 56) * 96) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c18))]));
          }
          for (int32_t oc_block_c19 = 0; oc_block_c19 < 4; ++oc_block_c19) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c19) + 76))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c19) + 76))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((i0_i1_fused_i2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 76))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 56) * 96) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c19))]));
          }
          for (int32_t oc_block_c20 = 0; oc_block_c20 < 4; ++oc_block_c20) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c20) + 80))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c20) + 80))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((i0_i1_fused_i2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 80))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 56) * 96) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c20))]));
          }
          for (int32_t oc_block_c21 = 0; oc_block_c21 < 4; ++oc_block_c21) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c21) + 84))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c21) + 84))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((i0_i1_fused_i2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 84))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 56) * 96) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c21))]));
          }
          for (int32_t oc_block_c22 = 0; oc_block_c22 < 4; ++oc_block_c22) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c22) + 88))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c22) + 88))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((i0_i1_fused_i2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 88))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 56) * 96) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c22))]));
          }
          for (int32_t oc_block_c23 = 0; oc_block_c23 < 4; ++oc_block_c23) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c23) + 92))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c23) + 92))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((i0_i1_fused_i2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 92))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 56) * 96) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c23))]));
          }
          for (int32_t oc_block_c24 = 0; oc_block_c24 < 4; ++oc_block_c24) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c24) + 96))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c24) + 96))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((i0_i1_fused_i2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 96))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 56) * 96) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c24))]));
          }
          for (int32_t oc_block_c25 = 0; oc_block_c25 < 4; ++oc_block_c25) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c25) + 100))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c25) + 100))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((i0_i1_fused_i2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 100))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 56) * 96) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c25))]));
          }
          for (int32_t oc_block_c26 = 0; oc_block_c26 < 4; ++oc_block_c26) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c26) + 104))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c26) + 104))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((i0_i1_fused_i2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 104))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 56) * 96) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c26))]));
          }
          for (int32_t oc_block_c27 = 0; oc_block_c27 < 4; ++oc_block_c27) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c27) + 108))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c27) + 108))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((i0_i1_fused_i2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 108))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 56) * 96) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c27))]));
          }
        }
      }
    }
    for (int32_t i3_outer = 0; i3_outer < 2; ++i3_outer) {
      for (int32_t i3_inner = 0; i3_inner < 28; ++i3_inner) {
        for (int32_t i4 = 0; i4 < 4; ++i4) {
          float _1 = conv2d_NCHWc_global[((((i3_outer * 112) + (i3_inner * 4)) + i4))] + ((float*)placeholder2)[((((i0_i1_fused_i2_outer_fused / 56) * 4) + i4))];
          float _2 = (_1) < (6.000000e+00f) ? (_1) : (6.000000e+00f);
          ((float*)compute)[(((((i0_i1_fused_i2_outer_fused * 224) + (i3_outer * 112)) + (i3_inner * 4)) + i4))] = ((_2) > (0.000000e+00f) ? (_2) : (0.000000e+00f));
        }
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_contrib_conv2d_NCHWc_add_6(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int32_t arg2_code = ((int32_t*)arg_type_ids)[(2)];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int32_t arg3_code = ((int32_t*)arg_type_ids)[(3)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* placeholder1 = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  void* placeholder2 = (((DLTensor*)arg2)[0].data);
  void* arg2_shape = (((DLTensor*)arg2)[0].shape);
  void* arg2_strides = (((DLTensor*)arg2)[0].strides);
  void* T_add = (((DLTensor*)arg3)[0].data);
  void* arg3_shape = (((DLTensor*)arg3)[0].shape);
  void* arg3_strides = (((DLTensor*)arg3)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  if (!(arg2_strides == NULL)) {
  }
  if (!(arg3_strides == NULL)) {
  }
  for (int32_t ax0_ax1_fused_ax2_outer_fused = 0; ax0_ax1_fused_ax2_outer_fused < 336; ++ax0_ax1_fused_ax2_outer_fused) {
    float conv2d_NCHWc_global[224];
    for (int32_t ow_c_outer = 0; ow_c_outer < 2; ++ow_c_outer) {
      for (int32_t oc_block_c_init = 0; oc_block_c_init < 4; ++oc_block_c_init) {
        conv2d_NCHWc_global[(((ow_c_outer * 112) + oc_block_c_init))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init1 = 0; oc_block_c_init1 < 4; ++oc_block_c_init1) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init1) + 4))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init2 = 0; oc_block_c_init2 < 4; ++oc_block_c_init2) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init2) + 8))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init3 = 0; oc_block_c_init3 < 4; ++oc_block_c_init3) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init3) + 12))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init4 = 0; oc_block_c_init4 < 4; ++oc_block_c_init4) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init4) + 16))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init5 = 0; oc_block_c_init5 < 4; ++oc_block_c_init5) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init5) + 20))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init6 = 0; oc_block_c_init6 < 4; ++oc_block_c_init6) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init6) + 24))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init7 = 0; oc_block_c_init7 < 4; ++oc_block_c_init7) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init7) + 28))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init8 = 0; oc_block_c_init8 < 4; ++oc_block_c_init8) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init8) + 32))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init9 = 0; oc_block_c_init9 < 4; ++oc_block_c_init9) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init9) + 36))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init10 = 0; oc_block_c_init10 < 4; ++oc_block_c_init10) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init10) + 40))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init11 = 0; oc_block_c_init11 < 4; ++oc_block_c_init11) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init11) + 44))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init12 = 0; oc_block_c_init12 < 4; ++oc_block_c_init12) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init12) + 48))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init13 = 0; oc_block_c_init13 < 4; ++oc_block_c_init13) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init13) + 52))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init14 = 0; oc_block_c_init14 < 4; ++oc_block_c_init14) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init14) + 56))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init15 = 0; oc_block_c_init15 < 4; ++oc_block_c_init15) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init15) + 60))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init16 = 0; oc_block_c_init16 < 4; ++oc_block_c_init16) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init16) + 64))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init17 = 0; oc_block_c_init17 < 4; ++oc_block_c_init17) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init17) + 68))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init18 = 0; oc_block_c_init18 < 4; ++oc_block_c_init18) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init18) + 72))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init19 = 0; oc_block_c_init19 < 4; ++oc_block_c_init19) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init19) + 76))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init20 = 0; oc_block_c_init20 < 4; ++oc_block_c_init20) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init20) + 80))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init21 = 0; oc_block_c_init21 < 4; ++oc_block_c_init21) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init21) + 84))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init22 = 0; oc_block_c_init22 < 4; ++oc_block_c_init22) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init22) + 88))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init23 = 0; oc_block_c_init23 < 4; ++oc_block_c_init23) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init23) + 92))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init24 = 0; oc_block_c_init24 < 4; ++oc_block_c_init24) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init24) + 96))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init25 = 0; oc_block_c_init25 < 4; ++oc_block_c_init25) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init25) + 100))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init26 = 0; oc_block_c_init26 < 4; ++oc_block_c_init26) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init26) + 104))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init27 = 0; oc_block_c_init27 < 4; ++oc_block_c_init27) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init27) + 108))] = 0.000000e+00f;
      }
      for (int32_t ic_outer = 0; ic_outer < 24; ++ic_outer) {
        for (int32_t ic_inner = 0; ic_inner < 4; ++ic_inner) {
          for (int32_t oc_block_c = 0; oc_block_c < 4; ++oc_block_c) {
            conv2d_NCHWc_global[(((ow_c_outer * 112) + oc_block_c))] = (conv2d_NCHWc_global[(((ow_c_outer * 112) + oc_block_c))] + (((float*)placeholder)[(((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c))]));
          }
          for (int32_t oc_block_c1 = 0; oc_block_c1 < 4; ++oc_block_c1) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c1) + 4))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c1) + 4))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 4))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c1))]));
          }
          for (int32_t oc_block_c2 = 0; oc_block_c2 < 4; ++oc_block_c2) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c2) + 8))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c2) + 8))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 8))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c2))]));
          }
          for (int32_t oc_block_c3 = 0; oc_block_c3 < 4; ++oc_block_c3) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c3) + 12))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c3) + 12))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 12))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c3))]));
          }
          for (int32_t oc_block_c4 = 0; oc_block_c4 < 4; ++oc_block_c4) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c4) + 16))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c4) + 16))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 16))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c4))]));
          }
          for (int32_t oc_block_c5 = 0; oc_block_c5 < 4; ++oc_block_c5) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c5) + 20))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c5) + 20))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 20))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c5))]));
          }
          for (int32_t oc_block_c6 = 0; oc_block_c6 < 4; ++oc_block_c6) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c6) + 24))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c6) + 24))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 24))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c6))]));
          }
          for (int32_t oc_block_c7 = 0; oc_block_c7 < 4; ++oc_block_c7) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c7) + 28))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c7) + 28))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 28))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c7))]));
          }
          for (int32_t oc_block_c8 = 0; oc_block_c8 < 4; ++oc_block_c8) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c8) + 32))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c8) + 32))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 32))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c8))]));
          }
          for (int32_t oc_block_c9 = 0; oc_block_c9 < 4; ++oc_block_c9) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c9) + 36))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c9) + 36))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 36))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c9))]));
          }
          for (int32_t oc_block_c10 = 0; oc_block_c10 < 4; ++oc_block_c10) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c10) + 40))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c10) + 40))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 40))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c10))]));
          }
          for (int32_t oc_block_c11 = 0; oc_block_c11 < 4; ++oc_block_c11) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c11) + 44))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c11) + 44))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 44))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c11))]));
          }
          for (int32_t oc_block_c12 = 0; oc_block_c12 < 4; ++oc_block_c12) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c12) + 48))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c12) + 48))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 48))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c12))]));
          }
          for (int32_t oc_block_c13 = 0; oc_block_c13 < 4; ++oc_block_c13) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c13) + 52))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c13) + 52))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 52))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c13))]));
          }
          for (int32_t oc_block_c14 = 0; oc_block_c14 < 4; ++oc_block_c14) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c14) + 56))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c14) + 56))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 56))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c14))]));
          }
          for (int32_t oc_block_c15 = 0; oc_block_c15 < 4; ++oc_block_c15) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c15) + 60))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c15) + 60))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 60))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c15))]));
          }
          for (int32_t oc_block_c16 = 0; oc_block_c16 < 4; ++oc_block_c16) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c16) + 64))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c16) + 64))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 64))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c16))]));
          }
          for (int32_t oc_block_c17 = 0; oc_block_c17 < 4; ++oc_block_c17) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c17) + 68))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c17) + 68))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 68))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c17))]));
          }
          for (int32_t oc_block_c18 = 0; oc_block_c18 < 4; ++oc_block_c18) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c18) + 72))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c18) + 72))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 72))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c18))]));
          }
          for (int32_t oc_block_c19 = 0; oc_block_c19 < 4; ++oc_block_c19) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c19) + 76))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c19) + 76))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 76))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c19))]));
          }
          for (int32_t oc_block_c20 = 0; oc_block_c20 < 4; ++oc_block_c20) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c20) + 80))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c20) + 80))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 80))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c20))]));
          }
          for (int32_t oc_block_c21 = 0; oc_block_c21 < 4; ++oc_block_c21) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c21) + 84))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c21) + 84))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 84))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c21))]));
          }
          for (int32_t oc_block_c22 = 0; oc_block_c22 < 4; ++oc_block_c22) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c22) + 88))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c22) + 88))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 88))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c22))]));
          }
          for (int32_t oc_block_c23 = 0; oc_block_c23 < 4; ++oc_block_c23) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c23) + 92))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c23) + 92))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 92))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c23))]));
          }
          for (int32_t oc_block_c24 = 0; oc_block_c24 < 4; ++oc_block_c24) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c24) + 96))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c24) + 96))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 96))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c24))]));
          }
          for (int32_t oc_block_c25 = 0; oc_block_c25 < 4; ++oc_block_c25) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c25) + 100))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c25) + 100))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 100))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c25))]));
          }
          for (int32_t oc_block_c26 = 0; oc_block_c26 < 4; ++oc_block_c26) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c26) + 104))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c26) + 104))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 104))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c26))]));
          }
          for (int32_t oc_block_c27 = 0; oc_block_c27 < 4; ++oc_block_c27) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c27) + 108))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c27) + 108))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 108))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c27))]));
          }
        }
      }
    }
    for (int32_t ax3_outer = 0; ax3_outer < 2; ++ax3_outer) {
      for (int32_t ax3_inner = 0; ax3_inner < 28; ++ax3_inner) {
        for (int32_t ax4 = 0; ax4 < 4; ++ax4) {
          ((float*)T_add)[(((((ax0_ax1_fused_ax2_outer_fused * 224) + (ax3_outer * 112)) + (ax3_inner * 4)) + ax4))] = (conv2d_NCHWc_global[((((ax3_outer * 112) + (ax3_inner * 4)) + ax4))] + ((float*)placeholder2)[((((ax0_ax1_fused_ax2_outer_fused / 56) * 4) + ax4))]);
        }
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_layout_transform_layout_transform_reshape(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* T_reshape = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  for (int32_t ax1_outer = 0; ax1_outer < 63; ++ax1_outer) {
    for (int32_t ax1_inner = 0; ax1_inner < 16; ++ax1_inner) {
      if (((ax1_outer * 16) + ax1_inner) < 1001) {
        ((float*)T_reshape)[(((ax1_outer * 16) + ax1_inner))] = ((float*)placeholder)[(((ax1_outer * 16) + ax1_inner))];
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_contrib_conv2d_NCHWc_add_clip_4(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int32_t arg2_code = ((int32_t*)arg_type_ids)[(2)];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int32_t arg3_code = ((int32_t*)arg_type_ids)[(3)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* placeholder1 = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  void* placeholder2 = (((DLTensor*)arg2)[0].data);
  void* arg2_shape = (((DLTensor*)arg2)[0].shape);
  void* arg2_strides = (((DLTensor*)arg2)[0].strides);
  void* compute = (((DLTensor*)arg3)[0].data);
  void* arg3_shape = (((DLTensor*)arg3)[0].shape);
  void* arg3_strides = (((DLTensor*)arg3)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  if (!(arg2_strides == NULL)) {
  }
  if (!(arg3_strides == NULL)) {
  }
  for (int32_t i0_i1_fused_i2_outer_fused = 0; i0_i1_fused_i2_outer_fused < 1344; ++i0_i1_fused_i2_outer_fused) {
    float conv2d_NCHWc_global[112];
    for (int32_t oc_block_c_init = 0; oc_block_c_init < 4; ++oc_block_c_init) {
      conv2d_NCHWc_global[(oc_block_c_init)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init1 = 0; oc_block_c_init1 < 4; ++oc_block_c_init1) {
      conv2d_NCHWc_global[((oc_block_c_init1 + 4))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init2 = 0; oc_block_c_init2 < 4; ++oc_block_c_init2) {
      conv2d_NCHWc_global[((oc_block_c_init2 + 8))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init3 = 0; oc_block_c_init3 < 4; ++oc_block_c_init3) {
      conv2d_NCHWc_global[((oc_block_c_init3 + 12))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init4 = 0; oc_block_c_init4 < 4; ++oc_block_c_init4) {
      conv2d_NCHWc_global[((oc_block_c_init4 + 16))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init5 = 0; oc_block_c_init5 < 4; ++oc_block_c_init5) {
      conv2d_NCHWc_global[((oc_block_c_init5 + 20))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init6 = 0; oc_block_c_init6 < 4; ++oc_block_c_init6) {
      conv2d_NCHWc_global[((oc_block_c_init6 + 24))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init7 = 0; oc_block_c_init7 < 4; ++oc_block_c_init7) {
      conv2d_NCHWc_global[((oc_block_c_init7 + 28))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init8 = 0; oc_block_c_init8 < 4; ++oc_block_c_init8) {
      conv2d_NCHWc_global[((oc_block_c_init8 + 32))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init9 = 0; oc_block_c_init9 < 4; ++oc_block_c_init9) {
      conv2d_NCHWc_global[((oc_block_c_init9 + 36))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init10 = 0; oc_block_c_init10 < 4; ++oc_block_c_init10) {
      conv2d_NCHWc_global[((oc_block_c_init10 + 40))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init11 = 0; oc_block_c_init11 < 4; ++oc_block_c_init11) {
      conv2d_NCHWc_global[((oc_block_c_init11 + 44))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init12 = 0; oc_block_c_init12 < 4; ++oc_block_c_init12) {
      conv2d_NCHWc_global[((oc_block_c_init12 + 48))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init13 = 0; oc_block_c_init13 < 4; ++oc_block_c_init13) {
      conv2d_NCHWc_global[((oc_block_c_init13 + 52))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init14 = 0; oc_block_c_init14 < 4; ++oc_block_c_init14) {
      conv2d_NCHWc_global[((oc_block_c_init14 + 56))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init15 = 0; oc_block_c_init15 < 4; ++oc_block_c_init15) {
      conv2d_NCHWc_global[((oc_block_c_init15 + 60))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init16 = 0; oc_block_c_init16 < 4; ++oc_block_c_init16) {
      conv2d_NCHWc_global[((oc_block_c_init16 + 64))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init17 = 0; oc_block_c_init17 < 4; ++oc_block_c_init17) {
      conv2d_NCHWc_global[((oc_block_c_init17 + 68))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init18 = 0; oc_block_c_init18 < 4; ++oc_block_c_init18) {
      conv2d_NCHWc_global[((oc_block_c_init18 + 72))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init19 = 0; oc_block_c_init19 < 4; ++oc_block_c_init19) {
      conv2d_NCHWc_global[((oc_block_c_init19 + 76))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init20 = 0; oc_block_c_init20 < 4; ++oc_block_c_init20) {
      conv2d_NCHWc_global[((oc_block_c_init20 + 80))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init21 = 0; oc_block_c_init21 < 4; ++oc_block_c_init21) {
      conv2d_NCHWc_global[((oc_block_c_init21 + 84))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init22 = 0; oc_block_c_init22 < 4; ++oc_block_c_init22) {
      conv2d_NCHWc_global[((oc_block_c_init22 + 88))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init23 = 0; oc_block_c_init23 < 4; ++oc_block_c_init23) {
      conv2d_NCHWc_global[((oc_block_c_init23 + 92))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init24 = 0; oc_block_c_init24 < 4; ++oc_block_c_init24) {
      conv2d_NCHWc_global[((oc_block_c_init24 + 96))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init25 = 0; oc_block_c_init25 < 4; ++oc_block_c_init25) {
      conv2d_NCHWc_global[((oc_block_c_init25 + 100))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init26 = 0; oc_block_c_init26 < 4; ++oc_block_c_init26) {
      conv2d_NCHWc_global[((oc_block_c_init26 + 104))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init27 = 0; oc_block_c_init27 < 4; ++oc_block_c_init27) {
      conv2d_NCHWc_global[((oc_block_c_init27 + 108))] = 0.000000e+00f;
    }
    for (int32_t ic_outer = 0; ic_outer < 8; ++ic_outer) {
      for (int32_t ic_inner = 0; ic_inner < 4; ++ic_inner) {
        for (int32_t oc_block_c = 0; oc_block_c < 4; ++oc_block_c) {
          conv2d_NCHWc_global[(oc_block_c)] = (conv2d_NCHWc_global[(oc_block_c)] + (((float*)placeholder)[((((ic_outer * 3136) + ((i0_i1_fused_i2_outer_fused % 28) * 112)) + ic_inner))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 28) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c))]));
        }
        for (int32_t oc_block_c1 = 0; oc_block_c1 < 4; ++oc_block_c1) {
          conv2d_NCHWc_global[((oc_block_c1 + 4))] = (conv2d_NCHWc_global[((oc_block_c1 + 4))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((i0_i1_fused_i2_outer_fused % 28) * 112)) + ic_inner) + 4))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 28) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c1))]));
        }
        for (int32_t oc_block_c2 = 0; oc_block_c2 < 4; ++oc_block_c2) {
          conv2d_NCHWc_global[((oc_block_c2 + 8))] = (conv2d_NCHWc_global[((oc_block_c2 + 8))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((i0_i1_fused_i2_outer_fused % 28) * 112)) + ic_inner) + 8))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 28) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c2))]));
        }
        for (int32_t oc_block_c3 = 0; oc_block_c3 < 4; ++oc_block_c3) {
          conv2d_NCHWc_global[((oc_block_c3 + 12))] = (conv2d_NCHWc_global[((oc_block_c3 + 12))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((i0_i1_fused_i2_outer_fused % 28) * 112)) + ic_inner) + 12))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 28) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c3))]));
        }
        for (int32_t oc_block_c4 = 0; oc_block_c4 < 4; ++oc_block_c4) {
          conv2d_NCHWc_global[((oc_block_c4 + 16))] = (conv2d_NCHWc_global[((oc_block_c4 + 16))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((i0_i1_fused_i2_outer_fused % 28) * 112)) + ic_inner) + 16))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 28) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c4))]));
        }
        for (int32_t oc_block_c5 = 0; oc_block_c5 < 4; ++oc_block_c5) {
          conv2d_NCHWc_global[((oc_block_c5 + 20))] = (conv2d_NCHWc_global[((oc_block_c5 + 20))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((i0_i1_fused_i2_outer_fused % 28) * 112)) + ic_inner) + 20))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 28) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c5))]));
        }
        for (int32_t oc_block_c6 = 0; oc_block_c6 < 4; ++oc_block_c6) {
          conv2d_NCHWc_global[((oc_block_c6 + 24))] = (conv2d_NCHWc_global[((oc_block_c6 + 24))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((i0_i1_fused_i2_outer_fused % 28) * 112)) + ic_inner) + 24))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 28) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c6))]));
        }
        for (int32_t oc_block_c7 = 0; oc_block_c7 < 4; ++oc_block_c7) {
          conv2d_NCHWc_global[((oc_block_c7 + 28))] = (conv2d_NCHWc_global[((oc_block_c7 + 28))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((i0_i1_fused_i2_outer_fused % 28) * 112)) + ic_inner) + 28))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 28) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c7))]));
        }
        for (int32_t oc_block_c8 = 0; oc_block_c8 < 4; ++oc_block_c8) {
          conv2d_NCHWc_global[((oc_block_c8 + 32))] = (conv2d_NCHWc_global[((oc_block_c8 + 32))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((i0_i1_fused_i2_outer_fused % 28) * 112)) + ic_inner) + 32))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 28) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c8))]));
        }
        for (int32_t oc_block_c9 = 0; oc_block_c9 < 4; ++oc_block_c9) {
          conv2d_NCHWc_global[((oc_block_c9 + 36))] = (conv2d_NCHWc_global[((oc_block_c9 + 36))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((i0_i1_fused_i2_outer_fused % 28) * 112)) + ic_inner) + 36))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 28) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c9))]));
        }
        for (int32_t oc_block_c10 = 0; oc_block_c10 < 4; ++oc_block_c10) {
          conv2d_NCHWc_global[((oc_block_c10 + 40))] = (conv2d_NCHWc_global[((oc_block_c10 + 40))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((i0_i1_fused_i2_outer_fused % 28) * 112)) + ic_inner) + 40))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 28) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c10))]));
        }
        for (int32_t oc_block_c11 = 0; oc_block_c11 < 4; ++oc_block_c11) {
          conv2d_NCHWc_global[((oc_block_c11 + 44))] = (conv2d_NCHWc_global[((oc_block_c11 + 44))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((i0_i1_fused_i2_outer_fused % 28) * 112)) + ic_inner) + 44))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 28) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c11))]));
        }
        for (int32_t oc_block_c12 = 0; oc_block_c12 < 4; ++oc_block_c12) {
          conv2d_NCHWc_global[((oc_block_c12 + 48))] = (conv2d_NCHWc_global[((oc_block_c12 + 48))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((i0_i1_fused_i2_outer_fused % 28) * 112)) + ic_inner) + 48))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 28) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c12))]));
        }
        for (int32_t oc_block_c13 = 0; oc_block_c13 < 4; ++oc_block_c13) {
          conv2d_NCHWc_global[((oc_block_c13 + 52))] = (conv2d_NCHWc_global[((oc_block_c13 + 52))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((i0_i1_fused_i2_outer_fused % 28) * 112)) + ic_inner) + 52))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 28) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c13))]));
        }
        for (int32_t oc_block_c14 = 0; oc_block_c14 < 4; ++oc_block_c14) {
          conv2d_NCHWc_global[((oc_block_c14 + 56))] = (conv2d_NCHWc_global[((oc_block_c14 + 56))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((i0_i1_fused_i2_outer_fused % 28) * 112)) + ic_inner) + 56))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 28) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c14))]));
        }
        for (int32_t oc_block_c15 = 0; oc_block_c15 < 4; ++oc_block_c15) {
          conv2d_NCHWc_global[((oc_block_c15 + 60))] = (conv2d_NCHWc_global[((oc_block_c15 + 60))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((i0_i1_fused_i2_outer_fused % 28) * 112)) + ic_inner) + 60))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 28) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c15))]));
        }
        for (int32_t oc_block_c16 = 0; oc_block_c16 < 4; ++oc_block_c16) {
          conv2d_NCHWc_global[((oc_block_c16 + 64))] = (conv2d_NCHWc_global[((oc_block_c16 + 64))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((i0_i1_fused_i2_outer_fused % 28) * 112)) + ic_inner) + 64))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 28) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c16))]));
        }
        for (int32_t oc_block_c17 = 0; oc_block_c17 < 4; ++oc_block_c17) {
          conv2d_NCHWc_global[((oc_block_c17 + 68))] = (conv2d_NCHWc_global[((oc_block_c17 + 68))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((i0_i1_fused_i2_outer_fused % 28) * 112)) + ic_inner) + 68))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 28) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c17))]));
        }
        for (int32_t oc_block_c18 = 0; oc_block_c18 < 4; ++oc_block_c18) {
          conv2d_NCHWc_global[((oc_block_c18 + 72))] = (conv2d_NCHWc_global[((oc_block_c18 + 72))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((i0_i1_fused_i2_outer_fused % 28) * 112)) + ic_inner) + 72))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 28) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c18))]));
        }
        for (int32_t oc_block_c19 = 0; oc_block_c19 < 4; ++oc_block_c19) {
          conv2d_NCHWc_global[((oc_block_c19 + 76))] = (conv2d_NCHWc_global[((oc_block_c19 + 76))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((i0_i1_fused_i2_outer_fused % 28) * 112)) + ic_inner) + 76))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 28) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c19))]));
        }
        for (int32_t oc_block_c20 = 0; oc_block_c20 < 4; ++oc_block_c20) {
          conv2d_NCHWc_global[((oc_block_c20 + 80))] = (conv2d_NCHWc_global[((oc_block_c20 + 80))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((i0_i1_fused_i2_outer_fused % 28) * 112)) + ic_inner) + 80))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 28) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c20))]));
        }
        for (int32_t oc_block_c21 = 0; oc_block_c21 < 4; ++oc_block_c21) {
          conv2d_NCHWc_global[((oc_block_c21 + 84))] = (conv2d_NCHWc_global[((oc_block_c21 + 84))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((i0_i1_fused_i2_outer_fused % 28) * 112)) + ic_inner) + 84))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 28) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c21))]));
        }
        for (int32_t oc_block_c22 = 0; oc_block_c22 < 4; ++oc_block_c22) {
          conv2d_NCHWc_global[((oc_block_c22 + 88))] = (conv2d_NCHWc_global[((oc_block_c22 + 88))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((i0_i1_fused_i2_outer_fused % 28) * 112)) + ic_inner) + 88))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 28) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c22))]));
        }
        for (int32_t oc_block_c23 = 0; oc_block_c23 < 4; ++oc_block_c23) {
          conv2d_NCHWc_global[((oc_block_c23 + 92))] = (conv2d_NCHWc_global[((oc_block_c23 + 92))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((i0_i1_fused_i2_outer_fused % 28) * 112)) + ic_inner) + 92))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 28) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c23))]));
        }
        for (int32_t oc_block_c24 = 0; oc_block_c24 < 4; ++oc_block_c24) {
          conv2d_NCHWc_global[((oc_block_c24 + 96))] = (conv2d_NCHWc_global[((oc_block_c24 + 96))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((i0_i1_fused_i2_outer_fused % 28) * 112)) + ic_inner) + 96))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 28) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c24))]));
        }
        for (int32_t oc_block_c25 = 0; oc_block_c25 < 4; ++oc_block_c25) {
          conv2d_NCHWc_global[((oc_block_c25 + 100))] = (conv2d_NCHWc_global[((oc_block_c25 + 100))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((i0_i1_fused_i2_outer_fused % 28) * 112)) + ic_inner) + 100))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 28) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c25))]));
        }
        for (int32_t oc_block_c26 = 0; oc_block_c26 < 4; ++oc_block_c26) {
          conv2d_NCHWc_global[((oc_block_c26 + 104))] = (conv2d_NCHWc_global[((oc_block_c26 + 104))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((i0_i1_fused_i2_outer_fused % 28) * 112)) + ic_inner) + 104))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 28) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c26))]));
        }
        for (int32_t oc_block_c27 = 0; oc_block_c27 < 4; ++oc_block_c27) {
          conv2d_NCHWc_global[((oc_block_c27 + 108))] = (conv2d_NCHWc_global[((oc_block_c27 + 108))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((i0_i1_fused_i2_outer_fused % 28) * 112)) + ic_inner) + 108))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 28) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c27))]));
        }
      }
    }
    for (int32_t i3_inner = 0; i3_inner < 28; ++i3_inner) {
      for (int32_t i4 = 0; i4 < 4; ++i4) {
        float _1 = conv2d_NCHWc_global[(((i3_inner * 4) + i4))] + ((float*)placeholder2)[((((i0_i1_fused_i2_outer_fused / 28) * 4) + i4))];
        float _2 = (_1) < (6.000000e+00f) ? (_1) : (6.000000e+00f);
        ((float*)compute)[((((i0_i1_fused_i2_outer_fused * 112) + (i3_inner * 4)) + i4))] = ((_2) > (0.000000e+00f) ? (_2) : (0.000000e+00f));
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_contrib_conv2d_NCHWc_add_1(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int32_t arg2_code = ((int32_t*)arg_type_ids)[(2)];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int32_t arg3_code = ((int32_t*)arg_type_ids)[(3)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* placeholder1 = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  void* placeholder2 = (((DLTensor*)arg2)[0].data);
  void* arg2_shape = (((DLTensor*)arg2)[0].shape);
  void* arg2_strides = (((DLTensor*)arg2)[0].strides);
  void* T_add = (((DLTensor*)arg3)[0].data);
  void* arg3_shape = (((DLTensor*)arg3)[0].shape);
  void* arg3_strides = (((DLTensor*)arg3)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  if (!(arg2_strides == NULL)) {
  }
  if (!(arg3_strides == NULL)) {
  }
  for (int32_t ax0_ax1_fused_ax2_outer_fused = 0; ax0_ax1_fused_ax2_outer_fused < 560; ++ax0_ax1_fused_ax2_outer_fused) {
    float conv2d_NCHWc_global[28];
    for (int32_t oc_block_c_init = 0; oc_block_c_init < 4; ++oc_block_c_init) {
      conv2d_NCHWc_global[(oc_block_c_init)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init1 = 0; oc_block_c_init1 < 4; ++oc_block_c_init1) {
      conv2d_NCHWc_global[((oc_block_c_init1 + 4))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init2 = 0; oc_block_c_init2 < 4; ++oc_block_c_init2) {
      conv2d_NCHWc_global[((oc_block_c_init2 + 8))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init3 = 0; oc_block_c_init3 < 4; ++oc_block_c_init3) {
      conv2d_NCHWc_global[((oc_block_c_init3 + 12))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init4 = 0; oc_block_c_init4 < 4; ++oc_block_c_init4) {
      conv2d_NCHWc_global[((oc_block_c_init4 + 16))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init5 = 0; oc_block_c_init5 < 4; ++oc_block_c_init5) {
      conv2d_NCHWc_global[((oc_block_c_init5 + 20))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init6 = 0; oc_block_c_init6 < 4; ++oc_block_c_init6) {
      conv2d_NCHWc_global[((oc_block_c_init6 + 24))] = 0.000000e+00f;
    }
    for (int32_t ic_outer = 0; ic_outer < 240; ++ic_outer) {
      for (int32_t ic_inner = 0; ic_inner < 4; ++ic_inner) {
        for (int32_t oc_block_c = 0; oc_block_c < 4; ++oc_block_c) {
          conv2d_NCHWc_global[(oc_block_c)] = (conv2d_NCHWc_global[(oc_block_c)] + (((float*)placeholder)[((((ic_outer * 196) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 28)) + ic_inner))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 3840) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c))]));
        }
        for (int32_t oc_block_c1 = 0; oc_block_c1 < 4; ++oc_block_c1) {
          conv2d_NCHWc_global[((oc_block_c1 + 4))] = (conv2d_NCHWc_global[((oc_block_c1 + 4))] + (((float*)placeholder)[(((((ic_outer * 196) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 28)) + ic_inner) + 4))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 3840) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c1))]));
        }
        for (int32_t oc_block_c2 = 0; oc_block_c2 < 4; ++oc_block_c2) {
          conv2d_NCHWc_global[((oc_block_c2 + 8))] = (conv2d_NCHWc_global[((oc_block_c2 + 8))] + (((float*)placeholder)[(((((ic_outer * 196) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 28)) + ic_inner) + 8))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 3840) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c2))]));
        }
        for (int32_t oc_block_c3 = 0; oc_block_c3 < 4; ++oc_block_c3) {
          conv2d_NCHWc_global[((oc_block_c3 + 12))] = (conv2d_NCHWc_global[((oc_block_c3 + 12))] + (((float*)placeholder)[(((((ic_outer * 196) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 28)) + ic_inner) + 12))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 3840) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c3))]));
        }
        for (int32_t oc_block_c4 = 0; oc_block_c4 < 4; ++oc_block_c4) {
          conv2d_NCHWc_global[((oc_block_c4 + 16))] = (conv2d_NCHWc_global[((oc_block_c4 + 16))] + (((float*)placeholder)[(((((ic_outer * 196) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 28)) + ic_inner) + 16))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 3840) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c4))]));
        }
        for (int32_t oc_block_c5 = 0; oc_block_c5 < 4; ++oc_block_c5) {
          conv2d_NCHWc_global[((oc_block_c5 + 20))] = (conv2d_NCHWc_global[((oc_block_c5 + 20))] + (((float*)placeholder)[(((((ic_outer * 196) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 28)) + ic_inner) + 20))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 3840) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c5))]));
        }
        for (int32_t oc_block_c6 = 0; oc_block_c6 < 4; ++oc_block_c6) {
          conv2d_NCHWc_global[((oc_block_c6 + 24))] = (conv2d_NCHWc_global[((oc_block_c6 + 24))] + (((float*)placeholder)[(((((ic_outer * 196) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 28)) + ic_inner) + 24))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 3840) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c6))]));
        }
      }
    }
    for (int32_t ax3_inner = 0; ax3_inner < 7; ++ax3_inner) {
      for (int32_t ax4 = 0; ax4 < 4; ++ax4) {
        ((float*)T_add)[((((ax0_ax1_fused_ax2_outer_fused * 28) + (ax3_inner * 4)) + ax4))] = (conv2d_NCHWc_global[(((ax3_inner * 4) + ax4))] + ((float*)placeholder2)[((((ax0_ax1_fused_ax2_outer_fused / 7) * 4) + ax4))]);
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_contrib_conv2d_NCHWc_add_add_4(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int32_t arg2_code = ((int32_t*)arg_type_ids)[(2)];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int32_t arg3_code = ((int32_t*)arg_type_ids)[(3)];
  void* arg4 = (((TVMValue*)args)[4].v_handle);
  int32_t arg4_code = ((int32_t*)arg_type_ids)[(4)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* placeholder1 = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  void* placeholder2 = (((DLTensor*)arg2)[0].data);
  void* arg2_shape = (((DLTensor*)arg2)[0].shape);
  void* arg2_strides = (((DLTensor*)arg2)[0].strides);
  void* placeholder3 = (((DLTensor*)arg3)[0].data);
  void* arg3_shape = (((DLTensor*)arg3)[0].shape);
  void* arg3_strides = (((DLTensor*)arg3)[0].strides);
  void* T_add = (((DLTensor*)arg4)[0].data);
  void* arg4_shape = (((DLTensor*)arg4)[0].shape);
  void* arg4_strides = (((DLTensor*)arg4)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  if (!(arg2_strides == NULL)) {
  }
  if (!(arg3_strides == NULL)) {
  }
  if (!(arg4_strides == NULL)) {
  }
  for (int32_t ax0_ax1_fused_ax2_outer_fused = 0; ax0_ax1_fused_ax2_outer_fused < 336; ++ax0_ax1_fused_ax2_outer_fused) {
    float conv2d_NCHWc_global[224];
    for (int32_t ow_c_outer = 0; ow_c_outer < 2; ++ow_c_outer) {
      for (int32_t oc_block_c_init = 0; oc_block_c_init < 4; ++oc_block_c_init) {
        conv2d_NCHWc_global[(((ow_c_outer * 112) + oc_block_c_init))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init1 = 0; oc_block_c_init1 < 4; ++oc_block_c_init1) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init1) + 4))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init2 = 0; oc_block_c_init2 < 4; ++oc_block_c_init2) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init2) + 8))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init3 = 0; oc_block_c_init3 < 4; ++oc_block_c_init3) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init3) + 12))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init4 = 0; oc_block_c_init4 < 4; ++oc_block_c_init4) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init4) + 16))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init5 = 0; oc_block_c_init5 < 4; ++oc_block_c_init5) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init5) + 20))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init6 = 0; oc_block_c_init6 < 4; ++oc_block_c_init6) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init6) + 24))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init7 = 0; oc_block_c_init7 < 4; ++oc_block_c_init7) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init7) + 28))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init8 = 0; oc_block_c_init8 < 4; ++oc_block_c_init8) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init8) + 32))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init9 = 0; oc_block_c_init9 < 4; ++oc_block_c_init9) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init9) + 36))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init10 = 0; oc_block_c_init10 < 4; ++oc_block_c_init10) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init10) + 40))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init11 = 0; oc_block_c_init11 < 4; ++oc_block_c_init11) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init11) + 44))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init12 = 0; oc_block_c_init12 < 4; ++oc_block_c_init12) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init12) + 48))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init13 = 0; oc_block_c_init13 < 4; ++oc_block_c_init13) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init13) + 52))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init14 = 0; oc_block_c_init14 < 4; ++oc_block_c_init14) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init14) + 56))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init15 = 0; oc_block_c_init15 < 4; ++oc_block_c_init15) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init15) + 60))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init16 = 0; oc_block_c_init16 < 4; ++oc_block_c_init16) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init16) + 64))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init17 = 0; oc_block_c_init17 < 4; ++oc_block_c_init17) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init17) + 68))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init18 = 0; oc_block_c_init18 < 4; ++oc_block_c_init18) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init18) + 72))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init19 = 0; oc_block_c_init19 < 4; ++oc_block_c_init19) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init19) + 76))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init20 = 0; oc_block_c_init20 < 4; ++oc_block_c_init20) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init20) + 80))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init21 = 0; oc_block_c_init21 < 4; ++oc_block_c_init21) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init21) + 84))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init22 = 0; oc_block_c_init22 < 4; ++oc_block_c_init22) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init22) + 88))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init23 = 0; oc_block_c_init23 < 4; ++oc_block_c_init23) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init23) + 92))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init24 = 0; oc_block_c_init24 < 4; ++oc_block_c_init24) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init24) + 96))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init25 = 0; oc_block_c_init25 < 4; ++oc_block_c_init25) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init25) + 100))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init26 = 0; oc_block_c_init26 < 4; ++oc_block_c_init26) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init26) + 104))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init27 = 0; oc_block_c_init27 < 4; ++oc_block_c_init27) {
        conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c_init27) + 108))] = 0.000000e+00f;
      }
      for (int32_t ic_outer = 0; ic_outer < 36; ++ic_outer) {
        for (int32_t ic_inner = 0; ic_inner < 4; ++ic_inner) {
          for (int32_t oc_block_c = 0; oc_block_c < 4; ++oc_block_c) {
            conv2d_NCHWc_global[(((ow_c_outer * 112) + oc_block_c))] = (conv2d_NCHWc_global[(((ow_c_outer * 112) + oc_block_c))] + (((float*)placeholder)[(((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c))]));
          }
          for (int32_t oc_block_c1 = 0; oc_block_c1 < 4; ++oc_block_c1) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c1) + 4))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c1) + 4))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 4))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c1))]));
          }
          for (int32_t oc_block_c2 = 0; oc_block_c2 < 4; ++oc_block_c2) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c2) + 8))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c2) + 8))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 8))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c2))]));
          }
          for (int32_t oc_block_c3 = 0; oc_block_c3 < 4; ++oc_block_c3) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c3) + 12))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c3) + 12))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 12))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c3))]));
          }
          for (int32_t oc_block_c4 = 0; oc_block_c4 < 4; ++oc_block_c4) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c4) + 16))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c4) + 16))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 16))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c4))]));
          }
          for (int32_t oc_block_c5 = 0; oc_block_c5 < 4; ++oc_block_c5) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c5) + 20))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c5) + 20))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 20))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c5))]));
          }
          for (int32_t oc_block_c6 = 0; oc_block_c6 < 4; ++oc_block_c6) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c6) + 24))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c6) + 24))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 24))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c6))]));
          }
          for (int32_t oc_block_c7 = 0; oc_block_c7 < 4; ++oc_block_c7) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c7) + 28))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c7) + 28))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 28))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c7))]));
          }
          for (int32_t oc_block_c8 = 0; oc_block_c8 < 4; ++oc_block_c8) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c8) + 32))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c8) + 32))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 32))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c8))]));
          }
          for (int32_t oc_block_c9 = 0; oc_block_c9 < 4; ++oc_block_c9) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c9) + 36))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c9) + 36))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 36))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c9))]));
          }
          for (int32_t oc_block_c10 = 0; oc_block_c10 < 4; ++oc_block_c10) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c10) + 40))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c10) + 40))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 40))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c10))]));
          }
          for (int32_t oc_block_c11 = 0; oc_block_c11 < 4; ++oc_block_c11) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c11) + 44))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c11) + 44))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 44))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c11))]));
          }
          for (int32_t oc_block_c12 = 0; oc_block_c12 < 4; ++oc_block_c12) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c12) + 48))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c12) + 48))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 48))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c12))]));
          }
          for (int32_t oc_block_c13 = 0; oc_block_c13 < 4; ++oc_block_c13) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c13) + 52))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c13) + 52))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 52))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c13))]));
          }
          for (int32_t oc_block_c14 = 0; oc_block_c14 < 4; ++oc_block_c14) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c14) + 56))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c14) + 56))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 56))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c14))]));
          }
          for (int32_t oc_block_c15 = 0; oc_block_c15 < 4; ++oc_block_c15) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c15) + 60))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c15) + 60))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 60))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c15))]));
          }
          for (int32_t oc_block_c16 = 0; oc_block_c16 < 4; ++oc_block_c16) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c16) + 64))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c16) + 64))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 64))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c16))]));
          }
          for (int32_t oc_block_c17 = 0; oc_block_c17 < 4; ++oc_block_c17) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c17) + 68))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c17) + 68))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 68))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c17))]));
          }
          for (int32_t oc_block_c18 = 0; oc_block_c18 < 4; ++oc_block_c18) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c18) + 72))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c18) + 72))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 72))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c18))]));
          }
          for (int32_t oc_block_c19 = 0; oc_block_c19 < 4; ++oc_block_c19) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c19) + 76))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c19) + 76))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 76))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c19))]));
          }
          for (int32_t oc_block_c20 = 0; oc_block_c20 < 4; ++oc_block_c20) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c20) + 80))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c20) + 80))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 80))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c20))]));
          }
          for (int32_t oc_block_c21 = 0; oc_block_c21 < 4; ++oc_block_c21) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c21) + 84))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c21) + 84))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 84))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c21))]));
          }
          for (int32_t oc_block_c22 = 0; oc_block_c22 < 4; ++oc_block_c22) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c22) + 88))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c22) + 88))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 88))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c22))]));
          }
          for (int32_t oc_block_c23 = 0; oc_block_c23 < 4; ++oc_block_c23) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c23) + 92))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c23) + 92))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 92))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c23))]));
          }
          for (int32_t oc_block_c24 = 0; oc_block_c24 < 4; ++oc_block_c24) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c24) + 96))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c24) + 96))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 96))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c24))]));
          }
          for (int32_t oc_block_c25 = 0; oc_block_c25 < 4; ++oc_block_c25) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c25) + 100))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c25) + 100))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 100))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c25))]));
          }
          for (int32_t oc_block_c26 = 0; oc_block_c26 < 4; ++oc_block_c26) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c26) + 104))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c26) + 104))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 104))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c26))]));
          }
          for (int32_t oc_block_c27 = 0; oc_block_c27 < 4; ++oc_block_c27) {
            conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c27) + 108))] = (conv2d_NCHWc_global[((((ow_c_outer * 112) + oc_block_c27) + 108))] + (((float*)placeholder)[((((((ic_outer * 12544) + ((ax0_ax1_fused_ax2_outer_fused % 56) * 224)) + (ow_c_outer * 112)) + ic_inner) + 108))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 56) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c27))]));
          }
        }
      }
    }
    for (int32_t ax3_outer = 0; ax3_outer < 2; ++ax3_outer) {
      for (int32_t ax3_inner = 0; ax3_inner < 28; ++ax3_inner) {
        for (int32_t ax4 = 0; ax4 < 4; ++ax4) {
          ((float*)T_add)[(((((ax0_ax1_fused_ax2_outer_fused * 224) + (ax3_outer * 112)) + (ax3_inner * 4)) + ax4))] = ((conv2d_NCHWc_global[((((ax3_outer * 112) + (ax3_inner * 4)) + ax4))] + ((float*)placeholder2)[((((ax0_ax1_fused_ax2_outer_fused / 56) * 4) + ax4))]) + ((float*)placeholder3)[(((((ax0_ax1_fused_ax2_outer_fused * 224) + (ax3_outer * 112)) + (ax3_inner * 4)) + ax4))]);
        }
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_contrib_depthwise_conv2d_NCHWc_add_clip_6(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int32_t arg2_code = ((int32_t*)arg_type_ids)[(2)];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int32_t arg3_code = ((int32_t*)arg_type_ids)[(3)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* placeholder1 = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  void* placeholder2 = (((DLTensor*)arg2)[0].data);
  void* arg2_shape = (((DLTensor*)arg2)[0].shape);
  void* arg2_strides = (((DLTensor*)arg2)[0].strides);
  void* compute = (((DLTensor*)arg3)[0].data);
  void* arg3_shape = (((DLTensor*)arg3)[0].shape);
  void* arg3_strides = (((DLTensor*)arg3)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  if (!(arg2_strides == NULL)) {
  }
  if (!(arg3_strides == NULL)) {
  }
  void* PaddedInput = TVMBackendAllocWorkspace(1, dev_id, (uint64_t)1871424, 2, 32);
  if (PaddedInput == NULL) {
    return -1;
  }
  for (int32_t i0_i1_fused_i2_fused = 0; i0_i1_fused_i2_fused < 2052; ++i0_i1_fused_i2_fused) {
    for (int32_t i3 = 0; i3 < 57; ++i3) {
      for (int32_t i4 = 0; i4 < 4; ++i4) {
        ((float*)PaddedInput)[((((i0_i1_fused_i2_fused * 228) + (i3 * 4)) + i4))] = ((((i0_i1_fused_i2_fused % 57) < 56) && (i3 < 56)) ? ((float*)placeholder)[((((((i0_i1_fused_i2_fused / 57) * 12544) + ((i0_i1_fused_i2_fused % 57) * 224)) + (i3 * 4)) + i4))] : 0.000000e+00f);
      }
    }
  }
  for (int32_t i1_i2_fused = 0; i1_i2_fused < 1008; ++i1_i2_fused) {
    float DepthwiseConv2d_global[112];
    for (int32_t oci_c_init = 0; oci_c_init < 4; ++oci_c_init) {
      DepthwiseConv2d_global[(oci_c_init)] = 0.000000e+00f;
    }
    for (int32_t oci_c_init1 = 0; oci_c_init1 < 4; ++oci_c_init1) {
      DepthwiseConv2d_global[((oci_c_init1 + 4))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init2 = 0; oci_c_init2 < 4; ++oci_c_init2) {
      DepthwiseConv2d_global[((oci_c_init2 + 8))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init3 = 0; oci_c_init3 < 4; ++oci_c_init3) {
      DepthwiseConv2d_global[((oci_c_init3 + 12))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init4 = 0; oci_c_init4 < 4; ++oci_c_init4) {
      DepthwiseConv2d_global[((oci_c_init4 + 16))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init5 = 0; oci_c_init5 < 4; ++oci_c_init5) {
      DepthwiseConv2d_global[((oci_c_init5 + 20))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init6 = 0; oci_c_init6 < 4; ++oci_c_init6) {
      DepthwiseConv2d_global[((oci_c_init6 + 24))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init7 = 0; oci_c_init7 < 4; ++oci_c_init7) {
      DepthwiseConv2d_global[((oci_c_init7 + 28))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init8 = 0; oci_c_init8 < 4; ++oci_c_init8) {
      DepthwiseConv2d_global[((oci_c_init8 + 32))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init9 = 0; oci_c_init9 < 4; ++oci_c_init9) {
      DepthwiseConv2d_global[((oci_c_init9 + 36))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init10 = 0; oci_c_init10 < 4; ++oci_c_init10) {
      DepthwiseConv2d_global[((oci_c_init10 + 40))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init11 = 0; oci_c_init11 < 4; ++oci_c_init11) {
      DepthwiseConv2d_global[((oci_c_init11 + 44))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init12 = 0; oci_c_init12 < 4; ++oci_c_init12) {
      DepthwiseConv2d_global[((oci_c_init12 + 48))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init13 = 0; oci_c_init13 < 4; ++oci_c_init13) {
      DepthwiseConv2d_global[((oci_c_init13 + 52))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init14 = 0; oci_c_init14 < 4; ++oci_c_init14) {
      DepthwiseConv2d_global[((oci_c_init14 + 56))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init15 = 0; oci_c_init15 < 4; ++oci_c_init15) {
      DepthwiseConv2d_global[((oci_c_init15 + 60))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init16 = 0; oci_c_init16 < 4; ++oci_c_init16) {
      DepthwiseConv2d_global[((oci_c_init16 + 64))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init17 = 0; oci_c_init17 < 4; ++oci_c_init17) {
      DepthwiseConv2d_global[((oci_c_init17 + 68))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init18 = 0; oci_c_init18 < 4; ++oci_c_init18) {
      DepthwiseConv2d_global[((oci_c_init18 + 72))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init19 = 0; oci_c_init19 < 4; ++oci_c_init19) {
      DepthwiseConv2d_global[((oci_c_init19 + 76))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init20 = 0; oci_c_init20 < 4; ++oci_c_init20) {
      DepthwiseConv2d_global[((oci_c_init20 + 80))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init21 = 0; oci_c_init21 < 4; ++oci_c_init21) {
      DepthwiseConv2d_global[((oci_c_init21 + 84))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init22 = 0; oci_c_init22 < 4; ++oci_c_init22) {
      DepthwiseConv2d_global[((oci_c_init22 + 88))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init23 = 0; oci_c_init23 < 4; ++oci_c_init23) {
      DepthwiseConv2d_global[((oci_c_init23 + 92))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init24 = 0; oci_c_init24 < 4; ++oci_c_init24) {
      DepthwiseConv2d_global[((oci_c_init24 + 96))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init25 = 0; oci_c_init25 < 4; ++oci_c_init25) {
      DepthwiseConv2d_global[((oci_c_init25 + 100))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init26 = 0; oci_c_init26 < 4; ++oci_c_init26) {
      DepthwiseConv2d_global[((oci_c_init26 + 104))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init27 = 0; oci_c_init27 < 4; ++oci_c_init27) {
      DepthwiseConv2d_global[((oci_c_init27 + 108))] = 0.000000e+00f;
    }
    for (int32_t kh = 0; kh < 3; ++kh) {
      for (int32_t kw = 0; kw < 3; ++kw) {
        for (int32_t oci_c = 0; oci_c < 4; ++oci_c) {
          DepthwiseConv2d_global[(oci_c)] = (DepthwiseConv2d_global[(oci_c)] + (((float*)PaddedInput)[(((((((i1_i2_fused / 28) * 12996) + ((i1_i2_fused % 28) * 456)) + (kh * 228)) + (kw * 4)) + oci_c))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c))]));
        }
        for (int32_t oci_c1 = 0; oci_c1 < 4; ++oci_c1) {
          DepthwiseConv2d_global[((oci_c1 + 4))] = (DepthwiseConv2d_global[((oci_c1 + 4))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 12996) + ((i1_i2_fused % 28) * 456)) + (kh * 228)) + (kw * 4)) + oci_c1) + 8))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c1))]));
        }
        for (int32_t oci_c2 = 0; oci_c2 < 4; ++oci_c2) {
          DepthwiseConv2d_global[((oci_c2 + 8))] = (DepthwiseConv2d_global[((oci_c2 + 8))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 12996) + ((i1_i2_fused % 28) * 456)) + (kh * 228)) + (kw * 4)) + oci_c2) + 16))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c2))]));
        }
        for (int32_t oci_c3 = 0; oci_c3 < 4; ++oci_c3) {
          DepthwiseConv2d_global[((oci_c3 + 12))] = (DepthwiseConv2d_global[((oci_c3 + 12))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 12996) + ((i1_i2_fused % 28) * 456)) + (kh * 228)) + (kw * 4)) + oci_c3) + 24))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c3))]));
        }
        for (int32_t oci_c4 = 0; oci_c4 < 4; ++oci_c4) {
          DepthwiseConv2d_global[((oci_c4 + 16))] = (DepthwiseConv2d_global[((oci_c4 + 16))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 12996) + ((i1_i2_fused % 28) * 456)) + (kh * 228)) + (kw * 4)) + oci_c4) + 32))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c4))]));
        }
        for (int32_t oci_c5 = 0; oci_c5 < 4; ++oci_c5) {
          DepthwiseConv2d_global[((oci_c5 + 20))] = (DepthwiseConv2d_global[((oci_c5 + 20))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 12996) + ((i1_i2_fused % 28) * 456)) + (kh * 228)) + (kw * 4)) + oci_c5) + 40))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c5))]));
        }
        for (int32_t oci_c6 = 0; oci_c6 < 4; ++oci_c6) {
          DepthwiseConv2d_global[((oci_c6 + 24))] = (DepthwiseConv2d_global[((oci_c6 + 24))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 12996) + ((i1_i2_fused % 28) * 456)) + (kh * 228)) + (kw * 4)) + oci_c6) + 48))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c6))]));
        }
        for (int32_t oci_c7 = 0; oci_c7 < 4; ++oci_c7) {
          DepthwiseConv2d_global[((oci_c7 + 28))] = (DepthwiseConv2d_global[((oci_c7 + 28))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 12996) + ((i1_i2_fused % 28) * 456)) + (kh * 228)) + (kw * 4)) + oci_c7) + 56))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c7))]));
        }
        for (int32_t oci_c8 = 0; oci_c8 < 4; ++oci_c8) {
          DepthwiseConv2d_global[((oci_c8 + 32))] = (DepthwiseConv2d_global[((oci_c8 + 32))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 12996) + ((i1_i2_fused % 28) * 456)) + (kh * 228)) + (kw * 4)) + oci_c8) + 64))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c8))]));
        }
        for (int32_t oci_c9 = 0; oci_c9 < 4; ++oci_c9) {
          DepthwiseConv2d_global[((oci_c9 + 36))] = (DepthwiseConv2d_global[((oci_c9 + 36))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 12996) + ((i1_i2_fused % 28) * 456)) + (kh * 228)) + (kw * 4)) + oci_c9) + 72))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c9))]));
        }
        for (int32_t oci_c10 = 0; oci_c10 < 4; ++oci_c10) {
          DepthwiseConv2d_global[((oci_c10 + 40))] = (DepthwiseConv2d_global[((oci_c10 + 40))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 12996) + ((i1_i2_fused % 28) * 456)) + (kh * 228)) + (kw * 4)) + oci_c10) + 80))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c10))]));
        }
        for (int32_t oci_c11 = 0; oci_c11 < 4; ++oci_c11) {
          DepthwiseConv2d_global[((oci_c11 + 44))] = (DepthwiseConv2d_global[((oci_c11 + 44))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 12996) + ((i1_i2_fused % 28) * 456)) + (kh * 228)) + (kw * 4)) + oci_c11) + 88))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c11))]));
        }
        for (int32_t oci_c12 = 0; oci_c12 < 4; ++oci_c12) {
          DepthwiseConv2d_global[((oci_c12 + 48))] = (DepthwiseConv2d_global[((oci_c12 + 48))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 12996) + ((i1_i2_fused % 28) * 456)) + (kh * 228)) + (kw * 4)) + oci_c12) + 96))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c12))]));
        }
        for (int32_t oci_c13 = 0; oci_c13 < 4; ++oci_c13) {
          DepthwiseConv2d_global[((oci_c13 + 52))] = (DepthwiseConv2d_global[((oci_c13 + 52))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 12996) + ((i1_i2_fused % 28) * 456)) + (kh * 228)) + (kw * 4)) + oci_c13) + 104))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c13))]));
        }
        for (int32_t oci_c14 = 0; oci_c14 < 4; ++oci_c14) {
          DepthwiseConv2d_global[((oci_c14 + 56))] = (DepthwiseConv2d_global[((oci_c14 + 56))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 12996) + ((i1_i2_fused % 28) * 456)) + (kh * 228)) + (kw * 4)) + oci_c14) + 112))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c14))]));
        }
        for (int32_t oci_c15 = 0; oci_c15 < 4; ++oci_c15) {
          DepthwiseConv2d_global[((oci_c15 + 60))] = (DepthwiseConv2d_global[((oci_c15 + 60))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 12996) + ((i1_i2_fused % 28) * 456)) + (kh * 228)) + (kw * 4)) + oci_c15) + 120))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c15))]));
        }
        for (int32_t oci_c16 = 0; oci_c16 < 4; ++oci_c16) {
          DepthwiseConv2d_global[((oci_c16 + 64))] = (DepthwiseConv2d_global[((oci_c16 + 64))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 12996) + ((i1_i2_fused % 28) * 456)) + (kh * 228)) + (kw * 4)) + oci_c16) + 128))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c16))]));
        }
        for (int32_t oci_c17 = 0; oci_c17 < 4; ++oci_c17) {
          DepthwiseConv2d_global[((oci_c17 + 68))] = (DepthwiseConv2d_global[((oci_c17 + 68))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 12996) + ((i1_i2_fused % 28) * 456)) + (kh * 228)) + (kw * 4)) + oci_c17) + 136))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c17))]));
        }
        for (int32_t oci_c18 = 0; oci_c18 < 4; ++oci_c18) {
          DepthwiseConv2d_global[((oci_c18 + 72))] = (DepthwiseConv2d_global[((oci_c18 + 72))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 12996) + ((i1_i2_fused % 28) * 456)) + (kh * 228)) + (kw * 4)) + oci_c18) + 144))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c18))]));
        }
        for (int32_t oci_c19 = 0; oci_c19 < 4; ++oci_c19) {
          DepthwiseConv2d_global[((oci_c19 + 76))] = (DepthwiseConv2d_global[((oci_c19 + 76))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 12996) + ((i1_i2_fused % 28) * 456)) + (kh * 228)) + (kw * 4)) + oci_c19) + 152))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c19))]));
        }
        for (int32_t oci_c20 = 0; oci_c20 < 4; ++oci_c20) {
          DepthwiseConv2d_global[((oci_c20 + 80))] = (DepthwiseConv2d_global[((oci_c20 + 80))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 12996) + ((i1_i2_fused % 28) * 456)) + (kh * 228)) + (kw * 4)) + oci_c20) + 160))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c20))]));
        }
        for (int32_t oci_c21 = 0; oci_c21 < 4; ++oci_c21) {
          DepthwiseConv2d_global[((oci_c21 + 84))] = (DepthwiseConv2d_global[((oci_c21 + 84))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 12996) + ((i1_i2_fused % 28) * 456)) + (kh * 228)) + (kw * 4)) + oci_c21) + 168))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c21))]));
        }
        for (int32_t oci_c22 = 0; oci_c22 < 4; ++oci_c22) {
          DepthwiseConv2d_global[((oci_c22 + 88))] = (DepthwiseConv2d_global[((oci_c22 + 88))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 12996) + ((i1_i2_fused % 28) * 456)) + (kh * 228)) + (kw * 4)) + oci_c22) + 176))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c22))]));
        }
        for (int32_t oci_c23 = 0; oci_c23 < 4; ++oci_c23) {
          DepthwiseConv2d_global[((oci_c23 + 92))] = (DepthwiseConv2d_global[((oci_c23 + 92))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 12996) + ((i1_i2_fused % 28) * 456)) + (kh * 228)) + (kw * 4)) + oci_c23) + 184))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c23))]));
        }
        for (int32_t oci_c24 = 0; oci_c24 < 4; ++oci_c24) {
          DepthwiseConv2d_global[((oci_c24 + 96))] = (DepthwiseConv2d_global[((oci_c24 + 96))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 12996) + ((i1_i2_fused % 28) * 456)) + (kh * 228)) + (kw * 4)) + oci_c24) + 192))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c24))]));
        }
        for (int32_t oci_c25 = 0; oci_c25 < 4; ++oci_c25) {
          DepthwiseConv2d_global[((oci_c25 + 100))] = (DepthwiseConv2d_global[((oci_c25 + 100))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 12996) + ((i1_i2_fused % 28) * 456)) + (kh * 228)) + (kw * 4)) + oci_c25) + 200))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c25))]));
        }
        for (int32_t oci_c26 = 0; oci_c26 < 4; ++oci_c26) {
          DepthwiseConv2d_global[((oci_c26 + 104))] = (DepthwiseConv2d_global[((oci_c26 + 104))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 12996) + ((i1_i2_fused % 28) * 456)) + (kh * 228)) + (kw * 4)) + oci_c26) + 208))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c26))]));
        }
        for (int32_t oci_c27 = 0; oci_c27 < 4; ++oci_c27) {
          DepthwiseConv2d_global[((oci_c27 + 108))] = (DepthwiseConv2d_global[((oci_c27 + 108))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 12996) + ((i1_i2_fused % 28) * 456)) + (kh * 228)) + (kw * 4)) + oci_c27) + 216))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c27))]));
        }
      }
    }
    for (int32_t i3_inner = 0; i3_inner < 28; ++i3_inner) {
      for (int32_t i41 = 0; i41 < 4; ++i41) {
        float _1 = DepthwiseConv2d_global[(((i3_inner * 4) + i41))] + ((float*)placeholder2)[((((i1_i2_fused / 28) * 4) + i41))];
        float _2 = (_1) < (6.000000e+00f) ? (_1) : (6.000000e+00f);
        ((float*)compute)[((((i1_i2_fused * 112) + (i3_inner * 4)) + i41))] = ((_2) > (0.000000e+00f) ? (_2) : (0.000000e+00f));
      }
    }
  }
  if (TVMBackendFreeWorkspace(1, dev_id, PaddedInput) != 0) {
    return -1;
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_layout_transform(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* T_layout_trans = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  for (int32_t ax0_ax1_fused_ax2_fused = 0; ax0_ax1_fused_ax2_fused < 1280; ++ax0_ax1_fused_ax2_fused) {
    ((float*)T_layout_trans)[(ax0_ax1_fused_ax2_fused)] = ((float*)placeholder)[(ax0_ax1_fused_ax2_fused)];
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_contrib_depthwise_conv2d_NCHWc_add_clip_7(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int32_t arg2_code = ((int32_t*)arg_type_ids)[(2)];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int32_t arg3_code = ((int32_t*)arg_type_ids)[(3)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* placeholder1 = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  void* placeholder2 = (((DLTensor*)arg2)[0].data);
  void* arg2_shape = (((DLTensor*)arg2)[0].shape);
  void* arg2_strides = (((DLTensor*)arg2)[0].strides);
  void* compute = (((DLTensor*)arg3)[0].data);
  void* arg3_shape = (((DLTensor*)arg3)[0].shape);
  void* arg3_strides = (((DLTensor*)arg3)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  if (!(arg2_strides == NULL)) {
  }
  if (!(arg3_strides == NULL)) {
  }
  void* PaddedInput = TVMBackendAllocWorkspace(1, dev_id, (uint64_t)1937664, 2, 32);
  if (PaddedInput == NULL) {
    return -1;
  }
  for (int32_t i0_i1_fused_i2_fused = 0; i0_i1_fused_i2_fused < 2088; ++i0_i1_fused_i2_fused) {
    for (int32_t i3 = 0; i3 < 58; ++i3) {
      for (int32_t i4 = 0; i4 < 4; ++i4) {
        ((float*)PaddedInput)[((((i0_i1_fused_i2_fused * 232) + (i3 * 4)) + i4))] = (((((1 <= (i0_i1_fused_i2_fused % 58)) && ((i0_i1_fused_i2_fused % 58) < 57)) && (1 <= i3)) && (i3 < 57)) ? ((float*)placeholder)[(((((((i0_i1_fused_i2_fused / 58) * 12544) + ((i0_i1_fused_i2_fused % 58) * 224)) + (i3 * 4)) + i4) - 228))] : 0.000000e+00f);
      }
    }
  }
  for (int32_t i1_i2_fused = 0; i1_i2_fused < 2016; ++i1_i2_fused) {
    float DepthwiseConv2d[224];
    float DepthwiseConv2d_global[112];
    for (int32_t ow_outer = 0; ow_outer < 2; ++ow_outer) {
      for (int32_t oci_c_init = 0; oci_c_init < 4; ++oci_c_init) {
        DepthwiseConv2d_global[(oci_c_init)] = 0.000000e+00f;
      }
      for (int32_t oci_c_init1 = 0; oci_c_init1 < 4; ++oci_c_init1) {
        DepthwiseConv2d_global[((oci_c_init1 + 4))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init2 = 0; oci_c_init2 < 4; ++oci_c_init2) {
        DepthwiseConv2d_global[((oci_c_init2 + 8))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init3 = 0; oci_c_init3 < 4; ++oci_c_init3) {
        DepthwiseConv2d_global[((oci_c_init3 + 12))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init4 = 0; oci_c_init4 < 4; ++oci_c_init4) {
        DepthwiseConv2d_global[((oci_c_init4 + 16))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init5 = 0; oci_c_init5 < 4; ++oci_c_init5) {
        DepthwiseConv2d_global[((oci_c_init5 + 20))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init6 = 0; oci_c_init6 < 4; ++oci_c_init6) {
        DepthwiseConv2d_global[((oci_c_init6 + 24))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init7 = 0; oci_c_init7 < 4; ++oci_c_init7) {
        DepthwiseConv2d_global[((oci_c_init7 + 28))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init8 = 0; oci_c_init8 < 4; ++oci_c_init8) {
        DepthwiseConv2d_global[((oci_c_init8 + 32))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init9 = 0; oci_c_init9 < 4; ++oci_c_init9) {
        DepthwiseConv2d_global[((oci_c_init9 + 36))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init10 = 0; oci_c_init10 < 4; ++oci_c_init10) {
        DepthwiseConv2d_global[((oci_c_init10 + 40))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init11 = 0; oci_c_init11 < 4; ++oci_c_init11) {
        DepthwiseConv2d_global[((oci_c_init11 + 44))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init12 = 0; oci_c_init12 < 4; ++oci_c_init12) {
        DepthwiseConv2d_global[((oci_c_init12 + 48))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init13 = 0; oci_c_init13 < 4; ++oci_c_init13) {
        DepthwiseConv2d_global[((oci_c_init13 + 52))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init14 = 0; oci_c_init14 < 4; ++oci_c_init14) {
        DepthwiseConv2d_global[((oci_c_init14 + 56))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init15 = 0; oci_c_init15 < 4; ++oci_c_init15) {
        DepthwiseConv2d_global[((oci_c_init15 + 60))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init16 = 0; oci_c_init16 < 4; ++oci_c_init16) {
        DepthwiseConv2d_global[((oci_c_init16 + 64))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init17 = 0; oci_c_init17 < 4; ++oci_c_init17) {
        DepthwiseConv2d_global[((oci_c_init17 + 68))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init18 = 0; oci_c_init18 < 4; ++oci_c_init18) {
        DepthwiseConv2d_global[((oci_c_init18 + 72))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init19 = 0; oci_c_init19 < 4; ++oci_c_init19) {
        DepthwiseConv2d_global[((oci_c_init19 + 76))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init20 = 0; oci_c_init20 < 4; ++oci_c_init20) {
        DepthwiseConv2d_global[((oci_c_init20 + 80))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init21 = 0; oci_c_init21 < 4; ++oci_c_init21) {
        DepthwiseConv2d_global[((oci_c_init21 + 84))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init22 = 0; oci_c_init22 < 4; ++oci_c_init22) {
        DepthwiseConv2d_global[((oci_c_init22 + 88))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init23 = 0; oci_c_init23 < 4; ++oci_c_init23) {
        DepthwiseConv2d_global[((oci_c_init23 + 92))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init24 = 0; oci_c_init24 < 4; ++oci_c_init24) {
        DepthwiseConv2d_global[((oci_c_init24 + 96))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init25 = 0; oci_c_init25 < 4; ++oci_c_init25) {
        DepthwiseConv2d_global[((oci_c_init25 + 100))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init26 = 0; oci_c_init26 < 4; ++oci_c_init26) {
        DepthwiseConv2d_global[((oci_c_init26 + 104))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init27 = 0; oci_c_init27 < 4; ++oci_c_init27) {
        DepthwiseConv2d_global[((oci_c_init27 + 108))] = 0.000000e+00f;
      }
      for (int32_t kh = 0; kh < 3; ++kh) {
        for (int32_t kw = 0; kw < 3; ++kw) {
          for (int32_t oci_c = 0; oci_c < 4; ++oci_c) {
            DepthwiseConv2d_global[(oci_c)] = (DepthwiseConv2d_global[(oci_c)] + (((float*)PaddedInput)[((((((((i1_i2_fused / 56) * 13456) + (kh * 232)) + ((i1_i2_fused % 56) * 232)) + (ow_outer * 112)) + (kw * 4)) + oci_c))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c))]));
          }
          for (int32_t oci_c1 = 0; oci_c1 < 4; ++oci_c1) {
            DepthwiseConv2d_global[((oci_c1 + 4))] = (DepthwiseConv2d_global[((oci_c1 + 4))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 13456) + (kh * 232)) + ((i1_i2_fused % 56) * 232)) + (ow_outer * 112)) + (kw * 4)) + oci_c1) + 4))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c1))]));
          }
          for (int32_t oci_c2 = 0; oci_c2 < 4; ++oci_c2) {
            DepthwiseConv2d_global[((oci_c2 + 8))] = (DepthwiseConv2d_global[((oci_c2 + 8))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 13456) + (kh * 232)) + ((i1_i2_fused % 56) * 232)) + (ow_outer * 112)) + (kw * 4)) + oci_c2) + 8))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c2))]));
          }
          for (int32_t oci_c3 = 0; oci_c3 < 4; ++oci_c3) {
            DepthwiseConv2d_global[((oci_c3 + 12))] = (DepthwiseConv2d_global[((oci_c3 + 12))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 13456) + (kh * 232)) + ((i1_i2_fused % 56) * 232)) + (ow_outer * 112)) + (kw * 4)) + oci_c3) + 12))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c3))]));
          }
          for (int32_t oci_c4 = 0; oci_c4 < 4; ++oci_c4) {
            DepthwiseConv2d_global[((oci_c4 + 16))] = (DepthwiseConv2d_global[((oci_c4 + 16))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 13456) + (kh * 232)) + ((i1_i2_fused % 56) * 232)) + (ow_outer * 112)) + (kw * 4)) + oci_c4) + 16))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c4))]));
          }
          for (int32_t oci_c5 = 0; oci_c5 < 4; ++oci_c5) {
            DepthwiseConv2d_global[((oci_c5 + 20))] = (DepthwiseConv2d_global[((oci_c5 + 20))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 13456) + (kh * 232)) + ((i1_i2_fused % 56) * 232)) + (ow_outer * 112)) + (kw * 4)) + oci_c5) + 20))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c5))]));
          }
          for (int32_t oci_c6 = 0; oci_c6 < 4; ++oci_c6) {
            DepthwiseConv2d_global[((oci_c6 + 24))] = (DepthwiseConv2d_global[((oci_c6 + 24))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 13456) + (kh * 232)) + ((i1_i2_fused % 56) * 232)) + (ow_outer * 112)) + (kw * 4)) + oci_c6) + 24))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c6))]));
          }
          for (int32_t oci_c7 = 0; oci_c7 < 4; ++oci_c7) {
            DepthwiseConv2d_global[((oci_c7 + 28))] = (DepthwiseConv2d_global[((oci_c7 + 28))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 13456) + (kh * 232)) + ((i1_i2_fused % 56) * 232)) + (ow_outer * 112)) + (kw * 4)) + oci_c7) + 28))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c7))]));
          }
          for (int32_t oci_c8 = 0; oci_c8 < 4; ++oci_c8) {
            DepthwiseConv2d_global[((oci_c8 + 32))] = (DepthwiseConv2d_global[((oci_c8 + 32))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 13456) + (kh * 232)) + ((i1_i2_fused % 56) * 232)) + (ow_outer * 112)) + (kw * 4)) + oci_c8) + 32))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c8))]));
          }
          for (int32_t oci_c9 = 0; oci_c9 < 4; ++oci_c9) {
            DepthwiseConv2d_global[((oci_c9 + 36))] = (DepthwiseConv2d_global[((oci_c9 + 36))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 13456) + (kh * 232)) + ((i1_i2_fused % 56) * 232)) + (ow_outer * 112)) + (kw * 4)) + oci_c9) + 36))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c9))]));
          }
          for (int32_t oci_c10 = 0; oci_c10 < 4; ++oci_c10) {
            DepthwiseConv2d_global[((oci_c10 + 40))] = (DepthwiseConv2d_global[((oci_c10 + 40))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 13456) + (kh * 232)) + ((i1_i2_fused % 56) * 232)) + (ow_outer * 112)) + (kw * 4)) + oci_c10) + 40))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c10))]));
          }
          for (int32_t oci_c11 = 0; oci_c11 < 4; ++oci_c11) {
            DepthwiseConv2d_global[((oci_c11 + 44))] = (DepthwiseConv2d_global[((oci_c11 + 44))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 13456) + (kh * 232)) + ((i1_i2_fused % 56) * 232)) + (ow_outer * 112)) + (kw * 4)) + oci_c11) + 44))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c11))]));
          }
          for (int32_t oci_c12 = 0; oci_c12 < 4; ++oci_c12) {
            DepthwiseConv2d_global[((oci_c12 + 48))] = (DepthwiseConv2d_global[((oci_c12 + 48))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 13456) + (kh * 232)) + ((i1_i2_fused % 56) * 232)) + (ow_outer * 112)) + (kw * 4)) + oci_c12) + 48))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c12))]));
          }
          for (int32_t oci_c13 = 0; oci_c13 < 4; ++oci_c13) {
            DepthwiseConv2d_global[((oci_c13 + 52))] = (DepthwiseConv2d_global[((oci_c13 + 52))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 13456) + (kh * 232)) + ((i1_i2_fused % 56) * 232)) + (ow_outer * 112)) + (kw * 4)) + oci_c13) + 52))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c13))]));
          }
          for (int32_t oci_c14 = 0; oci_c14 < 4; ++oci_c14) {
            DepthwiseConv2d_global[((oci_c14 + 56))] = (DepthwiseConv2d_global[((oci_c14 + 56))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 13456) + (kh * 232)) + ((i1_i2_fused % 56) * 232)) + (ow_outer * 112)) + (kw * 4)) + oci_c14) + 56))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c14))]));
          }
          for (int32_t oci_c15 = 0; oci_c15 < 4; ++oci_c15) {
            DepthwiseConv2d_global[((oci_c15 + 60))] = (DepthwiseConv2d_global[((oci_c15 + 60))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 13456) + (kh * 232)) + ((i1_i2_fused % 56) * 232)) + (ow_outer * 112)) + (kw * 4)) + oci_c15) + 60))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c15))]));
          }
          for (int32_t oci_c16 = 0; oci_c16 < 4; ++oci_c16) {
            DepthwiseConv2d_global[((oci_c16 + 64))] = (DepthwiseConv2d_global[((oci_c16 + 64))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 13456) + (kh * 232)) + ((i1_i2_fused % 56) * 232)) + (ow_outer * 112)) + (kw * 4)) + oci_c16) + 64))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c16))]));
          }
          for (int32_t oci_c17 = 0; oci_c17 < 4; ++oci_c17) {
            DepthwiseConv2d_global[((oci_c17 + 68))] = (DepthwiseConv2d_global[((oci_c17 + 68))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 13456) + (kh * 232)) + ((i1_i2_fused % 56) * 232)) + (ow_outer * 112)) + (kw * 4)) + oci_c17) + 68))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c17))]));
          }
          for (int32_t oci_c18 = 0; oci_c18 < 4; ++oci_c18) {
            DepthwiseConv2d_global[((oci_c18 + 72))] = (DepthwiseConv2d_global[((oci_c18 + 72))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 13456) + (kh * 232)) + ((i1_i2_fused % 56) * 232)) + (ow_outer * 112)) + (kw * 4)) + oci_c18) + 72))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c18))]));
          }
          for (int32_t oci_c19 = 0; oci_c19 < 4; ++oci_c19) {
            DepthwiseConv2d_global[((oci_c19 + 76))] = (DepthwiseConv2d_global[((oci_c19 + 76))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 13456) + (kh * 232)) + ((i1_i2_fused % 56) * 232)) + (ow_outer * 112)) + (kw * 4)) + oci_c19) + 76))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c19))]));
          }
          for (int32_t oci_c20 = 0; oci_c20 < 4; ++oci_c20) {
            DepthwiseConv2d_global[((oci_c20 + 80))] = (DepthwiseConv2d_global[((oci_c20 + 80))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 13456) + (kh * 232)) + ((i1_i2_fused % 56) * 232)) + (ow_outer * 112)) + (kw * 4)) + oci_c20) + 80))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c20))]));
          }
          for (int32_t oci_c21 = 0; oci_c21 < 4; ++oci_c21) {
            DepthwiseConv2d_global[((oci_c21 + 84))] = (DepthwiseConv2d_global[((oci_c21 + 84))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 13456) + (kh * 232)) + ((i1_i2_fused % 56) * 232)) + (ow_outer * 112)) + (kw * 4)) + oci_c21) + 84))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c21))]));
          }
          for (int32_t oci_c22 = 0; oci_c22 < 4; ++oci_c22) {
            DepthwiseConv2d_global[((oci_c22 + 88))] = (DepthwiseConv2d_global[((oci_c22 + 88))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 13456) + (kh * 232)) + ((i1_i2_fused % 56) * 232)) + (ow_outer * 112)) + (kw * 4)) + oci_c22) + 88))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c22))]));
          }
          for (int32_t oci_c23 = 0; oci_c23 < 4; ++oci_c23) {
            DepthwiseConv2d_global[((oci_c23 + 92))] = (DepthwiseConv2d_global[((oci_c23 + 92))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 13456) + (kh * 232)) + ((i1_i2_fused % 56) * 232)) + (ow_outer * 112)) + (kw * 4)) + oci_c23) + 92))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c23))]));
          }
          for (int32_t oci_c24 = 0; oci_c24 < 4; ++oci_c24) {
            DepthwiseConv2d_global[((oci_c24 + 96))] = (DepthwiseConv2d_global[((oci_c24 + 96))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 13456) + (kh * 232)) + ((i1_i2_fused % 56) * 232)) + (ow_outer * 112)) + (kw * 4)) + oci_c24) + 96))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c24))]));
          }
          for (int32_t oci_c25 = 0; oci_c25 < 4; ++oci_c25) {
            DepthwiseConv2d_global[((oci_c25 + 100))] = (DepthwiseConv2d_global[((oci_c25 + 100))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 13456) + (kh * 232)) + ((i1_i2_fused % 56) * 232)) + (ow_outer * 112)) + (kw * 4)) + oci_c25) + 100))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c25))]));
          }
          for (int32_t oci_c26 = 0; oci_c26 < 4; ++oci_c26) {
            DepthwiseConv2d_global[((oci_c26 + 104))] = (DepthwiseConv2d_global[((oci_c26 + 104))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 13456) + (kh * 232)) + ((i1_i2_fused % 56) * 232)) + (ow_outer * 112)) + (kw * 4)) + oci_c26) + 104))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c26))]));
          }
          for (int32_t oci_c27 = 0; oci_c27 < 4; ++oci_c27) {
            DepthwiseConv2d_global[((oci_c27 + 108))] = (DepthwiseConv2d_global[((oci_c27 + 108))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 13456) + (kh * 232)) + ((i1_i2_fused % 56) * 232)) + (ow_outer * 112)) + (kw * 4)) + oci_c27) + 108))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c27))]));
          }
        }
      }
      for (int32_t ow_inner = 0; ow_inner < 28; ++ow_inner) {
        for (int32_t oci = 0; oci < 4; ++oci) {
          DepthwiseConv2d[((((ow_outer * 112) + (ow_inner * 4)) + oci))] = DepthwiseConv2d_global[(((ow_inner * 4) + oci))];
        }
      }
    }
    for (int32_t i3_outer = 0; i3_outer < 2; ++i3_outer) {
      for (int32_t i3_inner = 0; i3_inner < 28; ++i3_inner) {
        for (int32_t i41 = 0; i41 < 4; ++i41) {
          float _1 = DepthwiseConv2d[((((i3_outer * 112) + (i3_inner * 4)) + i41))] + ((float*)placeholder2)[((((i1_i2_fused / 56) * 4) + i41))];
          float _2 = (_1) < (6.000000e+00f) ? (_1) : (6.000000e+00f);
          ((float*)compute)[(((((i1_i2_fused * 224) + (i3_outer * 112)) + (i3_inner * 4)) + i41))] = ((_2) > (0.000000e+00f) ? (_2) : (0.000000e+00f));
        }
      }
    }
  }
  if (TVMBackendFreeWorkspace(1, dev_id, PaddedInput) != 0) {
    return -1;
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_contrib_conv2d_NCHWc_add_4(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int32_t arg2_code = ((int32_t*)arg_type_ids)[(2)];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int32_t arg3_code = ((int32_t*)arg_type_ids)[(3)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* placeholder1 = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  void* placeholder2 = (((DLTensor*)arg2)[0].data);
  void* arg2_shape = (((DLTensor*)arg2)[0].shape);
  void* arg2_strides = (((DLTensor*)arg2)[0].strides);
  void* T_add = (((DLTensor*)arg3)[0].data);
  void* arg3_shape = (((DLTensor*)arg3)[0].shape);
  void* arg3_strides = (((DLTensor*)arg3)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  if (!(arg2_strides == NULL)) {
  }
  if (!(arg3_strides == NULL)) {
  }
  for (int32_t ax0_ax1_fused_ax2_outer_fused = 0; ax0_ax1_fused_ax2_outer_fused < 112; ++ax0_ax1_fused_ax2_outer_fused) {
    float conv2d_NCHWc_global[112];
    for (int32_t oc_block_c_init = 0; oc_block_c_init < 4; ++oc_block_c_init) {
      conv2d_NCHWc_global[(oc_block_c_init)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init1 = 0; oc_block_c_init1 < 4; ++oc_block_c_init1) {
      conv2d_NCHWc_global[((oc_block_c_init1 + 4))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init2 = 0; oc_block_c_init2 < 4; ++oc_block_c_init2) {
      conv2d_NCHWc_global[((oc_block_c_init2 + 8))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init3 = 0; oc_block_c_init3 < 4; ++oc_block_c_init3) {
      conv2d_NCHWc_global[((oc_block_c_init3 + 12))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init4 = 0; oc_block_c_init4 < 4; ++oc_block_c_init4) {
      conv2d_NCHWc_global[((oc_block_c_init4 + 16))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init5 = 0; oc_block_c_init5 < 4; ++oc_block_c_init5) {
      conv2d_NCHWc_global[((oc_block_c_init5 + 20))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init6 = 0; oc_block_c_init6 < 4; ++oc_block_c_init6) {
      conv2d_NCHWc_global[((oc_block_c_init6 + 24))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init7 = 0; oc_block_c_init7 < 4; ++oc_block_c_init7) {
      conv2d_NCHWc_global[((oc_block_c_init7 + 28))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init8 = 0; oc_block_c_init8 < 4; ++oc_block_c_init8) {
      conv2d_NCHWc_global[((oc_block_c_init8 + 32))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init9 = 0; oc_block_c_init9 < 4; ++oc_block_c_init9) {
      conv2d_NCHWc_global[((oc_block_c_init9 + 36))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init10 = 0; oc_block_c_init10 < 4; ++oc_block_c_init10) {
      conv2d_NCHWc_global[((oc_block_c_init10 + 40))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init11 = 0; oc_block_c_init11 < 4; ++oc_block_c_init11) {
      conv2d_NCHWc_global[((oc_block_c_init11 + 44))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init12 = 0; oc_block_c_init12 < 4; ++oc_block_c_init12) {
      conv2d_NCHWc_global[((oc_block_c_init12 + 48))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init13 = 0; oc_block_c_init13 < 4; ++oc_block_c_init13) {
      conv2d_NCHWc_global[((oc_block_c_init13 + 52))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init14 = 0; oc_block_c_init14 < 4; ++oc_block_c_init14) {
      conv2d_NCHWc_global[((oc_block_c_init14 + 56))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init15 = 0; oc_block_c_init15 < 4; ++oc_block_c_init15) {
      conv2d_NCHWc_global[((oc_block_c_init15 + 60))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init16 = 0; oc_block_c_init16 < 4; ++oc_block_c_init16) {
      conv2d_NCHWc_global[((oc_block_c_init16 + 64))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init17 = 0; oc_block_c_init17 < 4; ++oc_block_c_init17) {
      conv2d_NCHWc_global[((oc_block_c_init17 + 68))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init18 = 0; oc_block_c_init18 < 4; ++oc_block_c_init18) {
      conv2d_NCHWc_global[((oc_block_c_init18 + 72))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init19 = 0; oc_block_c_init19 < 4; ++oc_block_c_init19) {
      conv2d_NCHWc_global[((oc_block_c_init19 + 76))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init20 = 0; oc_block_c_init20 < 4; ++oc_block_c_init20) {
      conv2d_NCHWc_global[((oc_block_c_init20 + 80))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init21 = 0; oc_block_c_init21 < 4; ++oc_block_c_init21) {
      conv2d_NCHWc_global[((oc_block_c_init21 + 84))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init22 = 0; oc_block_c_init22 < 4; ++oc_block_c_init22) {
      conv2d_NCHWc_global[((oc_block_c_init22 + 88))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init23 = 0; oc_block_c_init23 < 4; ++oc_block_c_init23) {
      conv2d_NCHWc_global[((oc_block_c_init23 + 92))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init24 = 0; oc_block_c_init24 < 4; ++oc_block_c_init24) {
      conv2d_NCHWc_global[((oc_block_c_init24 + 96))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init25 = 0; oc_block_c_init25 < 4; ++oc_block_c_init25) {
      conv2d_NCHWc_global[((oc_block_c_init25 + 100))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init26 = 0; oc_block_c_init26 < 4; ++oc_block_c_init26) {
      conv2d_NCHWc_global[((oc_block_c_init26 + 104))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init27 = 0; oc_block_c_init27 < 4; ++oc_block_c_init27) {
      conv2d_NCHWc_global[((oc_block_c_init27 + 108))] = 0.000000e+00f;
    }
    for (int32_t ic_outer = 0; ic_outer < 48; ++ic_outer) {
      for (int32_t ic_inner = 0; ic_inner < 4; ++ic_inner) {
        for (int32_t oc_block_c = 0; oc_block_c < 4; ++oc_block_c) {
          conv2d_NCHWc_global[(oc_block_c)] = (conv2d_NCHWc_global[(oc_block_c)] + (((float*)placeholder)[((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c))]));
        }
        for (int32_t oc_block_c1 = 0; oc_block_c1 < 4; ++oc_block_c1) {
          conv2d_NCHWc_global[((oc_block_c1 + 4))] = (conv2d_NCHWc_global[((oc_block_c1 + 4))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 4))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c1))]));
        }
        for (int32_t oc_block_c2 = 0; oc_block_c2 < 4; ++oc_block_c2) {
          conv2d_NCHWc_global[((oc_block_c2 + 8))] = (conv2d_NCHWc_global[((oc_block_c2 + 8))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 8))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c2))]));
        }
        for (int32_t oc_block_c3 = 0; oc_block_c3 < 4; ++oc_block_c3) {
          conv2d_NCHWc_global[((oc_block_c3 + 12))] = (conv2d_NCHWc_global[((oc_block_c3 + 12))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 12))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c3))]));
        }
        for (int32_t oc_block_c4 = 0; oc_block_c4 < 4; ++oc_block_c4) {
          conv2d_NCHWc_global[((oc_block_c4 + 16))] = (conv2d_NCHWc_global[((oc_block_c4 + 16))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 16))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c4))]));
        }
        for (int32_t oc_block_c5 = 0; oc_block_c5 < 4; ++oc_block_c5) {
          conv2d_NCHWc_global[((oc_block_c5 + 20))] = (conv2d_NCHWc_global[((oc_block_c5 + 20))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 20))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c5))]));
        }
        for (int32_t oc_block_c6 = 0; oc_block_c6 < 4; ++oc_block_c6) {
          conv2d_NCHWc_global[((oc_block_c6 + 24))] = (conv2d_NCHWc_global[((oc_block_c6 + 24))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 24))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c6))]));
        }
        for (int32_t oc_block_c7 = 0; oc_block_c7 < 4; ++oc_block_c7) {
          conv2d_NCHWc_global[((oc_block_c7 + 28))] = (conv2d_NCHWc_global[((oc_block_c7 + 28))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 28))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c7))]));
        }
        for (int32_t oc_block_c8 = 0; oc_block_c8 < 4; ++oc_block_c8) {
          conv2d_NCHWc_global[((oc_block_c8 + 32))] = (conv2d_NCHWc_global[((oc_block_c8 + 32))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 32))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c8))]));
        }
        for (int32_t oc_block_c9 = 0; oc_block_c9 < 4; ++oc_block_c9) {
          conv2d_NCHWc_global[((oc_block_c9 + 36))] = (conv2d_NCHWc_global[((oc_block_c9 + 36))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 36))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c9))]));
        }
        for (int32_t oc_block_c10 = 0; oc_block_c10 < 4; ++oc_block_c10) {
          conv2d_NCHWc_global[((oc_block_c10 + 40))] = (conv2d_NCHWc_global[((oc_block_c10 + 40))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 40))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c10))]));
        }
        for (int32_t oc_block_c11 = 0; oc_block_c11 < 4; ++oc_block_c11) {
          conv2d_NCHWc_global[((oc_block_c11 + 44))] = (conv2d_NCHWc_global[((oc_block_c11 + 44))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 44))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c11))]));
        }
        for (int32_t oc_block_c12 = 0; oc_block_c12 < 4; ++oc_block_c12) {
          conv2d_NCHWc_global[((oc_block_c12 + 48))] = (conv2d_NCHWc_global[((oc_block_c12 + 48))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 48))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c12))]));
        }
        for (int32_t oc_block_c13 = 0; oc_block_c13 < 4; ++oc_block_c13) {
          conv2d_NCHWc_global[((oc_block_c13 + 52))] = (conv2d_NCHWc_global[((oc_block_c13 + 52))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 52))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c13))]));
        }
        for (int32_t oc_block_c14 = 0; oc_block_c14 < 4; ++oc_block_c14) {
          conv2d_NCHWc_global[((oc_block_c14 + 56))] = (conv2d_NCHWc_global[((oc_block_c14 + 56))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 56))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c14))]));
        }
        for (int32_t oc_block_c15 = 0; oc_block_c15 < 4; ++oc_block_c15) {
          conv2d_NCHWc_global[((oc_block_c15 + 60))] = (conv2d_NCHWc_global[((oc_block_c15 + 60))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 60))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c15))]));
        }
        for (int32_t oc_block_c16 = 0; oc_block_c16 < 4; ++oc_block_c16) {
          conv2d_NCHWc_global[((oc_block_c16 + 64))] = (conv2d_NCHWc_global[((oc_block_c16 + 64))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 64))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c16))]));
        }
        for (int32_t oc_block_c17 = 0; oc_block_c17 < 4; ++oc_block_c17) {
          conv2d_NCHWc_global[((oc_block_c17 + 68))] = (conv2d_NCHWc_global[((oc_block_c17 + 68))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 68))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c17))]));
        }
        for (int32_t oc_block_c18 = 0; oc_block_c18 < 4; ++oc_block_c18) {
          conv2d_NCHWc_global[((oc_block_c18 + 72))] = (conv2d_NCHWc_global[((oc_block_c18 + 72))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 72))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c18))]));
        }
        for (int32_t oc_block_c19 = 0; oc_block_c19 < 4; ++oc_block_c19) {
          conv2d_NCHWc_global[((oc_block_c19 + 76))] = (conv2d_NCHWc_global[((oc_block_c19 + 76))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 76))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c19))]));
        }
        for (int32_t oc_block_c20 = 0; oc_block_c20 < 4; ++oc_block_c20) {
          conv2d_NCHWc_global[((oc_block_c20 + 80))] = (conv2d_NCHWc_global[((oc_block_c20 + 80))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 80))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c20))]));
        }
        for (int32_t oc_block_c21 = 0; oc_block_c21 < 4; ++oc_block_c21) {
          conv2d_NCHWc_global[((oc_block_c21 + 84))] = (conv2d_NCHWc_global[((oc_block_c21 + 84))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 84))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c21))]));
        }
        for (int32_t oc_block_c22 = 0; oc_block_c22 < 4; ++oc_block_c22) {
          conv2d_NCHWc_global[((oc_block_c22 + 88))] = (conv2d_NCHWc_global[((oc_block_c22 + 88))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 88))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c22))]));
        }
        for (int32_t oc_block_c23 = 0; oc_block_c23 < 4; ++oc_block_c23) {
          conv2d_NCHWc_global[((oc_block_c23 + 92))] = (conv2d_NCHWc_global[((oc_block_c23 + 92))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 92))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c23))]));
        }
        for (int32_t oc_block_c24 = 0; oc_block_c24 < 4; ++oc_block_c24) {
          conv2d_NCHWc_global[((oc_block_c24 + 96))] = (conv2d_NCHWc_global[((oc_block_c24 + 96))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 96))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c24))]));
        }
        for (int32_t oc_block_c25 = 0; oc_block_c25 < 4; ++oc_block_c25) {
          conv2d_NCHWc_global[((oc_block_c25 + 100))] = (conv2d_NCHWc_global[((oc_block_c25 + 100))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 100))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c25))]));
        }
        for (int32_t oc_block_c26 = 0; oc_block_c26 < 4; ++oc_block_c26) {
          conv2d_NCHWc_global[((oc_block_c26 + 104))] = (conv2d_NCHWc_global[((oc_block_c26 + 104))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 104))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c26))]));
        }
        for (int32_t oc_block_c27 = 0; oc_block_c27 < 4; ++oc_block_c27) {
          conv2d_NCHWc_global[((oc_block_c27 + 108))] = (conv2d_NCHWc_global[((oc_block_c27 + 108))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 108))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 768) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c27))]));
        }
      }
    }
    for (int32_t ax2_inner = 0; ax2_inner < 2; ++ax2_inner) {
      for (int32_t ax3_inner = 0; ax3_inner < 14; ++ax3_inner) {
        for (int32_t ax4 = 0; ax4 < 4; ++ax4) {
          ((float*)T_add)[(((((ax0_ax1_fused_ax2_outer_fused * 112) + (ax2_inner * 56)) + (ax3_inner * 4)) + ax4))] = (conv2d_NCHWc_global[((((ax2_inner * 56) + (ax3_inner * 4)) + ax4))] + ((float*)placeholder2)[((((ax0_ax1_fused_ax2_outer_fused / 7) * 4) + ax4))]);
        }
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_softmax(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* T_softmax_norm = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  float T_softmax_maxelem[1];
  void* T_softmax_exp = TVMBackendAllocWorkspace(1, dev_id, (uint64_t)4004, 2, 32);
  if (T_softmax_exp == NULL) {
    return -1;
  }
  float T_softmax_expsum[1];
  T_softmax_maxelem[(0)] = -3.402823e+38f;
  for (int32_t k = 0; k < 1001; ++k) {
    float _1 = T_softmax_maxelem[(0)];
    float _2 = ((float*)placeholder)[(k)];
    T_softmax_maxelem[(0)] = ((_1) > (_2) ? (_1) : (_2));
  }
  for (int32_t i1 = 0; i1 < 1001; ++i1) {
    ((float*)T_softmax_exp)[(i1)] = expf((((float*)placeholder)[(i1)] - T_softmax_maxelem[(0)]));
  }
  T_softmax_expsum[(0)] = 0.000000e+00f;
  for (int32_t k1 = 0; k1 < 1001; ++k1) {
    T_softmax_expsum[(0)] = (T_softmax_expsum[(0)] + ((float*)T_softmax_exp)[(k1)]);
  }
  for (int32_t i11 = 0; i11 < 1001; ++i11) {
    ((float*)T_softmax_norm)[(i11)] = (((float*)T_softmax_exp)[(i11)] / T_softmax_expsum[(0)]);
  }
  if (TVMBackendFreeWorkspace(1, dev_id, T_softmax_exp) != 0) {
    return -1;
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_contrib_conv2d_NCHWc_add_2(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int32_t arg2_code = ((int32_t*)arg_type_ids)[(2)];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int32_t arg3_code = ((int32_t*)arg_type_ids)[(3)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* placeholder1 = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  void* placeholder2 = (((DLTensor*)arg2)[0].data);
  void* arg2_shape = (((DLTensor*)arg2)[0].shape);
  void* arg2_strides = (((DLTensor*)arg2)[0].strides);
  void* T_add = (((DLTensor*)arg3)[0].data);
  void* arg3_shape = (((DLTensor*)arg3)[0].shape);
  void* arg3_strides = (((DLTensor*)arg3)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  if (!(arg2_strides == NULL)) {
  }
  if (!(arg3_strides == NULL)) {
  }
  for (int32_t ax0_ax1_fused_ax2_outer_fused = 0; ax0_ax1_fused_ax2_outer_fused < 280; ++ax0_ax1_fused_ax2_outer_fused) {
    float conv2d_NCHWc_global[28];
    for (int32_t oc_block_c_init = 0; oc_block_c_init < 4; ++oc_block_c_init) {
      conv2d_NCHWc_global[(oc_block_c_init)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init1 = 0; oc_block_c_init1 < 4; ++oc_block_c_init1) {
      conv2d_NCHWc_global[((oc_block_c_init1 + 4))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init2 = 0; oc_block_c_init2 < 4; ++oc_block_c_init2) {
      conv2d_NCHWc_global[((oc_block_c_init2 + 8))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init3 = 0; oc_block_c_init3 < 4; ++oc_block_c_init3) {
      conv2d_NCHWc_global[((oc_block_c_init3 + 12))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init4 = 0; oc_block_c_init4 < 4; ++oc_block_c_init4) {
      conv2d_NCHWc_global[((oc_block_c_init4 + 16))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init5 = 0; oc_block_c_init5 < 4; ++oc_block_c_init5) {
      conv2d_NCHWc_global[((oc_block_c_init5 + 20))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init6 = 0; oc_block_c_init6 < 4; ++oc_block_c_init6) {
      conv2d_NCHWc_global[((oc_block_c_init6 + 24))] = 0.000000e+00f;
    }
    for (int32_t ic_outer = 0; ic_outer < 144; ++ic_outer) {
      for (int32_t ic_inner = 0; ic_inner < 4; ++ic_inner) {
        for (int32_t oc_block_c = 0; oc_block_c < 4; ++oc_block_c) {
          conv2d_NCHWc_global[(oc_block_c)] = (conv2d_NCHWc_global[(oc_block_c)] + (((float*)placeholder)[((((ic_outer * 196) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 28)) + ic_inner))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 2304) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c))]));
        }
        for (int32_t oc_block_c1 = 0; oc_block_c1 < 4; ++oc_block_c1) {
          conv2d_NCHWc_global[((oc_block_c1 + 4))] = (conv2d_NCHWc_global[((oc_block_c1 + 4))] + (((float*)placeholder)[(((((ic_outer * 196) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 28)) + ic_inner) + 4))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 2304) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c1))]));
        }
        for (int32_t oc_block_c2 = 0; oc_block_c2 < 4; ++oc_block_c2) {
          conv2d_NCHWc_global[((oc_block_c2 + 8))] = (conv2d_NCHWc_global[((oc_block_c2 + 8))] + (((float*)placeholder)[(((((ic_outer * 196) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 28)) + ic_inner) + 8))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 2304) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c2))]));
        }
        for (int32_t oc_block_c3 = 0; oc_block_c3 < 4; ++oc_block_c3) {
          conv2d_NCHWc_global[((oc_block_c3 + 12))] = (conv2d_NCHWc_global[((oc_block_c3 + 12))] + (((float*)placeholder)[(((((ic_outer * 196) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 28)) + ic_inner) + 12))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 2304) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c3))]));
        }
        for (int32_t oc_block_c4 = 0; oc_block_c4 < 4; ++oc_block_c4) {
          conv2d_NCHWc_global[((oc_block_c4 + 16))] = (conv2d_NCHWc_global[((oc_block_c4 + 16))] + (((float*)placeholder)[(((((ic_outer * 196) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 28)) + ic_inner) + 16))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 2304) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c4))]));
        }
        for (int32_t oc_block_c5 = 0; oc_block_c5 < 4; ++oc_block_c5) {
          conv2d_NCHWc_global[((oc_block_c5 + 20))] = (conv2d_NCHWc_global[((oc_block_c5 + 20))] + (((float*)placeholder)[(((((ic_outer * 196) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 28)) + ic_inner) + 20))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 2304) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c5))]));
        }
        for (int32_t oc_block_c6 = 0; oc_block_c6 < 4; ++oc_block_c6) {
          conv2d_NCHWc_global[((oc_block_c6 + 24))] = (conv2d_NCHWc_global[((oc_block_c6 + 24))] + (((float*)placeholder)[(((((ic_outer * 196) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 28)) + ic_inner) + 24))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 2304) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c6))]));
        }
      }
    }
    for (int32_t ax3_inner = 0; ax3_inner < 7; ++ax3_inner) {
      for (int32_t ax4 = 0; ax4 < 4; ++ax4) {
        ((float*)T_add)[((((ax0_ax1_fused_ax2_outer_fused * 28) + (ax3_inner * 4)) + ax4))] = (conv2d_NCHWc_global[(((ax3_inner * 4) + ax4))] + ((float*)placeholder2)[((((ax0_ax1_fused_ax2_outer_fused / 7) * 4) + ax4))]);
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_contrib_depthwise_conv2d_NCHWc_add_clip_2(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int32_t arg2_code = ((int32_t*)arg_type_ids)[(2)];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int32_t arg3_code = ((int32_t*)arg_type_ids)[(3)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* placeholder1 = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  void* placeholder2 = (((DLTensor*)arg2)[0].data);
  void* arg2_shape = (((DLTensor*)arg2)[0].shape);
  void* arg2_strides = (((DLTensor*)arg2)[0].strides);
  void* compute = (((DLTensor*)arg3)[0].data);
  void* arg3_shape = (((DLTensor*)arg3)[0].shape);
  void* arg3_strides = (((DLTensor*)arg3)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  if (!(arg2_strides == NULL)) {
  }
  if (!(arg3_strides == NULL)) {
  }
  void* PaddedInput = TVMBackendAllocWorkspace(1, dev_id, (uint64_t)589824, 2, 32);
  if (PaddedInput == NULL) {
    return -1;
  }
  for (int32_t i0_i1_fused_i2_fused = 0; i0_i1_fused_i2_fused < 2304; ++i0_i1_fused_i2_fused) {
    for (int32_t i3 = 0; i3 < 16; ++i3) {
      for (int32_t i4 = 0; i4 < 4; ++i4) {
        ((float*)PaddedInput)[((((i0_i1_fused_i2_fused * 64) + (i3 * 4)) + i4))] = (((((1 <= (i0_i1_fused_i2_fused & 15)) && ((i0_i1_fused_i2_fused & 15) < 15)) && (1 <= i3)) && (i3 < 15)) ? ((float*)placeholder)[(((((((i0_i1_fused_i2_fused >> 4) * 784) + ((i0_i1_fused_i2_fused & 15) * 56)) + (i3 * 4)) + i4) - 60))] : 0.000000e+00f);
      }
    }
  }
  for (int32_t i1_i2_fused = 0; i1_i2_fused < 2016; ++i1_i2_fused) {
    float DepthwiseConv2d_global[56];
    for (int32_t oci_c_init = 0; oci_c_init < 4; ++oci_c_init) {
      DepthwiseConv2d_global[(oci_c_init)] = 0.000000e+00f;
    }
    for (int32_t oci_c_init1 = 0; oci_c_init1 < 4; ++oci_c_init1) {
      DepthwiseConv2d_global[((oci_c_init1 + 4))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init2 = 0; oci_c_init2 < 4; ++oci_c_init2) {
      DepthwiseConv2d_global[((oci_c_init2 + 8))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init3 = 0; oci_c_init3 < 4; ++oci_c_init3) {
      DepthwiseConv2d_global[((oci_c_init3 + 12))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init4 = 0; oci_c_init4 < 4; ++oci_c_init4) {
      DepthwiseConv2d_global[((oci_c_init4 + 16))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init5 = 0; oci_c_init5 < 4; ++oci_c_init5) {
      DepthwiseConv2d_global[((oci_c_init5 + 20))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init6 = 0; oci_c_init6 < 4; ++oci_c_init6) {
      DepthwiseConv2d_global[((oci_c_init6 + 24))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init7 = 0; oci_c_init7 < 4; ++oci_c_init7) {
      DepthwiseConv2d_global[((oci_c_init7 + 28))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init8 = 0; oci_c_init8 < 4; ++oci_c_init8) {
      DepthwiseConv2d_global[((oci_c_init8 + 32))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init9 = 0; oci_c_init9 < 4; ++oci_c_init9) {
      DepthwiseConv2d_global[((oci_c_init9 + 36))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init10 = 0; oci_c_init10 < 4; ++oci_c_init10) {
      DepthwiseConv2d_global[((oci_c_init10 + 40))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init11 = 0; oci_c_init11 < 4; ++oci_c_init11) {
      DepthwiseConv2d_global[((oci_c_init11 + 44))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init12 = 0; oci_c_init12 < 4; ++oci_c_init12) {
      DepthwiseConv2d_global[((oci_c_init12 + 48))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init13 = 0; oci_c_init13 < 4; ++oci_c_init13) {
      DepthwiseConv2d_global[((oci_c_init13 + 52))] = 0.000000e+00f;
    }
    for (int32_t kh = 0; kh < 3; ++kh) {
      for (int32_t kw = 0; kw < 3; ++kw) {
        for (int32_t oci_c = 0; oci_c < 4; ++oci_c) {
          DepthwiseConv2d_global[(oci_c)] = (DepthwiseConv2d_global[(oci_c)] + (((float*)PaddedInput)[(((((((i1_i2_fused / 14) * 1024) + (kh * 64)) + ((i1_i2_fused % 14) * 64)) + (kw * 4)) + oci_c))] * ((float*)placeholder1)[((((((i1_i2_fused / 14) * 36) + (kh * 12)) + (kw * 4)) + oci_c))]));
        }
        for (int32_t oci_c1 = 0; oci_c1 < 4; ++oci_c1) {
          DepthwiseConv2d_global[((oci_c1 + 4))] = (DepthwiseConv2d_global[((oci_c1 + 4))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 14) * 1024) + (kh * 64)) + ((i1_i2_fused % 14) * 64)) + (kw * 4)) + oci_c1) + 4))] * ((float*)placeholder1)[((((((i1_i2_fused / 14) * 36) + (kh * 12)) + (kw * 4)) + oci_c1))]));
        }
        for (int32_t oci_c2 = 0; oci_c2 < 4; ++oci_c2) {
          DepthwiseConv2d_global[((oci_c2 + 8))] = (DepthwiseConv2d_global[((oci_c2 + 8))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 14) * 1024) + (kh * 64)) + ((i1_i2_fused % 14) * 64)) + (kw * 4)) + oci_c2) + 8))] * ((float*)placeholder1)[((((((i1_i2_fused / 14) * 36) + (kh * 12)) + (kw * 4)) + oci_c2))]));
        }
        for (int32_t oci_c3 = 0; oci_c3 < 4; ++oci_c3) {
          DepthwiseConv2d_global[((oci_c3 + 12))] = (DepthwiseConv2d_global[((oci_c3 + 12))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 14) * 1024) + (kh * 64)) + ((i1_i2_fused % 14) * 64)) + (kw * 4)) + oci_c3) + 12))] * ((float*)placeholder1)[((((((i1_i2_fused / 14) * 36) + (kh * 12)) + (kw * 4)) + oci_c3))]));
        }
        for (int32_t oci_c4 = 0; oci_c4 < 4; ++oci_c4) {
          DepthwiseConv2d_global[((oci_c4 + 16))] = (DepthwiseConv2d_global[((oci_c4 + 16))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 14) * 1024) + (kh * 64)) + ((i1_i2_fused % 14) * 64)) + (kw * 4)) + oci_c4) + 16))] * ((float*)placeholder1)[((((((i1_i2_fused / 14) * 36) + (kh * 12)) + (kw * 4)) + oci_c4))]));
        }
        for (int32_t oci_c5 = 0; oci_c5 < 4; ++oci_c5) {
          DepthwiseConv2d_global[((oci_c5 + 20))] = (DepthwiseConv2d_global[((oci_c5 + 20))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 14) * 1024) + (kh * 64)) + ((i1_i2_fused % 14) * 64)) + (kw * 4)) + oci_c5) + 20))] * ((float*)placeholder1)[((((((i1_i2_fused / 14) * 36) + (kh * 12)) + (kw * 4)) + oci_c5))]));
        }
        for (int32_t oci_c6 = 0; oci_c6 < 4; ++oci_c6) {
          DepthwiseConv2d_global[((oci_c6 + 24))] = (DepthwiseConv2d_global[((oci_c6 + 24))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 14) * 1024) + (kh * 64)) + ((i1_i2_fused % 14) * 64)) + (kw * 4)) + oci_c6) + 24))] * ((float*)placeholder1)[((((((i1_i2_fused / 14) * 36) + (kh * 12)) + (kw * 4)) + oci_c6))]));
        }
        for (int32_t oci_c7 = 0; oci_c7 < 4; ++oci_c7) {
          DepthwiseConv2d_global[((oci_c7 + 28))] = (DepthwiseConv2d_global[((oci_c7 + 28))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 14) * 1024) + (kh * 64)) + ((i1_i2_fused % 14) * 64)) + (kw * 4)) + oci_c7) + 28))] * ((float*)placeholder1)[((((((i1_i2_fused / 14) * 36) + (kh * 12)) + (kw * 4)) + oci_c7))]));
        }
        for (int32_t oci_c8 = 0; oci_c8 < 4; ++oci_c8) {
          DepthwiseConv2d_global[((oci_c8 + 32))] = (DepthwiseConv2d_global[((oci_c8 + 32))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 14) * 1024) + (kh * 64)) + ((i1_i2_fused % 14) * 64)) + (kw * 4)) + oci_c8) + 32))] * ((float*)placeholder1)[((((((i1_i2_fused / 14) * 36) + (kh * 12)) + (kw * 4)) + oci_c8))]));
        }
        for (int32_t oci_c9 = 0; oci_c9 < 4; ++oci_c9) {
          DepthwiseConv2d_global[((oci_c9 + 36))] = (DepthwiseConv2d_global[((oci_c9 + 36))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 14) * 1024) + (kh * 64)) + ((i1_i2_fused % 14) * 64)) + (kw * 4)) + oci_c9) + 36))] * ((float*)placeholder1)[((((((i1_i2_fused / 14) * 36) + (kh * 12)) + (kw * 4)) + oci_c9))]));
        }
        for (int32_t oci_c10 = 0; oci_c10 < 4; ++oci_c10) {
          DepthwiseConv2d_global[((oci_c10 + 40))] = (DepthwiseConv2d_global[((oci_c10 + 40))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 14) * 1024) + (kh * 64)) + ((i1_i2_fused % 14) * 64)) + (kw * 4)) + oci_c10) + 40))] * ((float*)placeholder1)[((((((i1_i2_fused / 14) * 36) + (kh * 12)) + (kw * 4)) + oci_c10))]));
        }
        for (int32_t oci_c11 = 0; oci_c11 < 4; ++oci_c11) {
          DepthwiseConv2d_global[((oci_c11 + 44))] = (DepthwiseConv2d_global[((oci_c11 + 44))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 14) * 1024) + (kh * 64)) + ((i1_i2_fused % 14) * 64)) + (kw * 4)) + oci_c11) + 44))] * ((float*)placeholder1)[((((((i1_i2_fused / 14) * 36) + (kh * 12)) + (kw * 4)) + oci_c11))]));
        }
        for (int32_t oci_c12 = 0; oci_c12 < 4; ++oci_c12) {
          DepthwiseConv2d_global[((oci_c12 + 48))] = (DepthwiseConv2d_global[((oci_c12 + 48))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 14) * 1024) + (kh * 64)) + ((i1_i2_fused % 14) * 64)) + (kw * 4)) + oci_c12) + 48))] * ((float*)placeholder1)[((((((i1_i2_fused / 14) * 36) + (kh * 12)) + (kw * 4)) + oci_c12))]));
        }
        for (int32_t oci_c13 = 0; oci_c13 < 4; ++oci_c13) {
          DepthwiseConv2d_global[((oci_c13 + 52))] = (DepthwiseConv2d_global[((oci_c13 + 52))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 14) * 1024) + (kh * 64)) + ((i1_i2_fused % 14) * 64)) + (kw * 4)) + oci_c13) + 52))] * ((float*)placeholder1)[((((((i1_i2_fused / 14) * 36) + (kh * 12)) + (kw * 4)) + oci_c13))]));
        }
      }
    }
    for (int32_t i3_inner = 0; i3_inner < 14; ++i3_inner) {
      for (int32_t i41 = 0; i41 < 4; ++i41) {
        float _1 = DepthwiseConv2d_global[(((i3_inner * 4) + i41))] + ((float*)placeholder2)[((((i1_i2_fused / 14) * 4) + i41))];
        float _2 = (_1) < (6.000000e+00f) ? (_1) : (6.000000e+00f);
        ((float*)compute)[((((i1_i2_fused * 56) + (i3_inner * 4)) + i41))] = ((_2) > (0.000000e+00f) ? (_2) : (0.000000e+00f));
      }
    }
  }
  if (TVMBackendFreeWorkspace(1, dev_id, PaddedInput) != 0) {
    return -1;
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_contrib_conv2d_NCHWc_add(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int32_t arg2_code = ((int32_t*)arg_type_ids)[(2)];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int32_t arg3_code = ((int32_t*)arg_type_ids)[(3)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* placeholder1 = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  void* placeholder2 = (((DLTensor*)arg2)[0].data);
  void* arg2_shape = (((DLTensor*)arg2)[0].shape);
  void* arg2_strides = (((DLTensor*)arg2)[0].strides);
  void* T_add = (((DLTensor*)arg3)[0].data);
  void* arg3_shape = (((DLTensor*)arg3)[0].shape);
  void* arg3_strides = (((DLTensor*)arg3)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  if (!(arg2_strides == NULL)) {
  }
  if (!(arg3_strides == NULL)) {
  }
  for (int32_t ax0_ax1_fused_ax2_outer_fused = 0; ax0_ax1_fused_ax2_outer_fused < 1001; ++ax0_ax1_fused_ax2_outer_fused) {
    float conv2d_NCHWc_global[1];
    conv2d_NCHWc_global[(0)] = 0.000000e+00f;
    for (int32_t ic_outer = 0; ic_outer < 1280; ++ic_outer) {
      conv2d_NCHWc_global[(0)] = (conv2d_NCHWc_global[(0)] + (((float*)placeholder)[(ic_outer)] * ((float*)placeholder1)[(((ax0_ax1_fused_ax2_outer_fused * 1280) + ic_outer))]));
    }
    ((float*)T_add)[(ax0_ax1_fused_ax2_outer_fused)] = (conv2d_NCHWc_global[(0)] + ((float*)placeholder2)[(ax0_ax1_fused_ax2_outer_fused)]);
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_contrib_conv2d_NCHWc_add_clip_7(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int32_t arg2_code = ((int32_t*)arg_type_ids)[(2)];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int32_t arg3_code = ((int32_t*)arg_type_ids)[(3)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* placeholder1 = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  void* placeholder2 = (((DLTensor*)arg2)[0].data);
  void* arg2_shape = (((DLTensor*)arg2)[0].shape);
  void* arg2_strides = (((DLTensor*)arg2)[0].strides);
  void* compute = (((DLTensor*)arg3)[0].data);
  void* arg3_shape = (((DLTensor*)arg3)[0].shape);
  void* arg3_strides = (((DLTensor*)arg3)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  if (!(arg2_strides == NULL)) {
  }
  if (!(arg3_strides == NULL)) {
  }
  void* data_pad = TVMBackendAllocWorkspace(1, dev_id, (uint64_t)607500, 2, 32);
  if (data_pad == NULL) {
    return -1;
  }
  for (int32_t i0_i1_fused_i2_fused = 0; i0_i1_fused_i2_fused < 225; ++i0_i1_fused_i2_fused) {
    for (int32_t i3 = 0; i3 < 225; ++i3) {
      for (int32_t i4 = 0; i4 < 3; ++i4) {
        ((float*)data_pad)[((((i0_i1_fused_i2_fused * 675) + (i3 * 3)) + i4))] = (((i0_i1_fused_i2_fused < 224) && (i3 < 224)) ? ((float*)placeholder)[((((i0_i1_fused_i2_fused * 672) + (i3 * 3)) + i4))] : 0.000000e+00f);
      }
    }
  }
  for (int32_t i0_i1_fused_i2_fused1 = 0; i0_i1_fused_i2_fused1 < 896; ++i0_i1_fused_i2_fused1) {
    void* conv2d_NCHWc = TVMBackendAllocWorkspace(1, dev_id, (uint64_t)1792, 2, 32);
    if (conv2d_NCHWc == NULL) {
      return -1;
    }
    float conv2d_NCHWc_global[112];
    for (int32_t ow_outer = 0; ow_outer < 4; ++ow_outer) {
      for (int32_t oc_block_c_init = 0; oc_block_c_init < 4; ++oc_block_c_init) {
        conv2d_NCHWc_global[(oc_block_c_init)] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init1 = 0; oc_block_c_init1 < 4; ++oc_block_c_init1) {
        conv2d_NCHWc_global[((oc_block_c_init1 + 4))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init2 = 0; oc_block_c_init2 < 4; ++oc_block_c_init2) {
        conv2d_NCHWc_global[((oc_block_c_init2 + 8))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init3 = 0; oc_block_c_init3 < 4; ++oc_block_c_init3) {
        conv2d_NCHWc_global[((oc_block_c_init3 + 12))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init4 = 0; oc_block_c_init4 < 4; ++oc_block_c_init4) {
        conv2d_NCHWc_global[((oc_block_c_init4 + 16))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init5 = 0; oc_block_c_init5 < 4; ++oc_block_c_init5) {
        conv2d_NCHWc_global[((oc_block_c_init5 + 20))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init6 = 0; oc_block_c_init6 < 4; ++oc_block_c_init6) {
        conv2d_NCHWc_global[((oc_block_c_init6 + 24))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init7 = 0; oc_block_c_init7 < 4; ++oc_block_c_init7) {
        conv2d_NCHWc_global[((oc_block_c_init7 + 28))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init8 = 0; oc_block_c_init8 < 4; ++oc_block_c_init8) {
        conv2d_NCHWc_global[((oc_block_c_init8 + 32))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init9 = 0; oc_block_c_init9 < 4; ++oc_block_c_init9) {
        conv2d_NCHWc_global[((oc_block_c_init9 + 36))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init10 = 0; oc_block_c_init10 < 4; ++oc_block_c_init10) {
        conv2d_NCHWc_global[((oc_block_c_init10 + 40))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init11 = 0; oc_block_c_init11 < 4; ++oc_block_c_init11) {
        conv2d_NCHWc_global[((oc_block_c_init11 + 44))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init12 = 0; oc_block_c_init12 < 4; ++oc_block_c_init12) {
        conv2d_NCHWc_global[((oc_block_c_init12 + 48))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init13 = 0; oc_block_c_init13 < 4; ++oc_block_c_init13) {
        conv2d_NCHWc_global[((oc_block_c_init13 + 52))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init14 = 0; oc_block_c_init14 < 4; ++oc_block_c_init14) {
        conv2d_NCHWc_global[((oc_block_c_init14 + 56))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init15 = 0; oc_block_c_init15 < 4; ++oc_block_c_init15) {
        conv2d_NCHWc_global[((oc_block_c_init15 + 60))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init16 = 0; oc_block_c_init16 < 4; ++oc_block_c_init16) {
        conv2d_NCHWc_global[((oc_block_c_init16 + 64))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init17 = 0; oc_block_c_init17 < 4; ++oc_block_c_init17) {
        conv2d_NCHWc_global[((oc_block_c_init17 + 68))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init18 = 0; oc_block_c_init18 < 4; ++oc_block_c_init18) {
        conv2d_NCHWc_global[((oc_block_c_init18 + 72))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init19 = 0; oc_block_c_init19 < 4; ++oc_block_c_init19) {
        conv2d_NCHWc_global[((oc_block_c_init19 + 76))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init20 = 0; oc_block_c_init20 < 4; ++oc_block_c_init20) {
        conv2d_NCHWc_global[((oc_block_c_init20 + 80))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init21 = 0; oc_block_c_init21 < 4; ++oc_block_c_init21) {
        conv2d_NCHWc_global[((oc_block_c_init21 + 84))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init22 = 0; oc_block_c_init22 < 4; ++oc_block_c_init22) {
        conv2d_NCHWc_global[((oc_block_c_init22 + 88))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init23 = 0; oc_block_c_init23 < 4; ++oc_block_c_init23) {
        conv2d_NCHWc_global[((oc_block_c_init23 + 92))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init24 = 0; oc_block_c_init24 < 4; ++oc_block_c_init24) {
        conv2d_NCHWc_global[((oc_block_c_init24 + 96))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init25 = 0; oc_block_c_init25 < 4; ++oc_block_c_init25) {
        conv2d_NCHWc_global[((oc_block_c_init25 + 100))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init26 = 0; oc_block_c_init26 < 4; ++oc_block_c_init26) {
        conv2d_NCHWc_global[((oc_block_c_init26 + 104))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init27 = 0; oc_block_c_init27 < 4; ++oc_block_c_init27) {
        conv2d_NCHWc_global[((oc_block_c_init27 + 108))] = 0.000000e+00f;
      }
      for (int32_t kh = 0; kh < 3; ++kh) {
        for (int32_t kw = 0; kw < 3; ++kw) {
          for (int32_t ic_inner = 0; ic_inner < 3; ++ic_inner) {
            for (int32_t oc_block_c = 0; oc_block_c < 4; ++oc_block_c) {
              conv2d_NCHWc_global[(oc_block_c)] = (conv2d_NCHWc_global[(oc_block_c)] + (((float*)data_pad)[(((((((i0_i1_fused_i2_fused1 % 112) * 1350) + (kh * 675)) + (ow_outer * 168)) + (kw * 3)) + ic_inner))] * ((float*)placeholder1)[(((((((i0_i1_fused_i2_fused1 / 112) * 108) + (kh * 36)) + (kw * 12)) + (ic_inner * 4)) + oc_block_c))]));
            }
            for (int32_t oc_block_c1 = 0; oc_block_c1 < 4; ++oc_block_c1) {
              conv2d_NCHWc_global[((oc_block_c1 + 4))] = (conv2d_NCHWc_global[((oc_block_c1 + 4))] + (((float*)data_pad)[((((((((i0_i1_fused_i2_fused1 % 112) * 1350) + (kh * 675)) + (ow_outer * 168)) + (kw * 3)) + ic_inner) + 6))] * ((float*)placeholder1)[(((((((i0_i1_fused_i2_fused1 / 112) * 108) + (kh * 36)) + (kw * 12)) + (ic_inner * 4)) + oc_block_c1))]));
            }
            for (int32_t oc_block_c2 = 0; oc_block_c2 < 4; ++oc_block_c2) {
              conv2d_NCHWc_global[((oc_block_c2 + 8))] = (conv2d_NCHWc_global[((oc_block_c2 + 8))] + (((float*)data_pad)[((((((((i0_i1_fused_i2_fused1 % 112) * 1350) + (kh * 675)) + (ow_outer * 168)) + (kw * 3)) + ic_inner) + 12))] * ((float*)placeholder1)[(((((((i0_i1_fused_i2_fused1 / 112) * 108) + (kh * 36)) + (kw * 12)) + (ic_inner * 4)) + oc_block_c2))]));
            }
            for (int32_t oc_block_c3 = 0; oc_block_c3 < 4; ++oc_block_c3) {
              conv2d_NCHWc_global[((oc_block_c3 + 12))] = (conv2d_NCHWc_global[((oc_block_c3 + 12))] + (((float*)data_pad)[((((((((i0_i1_fused_i2_fused1 % 112) * 1350) + (kh * 675)) + (ow_outer * 168)) + (kw * 3)) + ic_inner) + 18))] * ((float*)placeholder1)[(((((((i0_i1_fused_i2_fused1 / 112) * 108) + (kh * 36)) + (kw * 12)) + (ic_inner * 4)) + oc_block_c3))]));
            }
            for (int32_t oc_block_c4 = 0; oc_block_c4 < 4; ++oc_block_c4) {
              conv2d_NCHWc_global[((oc_block_c4 + 16))] = (conv2d_NCHWc_global[((oc_block_c4 + 16))] + (((float*)data_pad)[((((((((i0_i1_fused_i2_fused1 % 112) * 1350) + (kh * 675)) + (ow_outer * 168)) + (kw * 3)) + ic_inner) + 24))] * ((float*)placeholder1)[(((((((i0_i1_fused_i2_fused1 / 112) * 108) + (kh * 36)) + (kw * 12)) + (ic_inner * 4)) + oc_block_c4))]));
            }
            for (int32_t oc_block_c5 = 0; oc_block_c5 < 4; ++oc_block_c5) {
              conv2d_NCHWc_global[((oc_block_c5 + 20))] = (conv2d_NCHWc_global[((oc_block_c5 + 20))] + (((float*)data_pad)[((((((((i0_i1_fused_i2_fused1 % 112) * 1350) + (kh * 675)) + (ow_outer * 168)) + (kw * 3)) + ic_inner) + 30))] * ((float*)placeholder1)[(((((((i0_i1_fused_i2_fused1 / 112) * 108) + (kh * 36)) + (kw * 12)) + (ic_inner * 4)) + oc_block_c5))]));
            }
            for (int32_t oc_block_c6 = 0; oc_block_c6 < 4; ++oc_block_c6) {
              conv2d_NCHWc_global[((oc_block_c6 + 24))] = (conv2d_NCHWc_global[((oc_block_c6 + 24))] + (((float*)data_pad)[((((((((i0_i1_fused_i2_fused1 % 112) * 1350) + (kh * 675)) + (ow_outer * 168)) + (kw * 3)) + ic_inner) + 36))] * ((float*)placeholder1)[(((((((i0_i1_fused_i2_fused1 / 112) * 108) + (kh * 36)) + (kw * 12)) + (ic_inner * 4)) + oc_block_c6))]));
            }
            for (int32_t oc_block_c7 = 0; oc_block_c7 < 4; ++oc_block_c7) {
              conv2d_NCHWc_global[((oc_block_c7 + 28))] = (conv2d_NCHWc_global[((oc_block_c7 + 28))] + (((float*)data_pad)[((((((((i0_i1_fused_i2_fused1 % 112) * 1350) + (kh * 675)) + (ow_outer * 168)) + (kw * 3)) + ic_inner) + 42))] * ((float*)placeholder1)[(((((((i0_i1_fused_i2_fused1 / 112) * 108) + (kh * 36)) + (kw * 12)) + (ic_inner * 4)) + oc_block_c7))]));
            }
            for (int32_t oc_block_c8 = 0; oc_block_c8 < 4; ++oc_block_c8) {
              conv2d_NCHWc_global[((oc_block_c8 + 32))] = (conv2d_NCHWc_global[((oc_block_c8 + 32))] + (((float*)data_pad)[((((((((i0_i1_fused_i2_fused1 % 112) * 1350) + (kh * 675)) + (ow_outer * 168)) + (kw * 3)) + ic_inner) + 48))] * ((float*)placeholder1)[(((((((i0_i1_fused_i2_fused1 / 112) * 108) + (kh * 36)) + (kw * 12)) + (ic_inner * 4)) + oc_block_c8))]));
            }
            for (int32_t oc_block_c9 = 0; oc_block_c9 < 4; ++oc_block_c9) {
              conv2d_NCHWc_global[((oc_block_c9 + 36))] = (conv2d_NCHWc_global[((oc_block_c9 + 36))] + (((float*)data_pad)[((((((((i0_i1_fused_i2_fused1 % 112) * 1350) + (kh * 675)) + (ow_outer * 168)) + (kw * 3)) + ic_inner) + 54))] * ((float*)placeholder1)[(((((((i0_i1_fused_i2_fused1 / 112) * 108) + (kh * 36)) + (kw * 12)) + (ic_inner * 4)) + oc_block_c9))]));
            }
            for (int32_t oc_block_c10 = 0; oc_block_c10 < 4; ++oc_block_c10) {
              conv2d_NCHWc_global[((oc_block_c10 + 40))] = (conv2d_NCHWc_global[((oc_block_c10 + 40))] + (((float*)data_pad)[((((((((i0_i1_fused_i2_fused1 % 112) * 1350) + (kh * 675)) + (ow_outer * 168)) + (kw * 3)) + ic_inner) + 60))] * ((float*)placeholder1)[(((((((i0_i1_fused_i2_fused1 / 112) * 108) + (kh * 36)) + (kw * 12)) + (ic_inner * 4)) + oc_block_c10))]));
            }
            for (int32_t oc_block_c11 = 0; oc_block_c11 < 4; ++oc_block_c11) {
              conv2d_NCHWc_global[((oc_block_c11 + 44))] = (conv2d_NCHWc_global[((oc_block_c11 + 44))] + (((float*)data_pad)[((((((((i0_i1_fused_i2_fused1 % 112) * 1350) + (kh * 675)) + (ow_outer * 168)) + (kw * 3)) + ic_inner) + 66))] * ((float*)placeholder1)[(((((((i0_i1_fused_i2_fused1 / 112) * 108) + (kh * 36)) + (kw * 12)) + (ic_inner * 4)) + oc_block_c11))]));
            }
            for (int32_t oc_block_c12 = 0; oc_block_c12 < 4; ++oc_block_c12) {
              conv2d_NCHWc_global[((oc_block_c12 + 48))] = (conv2d_NCHWc_global[((oc_block_c12 + 48))] + (((float*)data_pad)[((((((((i0_i1_fused_i2_fused1 % 112) * 1350) + (kh * 675)) + (ow_outer * 168)) + (kw * 3)) + ic_inner) + 72))] * ((float*)placeholder1)[(((((((i0_i1_fused_i2_fused1 / 112) * 108) + (kh * 36)) + (kw * 12)) + (ic_inner * 4)) + oc_block_c12))]));
            }
            for (int32_t oc_block_c13 = 0; oc_block_c13 < 4; ++oc_block_c13) {
              conv2d_NCHWc_global[((oc_block_c13 + 52))] = (conv2d_NCHWc_global[((oc_block_c13 + 52))] + (((float*)data_pad)[((((((((i0_i1_fused_i2_fused1 % 112) * 1350) + (kh * 675)) + (ow_outer * 168)) + (kw * 3)) + ic_inner) + 78))] * ((float*)placeholder1)[(((((((i0_i1_fused_i2_fused1 / 112) * 108) + (kh * 36)) + (kw * 12)) + (ic_inner * 4)) + oc_block_c13))]));
            }
            for (int32_t oc_block_c14 = 0; oc_block_c14 < 4; ++oc_block_c14) {
              conv2d_NCHWc_global[((oc_block_c14 + 56))] = (conv2d_NCHWc_global[((oc_block_c14 + 56))] + (((float*)data_pad)[((((((((i0_i1_fused_i2_fused1 % 112) * 1350) + (kh * 675)) + (ow_outer * 168)) + (kw * 3)) + ic_inner) + 84))] * ((float*)placeholder1)[(((((((i0_i1_fused_i2_fused1 / 112) * 108) + (kh * 36)) + (kw * 12)) + (ic_inner * 4)) + oc_block_c14))]));
            }
            for (int32_t oc_block_c15 = 0; oc_block_c15 < 4; ++oc_block_c15) {
              conv2d_NCHWc_global[((oc_block_c15 + 60))] = (conv2d_NCHWc_global[((oc_block_c15 + 60))] + (((float*)data_pad)[((((((((i0_i1_fused_i2_fused1 % 112) * 1350) + (kh * 675)) + (ow_outer * 168)) + (kw * 3)) + ic_inner) + 90))] * ((float*)placeholder1)[(((((((i0_i1_fused_i2_fused1 / 112) * 108) + (kh * 36)) + (kw * 12)) + (ic_inner * 4)) + oc_block_c15))]));
            }
            for (int32_t oc_block_c16 = 0; oc_block_c16 < 4; ++oc_block_c16) {
              conv2d_NCHWc_global[((oc_block_c16 + 64))] = (conv2d_NCHWc_global[((oc_block_c16 + 64))] + (((float*)data_pad)[((((((((i0_i1_fused_i2_fused1 % 112) * 1350) + (kh * 675)) + (ow_outer * 168)) + (kw * 3)) + ic_inner) + 96))] * ((float*)placeholder1)[(((((((i0_i1_fused_i2_fused1 / 112) * 108) + (kh * 36)) + (kw * 12)) + (ic_inner * 4)) + oc_block_c16))]));
            }
            for (int32_t oc_block_c17 = 0; oc_block_c17 < 4; ++oc_block_c17) {
              conv2d_NCHWc_global[((oc_block_c17 + 68))] = (conv2d_NCHWc_global[((oc_block_c17 + 68))] + (((float*)data_pad)[((((((((i0_i1_fused_i2_fused1 % 112) * 1350) + (kh * 675)) + (ow_outer * 168)) + (kw * 3)) + ic_inner) + 102))] * ((float*)placeholder1)[(((((((i0_i1_fused_i2_fused1 / 112) * 108) + (kh * 36)) + (kw * 12)) + (ic_inner * 4)) + oc_block_c17))]));
            }
            for (int32_t oc_block_c18 = 0; oc_block_c18 < 4; ++oc_block_c18) {
              conv2d_NCHWc_global[((oc_block_c18 + 72))] = (conv2d_NCHWc_global[((oc_block_c18 + 72))] + (((float*)data_pad)[((((((((i0_i1_fused_i2_fused1 % 112) * 1350) + (kh * 675)) + (ow_outer * 168)) + (kw * 3)) + ic_inner) + 108))] * ((float*)placeholder1)[(((((((i0_i1_fused_i2_fused1 / 112) * 108) + (kh * 36)) + (kw * 12)) + (ic_inner * 4)) + oc_block_c18))]));
            }
            for (int32_t oc_block_c19 = 0; oc_block_c19 < 4; ++oc_block_c19) {
              conv2d_NCHWc_global[((oc_block_c19 + 76))] = (conv2d_NCHWc_global[((oc_block_c19 + 76))] + (((float*)data_pad)[((((((((i0_i1_fused_i2_fused1 % 112) * 1350) + (kh * 675)) + (ow_outer * 168)) + (kw * 3)) + ic_inner) + 114))] * ((float*)placeholder1)[(((((((i0_i1_fused_i2_fused1 / 112) * 108) + (kh * 36)) + (kw * 12)) + (ic_inner * 4)) + oc_block_c19))]));
            }
            for (int32_t oc_block_c20 = 0; oc_block_c20 < 4; ++oc_block_c20) {
              conv2d_NCHWc_global[((oc_block_c20 + 80))] = (conv2d_NCHWc_global[((oc_block_c20 + 80))] + (((float*)data_pad)[((((((((i0_i1_fused_i2_fused1 % 112) * 1350) + (kh * 675)) + (ow_outer * 168)) + (kw * 3)) + ic_inner) + 120))] * ((float*)placeholder1)[(((((((i0_i1_fused_i2_fused1 / 112) * 108) + (kh * 36)) + (kw * 12)) + (ic_inner * 4)) + oc_block_c20))]));
            }
            for (int32_t oc_block_c21 = 0; oc_block_c21 < 4; ++oc_block_c21) {
              conv2d_NCHWc_global[((oc_block_c21 + 84))] = (conv2d_NCHWc_global[((oc_block_c21 + 84))] + (((float*)data_pad)[((((((((i0_i1_fused_i2_fused1 % 112) * 1350) + (kh * 675)) + (ow_outer * 168)) + (kw * 3)) + ic_inner) + 126))] * ((float*)placeholder1)[(((((((i0_i1_fused_i2_fused1 / 112) * 108) + (kh * 36)) + (kw * 12)) + (ic_inner * 4)) + oc_block_c21))]));
            }
            for (int32_t oc_block_c22 = 0; oc_block_c22 < 4; ++oc_block_c22) {
              conv2d_NCHWc_global[((oc_block_c22 + 88))] = (conv2d_NCHWc_global[((oc_block_c22 + 88))] + (((float*)data_pad)[((((((((i0_i1_fused_i2_fused1 % 112) * 1350) + (kh * 675)) + (ow_outer * 168)) + (kw * 3)) + ic_inner) + 132))] * ((float*)placeholder1)[(((((((i0_i1_fused_i2_fused1 / 112) * 108) + (kh * 36)) + (kw * 12)) + (ic_inner * 4)) + oc_block_c22))]));
            }
            for (int32_t oc_block_c23 = 0; oc_block_c23 < 4; ++oc_block_c23) {
              conv2d_NCHWc_global[((oc_block_c23 + 92))] = (conv2d_NCHWc_global[((oc_block_c23 + 92))] + (((float*)data_pad)[((((((((i0_i1_fused_i2_fused1 % 112) * 1350) + (kh * 675)) + (ow_outer * 168)) + (kw * 3)) + ic_inner) + 138))] * ((float*)placeholder1)[(((((((i0_i1_fused_i2_fused1 / 112) * 108) + (kh * 36)) + (kw * 12)) + (ic_inner * 4)) + oc_block_c23))]));
            }
            for (int32_t oc_block_c24 = 0; oc_block_c24 < 4; ++oc_block_c24) {
              conv2d_NCHWc_global[((oc_block_c24 + 96))] = (conv2d_NCHWc_global[((oc_block_c24 + 96))] + (((float*)data_pad)[((((((((i0_i1_fused_i2_fused1 % 112) * 1350) + (kh * 675)) + (ow_outer * 168)) + (kw * 3)) + ic_inner) + 144))] * ((float*)placeholder1)[(((((((i0_i1_fused_i2_fused1 / 112) * 108) + (kh * 36)) + (kw * 12)) + (ic_inner * 4)) + oc_block_c24))]));
            }
            for (int32_t oc_block_c25 = 0; oc_block_c25 < 4; ++oc_block_c25) {
              conv2d_NCHWc_global[((oc_block_c25 + 100))] = (conv2d_NCHWc_global[((oc_block_c25 + 100))] + (((float*)data_pad)[((((((((i0_i1_fused_i2_fused1 % 112) * 1350) + (kh * 675)) + (ow_outer * 168)) + (kw * 3)) + ic_inner) + 150))] * ((float*)placeholder1)[(((((((i0_i1_fused_i2_fused1 / 112) * 108) + (kh * 36)) + (kw * 12)) + (ic_inner * 4)) + oc_block_c25))]));
            }
            for (int32_t oc_block_c26 = 0; oc_block_c26 < 4; ++oc_block_c26) {
              conv2d_NCHWc_global[((oc_block_c26 + 104))] = (conv2d_NCHWc_global[((oc_block_c26 + 104))] + (((float*)data_pad)[((((((((i0_i1_fused_i2_fused1 % 112) * 1350) + (kh * 675)) + (ow_outer * 168)) + (kw * 3)) + ic_inner) + 156))] * ((float*)placeholder1)[(((((((i0_i1_fused_i2_fused1 / 112) * 108) + (kh * 36)) + (kw * 12)) + (ic_inner * 4)) + oc_block_c26))]));
            }
            for (int32_t oc_block_c27 = 0; oc_block_c27 < 4; ++oc_block_c27) {
              conv2d_NCHWc_global[((oc_block_c27 + 108))] = (conv2d_NCHWc_global[((oc_block_c27 + 108))] + (((float*)data_pad)[((((((((i0_i1_fused_i2_fused1 % 112) * 1350) + (kh * 675)) + (ow_outer * 168)) + (kw * 3)) + ic_inner) + 162))] * ((float*)placeholder1)[(((((((i0_i1_fused_i2_fused1 / 112) * 108) + (kh * 36)) + (kw * 12)) + (ic_inner * 4)) + oc_block_c27))]));
            }
          }
        }
      }
      for (int32_t ow_inner = 0; ow_inner < 28; ++ow_inner) {
        for (int32_t oc_block = 0; oc_block < 4; ++oc_block) {
          ((float*)conv2d_NCHWc)[((((ow_outer * 112) + (ow_inner * 4)) + oc_block))] = conv2d_NCHWc_global[(((ow_inner * 4) + oc_block))];
        }
      }
    }
    for (int32_t i3_outer = 0; i3_outer < 4; ++i3_outer) {
      for (int32_t i3_inner = 0; i3_inner < 28; ++i3_inner) {
        for (int32_t i41 = 0; i41 < 4; ++i41) {
          float _1 = ((float*)conv2d_NCHWc)[((((i3_outer * 112) + (i3_inner * 4)) + i41))] + ((float*)placeholder2)[((((i0_i1_fused_i2_fused1 / 112) * 4) + i41))];
          float _2 = (_1) < (6.000000e+00f) ? (_1) : (6.000000e+00f);
          ((float*)compute)[(((((i0_i1_fused_i2_fused1 * 448) + (i3_outer * 112)) + (i3_inner * 4)) + i41))] = ((_2) > (0.000000e+00f) ? (_2) : (0.000000e+00f));
        }
      }
    }
    if (TVMBackendFreeWorkspace(1, dev_id, conv2d_NCHWc) != 0) {
      return -1;
    }
  }
  if (TVMBackendFreeWorkspace(1, dev_id, data_pad) != 0) {
    return -1;
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_contrib_conv2d_NCHWc_add_3(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int32_t arg2_code = ((int32_t*)arg_type_ids)[(2)];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int32_t arg3_code = ((int32_t*)arg_type_ids)[(3)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* placeholder1 = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  void* placeholder2 = (((DLTensor*)arg2)[0].data);
  void* arg2_shape = (((DLTensor*)arg2)[0].shape);
  void* arg2_strides = (((DLTensor*)arg2)[0].strides);
  void* T_add = (((DLTensor*)arg3)[0].data);
  void* arg3_shape = (((DLTensor*)arg3)[0].shape);
  void* arg3_strides = (((DLTensor*)arg3)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  if (!(arg2_strides == NULL)) {
  }
  if (!(arg3_strides == NULL)) {
  }
  for (int32_t ax0_ax1_fused_ax2_outer_fused = 0; ax0_ax1_fused_ax2_outer_fused < 168; ++ax0_ax1_fused_ax2_outer_fused) {
    float conv2d_NCHWc_global[112];
    for (int32_t oc_block_c_init = 0; oc_block_c_init < 4; ++oc_block_c_init) {
      conv2d_NCHWc_global[(oc_block_c_init)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init1 = 0; oc_block_c_init1 < 4; ++oc_block_c_init1) {
      conv2d_NCHWc_global[((oc_block_c_init1 + 4))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init2 = 0; oc_block_c_init2 < 4; ++oc_block_c_init2) {
      conv2d_NCHWc_global[((oc_block_c_init2 + 8))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init3 = 0; oc_block_c_init3 < 4; ++oc_block_c_init3) {
      conv2d_NCHWc_global[((oc_block_c_init3 + 12))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init4 = 0; oc_block_c_init4 < 4; ++oc_block_c_init4) {
      conv2d_NCHWc_global[((oc_block_c_init4 + 16))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init5 = 0; oc_block_c_init5 < 4; ++oc_block_c_init5) {
      conv2d_NCHWc_global[((oc_block_c_init5 + 20))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init6 = 0; oc_block_c_init6 < 4; ++oc_block_c_init6) {
      conv2d_NCHWc_global[((oc_block_c_init6 + 24))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init7 = 0; oc_block_c_init7 < 4; ++oc_block_c_init7) {
      conv2d_NCHWc_global[((oc_block_c_init7 + 28))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init8 = 0; oc_block_c_init8 < 4; ++oc_block_c_init8) {
      conv2d_NCHWc_global[((oc_block_c_init8 + 32))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init9 = 0; oc_block_c_init9 < 4; ++oc_block_c_init9) {
      conv2d_NCHWc_global[((oc_block_c_init9 + 36))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init10 = 0; oc_block_c_init10 < 4; ++oc_block_c_init10) {
      conv2d_NCHWc_global[((oc_block_c_init10 + 40))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init11 = 0; oc_block_c_init11 < 4; ++oc_block_c_init11) {
      conv2d_NCHWc_global[((oc_block_c_init11 + 44))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init12 = 0; oc_block_c_init12 < 4; ++oc_block_c_init12) {
      conv2d_NCHWc_global[((oc_block_c_init12 + 48))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init13 = 0; oc_block_c_init13 < 4; ++oc_block_c_init13) {
      conv2d_NCHWc_global[((oc_block_c_init13 + 52))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init14 = 0; oc_block_c_init14 < 4; ++oc_block_c_init14) {
      conv2d_NCHWc_global[((oc_block_c_init14 + 56))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init15 = 0; oc_block_c_init15 < 4; ++oc_block_c_init15) {
      conv2d_NCHWc_global[((oc_block_c_init15 + 60))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init16 = 0; oc_block_c_init16 < 4; ++oc_block_c_init16) {
      conv2d_NCHWc_global[((oc_block_c_init16 + 64))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init17 = 0; oc_block_c_init17 < 4; ++oc_block_c_init17) {
      conv2d_NCHWc_global[((oc_block_c_init17 + 68))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init18 = 0; oc_block_c_init18 < 4; ++oc_block_c_init18) {
      conv2d_NCHWc_global[((oc_block_c_init18 + 72))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init19 = 0; oc_block_c_init19 < 4; ++oc_block_c_init19) {
      conv2d_NCHWc_global[((oc_block_c_init19 + 76))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init20 = 0; oc_block_c_init20 < 4; ++oc_block_c_init20) {
      conv2d_NCHWc_global[((oc_block_c_init20 + 80))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init21 = 0; oc_block_c_init21 < 4; ++oc_block_c_init21) {
      conv2d_NCHWc_global[((oc_block_c_init21 + 84))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init22 = 0; oc_block_c_init22 < 4; ++oc_block_c_init22) {
      conv2d_NCHWc_global[((oc_block_c_init22 + 88))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init23 = 0; oc_block_c_init23 < 4; ++oc_block_c_init23) {
      conv2d_NCHWc_global[((oc_block_c_init23 + 92))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init24 = 0; oc_block_c_init24 < 4; ++oc_block_c_init24) {
      conv2d_NCHWc_global[((oc_block_c_init24 + 96))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init25 = 0; oc_block_c_init25 < 4; ++oc_block_c_init25) {
      conv2d_NCHWc_global[((oc_block_c_init25 + 100))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init26 = 0; oc_block_c_init26 < 4; ++oc_block_c_init26) {
      conv2d_NCHWc_global[((oc_block_c_init26 + 104))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init27 = 0; oc_block_c_init27 < 4; ++oc_block_c_init27) {
      conv2d_NCHWc_global[((oc_block_c_init27 + 108))] = 0.000000e+00f;
    }
    for (int32_t ic_outer = 0; ic_outer < 96; ++ic_outer) {
      for (int32_t ic_inner = 0; ic_inner < 4; ++ic_inner) {
        for (int32_t oc_block_c = 0; oc_block_c < 4; ++oc_block_c) {
          conv2d_NCHWc_global[(oc_block_c)] = (conv2d_NCHWc_global[(oc_block_c)] + (((float*)placeholder)[((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c))]));
        }
        for (int32_t oc_block_c1 = 0; oc_block_c1 < 4; ++oc_block_c1) {
          conv2d_NCHWc_global[((oc_block_c1 + 4))] = (conv2d_NCHWc_global[((oc_block_c1 + 4))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 4))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c1))]));
        }
        for (int32_t oc_block_c2 = 0; oc_block_c2 < 4; ++oc_block_c2) {
          conv2d_NCHWc_global[((oc_block_c2 + 8))] = (conv2d_NCHWc_global[((oc_block_c2 + 8))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 8))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c2))]));
        }
        for (int32_t oc_block_c3 = 0; oc_block_c3 < 4; ++oc_block_c3) {
          conv2d_NCHWc_global[((oc_block_c3 + 12))] = (conv2d_NCHWc_global[((oc_block_c3 + 12))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 12))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c3))]));
        }
        for (int32_t oc_block_c4 = 0; oc_block_c4 < 4; ++oc_block_c4) {
          conv2d_NCHWc_global[((oc_block_c4 + 16))] = (conv2d_NCHWc_global[((oc_block_c4 + 16))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 16))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c4))]));
        }
        for (int32_t oc_block_c5 = 0; oc_block_c5 < 4; ++oc_block_c5) {
          conv2d_NCHWc_global[((oc_block_c5 + 20))] = (conv2d_NCHWc_global[((oc_block_c5 + 20))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 20))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c5))]));
        }
        for (int32_t oc_block_c6 = 0; oc_block_c6 < 4; ++oc_block_c6) {
          conv2d_NCHWc_global[((oc_block_c6 + 24))] = (conv2d_NCHWc_global[((oc_block_c6 + 24))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 24))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c6))]));
        }
        for (int32_t oc_block_c7 = 0; oc_block_c7 < 4; ++oc_block_c7) {
          conv2d_NCHWc_global[((oc_block_c7 + 28))] = (conv2d_NCHWc_global[((oc_block_c7 + 28))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 28))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c7))]));
        }
        for (int32_t oc_block_c8 = 0; oc_block_c8 < 4; ++oc_block_c8) {
          conv2d_NCHWc_global[((oc_block_c8 + 32))] = (conv2d_NCHWc_global[((oc_block_c8 + 32))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 32))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c8))]));
        }
        for (int32_t oc_block_c9 = 0; oc_block_c9 < 4; ++oc_block_c9) {
          conv2d_NCHWc_global[((oc_block_c9 + 36))] = (conv2d_NCHWc_global[((oc_block_c9 + 36))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 36))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c9))]));
        }
        for (int32_t oc_block_c10 = 0; oc_block_c10 < 4; ++oc_block_c10) {
          conv2d_NCHWc_global[((oc_block_c10 + 40))] = (conv2d_NCHWc_global[((oc_block_c10 + 40))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 40))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c10))]));
        }
        for (int32_t oc_block_c11 = 0; oc_block_c11 < 4; ++oc_block_c11) {
          conv2d_NCHWc_global[((oc_block_c11 + 44))] = (conv2d_NCHWc_global[((oc_block_c11 + 44))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 44))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c11))]));
        }
        for (int32_t oc_block_c12 = 0; oc_block_c12 < 4; ++oc_block_c12) {
          conv2d_NCHWc_global[((oc_block_c12 + 48))] = (conv2d_NCHWc_global[((oc_block_c12 + 48))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 48))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c12))]));
        }
        for (int32_t oc_block_c13 = 0; oc_block_c13 < 4; ++oc_block_c13) {
          conv2d_NCHWc_global[((oc_block_c13 + 52))] = (conv2d_NCHWc_global[((oc_block_c13 + 52))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 52))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c13))]));
        }
        for (int32_t oc_block_c14 = 0; oc_block_c14 < 4; ++oc_block_c14) {
          conv2d_NCHWc_global[((oc_block_c14 + 56))] = (conv2d_NCHWc_global[((oc_block_c14 + 56))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 56))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c14))]));
        }
        for (int32_t oc_block_c15 = 0; oc_block_c15 < 4; ++oc_block_c15) {
          conv2d_NCHWc_global[((oc_block_c15 + 60))] = (conv2d_NCHWc_global[((oc_block_c15 + 60))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 60))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c15))]));
        }
        for (int32_t oc_block_c16 = 0; oc_block_c16 < 4; ++oc_block_c16) {
          conv2d_NCHWc_global[((oc_block_c16 + 64))] = (conv2d_NCHWc_global[((oc_block_c16 + 64))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 64))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c16))]));
        }
        for (int32_t oc_block_c17 = 0; oc_block_c17 < 4; ++oc_block_c17) {
          conv2d_NCHWc_global[((oc_block_c17 + 68))] = (conv2d_NCHWc_global[((oc_block_c17 + 68))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 68))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c17))]));
        }
        for (int32_t oc_block_c18 = 0; oc_block_c18 < 4; ++oc_block_c18) {
          conv2d_NCHWc_global[((oc_block_c18 + 72))] = (conv2d_NCHWc_global[((oc_block_c18 + 72))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 72))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c18))]));
        }
        for (int32_t oc_block_c19 = 0; oc_block_c19 < 4; ++oc_block_c19) {
          conv2d_NCHWc_global[((oc_block_c19 + 76))] = (conv2d_NCHWc_global[((oc_block_c19 + 76))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 76))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c19))]));
        }
        for (int32_t oc_block_c20 = 0; oc_block_c20 < 4; ++oc_block_c20) {
          conv2d_NCHWc_global[((oc_block_c20 + 80))] = (conv2d_NCHWc_global[((oc_block_c20 + 80))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 80))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c20))]));
        }
        for (int32_t oc_block_c21 = 0; oc_block_c21 < 4; ++oc_block_c21) {
          conv2d_NCHWc_global[((oc_block_c21 + 84))] = (conv2d_NCHWc_global[((oc_block_c21 + 84))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 84))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c21))]));
        }
        for (int32_t oc_block_c22 = 0; oc_block_c22 < 4; ++oc_block_c22) {
          conv2d_NCHWc_global[((oc_block_c22 + 88))] = (conv2d_NCHWc_global[((oc_block_c22 + 88))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 88))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c22))]));
        }
        for (int32_t oc_block_c23 = 0; oc_block_c23 < 4; ++oc_block_c23) {
          conv2d_NCHWc_global[((oc_block_c23 + 92))] = (conv2d_NCHWc_global[((oc_block_c23 + 92))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 92))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c23))]));
        }
        for (int32_t oc_block_c24 = 0; oc_block_c24 < 4; ++oc_block_c24) {
          conv2d_NCHWc_global[((oc_block_c24 + 96))] = (conv2d_NCHWc_global[((oc_block_c24 + 96))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 96))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c24))]));
        }
        for (int32_t oc_block_c25 = 0; oc_block_c25 < 4; ++oc_block_c25) {
          conv2d_NCHWc_global[((oc_block_c25 + 100))] = (conv2d_NCHWc_global[((oc_block_c25 + 100))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 100))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c25))]));
        }
        for (int32_t oc_block_c26 = 0; oc_block_c26 < 4; ++oc_block_c26) {
          conv2d_NCHWc_global[((oc_block_c26 + 104))] = (conv2d_NCHWc_global[((oc_block_c26 + 104))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 104))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c26))]));
        }
        for (int32_t oc_block_c27 = 0; oc_block_c27 < 4; ++oc_block_c27) {
          conv2d_NCHWc_global[((oc_block_c27 + 108))] = (conv2d_NCHWc_global[((oc_block_c27 + 108))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 108))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c27))]));
        }
      }
    }
    for (int32_t ax2_inner = 0; ax2_inner < 2; ++ax2_inner) {
      for (int32_t ax3_inner = 0; ax3_inner < 14; ++ax3_inner) {
        for (int32_t ax4 = 0; ax4 < 4; ++ax4) {
          ((float*)T_add)[(((((ax0_ax1_fused_ax2_outer_fused * 112) + (ax2_inner * 56)) + (ax3_inner * 4)) + ax4))] = (conv2d_NCHWc_global[((((ax2_inner * 56) + (ax3_inner * 4)) + ax4))] + ((float*)placeholder2)[((((ax0_ax1_fused_ax2_outer_fused / 7) * 4) + ax4))]);
        }
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_contrib_depthwise_conv2d_NCHWc_add_clip_3(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int32_t arg2_code = ((int32_t*)arg_type_ids)[(2)];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int32_t arg3_code = ((int32_t*)arg_type_ids)[(3)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* placeholder1 = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  void* placeholder2 = (((DLTensor*)arg2)[0].data);
  void* arg2_shape = (((DLTensor*)arg2)[0].shape);
  void* arg2_strides = (((DLTensor*)arg2)[0].strides);
  void* compute = (((DLTensor*)arg3)[0].data);
  void* arg3_shape = (((DLTensor*)arg3)[0].shape);
  void* arg3_strides = (((DLTensor*)arg3)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  if (!(arg2_strides == NULL)) {
  }
  if (!(arg3_strides == NULL)) {
  }
  void* PaddedInput = TVMBackendAllocWorkspace(1, dev_id, (uint64_t)393216, 2, 32);
  if (PaddedInput == NULL) {
    return -1;
  }
  for (int32_t i0_i1_fused_i2_fused = 0; i0_i1_fused_i2_fused < 1536; ++i0_i1_fused_i2_fused) {
    for (int32_t i3 = 0; i3 < 16; ++i3) {
      for (int32_t i4 = 0; i4 < 4; ++i4) {
        ((float*)PaddedInput)[((((i0_i1_fused_i2_fused * 64) + (i3 * 4)) + i4))] = (((((1 <= (i0_i1_fused_i2_fused & 15)) && ((i0_i1_fused_i2_fused & 15) < 15)) && (1 <= i3)) && (i3 < 15)) ? ((float*)placeholder)[(((((((i0_i1_fused_i2_fused >> 4) * 784) + ((i0_i1_fused_i2_fused & 15) * 56)) + (i3 * 4)) + i4) - 60))] : 0.000000e+00f);
      }
    }
  }
  for (int32_t i1_i2_fused = 0; i1_i2_fused < 1344; ++i1_i2_fused) {
    float DepthwiseConv2d_global[56];
    for (int32_t oci_c_init = 0; oci_c_init < 4; ++oci_c_init) {
      DepthwiseConv2d_global[(oci_c_init)] = 0.000000e+00f;
    }
    for (int32_t oci_c_init1 = 0; oci_c_init1 < 4; ++oci_c_init1) {
      DepthwiseConv2d_global[((oci_c_init1 + 4))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init2 = 0; oci_c_init2 < 4; ++oci_c_init2) {
      DepthwiseConv2d_global[((oci_c_init2 + 8))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init3 = 0; oci_c_init3 < 4; ++oci_c_init3) {
      DepthwiseConv2d_global[((oci_c_init3 + 12))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init4 = 0; oci_c_init4 < 4; ++oci_c_init4) {
      DepthwiseConv2d_global[((oci_c_init4 + 16))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init5 = 0; oci_c_init5 < 4; ++oci_c_init5) {
      DepthwiseConv2d_global[((oci_c_init5 + 20))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init6 = 0; oci_c_init6 < 4; ++oci_c_init6) {
      DepthwiseConv2d_global[((oci_c_init6 + 24))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init7 = 0; oci_c_init7 < 4; ++oci_c_init7) {
      DepthwiseConv2d_global[((oci_c_init7 + 28))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init8 = 0; oci_c_init8 < 4; ++oci_c_init8) {
      DepthwiseConv2d_global[((oci_c_init8 + 32))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init9 = 0; oci_c_init9 < 4; ++oci_c_init9) {
      DepthwiseConv2d_global[((oci_c_init9 + 36))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init10 = 0; oci_c_init10 < 4; ++oci_c_init10) {
      DepthwiseConv2d_global[((oci_c_init10 + 40))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init11 = 0; oci_c_init11 < 4; ++oci_c_init11) {
      DepthwiseConv2d_global[((oci_c_init11 + 44))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init12 = 0; oci_c_init12 < 4; ++oci_c_init12) {
      DepthwiseConv2d_global[((oci_c_init12 + 48))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init13 = 0; oci_c_init13 < 4; ++oci_c_init13) {
      DepthwiseConv2d_global[((oci_c_init13 + 52))] = 0.000000e+00f;
    }
    for (int32_t kh = 0; kh < 3; ++kh) {
      for (int32_t kw = 0; kw < 3; ++kw) {
        for (int32_t oci_c = 0; oci_c < 4; ++oci_c) {
          DepthwiseConv2d_global[(oci_c)] = (DepthwiseConv2d_global[(oci_c)] + (((float*)PaddedInput)[(((((((i1_i2_fused / 14) * 1024) + (kh * 64)) + ((i1_i2_fused % 14) * 64)) + (kw * 4)) + oci_c))] * ((float*)placeholder1)[((((((i1_i2_fused / 14) * 36) + (kh * 12)) + (kw * 4)) + oci_c))]));
        }
        for (int32_t oci_c1 = 0; oci_c1 < 4; ++oci_c1) {
          DepthwiseConv2d_global[((oci_c1 + 4))] = (DepthwiseConv2d_global[((oci_c1 + 4))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 14) * 1024) + (kh * 64)) + ((i1_i2_fused % 14) * 64)) + (kw * 4)) + oci_c1) + 4))] * ((float*)placeholder1)[((((((i1_i2_fused / 14) * 36) + (kh * 12)) + (kw * 4)) + oci_c1))]));
        }
        for (int32_t oci_c2 = 0; oci_c2 < 4; ++oci_c2) {
          DepthwiseConv2d_global[((oci_c2 + 8))] = (DepthwiseConv2d_global[((oci_c2 + 8))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 14) * 1024) + (kh * 64)) + ((i1_i2_fused % 14) * 64)) + (kw * 4)) + oci_c2) + 8))] * ((float*)placeholder1)[((((((i1_i2_fused / 14) * 36) + (kh * 12)) + (kw * 4)) + oci_c2))]));
        }
        for (int32_t oci_c3 = 0; oci_c3 < 4; ++oci_c3) {
          DepthwiseConv2d_global[((oci_c3 + 12))] = (DepthwiseConv2d_global[((oci_c3 + 12))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 14) * 1024) + (kh * 64)) + ((i1_i2_fused % 14) * 64)) + (kw * 4)) + oci_c3) + 12))] * ((float*)placeholder1)[((((((i1_i2_fused / 14) * 36) + (kh * 12)) + (kw * 4)) + oci_c3))]));
        }
        for (int32_t oci_c4 = 0; oci_c4 < 4; ++oci_c4) {
          DepthwiseConv2d_global[((oci_c4 + 16))] = (DepthwiseConv2d_global[((oci_c4 + 16))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 14) * 1024) + (kh * 64)) + ((i1_i2_fused % 14) * 64)) + (kw * 4)) + oci_c4) + 16))] * ((float*)placeholder1)[((((((i1_i2_fused / 14) * 36) + (kh * 12)) + (kw * 4)) + oci_c4))]));
        }
        for (int32_t oci_c5 = 0; oci_c5 < 4; ++oci_c5) {
          DepthwiseConv2d_global[((oci_c5 + 20))] = (DepthwiseConv2d_global[((oci_c5 + 20))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 14) * 1024) + (kh * 64)) + ((i1_i2_fused % 14) * 64)) + (kw * 4)) + oci_c5) + 20))] * ((float*)placeholder1)[((((((i1_i2_fused / 14) * 36) + (kh * 12)) + (kw * 4)) + oci_c5))]));
        }
        for (int32_t oci_c6 = 0; oci_c6 < 4; ++oci_c6) {
          DepthwiseConv2d_global[((oci_c6 + 24))] = (DepthwiseConv2d_global[((oci_c6 + 24))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 14) * 1024) + (kh * 64)) + ((i1_i2_fused % 14) * 64)) + (kw * 4)) + oci_c6) + 24))] * ((float*)placeholder1)[((((((i1_i2_fused / 14) * 36) + (kh * 12)) + (kw * 4)) + oci_c6))]));
        }
        for (int32_t oci_c7 = 0; oci_c7 < 4; ++oci_c7) {
          DepthwiseConv2d_global[((oci_c7 + 28))] = (DepthwiseConv2d_global[((oci_c7 + 28))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 14) * 1024) + (kh * 64)) + ((i1_i2_fused % 14) * 64)) + (kw * 4)) + oci_c7) + 28))] * ((float*)placeholder1)[((((((i1_i2_fused / 14) * 36) + (kh * 12)) + (kw * 4)) + oci_c7))]));
        }
        for (int32_t oci_c8 = 0; oci_c8 < 4; ++oci_c8) {
          DepthwiseConv2d_global[((oci_c8 + 32))] = (DepthwiseConv2d_global[((oci_c8 + 32))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 14) * 1024) + (kh * 64)) + ((i1_i2_fused % 14) * 64)) + (kw * 4)) + oci_c8) + 32))] * ((float*)placeholder1)[((((((i1_i2_fused / 14) * 36) + (kh * 12)) + (kw * 4)) + oci_c8))]));
        }
        for (int32_t oci_c9 = 0; oci_c9 < 4; ++oci_c9) {
          DepthwiseConv2d_global[((oci_c9 + 36))] = (DepthwiseConv2d_global[((oci_c9 + 36))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 14) * 1024) + (kh * 64)) + ((i1_i2_fused % 14) * 64)) + (kw * 4)) + oci_c9) + 36))] * ((float*)placeholder1)[((((((i1_i2_fused / 14) * 36) + (kh * 12)) + (kw * 4)) + oci_c9))]));
        }
        for (int32_t oci_c10 = 0; oci_c10 < 4; ++oci_c10) {
          DepthwiseConv2d_global[((oci_c10 + 40))] = (DepthwiseConv2d_global[((oci_c10 + 40))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 14) * 1024) + (kh * 64)) + ((i1_i2_fused % 14) * 64)) + (kw * 4)) + oci_c10) + 40))] * ((float*)placeholder1)[((((((i1_i2_fused / 14) * 36) + (kh * 12)) + (kw * 4)) + oci_c10))]));
        }
        for (int32_t oci_c11 = 0; oci_c11 < 4; ++oci_c11) {
          DepthwiseConv2d_global[((oci_c11 + 44))] = (DepthwiseConv2d_global[((oci_c11 + 44))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 14) * 1024) + (kh * 64)) + ((i1_i2_fused % 14) * 64)) + (kw * 4)) + oci_c11) + 44))] * ((float*)placeholder1)[((((((i1_i2_fused / 14) * 36) + (kh * 12)) + (kw * 4)) + oci_c11))]));
        }
        for (int32_t oci_c12 = 0; oci_c12 < 4; ++oci_c12) {
          DepthwiseConv2d_global[((oci_c12 + 48))] = (DepthwiseConv2d_global[((oci_c12 + 48))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 14) * 1024) + (kh * 64)) + ((i1_i2_fused % 14) * 64)) + (kw * 4)) + oci_c12) + 48))] * ((float*)placeholder1)[((((((i1_i2_fused / 14) * 36) + (kh * 12)) + (kw * 4)) + oci_c12))]));
        }
        for (int32_t oci_c13 = 0; oci_c13 < 4; ++oci_c13) {
          DepthwiseConv2d_global[((oci_c13 + 52))] = (DepthwiseConv2d_global[((oci_c13 + 52))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 14) * 1024) + (kh * 64)) + ((i1_i2_fused % 14) * 64)) + (kw * 4)) + oci_c13) + 52))] * ((float*)placeholder1)[((((((i1_i2_fused / 14) * 36) + (kh * 12)) + (kw * 4)) + oci_c13))]));
        }
      }
    }
    for (int32_t i3_inner = 0; i3_inner < 14; ++i3_inner) {
      for (int32_t i41 = 0; i41 < 4; ++i41) {
        float _1 = DepthwiseConv2d_global[(((i3_inner * 4) + i41))] + ((float*)placeholder2)[((((i1_i2_fused / 14) * 4) + i41))];
        float _2 = (_1) < (6.000000e+00f) ? (_1) : (6.000000e+00f);
        ((float*)compute)[((((i1_i2_fused * 56) + (i3_inner * 4)) + i41))] = ((_2) > (0.000000e+00f) ? (_2) : (0.000000e+00f));
      }
    }
  }
  if (TVMBackendFreeWorkspace(1, dev_id, PaddedInput) != 0) {
    return -1;
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_contrib_depthwise_conv2d_NCHWc_add_clip_1(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int32_t arg2_code = ((int32_t*)arg_type_ids)[(2)];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int32_t arg3_code = ((int32_t*)arg_type_ids)[(3)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* placeholder1 = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  void* placeholder2 = (((DLTensor*)arg2)[0].data);
  void* arg2_shape = (((DLTensor*)arg2)[0].shape);
  void* arg2_strides = (((DLTensor*)arg2)[0].strides);
  void* compute = (((DLTensor*)arg3)[0].data);
  void* arg3_shape = (((DLTensor*)arg3)[0].shape);
  void* arg3_strides = (((DLTensor*)arg3)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  if (!(arg2_strides == NULL)) {
  }
  if (!(arg3_strides == NULL)) {
  }
  void* PaddedInput = TVMBackendAllocWorkspace(1, dev_id, (uint64_t)518400, 2, 32);
  if (PaddedInput == NULL) {
    return -1;
  }
  for (int32_t i0_i1_fused_i2_fused = 0; i0_i1_fused_i2_fused < 2160; ++i0_i1_fused_i2_fused) {
    for (int32_t i3 = 0; i3 < 15; ++i3) {
      for (int32_t i4 = 0; i4 < 4; ++i4) {
        ((float*)PaddedInput)[((((i0_i1_fused_i2_fused * 60) + (i3 * 4)) + i4))] = ((((i0_i1_fused_i2_fused % 15) < 14) && (i3 < 14)) ? ((float*)placeholder)[((((((i0_i1_fused_i2_fused / 15) * 784) + ((i0_i1_fused_i2_fused % 15) * 56)) + (i3 * 4)) + i4))] : 0.000000e+00f);
      }
    }
  }
  for (int32_t i1_i2_fused = 0; i1_i2_fused < 1008; ++i1_i2_fused) {
    float DepthwiseConv2d_global[28];
    for (int32_t oci_c_init = 0; oci_c_init < 4; ++oci_c_init) {
      DepthwiseConv2d_global[(oci_c_init)] = 0.000000e+00f;
    }
    for (int32_t oci_c_init1 = 0; oci_c_init1 < 4; ++oci_c_init1) {
      DepthwiseConv2d_global[((oci_c_init1 + 4))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init2 = 0; oci_c_init2 < 4; ++oci_c_init2) {
      DepthwiseConv2d_global[((oci_c_init2 + 8))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init3 = 0; oci_c_init3 < 4; ++oci_c_init3) {
      DepthwiseConv2d_global[((oci_c_init3 + 12))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init4 = 0; oci_c_init4 < 4; ++oci_c_init4) {
      DepthwiseConv2d_global[((oci_c_init4 + 16))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init5 = 0; oci_c_init5 < 4; ++oci_c_init5) {
      DepthwiseConv2d_global[((oci_c_init5 + 20))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init6 = 0; oci_c_init6 < 4; ++oci_c_init6) {
      DepthwiseConv2d_global[((oci_c_init6 + 24))] = 0.000000e+00f;
    }
    for (int32_t kh = 0; kh < 3; ++kh) {
      for (int32_t kw = 0; kw < 3; ++kw) {
        for (int32_t oci_c = 0; oci_c < 4; ++oci_c) {
          DepthwiseConv2d_global[(oci_c)] = (DepthwiseConv2d_global[(oci_c)] + (((float*)PaddedInput)[(((((((i1_i2_fused / 7) * 900) + ((i1_i2_fused % 7) * 120)) + (kh * 60)) + (kw * 4)) + oci_c))] * ((float*)placeholder1)[((((((i1_i2_fused / 7) * 36) + (kh * 12)) + (kw * 4)) + oci_c))]));
        }
        for (int32_t oci_c1 = 0; oci_c1 < 4; ++oci_c1) {
          DepthwiseConv2d_global[((oci_c1 + 4))] = (DepthwiseConv2d_global[((oci_c1 + 4))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 7) * 900) + ((i1_i2_fused % 7) * 120)) + (kh * 60)) + (kw * 4)) + oci_c1) + 8))] * ((float*)placeholder1)[((((((i1_i2_fused / 7) * 36) + (kh * 12)) + (kw * 4)) + oci_c1))]));
        }
        for (int32_t oci_c2 = 0; oci_c2 < 4; ++oci_c2) {
          DepthwiseConv2d_global[((oci_c2 + 8))] = (DepthwiseConv2d_global[((oci_c2 + 8))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 7) * 900) + ((i1_i2_fused % 7) * 120)) + (kh * 60)) + (kw * 4)) + oci_c2) + 16))] * ((float*)placeholder1)[((((((i1_i2_fused / 7) * 36) + (kh * 12)) + (kw * 4)) + oci_c2))]));
        }
        for (int32_t oci_c3 = 0; oci_c3 < 4; ++oci_c3) {
          DepthwiseConv2d_global[((oci_c3 + 12))] = (DepthwiseConv2d_global[((oci_c3 + 12))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 7) * 900) + ((i1_i2_fused % 7) * 120)) + (kh * 60)) + (kw * 4)) + oci_c3) + 24))] * ((float*)placeholder1)[((((((i1_i2_fused / 7) * 36) + (kh * 12)) + (kw * 4)) + oci_c3))]));
        }
        for (int32_t oci_c4 = 0; oci_c4 < 4; ++oci_c4) {
          DepthwiseConv2d_global[((oci_c4 + 16))] = (DepthwiseConv2d_global[((oci_c4 + 16))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 7) * 900) + ((i1_i2_fused % 7) * 120)) + (kh * 60)) + (kw * 4)) + oci_c4) + 32))] * ((float*)placeholder1)[((((((i1_i2_fused / 7) * 36) + (kh * 12)) + (kw * 4)) + oci_c4))]));
        }
        for (int32_t oci_c5 = 0; oci_c5 < 4; ++oci_c5) {
          DepthwiseConv2d_global[((oci_c5 + 20))] = (DepthwiseConv2d_global[((oci_c5 + 20))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 7) * 900) + ((i1_i2_fused % 7) * 120)) + (kh * 60)) + (kw * 4)) + oci_c5) + 40))] * ((float*)placeholder1)[((((((i1_i2_fused / 7) * 36) + (kh * 12)) + (kw * 4)) + oci_c5))]));
        }
        for (int32_t oci_c6 = 0; oci_c6 < 4; ++oci_c6) {
          DepthwiseConv2d_global[((oci_c6 + 24))] = (DepthwiseConv2d_global[((oci_c6 + 24))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 7) * 900) + ((i1_i2_fused % 7) * 120)) + (kh * 60)) + (kw * 4)) + oci_c6) + 48))] * ((float*)placeholder1)[((((((i1_i2_fused / 7) * 36) + (kh * 12)) + (kw * 4)) + oci_c6))]));
        }
      }
    }
    for (int32_t i3_inner = 0; i3_inner < 7; ++i3_inner) {
      for (int32_t i41 = 0; i41 < 4; ++i41) {
        float _1 = DepthwiseConv2d_global[(((i3_inner * 4) + i41))] + ((float*)placeholder2)[((((i1_i2_fused / 7) * 4) + i41))];
        float _2 = (_1) < (6.000000e+00f) ? (_1) : (6.000000e+00f);
        ((float*)compute)[((((i1_i2_fused * 28) + (i3_inner * 4)) + i41))] = ((_2) > (0.000000e+00f) ? (_2) : (0.000000e+00f));
      }
    }
  }
  if (TVMBackendFreeWorkspace(1, dev_id, PaddedInput) != 0) {
    return -1;
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_contrib_conv2d_NCHWc_add_7(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int32_t arg2_code = ((int32_t*)arg_type_ids)[(2)];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int32_t arg3_code = ((int32_t*)arg_type_ids)[(3)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* placeholder1 = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  void* placeholder2 = (((DLTensor*)arg2)[0].data);
  void* arg2_shape = (((DLTensor*)arg2)[0].shape);
  void* arg2_strides = (((DLTensor*)arg2)[0].strides);
  void* T_add = (((DLTensor*)arg3)[0].data);
  void* arg3_shape = (((DLTensor*)arg3)[0].shape);
  void* arg3_strides = (((DLTensor*)arg3)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  if (!(arg2_strides == NULL)) {
  }
  if (!(arg3_strides == NULL)) {
  }
  for (int32_t ax0_ax1_fused_ax2_outer_fused = 0; ax0_ax1_fused_ax2_outer_fused < 448; ++ax0_ax1_fused_ax2_outer_fused) {
    void* conv2d_NCHWc_global = TVMBackendAllocWorkspace(1, dev_id, (uint64_t)1792, 2, 32);
    if (conv2d_NCHWc_global == NULL) {
      return -1;
    }
    for (int32_t ow_c_outer = 0; ow_c_outer < 4; ++ow_c_outer) {
      for (int32_t oc_block_c_init = 0; oc_block_c_init < 4; ++oc_block_c_init) {
        ((float*)conv2d_NCHWc_global)[(((ow_c_outer * 112) + oc_block_c_init))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init1 = 0; oc_block_c_init1 < 4; ++oc_block_c_init1) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init1) + 4))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init2 = 0; oc_block_c_init2 < 4; ++oc_block_c_init2) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init2) + 8))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init3 = 0; oc_block_c_init3 < 4; ++oc_block_c_init3) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init3) + 12))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init4 = 0; oc_block_c_init4 < 4; ++oc_block_c_init4) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init4) + 16))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init5 = 0; oc_block_c_init5 < 4; ++oc_block_c_init5) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init5) + 20))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init6 = 0; oc_block_c_init6 < 4; ++oc_block_c_init6) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init6) + 24))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init7 = 0; oc_block_c_init7 < 4; ++oc_block_c_init7) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init7) + 28))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init8 = 0; oc_block_c_init8 < 4; ++oc_block_c_init8) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init8) + 32))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init9 = 0; oc_block_c_init9 < 4; ++oc_block_c_init9) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init9) + 36))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init10 = 0; oc_block_c_init10 < 4; ++oc_block_c_init10) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init10) + 40))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init11 = 0; oc_block_c_init11 < 4; ++oc_block_c_init11) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init11) + 44))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init12 = 0; oc_block_c_init12 < 4; ++oc_block_c_init12) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init12) + 48))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init13 = 0; oc_block_c_init13 < 4; ++oc_block_c_init13) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init13) + 52))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init14 = 0; oc_block_c_init14 < 4; ++oc_block_c_init14) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init14) + 56))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init15 = 0; oc_block_c_init15 < 4; ++oc_block_c_init15) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init15) + 60))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init16 = 0; oc_block_c_init16 < 4; ++oc_block_c_init16) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init16) + 64))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init17 = 0; oc_block_c_init17 < 4; ++oc_block_c_init17) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init17) + 68))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init18 = 0; oc_block_c_init18 < 4; ++oc_block_c_init18) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init18) + 72))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init19 = 0; oc_block_c_init19 < 4; ++oc_block_c_init19) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init19) + 76))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init20 = 0; oc_block_c_init20 < 4; ++oc_block_c_init20) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init20) + 80))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init21 = 0; oc_block_c_init21 < 4; ++oc_block_c_init21) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init21) + 84))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init22 = 0; oc_block_c_init22 < 4; ++oc_block_c_init22) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init22) + 88))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init23 = 0; oc_block_c_init23 < 4; ++oc_block_c_init23) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init23) + 92))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init24 = 0; oc_block_c_init24 < 4; ++oc_block_c_init24) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init24) + 96))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init25 = 0; oc_block_c_init25 < 4; ++oc_block_c_init25) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init25) + 100))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init26 = 0; oc_block_c_init26 < 4; ++oc_block_c_init26) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init26) + 104))] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init27 = 0; oc_block_c_init27 < 4; ++oc_block_c_init27) {
        ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c_init27) + 108))] = 0.000000e+00f;
      }
      for (int32_t ic_outer = 0; ic_outer < 8; ++ic_outer) {
        for (int32_t ic_inner = 0; ic_inner < 4; ++ic_inner) {
          for (int32_t oc_block_c = 0; oc_block_c < 4; ++oc_block_c) {
            ((float*)conv2d_NCHWc_global)[(((ow_c_outer * 112) + oc_block_c))] = (((float*)conv2d_NCHWc_global)[(((ow_c_outer * 112) + oc_block_c))] + (((float*)placeholder)[(((((ic_outer * 50176) + ((ax0_ax1_fused_ax2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 112) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c))]));
          }
          for (int32_t oc_block_c1 = 0; oc_block_c1 < 4; ++oc_block_c1) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c1) + 4))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c1) + 4))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((ax0_ax1_fused_ax2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 4))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 112) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c1))]));
          }
          for (int32_t oc_block_c2 = 0; oc_block_c2 < 4; ++oc_block_c2) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c2) + 8))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c2) + 8))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((ax0_ax1_fused_ax2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 8))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 112) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c2))]));
          }
          for (int32_t oc_block_c3 = 0; oc_block_c3 < 4; ++oc_block_c3) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c3) + 12))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c3) + 12))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((ax0_ax1_fused_ax2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 12))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 112) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c3))]));
          }
          for (int32_t oc_block_c4 = 0; oc_block_c4 < 4; ++oc_block_c4) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c4) + 16))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c4) + 16))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((ax0_ax1_fused_ax2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 16))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 112) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c4))]));
          }
          for (int32_t oc_block_c5 = 0; oc_block_c5 < 4; ++oc_block_c5) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c5) + 20))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c5) + 20))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((ax0_ax1_fused_ax2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 20))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 112) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c5))]));
          }
          for (int32_t oc_block_c6 = 0; oc_block_c6 < 4; ++oc_block_c6) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c6) + 24))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c6) + 24))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((ax0_ax1_fused_ax2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 24))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 112) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c6))]));
          }
          for (int32_t oc_block_c7 = 0; oc_block_c7 < 4; ++oc_block_c7) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c7) + 28))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c7) + 28))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((ax0_ax1_fused_ax2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 28))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 112) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c7))]));
          }
          for (int32_t oc_block_c8 = 0; oc_block_c8 < 4; ++oc_block_c8) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c8) + 32))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c8) + 32))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((ax0_ax1_fused_ax2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 32))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 112) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c8))]));
          }
          for (int32_t oc_block_c9 = 0; oc_block_c9 < 4; ++oc_block_c9) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c9) + 36))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c9) + 36))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((ax0_ax1_fused_ax2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 36))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 112) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c9))]));
          }
          for (int32_t oc_block_c10 = 0; oc_block_c10 < 4; ++oc_block_c10) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c10) + 40))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c10) + 40))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((ax0_ax1_fused_ax2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 40))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 112) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c10))]));
          }
          for (int32_t oc_block_c11 = 0; oc_block_c11 < 4; ++oc_block_c11) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c11) + 44))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c11) + 44))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((ax0_ax1_fused_ax2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 44))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 112) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c11))]));
          }
          for (int32_t oc_block_c12 = 0; oc_block_c12 < 4; ++oc_block_c12) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c12) + 48))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c12) + 48))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((ax0_ax1_fused_ax2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 48))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 112) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c12))]));
          }
          for (int32_t oc_block_c13 = 0; oc_block_c13 < 4; ++oc_block_c13) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c13) + 52))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c13) + 52))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((ax0_ax1_fused_ax2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 52))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 112) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c13))]));
          }
          for (int32_t oc_block_c14 = 0; oc_block_c14 < 4; ++oc_block_c14) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c14) + 56))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c14) + 56))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((ax0_ax1_fused_ax2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 56))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 112) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c14))]));
          }
          for (int32_t oc_block_c15 = 0; oc_block_c15 < 4; ++oc_block_c15) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c15) + 60))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c15) + 60))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((ax0_ax1_fused_ax2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 60))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 112) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c15))]));
          }
          for (int32_t oc_block_c16 = 0; oc_block_c16 < 4; ++oc_block_c16) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c16) + 64))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c16) + 64))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((ax0_ax1_fused_ax2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 64))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 112) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c16))]));
          }
          for (int32_t oc_block_c17 = 0; oc_block_c17 < 4; ++oc_block_c17) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c17) + 68))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c17) + 68))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((ax0_ax1_fused_ax2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 68))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 112) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c17))]));
          }
          for (int32_t oc_block_c18 = 0; oc_block_c18 < 4; ++oc_block_c18) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c18) + 72))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c18) + 72))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((ax0_ax1_fused_ax2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 72))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 112) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c18))]));
          }
          for (int32_t oc_block_c19 = 0; oc_block_c19 < 4; ++oc_block_c19) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c19) + 76))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c19) + 76))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((ax0_ax1_fused_ax2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 76))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 112) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c19))]));
          }
          for (int32_t oc_block_c20 = 0; oc_block_c20 < 4; ++oc_block_c20) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c20) + 80))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c20) + 80))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((ax0_ax1_fused_ax2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 80))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 112) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c20))]));
          }
          for (int32_t oc_block_c21 = 0; oc_block_c21 < 4; ++oc_block_c21) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c21) + 84))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c21) + 84))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((ax0_ax1_fused_ax2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 84))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 112) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c21))]));
          }
          for (int32_t oc_block_c22 = 0; oc_block_c22 < 4; ++oc_block_c22) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c22) + 88))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c22) + 88))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((ax0_ax1_fused_ax2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 88))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 112) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c22))]));
          }
          for (int32_t oc_block_c23 = 0; oc_block_c23 < 4; ++oc_block_c23) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c23) + 92))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c23) + 92))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((ax0_ax1_fused_ax2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 92))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 112) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c23))]));
          }
          for (int32_t oc_block_c24 = 0; oc_block_c24 < 4; ++oc_block_c24) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c24) + 96))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c24) + 96))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((ax0_ax1_fused_ax2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 96))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 112) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c24))]));
          }
          for (int32_t oc_block_c25 = 0; oc_block_c25 < 4; ++oc_block_c25) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c25) + 100))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c25) + 100))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((ax0_ax1_fused_ax2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 100))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 112) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c25))]));
          }
          for (int32_t oc_block_c26 = 0; oc_block_c26 < 4; ++oc_block_c26) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c26) + 104))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c26) + 104))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((ax0_ax1_fused_ax2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 104))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 112) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c26))]));
          }
          for (int32_t oc_block_c27 = 0; oc_block_c27 < 4; ++oc_block_c27) {
            ((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c27) + 108))] = (((float*)conv2d_NCHWc_global)[((((ow_c_outer * 112) + oc_block_c27) + 108))] + (((float*)placeholder)[((((((ic_outer * 50176) + ((ax0_ax1_fused_ax2_outer_fused % 112) * 448)) + (ow_c_outer * 112)) + ic_inner) + 108))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 112) * 128) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c27))]));
          }
        }
      }
    }
    for (int32_t ax3_outer = 0; ax3_outer < 4; ++ax3_outer) {
      for (int32_t ax3_inner = 0; ax3_inner < 28; ++ax3_inner) {
        for (int32_t ax4 = 0; ax4 < 4; ++ax4) {
          ((float*)T_add)[(((((ax0_ax1_fused_ax2_outer_fused * 448) + (ax3_outer * 112)) + (ax3_inner * 4)) + ax4))] = (((float*)conv2d_NCHWc_global)[((((ax3_outer * 112) + (ax3_inner * 4)) + ax4))] + ((float*)placeholder2)[((((ax0_ax1_fused_ax2_outer_fused / 112) * 4) + ax4))]);
        }
      }
    }
    if (TVMBackendFreeWorkspace(1, dev_id, conv2d_NCHWc_global) != 0) {
      return -1;
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_contrib_conv2d_NCHWc_add_5(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int32_t arg2_code = ((int32_t*)arg_type_ids)[(2)];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int32_t arg3_code = ((int32_t*)arg_type_ids)[(3)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* placeholder1 = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  void* placeholder2 = (((DLTensor*)arg2)[0].data);
  void* arg2_shape = (((DLTensor*)arg2)[0].shape);
  void* arg2_strides = (((DLTensor*)arg2)[0].strides);
  void* T_add = (((DLTensor*)arg3)[0].data);
  void* arg3_shape = (((DLTensor*)arg3)[0].shape);
  void* arg3_strides = (((DLTensor*)arg3)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  if (!(arg2_strides == NULL)) {
  }
  if (!(arg3_strides == NULL)) {
  }
  for (int32_t ax0_ax1_fused_ax2_outer_fused = 0; ax0_ax1_fused_ax2_outer_fused < 224; ++ax0_ax1_fused_ax2_outer_fused) {
    float conv2d_NCHWc_global[112];
    for (int32_t oc_block_c_init = 0; oc_block_c_init < 4; ++oc_block_c_init) {
      conv2d_NCHWc_global[(oc_block_c_init)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init1 = 0; oc_block_c_init1 < 4; ++oc_block_c_init1) {
      conv2d_NCHWc_global[((oc_block_c_init1 + 4))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init2 = 0; oc_block_c_init2 < 4; ++oc_block_c_init2) {
      conv2d_NCHWc_global[((oc_block_c_init2 + 8))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init3 = 0; oc_block_c_init3 < 4; ++oc_block_c_init3) {
      conv2d_NCHWc_global[((oc_block_c_init3 + 12))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init4 = 0; oc_block_c_init4 < 4; ++oc_block_c_init4) {
      conv2d_NCHWc_global[((oc_block_c_init4 + 16))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init5 = 0; oc_block_c_init5 < 4; ++oc_block_c_init5) {
      conv2d_NCHWc_global[((oc_block_c_init5 + 20))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init6 = 0; oc_block_c_init6 < 4; ++oc_block_c_init6) {
      conv2d_NCHWc_global[((oc_block_c_init6 + 24))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init7 = 0; oc_block_c_init7 < 4; ++oc_block_c_init7) {
      conv2d_NCHWc_global[((oc_block_c_init7 + 28))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init8 = 0; oc_block_c_init8 < 4; ++oc_block_c_init8) {
      conv2d_NCHWc_global[((oc_block_c_init8 + 32))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init9 = 0; oc_block_c_init9 < 4; ++oc_block_c_init9) {
      conv2d_NCHWc_global[((oc_block_c_init9 + 36))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init10 = 0; oc_block_c_init10 < 4; ++oc_block_c_init10) {
      conv2d_NCHWc_global[((oc_block_c_init10 + 40))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init11 = 0; oc_block_c_init11 < 4; ++oc_block_c_init11) {
      conv2d_NCHWc_global[((oc_block_c_init11 + 44))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init12 = 0; oc_block_c_init12 < 4; ++oc_block_c_init12) {
      conv2d_NCHWc_global[((oc_block_c_init12 + 48))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init13 = 0; oc_block_c_init13 < 4; ++oc_block_c_init13) {
      conv2d_NCHWc_global[((oc_block_c_init13 + 52))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init14 = 0; oc_block_c_init14 < 4; ++oc_block_c_init14) {
      conv2d_NCHWc_global[((oc_block_c_init14 + 56))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init15 = 0; oc_block_c_init15 < 4; ++oc_block_c_init15) {
      conv2d_NCHWc_global[((oc_block_c_init15 + 60))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init16 = 0; oc_block_c_init16 < 4; ++oc_block_c_init16) {
      conv2d_NCHWc_global[((oc_block_c_init16 + 64))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init17 = 0; oc_block_c_init17 < 4; ++oc_block_c_init17) {
      conv2d_NCHWc_global[((oc_block_c_init17 + 68))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init18 = 0; oc_block_c_init18 < 4; ++oc_block_c_init18) {
      conv2d_NCHWc_global[((oc_block_c_init18 + 72))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init19 = 0; oc_block_c_init19 < 4; ++oc_block_c_init19) {
      conv2d_NCHWc_global[((oc_block_c_init19 + 76))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init20 = 0; oc_block_c_init20 < 4; ++oc_block_c_init20) {
      conv2d_NCHWc_global[((oc_block_c_init20 + 80))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init21 = 0; oc_block_c_init21 < 4; ++oc_block_c_init21) {
      conv2d_NCHWc_global[((oc_block_c_init21 + 84))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init22 = 0; oc_block_c_init22 < 4; ++oc_block_c_init22) {
      conv2d_NCHWc_global[((oc_block_c_init22 + 88))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init23 = 0; oc_block_c_init23 < 4; ++oc_block_c_init23) {
      conv2d_NCHWc_global[((oc_block_c_init23 + 92))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init24 = 0; oc_block_c_init24 < 4; ++oc_block_c_init24) {
      conv2d_NCHWc_global[((oc_block_c_init24 + 96))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init25 = 0; oc_block_c_init25 < 4; ++oc_block_c_init25) {
      conv2d_NCHWc_global[((oc_block_c_init25 + 100))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init26 = 0; oc_block_c_init26 < 4; ++oc_block_c_init26) {
      conv2d_NCHWc_global[((oc_block_c_init26 + 104))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init27 = 0; oc_block_c_init27 < 4; ++oc_block_c_init27) {
      conv2d_NCHWc_global[((oc_block_c_init27 + 108))] = 0.000000e+00f;
    }
    for (int32_t ic_outer = 0; ic_outer < 36; ++ic_outer) {
      for (int32_t ic_inner = 0; ic_inner < 4; ++ic_inner) {
        for (int32_t oc_block_c = 0; oc_block_c < 4; ++oc_block_c) {
          conv2d_NCHWc_global[(oc_block_c)] = (conv2d_NCHWc_global[(oc_block_c)] + (((float*)placeholder)[((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c))]));
        }
        for (int32_t oc_block_c1 = 0; oc_block_c1 < 4; ++oc_block_c1) {
          conv2d_NCHWc_global[((oc_block_c1 + 4))] = (conv2d_NCHWc_global[((oc_block_c1 + 4))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 4))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c1))]));
        }
        for (int32_t oc_block_c2 = 0; oc_block_c2 < 4; ++oc_block_c2) {
          conv2d_NCHWc_global[((oc_block_c2 + 8))] = (conv2d_NCHWc_global[((oc_block_c2 + 8))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 8))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c2))]));
        }
        for (int32_t oc_block_c3 = 0; oc_block_c3 < 4; ++oc_block_c3) {
          conv2d_NCHWc_global[((oc_block_c3 + 12))] = (conv2d_NCHWc_global[((oc_block_c3 + 12))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 12))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c3))]));
        }
        for (int32_t oc_block_c4 = 0; oc_block_c4 < 4; ++oc_block_c4) {
          conv2d_NCHWc_global[((oc_block_c4 + 16))] = (conv2d_NCHWc_global[((oc_block_c4 + 16))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 16))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c4))]));
        }
        for (int32_t oc_block_c5 = 0; oc_block_c5 < 4; ++oc_block_c5) {
          conv2d_NCHWc_global[((oc_block_c5 + 20))] = (conv2d_NCHWc_global[((oc_block_c5 + 20))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 20))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c5))]));
        }
        for (int32_t oc_block_c6 = 0; oc_block_c6 < 4; ++oc_block_c6) {
          conv2d_NCHWc_global[((oc_block_c6 + 24))] = (conv2d_NCHWc_global[((oc_block_c6 + 24))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 24))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c6))]));
        }
        for (int32_t oc_block_c7 = 0; oc_block_c7 < 4; ++oc_block_c7) {
          conv2d_NCHWc_global[((oc_block_c7 + 28))] = (conv2d_NCHWc_global[((oc_block_c7 + 28))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 28))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c7))]));
        }
        for (int32_t oc_block_c8 = 0; oc_block_c8 < 4; ++oc_block_c8) {
          conv2d_NCHWc_global[((oc_block_c8 + 32))] = (conv2d_NCHWc_global[((oc_block_c8 + 32))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 32))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c8))]));
        }
        for (int32_t oc_block_c9 = 0; oc_block_c9 < 4; ++oc_block_c9) {
          conv2d_NCHWc_global[((oc_block_c9 + 36))] = (conv2d_NCHWc_global[((oc_block_c9 + 36))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 36))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c9))]));
        }
        for (int32_t oc_block_c10 = 0; oc_block_c10 < 4; ++oc_block_c10) {
          conv2d_NCHWc_global[((oc_block_c10 + 40))] = (conv2d_NCHWc_global[((oc_block_c10 + 40))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 40))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c10))]));
        }
        for (int32_t oc_block_c11 = 0; oc_block_c11 < 4; ++oc_block_c11) {
          conv2d_NCHWc_global[((oc_block_c11 + 44))] = (conv2d_NCHWc_global[((oc_block_c11 + 44))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 44))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c11))]));
        }
        for (int32_t oc_block_c12 = 0; oc_block_c12 < 4; ++oc_block_c12) {
          conv2d_NCHWc_global[((oc_block_c12 + 48))] = (conv2d_NCHWc_global[((oc_block_c12 + 48))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 48))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c12))]));
        }
        for (int32_t oc_block_c13 = 0; oc_block_c13 < 4; ++oc_block_c13) {
          conv2d_NCHWc_global[((oc_block_c13 + 52))] = (conv2d_NCHWc_global[((oc_block_c13 + 52))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 52))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c13))]));
        }
        for (int32_t oc_block_c14 = 0; oc_block_c14 < 4; ++oc_block_c14) {
          conv2d_NCHWc_global[((oc_block_c14 + 56))] = (conv2d_NCHWc_global[((oc_block_c14 + 56))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 56))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c14))]));
        }
        for (int32_t oc_block_c15 = 0; oc_block_c15 < 4; ++oc_block_c15) {
          conv2d_NCHWc_global[((oc_block_c15 + 60))] = (conv2d_NCHWc_global[((oc_block_c15 + 60))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 60))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c15))]));
        }
        for (int32_t oc_block_c16 = 0; oc_block_c16 < 4; ++oc_block_c16) {
          conv2d_NCHWc_global[((oc_block_c16 + 64))] = (conv2d_NCHWc_global[((oc_block_c16 + 64))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 64))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c16))]));
        }
        for (int32_t oc_block_c17 = 0; oc_block_c17 < 4; ++oc_block_c17) {
          conv2d_NCHWc_global[((oc_block_c17 + 68))] = (conv2d_NCHWc_global[((oc_block_c17 + 68))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 68))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c17))]));
        }
        for (int32_t oc_block_c18 = 0; oc_block_c18 < 4; ++oc_block_c18) {
          conv2d_NCHWc_global[((oc_block_c18 + 72))] = (conv2d_NCHWc_global[((oc_block_c18 + 72))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 72))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c18))]));
        }
        for (int32_t oc_block_c19 = 0; oc_block_c19 < 4; ++oc_block_c19) {
          conv2d_NCHWc_global[((oc_block_c19 + 76))] = (conv2d_NCHWc_global[((oc_block_c19 + 76))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 76))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c19))]));
        }
        for (int32_t oc_block_c20 = 0; oc_block_c20 < 4; ++oc_block_c20) {
          conv2d_NCHWc_global[((oc_block_c20 + 80))] = (conv2d_NCHWc_global[((oc_block_c20 + 80))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 80))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c20))]));
        }
        for (int32_t oc_block_c21 = 0; oc_block_c21 < 4; ++oc_block_c21) {
          conv2d_NCHWc_global[((oc_block_c21 + 84))] = (conv2d_NCHWc_global[((oc_block_c21 + 84))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 84))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c21))]));
        }
        for (int32_t oc_block_c22 = 0; oc_block_c22 < 4; ++oc_block_c22) {
          conv2d_NCHWc_global[((oc_block_c22 + 88))] = (conv2d_NCHWc_global[((oc_block_c22 + 88))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 88))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c22))]));
        }
        for (int32_t oc_block_c23 = 0; oc_block_c23 < 4; ++oc_block_c23) {
          conv2d_NCHWc_global[((oc_block_c23 + 92))] = (conv2d_NCHWc_global[((oc_block_c23 + 92))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 92))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c23))]));
        }
        for (int32_t oc_block_c24 = 0; oc_block_c24 < 4; ++oc_block_c24) {
          conv2d_NCHWc_global[((oc_block_c24 + 96))] = (conv2d_NCHWc_global[((oc_block_c24 + 96))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 96))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c24))]));
        }
        for (int32_t oc_block_c25 = 0; oc_block_c25 < 4; ++oc_block_c25) {
          conv2d_NCHWc_global[((oc_block_c25 + 100))] = (conv2d_NCHWc_global[((oc_block_c25 + 100))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 100))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c25))]));
        }
        for (int32_t oc_block_c26 = 0; oc_block_c26 < 4; ++oc_block_c26) {
          conv2d_NCHWc_global[((oc_block_c26 + 104))] = (conv2d_NCHWc_global[((oc_block_c26 + 104))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 104))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c26))]));
        }
        for (int32_t oc_block_c27 = 0; oc_block_c27 < 4; ++oc_block_c27) {
          conv2d_NCHWc_global[((oc_block_c27 + 108))] = (conv2d_NCHWc_global[((oc_block_c27 + 108))] + (((float*)placeholder)[(((((ic_outer * 3136) + ((ax0_ax1_fused_ax2_outer_fused % 28) * 112)) + ic_inner) + 108))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 28) * 576) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c27))]));
        }
      }
    }
    for (int32_t ax3_inner = 0; ax3_inner < 28; ++ax3_inner) {
      for (int32_t ax4 = 0; ax4 < 4; ++ax4) {
        ((float*)T_add)[((((ax0_ax1_fused_ax2_outer_fused * 112) + (ax3_inner * 4)) + ax4))] = (conv2d_NCHWc_global[(((ax3_inner * 4) + ax4))] + ((float*)placeholder2)[((((ax0_ax1_fused_ax2_outer_fused / 28) * 4) + ax4))]);
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_contrib_depthwise_conv2d_NCHWc_add_clip(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int32_t arg2_code = ((int32_t*)arg_type_ids)[(2)];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int32_t arg3_code = ((int32_t*)arg_type_ids)[(3)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* placeholder1 = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  void* placeholder2 = (((DLTensor*)arg2)[0].data);
  void* arg2_shape = (((DLTensor*)arg2)[0].shape);
  void* arg2_strides = (((DLTensor*)arg2)[0].strides);
  void* compute = (((DLTensor*)arg3)[0].data);
  void* arg3_shape = (((DLTensor*)arg3)[0].shape);
  void* arg3_strides = (((DLTensor*)arg3)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  if (!(arg2_strides == NULL)) {
  }
  if (!(arg3_strides == NULL)) {
  }
  void* PaddedInput = TVMBackendAllocWorkspace(1, dev_id, (uint64_t)311040, 2, 32);
  if (PaddedInput == NULL) {
    return -1;
  }
  for (int32_t i0_i1_fused_i2_fused = 0; i0_i1_fused_i2_fused < 2160; ++i0_i1_fused_i2_fused) {
    for (int32_t i3 = 0; i3 < 9; ++i3) {
      for (int32_t i4 = 0; i4 < 4; ++i4) {
        ((float*)PaddedInput)[((((i0_i1_fused_i2_fused * 36) + (i3 * 4)) + i4))] = (((((1 <= (i0_i1_fused_i2_fused % 9)) && ((i0_i1_fused_i2_fused % 9) < 8)) && (1 <= i3)) && (i3 < 8)) ? ((float*)placeholder)[(((((((i0_i1_fused_i2_fused / 9) * 196) + ((i0_i1_fused_i2_fused % 9) * 28)) + (i3 * 4)) + i4) - 32))] : 0.000000e+00f);
      }
    }
  }
  for (int32_t i1_i2_fused = 0; i1_i2_fused < 1680; ++i1_i2_fused) {
    float DepthwiseConv2d_global[28];
    for (int32_t oci_c_init = 0; oci_c_init < 4; ++oci_c_init) {
      DepthwiseConv2d_global[(oci_c_init)] = 0.000000e+00f;
    }
    for (int32_t oci_c_init1 = 0; oci_c_init1 < 4; ++oci_c_init1) {
      DepthwiseConv2d_global[((oci_c_init1 + 4))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init2 = 0; oci_c_init2 < 4; ++oci_c_init2) {
      DepthwiseConv2d_global[((oci_c_init2 + 8))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init3 = 0; oci_c_init3 < 4; ++oci_c_init3) {
      DepthwiseConv2d_global[((oci_c_init3 + 12))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init4 = 0; oci_c_init4 < 4; ++oci_c_init4) {
      DepthwiseConv2d_global[((oci_c_init4 + 16))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init5 = 0; oci_c_init5 < 4; ++oci_c_init5) {
      DepthwiseConv2d_global[((oci_c_init5 + 20))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init6 = 0; oci_c_init6 < 4; ++oci_c_init6) {
      DepthwiseConv2d_global[((oci_c_init6 + 24))] = 0.000000e+00f;
    }
    for (int32_t kh = 0; kh < 3; ++kh) {
      for (int32_t kw = 0; kw < 3; ++kw) {
        for (int32_t oci_c = 0; oci_c < 4; ++oci_c) {
          DepthwiseConv2d_global[(oci_c)] = (DepthwiseConv2d_global[(oci_c)] + (((float*)PaddedInput)[(((((((i1_i2_fused / 7) * 324) + (kh * 36)) + ((i1_i2_fused % 7) * 36)) + (kw * 4)) + oci_c))] * ((float*)placeholder1)[((((((i1_i2_fused / 7) * 36) + (kh * 12)) + (kw * 4)) + oci_c))]));
        }
        for (int32_t oci_c1 = 0; oci_c1 < 4; ++oci_c1) {
          DepthwiseConv2d_global[((oci_c1 + 4))] = (DepthwiseConv2d_global[((oci_c1 + 4))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 7) * 324) + (kh * 36)) + ((i1_i2_fused % 7) * 36)) + (kw * 4)) + oci_c1) + 4))] * ((float*)placeholder1)[((((((i1_i2_fused / 7) * 36) + (kh * 12)) + (kw * 4)) + oci_c1))]));
        }
        for (int32_t oci_c2 = 0; oci_c2 < 4; ++oci_c2) {
          DepthwiseConv2d_global[((oci_c2 + 8))] = (DepthwiseConv2d_global[((oci_c2 + 8))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 7) * 324) + (kh * 36)) + ((i1_i2_fused % 7) * 36)) + (kw * 4)) + oci_c2) + 8))] * ((float*)placeholder1)[((((((i1_i2_fused / 7) * 36) + (kh * 12)) + (kw * 4)) + oci_c2))]));
        }
        for (int32_t oci_c3 = 0; oci_c3 < 4; ++oci_c3) {
          DepthwiseConv2d_global[((oci_c3 + 12))] = (DepthwiseConv2d_global[((oci_c3 + 12))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 7) * 324) + (kh * 36)) + ((i1_i2_fused % 7) * 36)) + (kw * 4)) + oci_c3) + 12))] * ((float*)placeholder1)[((((((i1_i2_fused / 7) * 36) + (kh * 12)) + (kw * 4)) + oci_c3))]));
        }
        for (int32_t oci_c4 = 0; oci_c4 < 4; ++oci_c4) {
          DepthwiseConv2d_global[((oci_c4 + 16))] = (DepthwiseConv2d_global[((oci_c4 + 16))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 7) * 324) + (kh * 36)) + ((i1_i2_fused % 7) * 36)) + (kw * 4)) + oci_c4) + 16))] * ((float*)placeholder1)[((((((i1_i2_fused / 7) * 36) + (kh * 12)) + (kw * 4)) + oci_c4))]));
        }
        for (int32_t oci_c5 = 0; oci_c5 < 4; ++oci_c5) {
          DepthwiseConv2d_global[((oci_c5 + 20))] = (DepthwiseConv2d_global[((oci_c5 + 20))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 7) * 324) + (kh * 36)) + ((i1_i2_fused % 7) * 36)) + (kw * 4)) + oci_c5) + 20))] * ((float*)placeholder1)[((((((i1_i2_fused / 7) * 36) + (kh * 12)) + (kw * 4)) + oci_c5))]));
        }
        for (int32_t oci_c6 = 0; oci_c6 < 4; ++oci_c6) {
          DepthwiseConv2d_global[((oci_c6 + 24))] = (DepthwiseConv2d_global[((oci_c6 + 24))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 7) * 324) + (kh * 36)) + ((i1_i2_fused % 7) * 36)) + (kw * 4)) + oci_c6) + 24))] * ((float*)placeholder1)[((((((i1_i2_fused / 7) * 36) + (kh * 12)) + (kw * 4)) + oci_c6))]));
        }
      }
    }
    for (int32_t i3_inner = 0; i3_inner < 7; ++i3_inner) {
      for (int32_t i41 = 0; i41 < 4; ++i41) {
        float _1 = DepthwiseConv2d_global[(((i3_inner * 4) + i41))] + ((float*)placeholder2)[((((i1_i2_fused / 7) * 4) + i41))];
        float _2 = (_1) < (6.000000e+00f) ? (_1) : (6.000000e+00f);
        ((float*)compute)[((((i1_i2_fused * 28) + (i3_inner * 4)) + i41))] = ((_2) > (0.000000e+00f) ? (_2) : (0.000000e+00f));
      }
    }
  }
  if (TVMBackendFreeWorkspace(1, dev_id, PaddedInput) != 0) {
    return -1;
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_contrib_conv2d_NCHWc_add_clip_1(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int32_t arg2_code = ((int32_t*)arg_type_ids)[(2)];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int32_t arg3_code = ((int32_t*)arg_type_ids)[(3)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* placeholder1 = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  void* placeholder2 = (((DLTensor*)arg2)[0].data);
  void* arg2_shape = (((DLTensor*)arg2)[0].shape);
  void* arg2_strides = (((DLTensor*)arg2)[0].strides);
  void* compute = (((DLTensor*)arg3)[0].data);
  void* arg3_shape = (((DLTensor*)arg3)[0].shape);
  void* arg3_strides = (((DLTensor*)arg3)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  if (!(arg2_strides == NULL)) {
  }
  if (!(arg3_strides == NULL)) {
  }
  for (int32_t i0_i1_fused_i2_outer_fused = 0; i0_i1_fused_i2_outer_fused < 1680; ++i0_i1_fused_i2_outer_fused) {
    float conv2d_NCHWc_global[28];
    for (int32_t oc_block_c_init = 0; oc_block_c_init < 4; ++oc_block_c_init) {
      conv2d_NCHWc_global[(oc_block_c_init)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init1 = 0; oc_block_c_init1 < 4; ++oc_block_c_init1) {
      conv2d_NCHWc_global[((oc_block_c_init1 + 4))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init2 = 0; oc_block_c_init2 < 4; ++oc_block_c_init2) {
      conv2d_NCHWc_global[((oc_block_c_init2 + 8))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init3 = 0; oc_block_c_init3 < 4; ++oc_block_c_init3) {
      conv2d_NCHWc_global[((oc_block_c_init3 + 12))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init4 = 0; oc_block_c_init4 < 4; ++oc_block_c_init4) {
      conv2d_NCHWc_global[((oc_block_c_init4 + 16))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init5 = 0; oc_block_c_init5 < 4; ++oc_block_c_init5) {
      conv2d_NCHWc_global[((oc_block_c_init5 + 20))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init6 = 0; oc_block_c_init6 < 4; ++oc_block_c_init6) {
      conv2d_NCHWc_global[((oc_block_c_init6 + 24))] = 0.000000e+00f;
    }
    for (int32_t ic_outer = 0; ic_outer < 40; ++ic_outer) {
      for (int32_t ic_inner = 0; ic_inner < 4; ++ic_inner) {
        for (int32_t oc_block_c = 0; oc_block_c < 4; ++oc_block_c) {
          conv2d_NCHWc_global[(oc_block_c)] = (conv2d_NCHWc_global[(oc_block_c)] + (((float*)placeholder)[((((ic_outer * 196) + ((i0_i1_fused_i2_outer_fused % 7) * 28)) + ic_inner))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 640) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c))]));
        }
        for (int32_t oc_block_c1 = 0; oc_block_c1 < 4; ++oc_block_c1) {
          conv2d_NCHWc_global[((oc_block_c1 + 4))] = (conv2d_NCHWc_global[((oc_block_c1 + 4))] + (((float*)placeholder)[(((((ic_outer * 196) + ((i0_i1_fused_i2_outer_fused % 7) * 28)) + ic_inner) + 4))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 640) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c1))]));
        }
        for (int32_t oc_block_c2 = 0; oc_block_c2 < 4; ++oc_block_c2) {
          conv2d_NCHWc_global[((oc_block_c2 + 8))] = (conv2d_NCHWc_global[((oc_block_c2 + 8))] + (((float*)placeholder)[(((((ic_outer * 196) + ((i0_i1_fused_i2_outer_fused % 7) * 28)) + ic_inner) + 8))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 640) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c2))]));
        }
        for (int32_t oc_block_c3 = 0; oc_block_c3 < 4; ++oc_block_c3) {
          conv2d_NCHWc_global[((oc_block_c3 + 12))] = (conv2d_NCHWc_global[((oc_block_c3 + 12))] + (((float*)placeholder)[(((((ic_outer * 196) + ((i0_i1_fused_i2_outer_fused % 7) * 28)) + ic_inner) + 12))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 640) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c3))]));
        }
        for (int32_t oc_block_c4 = 0; oc_block_c4 < 4; ++oc_block_c4) {
          conv2d_NCHWc_global[((oc_block_c4 + 16))] = (conv2d_NCHWc_global[((oc_block_c4 + 16))] + (((float*)placeholder)[(((((ic_outer * 196) + ((i0_i1_fused_i2_outer_fused % 7) * 28)) + ic_inner) + 16))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 640) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c4))]));
        }
        for (int32_t oc_block_c5 = 0; oc_block_c5 < 4; ++oc_block_c5) {
          conv2d_NCHWc_global[((oc_block_c5 + 20))] = (conv2d_NCHWc_global[((oc_block_c5 + 20))] + (((float*)placeholder)[(((((ic_outer * 196) + ((i0_i1_fused_i2_outer_fused % 7) * 28)) + ic_inner) + 20))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 640) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c5))]));
        }
        for (int32_t oc_block_c6 = 0; oc_block_c6 < 4; ++oc_block_c6) {
          conv2d_NCHWc_global[((oc_block_c6 + 24))] = (conv2d_NCHWc_global[((oc_block_c6 + 24))] + (((float*)placeholder)[(((((ic_outer * 196) + ((i0_i1_fused_i2_outer_fused % 7) * 28)) + ic_inner) + 24))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 640) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c6))]));
        }
      }
    }
    for (int32_t i3_inner = 0; i3_inner < 7; ++i3_inner) {
      for (int32_t i4 = 0; i4 < 4; ++i4) {
        float _1 = conv2d_NCHWc_global[(((i3_inner * 4) + i4))] + ((float*)placeholder2)[((((i0_i1_fused_i2_outer_fused / 7) * 4) + i4))];
        float _2 = (_1) < (6.000000e+00f) ? (_1) : (6.000000e+00f);
        ((float*)compute)[((((i0_i1_fused_i2_outer_fused * 28) + (i3_inner * 4)) + i4))] = ((_2) > (0.000000e+00f) ? (_2) : (0.000000e+00f));
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_contrib_depthwise_conv2d_NCHWc_add_clip_8(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int32_t arg2_code = ((int32_t*)arg_type_ids)[(2)];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int32_t arg3_code = ((int32_t*)arg_type_ids)[(3)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* placeholder1 = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  void* placeholder2 = (((DLTensor*)arg2)[0].data);
  void* arg2_shape = (((DLTensor*)arg2)[0].shape);
  void* arg2_strides = (((DLTensor*)arg2)[0].strides);
  void* compute = (((DLTensor*)arg3)[0].data);
  void* arg3_shape = (((DLTensor*)arg3)[0].shape);
  void* arg3_strides = (((DLTensor*)arg3)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  if (!(arg2_strides == NULL)) {
  }
  if (!(arg3_strides == NULL)) {
  }
  void* PaddedInput = TVMBackendAllocWorkspace(1, dev_id, (uint64_t)4903296, 2, 32);
  if (PaddedInput == NULL) {
    return -1;
  }
  for (int32_t i0_i1_fused_i2_fused = 0; i0_i1_fused_i2_fused < 2712; ++i0_i1_fused_i2_fused) {
    for (int32_t i3 = 0; i3 < 113; ++i3) {
      for (int32_t i4 = 0; i4 < 4; ++i4) {
        ((float*)PaddedInput)[((((i0_i1_fused_i2_fused * 452) + (i3 * 4)) + i4))] = ((((i0_i1_fused_i2_fused % 113) < 112) && (i3 < 112)) ? ((float*)placeholder)[((((((i0_i1_fused_i2_fused / 113) * 50176) + ((i0_i1_fused_i2_fused % 113) * 448)) + (i3 * 4)) + i4))] : 0.000000e+00f);
      }
    }
  }
  for (int32_t i1_i2_fused = 0; i1_i2_fused < 1344; ++i1_i2_fused) {
    float DepthwiseConv2d[224];
    float DepthwiseConv2d_global[112];
    for (int32_t ow_outer = 0; ow_outer < 2; ++ow_outer) {
      for (int32_t oci_c_init = 0; oci_c_init < 4; ++oci_c_init) {
        DepthwiseConv2d_global[(oci_c_init)] = 0.000000e+00f;
      }
      for (int32_t oci_c_init1 = 0; oci_c_init1 < 4; ++oci_c_init1) {
        DepthwiseConv2d_global[((oci_c_init1 + 4))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init2 = 0; oci_c_init2 < 4; ++oci_c_init2) {
        DepthwiseConv2d_global[((oci_c_init2 + 8))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init3 = 0; oci_c_init3 < 4; ++oci_c_init3) {
        DepthwiseConv2d_global[((oci_c_init3 + 12))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init4 = 0; oci_c_init4 < 4; ++oci_c_init4) {
        DepthwiseConv2d_global[((oci_c_init4 + 16))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init5 = 0; oci_c_init5 < 4; ++oci_c_init5) {
        DepthwiseConv2d_global[((oci_c_init5 + 20))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init6 = 0; oci_c_init6 < 4; ++oci_c_init6) {
        DepthwiseConv2d_global[((oci_c_init6 + 24))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init7 = 0; oci_c_init7 < 4; ++oci_c_init7) {
        DepthwiseConv2d_global[((oci_c_init7 + 28))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init8 = 0; oci_c_init8 < 4; ++oci_c_init8) {
        DepthwiseConv2d_global[((oci_c_init8 + 32))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init9 = 0; oci_c_init9 < 4; ++oci_c_init9) {
        DepthwiseConv2d_global[((oci_c_init9 + 36))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init10 = 0; oci_c_init10 < 4; ++oci_c_init10) {
        DepthwiseConv2d_global[((oci_c_init10 + 40))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init11 = 0; oci_c_init11 < 4; ++oci_c_init11) {
        DepthwiseConv2d_global[((oci_c_init11 + 44))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init12 = 0; oci_c_init12 < 4; ++oci_c_init12) {
        DepthwiseConv2d_global[((oci_c_init12 + 48))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init13 = 0; oci_c_init13 < 4; ++oci_c_init13) {
        DepthwiseConv2d_global[((oci_c_init13 + 52))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init14 = 0; oci_c_init14 < 4; ++oci_c_init14) {
        DepthwiseConv2d_global[((oci_c_init14 + 56))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init15 = 0; oci_c_init15 < 4; ++oci_c_init15) {
        DepthwiseConv2d_global[((oci_c_init15 + 60))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init16 = 0; oci_c_init16 < 4; ++oci_c_init16) {
        DepthwiseConv2d_global[((oci_c_init16 + 64))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init17 = 0; oci_c_init17 < 4; ++oci_c_init17) {
        DepthwiseConv2d_global[((oci_c_init17 + 68))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init18 = 0; oci_c_init18 < 4; ++oci_c_init18) {
        DepthwiseConv2d_global[((oci_c_init18 + 72))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init19 = 0; oci_c_init19 < 4; ++oci_c_init19) {
        DepthwiseConv2d_global[((oci_c_init19 + 76))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init20 = 0; oci_c_init20 < 4; ++oci_c_init20) {
        DepthwiseConv2d_global[((oci_c_init20 + 80))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init21 = 0; oci_c_init21 < 4; ++oci_c_init21) {
        DepthwiseConv2d_global[((oci_c_init21 + 84))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init22 = 0; oci_c_init22 < 4; ++oci_c_init22) {
        DepthwiseConv2d_global[((oci_c_init22 + 88))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init23 = 0; oci_c_init23 < 4; ++oci_c_init23) {
        DepthwiseConv2d_global[((oci_c_init23 + 92))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init24 = 0; oci_c_init24 < 4; ++oci_c_init24) {
        DepthwiseConv2d_global[((oci_c_init24 + 96))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init25 = 0; oci_c_init25 < 4; ++oci_c_init25) {
        DepthwiseConv2d_global[((oci_c_init25 + 100))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init26 = 0; oci_c_init26 < 4; ++oci_c_init26) {
        DepthwiseConv2d_global[((oci_c_init26 + 104))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init27 = 0; oci_c_init27 < 4; ++oci_c_init27) {
        DepthwiseConv2d_global[((oci_c_init27 + 108))] = 0.000000e+00f;
      }
      for (int32_t kh = 0; kh < 3; ++kh) {
        for (int32_t kw = 0; kw < 3; ++kw) {
          for (int32_t oci_c = 0; oci_c < 4; ++oci_c) {
            DepthwiseConv2d_global[(oci_c)] = (DepthwiseConv2d_global[(oci_c)] + (((float*)PaddedInput)[((((((((i1_i2_fused / 56) * 51076) + ((i1_i2_fused % 56) * 904)) + (kh * 452)) + (ow_outer * 224)) + (kw * 4)) + oci_c))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c))]));
          }
          for (int32_t oci_c1 = 0; oci_c1 < 4; ++oci_c1) {
            DepthwiseConv2d_global[((oci_c1 + 4))] = (DepthwiseConv2d_global[((oci_c1 + 4))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 51076) + ((i1_i2_fused % 56) * 904)) + (kh * 452)) + (ow_outer * 224)) + (kw * 4)) + oci_c1) + 8))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c1))]));
          }
          for (int32_t oci_c2 = 0; oci_c2 < 4; ++oci_c2) {
            DepthwiseConv2d_global[((oci_c2 + 8))] = (DepthwiseConv2d_global[((oci_c2 + 8))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 51076) + ((i1_i2_fused % 56) * 904)) + (kh * 452)) + (ow_outer * 224)) + (kw * 4)) + oci_c2) + 16))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c2))]));
          }
          for (int32_t oci_c3 = 0; oci_c3 < 4; ++oci_c3) {
            DepthwiseConv2d_global[((oci_c3 + 12))] = (DepthwiseConv2d_global[((oci_c3 + 12))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 51076) + ((i1_i2_fused % 56) * 904)) + (kh * 452)) + (ow_outer * 224)) + (kw * 4)) + oci_c3) + 24))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c3))]));
          }
          for (int32_t oci_c4 = 0; oci_c4 < 4; ++oci_c4) {
            DepthwiseConv2d_global[((oci_c4 + 16))] = (DepthwiseConv2d_global[((oci_c4 + 16))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 51076) + ((i1_i2_fused % 56) * 904)) + (kh * 452)) + (ow_outer * 224)) + (kw * 4)) + oci_c4) + 32))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c4))]));
          }
          for (int32_t oci_c5 = 0; oci_c5 < 4; ++oci_c5) {
            DepthwiseConv2d_global[((oci_c5 + 20))] = (DepthwiseConv2d_global[((oci_c5 + 20))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 51076) + ((i1_i2_fused % 56) * 904)) + (kh * 452)) + (ow_outer * 224)) + (kw * 4)) + oci_c5) + 40))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c5))]));
          }
          for (int32_t oci_c6 = 0; oci_c6 < 4; ++oci_c6) {
            DepthwiseConv2d_global[((oci_c6 + 24))] = (DepthwiseConv2d_global[((oci_c6 + 24))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 51076) + ((i1_i2_fused % 56) * 904)) + (kh * 452)) + (ow_outer * 224)) + (kw * 4)) + oci_c6) + 48))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c6))]));
          }
          for (int32_t oci_c7 = 0; oci_c7 < 4; ++oci_c7) {
            DepthwiseConv2d_global[((oci_c7 + 28))] = (DepthwiseConv2d_global[((oci_c7 + 28))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 51076) + ((i1_i2_fused % 56) * 904)) + (kh * 452)) + (ow_outer * 224)) + (kw * 4)) + oci_c7) + 56))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c7))]));
          }
          for (int32_t oci_c8 = 0; oci_c8 < 4; ++oci_c8) {
            DepthwiseConv2d_global[((oci_c8 + 32))] = (DepthwiseConv2d_global[((oci_c8 + 32))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 51076) + ((i1_i2_fused % 56) * 904)) + (kh * 452)) + (ow_outer * 224)) + (kw * 4)) + oci_c8) + 64))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c8))]));
          }
          for (int32_t oci_c9 = 0; oci_c9 < 4; ++oci_c9) {
            DepthwiseConv2d_global[((oci_c9 + 36))] = (DepthwiseConv2d_global[((oci_c9 + 36))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 51076) + ((i1_i2_fused % 56) * 904)) + (kh * 452)) + (ow_outer * 224)) + (kw * 4)) + oci_c9) + 72))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c9))]));
          }
          for (int32_t oci_c10 = 0; oci_c10 < 4; ++oci_c10) {
            DepthwiseConv2d_global[((oci_c10 + 40))] = (DepthwiseConv2d_global[((oci_c10 + 40))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 51076) + ((i1_i2_fused % 56) * 904)) + (kh * 452)) + (ow_outer * 224)) + (kw * 4)) + oci_c10) + 80))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c10))]));
          }
          for (int32_t oci_c11 = 0; oci_c11 < 4; ++oci_c11) {
            DepthwiseConv2d_global[((oci_c11 + 44))] = (DepthwiseConv2d_global[((oci_c11 + 44))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 51076) + ((i1_i2_fused % 56) * 904)) + (kh * 452)) + (ow_outer * 224)) + (kw * 4)) + oci_c11) + 88))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c11))]));
          }
          for (int32_t oci_c12 = 0; oci_c12 < 4; ++oci_c12) {
            DepthwiseConv2d_global[((oci_c12 + 48))] = (DepthwiseConv2d_global[((oci_c12 + 48))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 51076) + ((i1_i2_fused % 56) * 904)) + (kh * 452)) + (ow_outer * 224)) + (kw * 4)) + oci_c12) + 96))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c12))]));
          }
          for (int32_t oci_c13 = 0; oci_c13 < 4; ++oci_c13) {
            DepthwiseConv2d_global[((oci_c13 + 52))] = (DepthwiseConv2d_global[((oci_c13 + 52))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 51076) + ((i1_i2_fused % 56) * 904)) + (kh * 452)) + (ow_outer * 224)) + (kw * 4)) + oci_c13) + 104))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c13))]));
          }
          for (int32_t oci_c14 = 0; oci_c14 < 4; ++oci_c14) {
            DepthwiseConv2d_global[((oci_c14 + 56))] = (DepthwiseConv2d_global[((oci_c14 + 56))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 51076) + ((i1_i2_fused % 56) * 904)) + (kh * 452)) + (ow_outer * 224)) + (kw * 4)) + oci_c14) + 112))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c14))]));
          }
          for (int32_t oci_c15 = 0; oci_c15 < 4; ++oci_c15) {
            DepthwiseConv2d_global[((oci_c15 + 60))] = (DepthwiseConv2d_global[((oci_c15 + 60))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 51076) + ((i1_i2_fused % 56) * 904)) + (kh * 452)) + (ow_outer * 224)) + (kw * 4)) + oci_c15) + 120))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c15))]));
          }
          for (int32_t oci_c16 = 0; oci_c16 < 4; ++oci_c16) {
            DepthwiseConv2d_global[((oci_c16 + 64))] = (DepthwiseConv2d_global[((oci_c16 + 64))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 51076) + ((i1_i2_fused % 56) * 904)) + (kh * 452)) + (ow_outer * 224)) + (kw * 4)) + oci_c16) + 128))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c16))]));
          }
          for (int32_t oci_c17 = 0; oci_c17 < 4; ++oci_c17) {
            DepthwiseConv2d_global[((oci_c17 + 68))] = (DepthwiseConv2d_global[((oci_c17 + 68))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 51076) + ((i1_i2_fused % 56) * 904)) + (kh * 452)) + (ow_outer * 224)) + (kw * 4)) + oci_c17) + 136))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c17))]));
          }
          for (int32_t oci_c18 = 0; oci_c18 < 4; ++oci_c18) {
            DepthwiseConv2d_global[((oci_c18 + 72))] = (DepthwiseConv2d_global[((oci_c18 + 72))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 51076) + ((i1_i2_fused % 56) * 904)) + (kh * 452)) + (ow_outer * 224)) + (kw * 4)) + oci_c18) + 144))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c18))]));
          }
          for (int32_t oci_c19 = 0; oci_c19 < 4; ++oci_c19) {
            DepthwiseConv2d_global[((oci_c19 + 76))] = (DepthwiseConv2d_global[((oci_c19 + 76))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 51076) + ((i1_i2_fused % 56) * 904)) + (kh * 452)) + (ow_outer * 224)) + (kw * 4)) + oci_c19) + 152))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c19))]));
          }
          for (int32_t oci_c20 = 0; oci_c20 < 4; ++oci_c20) {
            DepthwiseConv2d_global[((oci_c20 + 80))] = (DepthwiseConv2d_global[((oci_c20 + 80))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 51076) + ((i1_i2_fused % 56) * 904)) + (kh * 452)) + (ow_outer * 224)) + (kw * 4)) + oci_c20) + 160))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c20))]));
          }
          for (int32_t oci_c21 = 0; oci_c21 < 4; ++oci_c21) {
            DepthwiseConv2d_global[((oci_c21 + 84))] = (DepthwiseConv2d_global[((oci_c21 + 84))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 51076) + ((i1_i2_fused % 56) * 904)) + (kh * 452)) + (ow_outer * 224)) + (kw * 4)) + oci_c21) + 168))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c21))]));
          }
          for (int32_t oci_c22 = 0; oci_c22 < 4; ++oci_c22) {
            DepthwiseConv2d_global[((oci_c22 + 88))] = (DepthwiseConv2d_global[((oci_c22 + 88))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 51076) + ((i1_i2_fused % 56) * 904)) + (kh * 452)) + (ow_outer * 224)) + (kw * 4)) + oci_c22) + 176))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c22))]));
          }
          for (int32_t oci_c23 = 0; oci_c23 < 4; ++oci_c23) {
            DepthwiseConv2d_global[((oci_c23 + 92))] = (DepthwiseConv2d_global[((oci_c23 + 92))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 51076) + ((i1_i2_fused % 56) * 904)) + (kh * 452)) + (ow_outer * 224)) + (kw * 4)) + oci_c23) + 184))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c23))]));
          }
          for (int32_t oci_c24 = 0; oci_c24 < 4; ++oci_c24) {
            DepthwiseConv2d_global[((oci_c24 + 96))] = (DepthwiseConv2d_global[((oci_c24 + 96))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 51076) + ((i1_i2_fused % 56) * 904)) + (kh * 452)) + (ow_outer * 224)) + (kw * 4)) + oci_c24) + 192))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c24))]));
          }
          for (int32_t oci_c25 = 0; oci_c25 < 4; ++oci_c25) {
            DepthwiseConv2d_global[((oci_c25 + 100))] = (DepthwiseConv2d_global[((oci_c25 + 100))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 51076) + ((i1_i2_fused % 56) * 904)) + (kh * 452)) + (ow_outer * 224)) + (kw * 4)) + oci_c25) + 200))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c25))]));
          }
          for (int32_t oci_c26 = 0; oci_c26 < 4; ++oci_c26) {
            DepthwiseConv2d_global[((oci_c26 + 104))] = (DepthwiseConv2d_global[((oci_c26 + 104))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 51076) + ((i1_i2_fused % 56) * 904)) + (kh * 452)) + (ow_outer * 224)) + (kw * 4)) + oci_c26) + 208))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c26))]));
          }
          for (int32_t oci_c27 = 0; oci_c27 < 4; ++oci_c27) {
            DepthwiseConv2d_global[((oci_c27 + 108))] = (DepthwiseConv2d_global[((oci_c27 + 108))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 56) * 51076) + ((i1_i2_fused % 56) * 904)) + (kh * 452)) + (ow_outer * 224)) + (kw * 4)) + oci_c27) + 216))] * ((float*)placeholder1)[((((((i1_i2_fused / 56) * 36) + (kh * 12)) + (kw * 4)) + oci_c27))]));
          }
        }
      }
      for (int32_t ow_inner = 0; ow_inner < 28; ++ow_inner) {
        for (int32_t oci = 0; oci < 4; ++oci) {
          DepthwiseConv2d[((((ow_outer * 112) + (ow_inner * 4)) + oci))] = DepthwiseConv2d_global[(((ow_inner * 4) + oci))];
        }
      }
    }
    for (int32_t i3_outer = 0; i3_outer < 2; ++i3_outer) {
      for (int32_t i3_inner = 0; i3_inner < 28; ++i3_inner) {
        for (int32_t i41 = 0; i41 < 4; ++i41) {
          float _1 = DepthwiseConv2d[((((i3_outer * 112) + (i3_inner * 4)) + i41))] + ((float*)placeholder2)[((((i1_i2_fused / 56) * 4) + i41))];
          float _2 = (_1) < (6.000000e+00f) ? (_1) : (6.000000e+00f);
          ((float*)compute)[(((((i1_i2_fused * 224) + (i3_outer * 112)) + (i3_inner * 4)) + i41))] = ((_2) > (0.000000e+00f) ? (_2) : (0.000000e+00f));
        }
      }
    }
  }
  if (TVMBackendFreeWorkspace(1, dev_id, PaddedInput) != 0) {
    return -1;
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_contrib_conv2d_NCHWc_add_clip_3(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int32_t arg2_code = ((int32_t*)arg_type_ids)[(2)];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int32_t arg3_code = ((int32_t*)arg_type_ids)[(3)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* placeholder1 = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  void* placeholder2 = (((DLTensor*)arg2)[0].data);
  void* arg2_shape = (((DLTensor*)arg2)[0].shape);
  void* arg2_strides = (((DLTensor*)arg2)[0].strides);
  void* compute = (((DLTensor*)arg3)[0].data);
  void* arg3_shape = (((DLTensor*)arg3)[0].shape);
  void* arg3_strides = (((DLTensor*)arg3)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  if (!(arg2_strides == NULL)) {
  }
  if (!(arg3_strides == NULL)) {
  }
  for (int32_t i0_i1_fused_i2_outer_fused = 0; i0_i1_fused_i2_outer_fused < 672; ++i0_i1_fused_i2_outer_fused) {
    float conv2d_NCHWc_global[112];
    for (int32_t oc_block_c_init = 0; oc_block_c_init < 4; ++oc_block_c_init) {
      conv2d_NCHWc_global[(oc_block_c_init)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init1 = 0; oc_block_c_init1 < 4; ++oc_block_c_init1) {
      conv2d_NCHWc_global[((oc_block_c_init1 + 4))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init2 = 0; oc_block_c_init2 < 4; ++oc_block_c_init2) {
      conv2d_NCHWc_global[((oc_block_c_init2 + 8))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init3 = 0; oc_block_c_init3 < 4; ++oc_block_c_init3) {
      conv2d_NCHWc_global[((oc_block_c_init3 + 12))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init4 = 0; oc_block_c_init4 < 4; ++oc_block_c_init4) {
      conv2d_NCHWc_global[((oc_block_c_init4 + 16))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init5 = 0; oc_block_c_init5 < 4; ++oc_block_c_init5) {
      conv2d_NCHWc_global[((oc_block_c_init5 + 20))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init6 = 0; oc_block_c_init6 < 4; ++oc_block_c_init6) {
      conv2d_NCHWc_global[((oc_block_c_init6 + 24))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init7 = 0; oc_block_c_init7 < 4; ++oc_block_c_init7) {
      conv2d_NCHWc_global[((oc_block_c_init7 + 28))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init8 = 0; oc_block_c_init8 < 4; ++oc_block_c_init8) {
      conv2d_NCHWc_global[((oc_block_c_init8 + 32))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init9 = 0; oc_block_c_init9 < 4; ++oc_block_c_init9) {
      conv2d_NCHWc_global[((oc_block_c_init9 + 36))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init10 = 0; oc_block_c_init10 < 4; ++oc_block_c_init10) {
      conv2d_NCHWc_global[((oc_block_c_init10 + 40))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init11 = 0; oc_block_c_init11 < 4; ++oc_block_c_init11) {
      conv2d_NCHWc_global[((oc_block_c_init11 + 44))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init12 = 0; oc_block_c_init12 < 4; ++oc_block_c_init12) {
      conv2d_NCHWc_global[((oc_block_c_init12 + 48))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init13 = 0; oc_block_c_init13 < 4; ++oc_block_c_init13) {
      conv2d_NCHWc_global[((oc_block_c_init13 + 52))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init14 = 0; oc_block_c_init14 < 4; ++oc_block_c_init14) {
      conv2d_NCHWc_global[((oc_block_c_init14 + 56))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init15 = 0; oc_block_c_init15 < 4; ++oc_block_c_init15) {
      conv2d_NCHWc_global[((oc_block_c_init15 + 60))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init16 = 0; oc_block_c_init16 < 4; ++oc_block_c_init16) {
      conv2d_NCHWc_global[((oc_block_c_init16 + 64))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init17 = 0; oc_block_c_init17 < 4; ++oc_block_c_init17) {
      conv2d_NCHWc_global[((oc_block_c_init17 + 68))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init18 = 0; oc_block_c_init18 < 4; ++oc_block_c_init18) {
      conv2d_NCHWc_global[((oc_block_c_init18 + 72))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init19 = 0; oc_block_c_init19 < 4; ++oc_block_c_init19) {
      conv2d_NCHWc_global[((oc_block_c_init19 + 76))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init20 = 0; oc_block_c_init20 < 4; ++oc_block_c_init20) {
      conv2d_NCHWc_global[((oc_block_c_init20 + 80))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init21 = 0; oc_block_c_init21 < 4; ++oc_block_c_init21) {
      conv2d_NCHWc_global[((oc_block_c_init21 + 84))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init22 = 0; oc_block_c_init22 < 4; ++oc_block_c_init22) {
      conv2d_NCHWc_global[((oc_block_c_init22 + 88))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init23 = 0; oc_block_c_init23 < 4; ++oc_block_c_init23) {
      conv2d_NCHWc_global[((oc_block_c_init23 + 92))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init24 = 0; oc_block_c_init24 < 4; ++oc_block_c_init24) {
      conv2d_NCHWc_global[((oc_block_c_init24 + 96))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init25 = 0; oc_block_c_init25 < 4; ++oc_block_c_init25) {
      conv2d_NCHWc_global[((oc_block_c_init25 + 100))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init26 = 0; oc_block_c_init26 < 4; ++oc_block_c_init26) {
      conv2d_NCHWc_global[((oc_block_c_init26 + 104))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init27 = 0; oc_block_c_init27 < 4; ++oc_block_c_init27) {
      conv2d_NCHWc_global[((oc_block_c_init27 + 108))] = 0.000000e+00f;
    }
    for (int32_t ic_outer = 0; ic_outer < 16; ++ic_outer) {
      for (int32_t ic_inner = 0; ic_inner < 4; ++ic_inner) {
        for (int32_t oc_block_c = 0; oc_block_c < 4; ++oc_block_c) {
          conv2d_NCHWc_global[(oc_block_c)] = (conv2d_NCHWc_global[(oc_block_c)] + (((float*)placeholder)[((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 256) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c))]));
        }
        for (int32_t oc_block_c1 = 0; oc_block_c1 < 4; ++oc_block_c1) {
          conv2d_NCHWc_global[((oc_block_c1 + 4))] = (conv2d_NCHWc_global[((oc_block_c1 + 4))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 4))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 256) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c1))]));
        }
        for (int32_t oc_block_c2 = 0; oc_block_c2 < 4; ++oc_block_c2) {
          conv2d_NCHWc_global[((oc_block_c2 + 8))] = (conv2d_NCHWc_global[((oc_block_c2 + 8))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 8))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 256) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c2))]));
        }
        for (int32_t oc_block_c3 = 0; oc_block_c3 < 4; ++oc_block_c3) {
          conv2d_NCHWc_global[((oc_block_c3 + 12))] = (conv2d_NCHWc_global[((oc_block_c3 + 12))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 12))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 256) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c3))]));
        }
        for (int32_t oc_block_c4 = 0; oc_block_c4 < 4; ++oc_block_c4) {
          conv2d_NCHWc_global[((oc_block_c4 + 16))] = (conv2d_NCHWc_global[((oc_block_c4 + 16))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 16))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 256) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c4))]));
        }
        for (int32_t oc_block_c5 = 0; oc_block_c5 < 4; ++oc_block_c5) {
          conv2d_NCHWc_global[((oc_block_c5 + 20))] = (conv2d_NCHWc_global[((oc_block_c5 + 20))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 20))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 256) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c5))]));
        }
        for (int32_t oc_block_c6 = 0; oc_block_c6 < 4; ++oc_block_c6) {
          conv2d_NCHWc_global[((oc_block_c6 + 24))] = (conv2d_NCHWc_global[((oc_block_c6 + 24))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 24))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 256) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c6))]));
        }
        for (int32_t oc_block_c7 = 0; oc_block_c7 < 4; ++oc_block_c7) {
          conv2d_NCHWc_global[((oc_block_c7 + 28))] = (conv2d_NCHWc_global[((oc_block_c7 + 28))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 28))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 256) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c7))]));
        }
        for (int32_t oc_block_c8 = 0; oc_block_c8 < 4; ++oc_block_c8) {
          conv2d_NCHWc_global[((oc_block_c8 + 32))] = (conv2d_NCHWc_global[((oc_block_c8 + 32))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 32))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 256) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c8))]));
        }
        for (int32_t oc_block_c9 = 0; oc_block_c9 < 4; ++oc_block_c9) {
          conv2d_NCHWc_global[((oc_block_c9 + 36))] = (conv2d_NCHWc_global[((oc_block_c9 + 36))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 36))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 256) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c9))]));
        }
        for (int32_t oc_block_c10 = 0; oc_block_c10 < 4; ++oc_block_c10) {
          conv2d_NCHWc_global[((oc_block_c10 + 40))] = (conv2d_NCHWc_global[((oc_block_c10 + 40))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 40))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 256) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c10))]));
        }
        for (int32_t oc_block_c11 = 0; oc_block_c11 < 4; ++oc_block_c11) {
          conv2d_NCHWc_global[((oc_block_c11 + 44))] = (conv2d_NCHWc_global[((oc_block_c11 + 44))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 44))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 256) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c11))]));
        }
        for (int32_t oc_block_c12 = 0; oc_block_c12 < 4; ++oc_block_c12) {
          conv2d_NCHWc_global[((oc_block_c12 + 48))] = (conv2d_NCHWc_global[((oc_block_c12 + 48))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 48))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 256) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c12))]));
        }
        for (int32_t oc_block_c13 = 0; oc_block_c13 < 4; ++oc_block_c13) {
          conv2d_NCHWc_global[((oc_block_c13 + 52))] = (conv2d_NCHWc_global[((oc_block_c13 + 52))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 52))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 256) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c13))]));
        }
        for (int32_t oc_block_c14 = 0; oc_block_c14 < 4; ++oc_block_c14) {
          conv2d_NCHWc_global[((oc_block_c14 + 56))] = (conv2d_NCHWc_global[((oc_block_c14 + 56))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 56))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 256) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c14))]));
        }
        for (int32_t oc_block_c15 = 0; oc_block_c15 < 4; ++oc_block_c15) {
          conv2d_NCHWc_global[((oc_block_c15 + 60))] = (conv2d_NCHWc_global[((oc_block_c15 + 60))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 60))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 256) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c15))]));
        }
        for (int32_t oc_block_c16 = 0; oc_block_c16 < 4; ++oc_block_c16) {
          conv2d_NCHWc_global[((oc_block_c16 + 64))] = (conv2d_NCHWc_global[((oc_block_c16 + 64))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 64))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 256) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c16))]));
        }
        for (int32_t oc_block_c17 = 0; oc_block_c17 < 4; ++oc_block_c17) {
          conv2d_NCHWc_global[((oc_block_c17 + 68))] = (conv2d_NCHWc_global[((oc_block_c17 + 68))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 68))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 256) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c17))]));
        }
        for (int32_t oc_block_c18 = 0; oc_block_c18 < 4; ++oc_block_c18) {
          conv2d_NCHWc_global[((oc_block_c18 + 72))] = (conv2d_NCHWc_global[((oc_block_c18 + 72))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 72))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 256) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c18))]));
        }
        for (int32_t oc_block_c19 = 0; oc_block_c19 < 4; ++oc_block_c19) {
          conv2d_NCHWc_global[((oc_block_c19 + 76))] = (conv2d_NCHWc_global[((oc_block_c19 + 76))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 76))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 256) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c19))]));
        }
        for (int32_t oc_block_c20 = 0; oc_block_c20 < 4; ++oc_block_c20) {
          conv2d_NCHWc_global[((oc_block_c20 + 80))] = (conv2d_NCHWc_global[((oc_block_c20 + 80))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 80))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 256) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c20))]));
        }
        for (int32_t oc_block_c21 = 0; oc_block_c21 < 4; ++oc_block_c21) {
          conv2d_NCHWc_global[((oc_block_c21 + 84))] = (conv2d_NCHWc_global[((oc_block_c21 + 84))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 84))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 256) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c21))]));
        }
        for (int32_t oc_block_c22 = 0; oc_block_c22 < 4; ++oc_block_c22) {
          conv2d_NCHWc_global[((oc_block_c22 + 88))] = (conv2d_NCHWc_global[((oc_block_c22 + 88))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 88))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 256) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c22))]));
        }
        for (int32_t oc_block_c23 = 0; oc_block_c23 < 4; ++oc_block_c23) {
          conv2d_NCHWc_global[((oc_block_c23 + 92))] = (conv2d_NCHWc_global[((oc_block_c23 + 92))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 92))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 256) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c23))]));
        }
        for (int32_t oc_block_c24 = 0; oc_block_c24 < 4; ++oc_block_c24) {
          conv2d_NCHWc_global[((oc_block_c24 + 96))] = (conv2d_NCHWc_global[((oc_block_c24 + 96))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 96))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 256) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c24))]));
        }
        for (int32_t oc_block_c25 = 0; oc_block_c25 < 4; ++oc_block_c25) {
          conv2d_NCHWc_global[((oc_block_c25 + 100))] = (conv2d_NCHWc_global[((oc_block_c25 + 100))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 100))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 256) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c25))]));
        }
        for (int32_t oc_block_c26 = 0; oc_block_c26 < 4; ++oc_block_c26) {
          conv2d_NCHWc_global[((oc_block_c26 + 104))] = (conv2d_NCHWc_global[((oc_block_c26 + 104))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 104))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 256) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c26))]));
        }
        for (int32_t oc_block_c27 = 0; oc_block_c27 < 4; ++oc_block_c27) {
          conv2d_NCHWc_global[((oc_block_c27 + 108))] = (conv2d_NCHWc_global[((oc_block_c27 + 108))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 108))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 256) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c27))]));
        }
      }
    }
    for (int32_t i2_inner = 0; i2_inner < 2; ++i2_inner) {
      for (int32_t i3_inner = 0; i3_inner < 14; ++i3_inner) {
        for (int32_t i4 = 0; i4 < 4; ++i4) {
          float _1 = conv2d_NCHWc_global[((((i2_inner * 56) + (i3_inner * 4)) + i4))] + ((float*)placeholder2)[((((i0_i1_fused_i2_outer_fused / 7) * 4) + i4))];
          float _2 = (_1) < (6.000000e+00f) ? (_1) : (6.000000e+00f);
          ((float*)compute)[(((((i0_i1_fused_i2_outer_fused * 112) + (i2_inner * 56)) + (i3_inner * 4)) + i4))] = ((_2) > (0.000000e+00f) ? (_2) : (0.000000e+00f));
        }
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_contrib_conv2d_NCHWc_add_add_2(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int32_t arg2_code = ((int32_t*)arg_type_ids)[(2)];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int32_t arg3_code = ((int32_t*)arg_type_ids)[(3)];
  void* arg4 = (((TVMValue*)args)[4].v_handle);
  int32_t arg4_code = ((int32_t*)arg_type_ids)[(4)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* placeholder1 = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  void* placeholder2 = (((DLTensor*)arg2)[0].data);
  void* arg2_shape = (((DLTensor*)arg2)[0].shape);
  void* arg2_strides = (((DLTensor*)arg2)[0].strides);
  void* placeholder3 = (((DLTensor*)arg3)[0].data);
  void* arg3_shape = (((DLTensor*)arg3)[0].shape);
  void* arg3_strides = (((DLTensor*)arg3)[0].strides);
  void* T_add = (((DLTensor*)arg4)[0].data);
  void* arg4_shape = (((DLTensor*)arg4)[0].shape);
  void* arg4_strides = (((DLTensor*)arg4)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  if (!(arg2_strides == NULL)) {
  }
  if (!(arg3_strides == NULL)) {
  }
  if (!(arg4_strides == NULL)) {
  }
  for (int32_t ax0_ax1_fused_ax2_outer_fused = 0; ax0_ax1_fused_ax2_outer_fused < 112; ++ax0_ax1_fused_ax2_outer_fused) {
    float conv2d_NCHWc_global[112];
    for (int32_t oc_block_c_init = 0; oc_block_c_init < 4; ++oc_block_c_init) {
      conv2d_NCHWc_global[(oc_block_c_init)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init1 = 0; oc_block_c_init1 < 4; ++oc_block_c_init1) {
      conv2d_NCHWc_global[((oc_block_c_init1 + 4))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init2 = 0; oc_block_c_init2 < 4; ++oc_block_c_init2) {
      conv2d_NCHWc_global[((oc_block_c_init2 + 8))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init3 = 0; oc_block_c_init3 < 4; ++oc_block_c_init3) {
      conv2d_NCHWc_global[((oc_block_c_init3 + 12))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init4 = 0; oc_block_c_init4 < 4; ++oc_block_c_init4) {
      conv2d_NCHWc_global[((oc_block_c_init4 + 16))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init5 = 0; oc_block_c_init5 < 4; ++oc_block_c_init5) {
      conv2d_NCHWc_global[((oc_block_c_init5 + 20))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init6 = 0; oc_block_c_init6 < 4; ++oc_block_c_init6) {
      conv2d_NCHWc_global[((oc_block_c_init6 + 24))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init7 = 0; oc_block_c_init7 < 4; ++oc_block_c_init7) {
      conv2d_NCHWc_global[((oc_block_c_init7 + 28))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init8 = 0; oc_block_c_init8 < 4; ++oc_block_c_init8) {
      conv2d_NCHWc_global[((oc_block_c_init8 + 32))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init9 = 0; oc_block_c_init9 < 4; ++oc_block_c_init9) {
      conv2d_NCHWc_global[((oc_block_c_init9 + 36))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init10 = 0; oc_block_c_init10 < 4; ++oc_block_c_init10) {
      conv2d_NCHWc_global[((oc_block_c_init10 + 40))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init11 = 0; oc_block_c_init11 < 4; ++oc_block_c_init11) {
      conv2d_NCHWc_global[((oc_block_c_init11 + 44))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init12 = 0; oc_block_c_init12 < 4; ++oc_block_c_init12) {
      conv2d_NCHWc_global[((oc_block_c_init12 + 48))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init13 = 0; oc_block_c_init13 < 4; ++oc_block_c_init13) {
      conv2d_NCHWc_global[((oc_block_c_init13 + 52))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init14 = 0; oc_block_c_init14 < 4; ++oc_block_c_init14) {
      conv2d_NCHWc_global[((oc_block_c_init14 + 56))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init15 = 0; oc_block_c_init15 < 4; ++oc_block_c_init15) {
      conv2d_NCHWc_global[((oc_block_c_init15 + 60))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init16 = 0; oc_block_c_init16 < 4; ++oc_block_c_init16) {
      conv2d_NCHWc_global[((oc_block_c_init16 + 64))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init17 = 0; oc_block_c_init17 < 4; ++oc_block_c_init17) {
      conv2d_NCHWc_global[((oc_block_c_init17 + 68))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init18 = 0; oc_block_c_init18 < 4; ++oc_block_c_init18) {
      conv2d_NCHWc_global[((oc_block_c_init18 + 72))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init19 = 0; oc_block_c_init19 < 4; ++oc_block_c_init19) {
      conv2d_NCHWc_global[((oc_block_c_init19 + 76))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init20 = 0; oc_block_c_init20 < 4; ++oc_block_c_init20) {
      conv2d_NCHWc_global[((oc_block_c_init20 + 80))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init21 = 0; oc_block_c_init21 < 4; ++oc_block_c_init21) {
      conv2d_NCHWc_global[((oc_block_c_init21 + 84))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init22 = 0; oc_block_c_init22 < 4; ++oc_block_c_init22) {
      conv2d_NCHWc_global[((oc_block_c_init22 + 88))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init23 = 0; oc_block_c_init23 < 4; ++oc_block_c_init23) {
      conv2d_NCHWc_global[((oc_block_c_init23 + 92))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init24 = 0; oc_block_c_init24 < 4; ++oc_block_c_init24) {
      conv2d_NCHWc_global[((oc_block_c_init24 + 96))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init25 = 0; oc_block_c_init25 < 4; ++oc_block_c_init25) {
      conv2d_NCHWc_global[((oc_block_c_init25 + 100))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init26 = 0; oc_block_c_init26 < 4; ++oc_block_c_init26) {
      conv2d_NCHWc_global[((oc_block_c_init26 + 104))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init27 = 0; oc_block_c_init27 < 4; ++oc_block_c_init27) {
      conv2d_NCHWc_global[((oc_block_c_init27 + 108))] = 0.000000e+00f;
    }
    for (int32_t ic_outer = 0; ic_outer < 96; ++ic_outer) {
      for (int32_t ic_inner = 0; ic_inner < 4; ++ic_inner) {
        for (int32_t oc_block_c = 0; oc_block_c < 4; ++oc_block_c) {
          conv2d_NCHWc_global[(oc_block_c)] = (conv2d_NCHWc_global[(oc_block_c)] + (((float*)placeholder)[((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c))]));
        }
        for (int32_t oc_block_c1 = 0; oc_block_c1 < 4; ++oc_block_c1) {
          conv2d_NCHWc_global[((oc_block_c1 + 4))] = (conv2d_NCHWc_global[((oc_block_c1 + 4))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 4))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c1))]));
        }
        for (int32_t oc_block_c2 = 0; oc_block_c2 < 4; ++oc_block_c2) {
          conv2d_NCHWc_global[((oc_block_c2 + 8))] = (conv2d_NCHWc_global[((oc_block_c2 + 8))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 8))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c2))]));
        }
        for (int32_t oc_block_c3 = 0; oc_block_c3 < 4; ++oc_block_c3) {
          conv2d_NCHWc_global[((oc_block_c3 + 12))] = (conv2d_NCHWc_global[((oc_block_c3 + 12))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 12))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c3))]));
        }
        for (int32_t oc_block_c4 = 0; oc_block_c4 < 4; ++oc_block_c4) {
          conv2d_NCHWc_global[((oc_block_c4 + 16))] = (conv2d_NCHWc_global[((oc_block_c4 + 16))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 16))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c4))]));
        }
        for (int32_t oc_block_c5 = 0; oc_block_c5 < 4; ++oc_block_c5) {
          conv2d_NCHWc_global[((oc_block_c5 + 20))] = (conv2d_NCHWc_global[((oc_block_c5 + 20))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 20))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c5))]));
        }
        for (int32_t oc_block_c6 = 0; oc_block_c6 < 4; ++oc_block_c6) {
          conv2d_NCHWc_global[((oc_block_c6 + 24))] = (conv2d_NCHWc_global[((oc_block_c6 + 24))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 24))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c6))]));
        }
        for (int32_t oc_block_c7 = 0; oc_block_c7 < 4; ++oc_block_c7) {
          conv2d_NCHWc_global[((oc_block_c7 + 28))] = (conv2d_NCHWc_global[((oc_block_c7 + 28))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 28))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c7))]));
        }
        for (int32_t oc_block_c8 = 0; oc_block_c8 < 4; ++oc_block_c8) {
          conv2d_NCHWc_global[((oc_block_c8 + 32))] = (conv2d_NCHWc_global[((oc_block_c8 + 32))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 32))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c8))]));
        }
        for (int32_t oc_block_c9 = 0; oc_block_c9 < 4; ++oc_block_c9) {
          conv2d_NCHWc_global[((oc_block_c9 + 36))] = (conv2d_NCHWc_global[((oc_block_c9 + 36))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 36))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c9))]));
        }
        for (int32_t oc_block_c10 = 0; oc_block_c10 < 4; ++oc_block_c10) {
          conv2d_NCHWc_global[((oc_block_c10 + 40))] = (conv2d_NCHWc_global[((oc_block_c10 + 40))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 40))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c10))]));
        }
        for (int32_t oc_block_c11 = 0; oc_block_c11 < 4; ++oc_block_c11) {
          conv2d_NCHWc_global[((oc_block_c11 + 44))] = (conv2d_NCHWc_global[((oc_block_c11 + 44))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 44))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c11))]));
        }
        for (int32_t oc_block_c12 = 0; oc_block_c12 < 4; ++oc_block_c12) {
          conv2d_NCHWc_global[((oc_block_c12 + 48))] = (conv2d_NCHWc_global[((oc_block_c12 + 48))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 48))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c12))]));
        }
        for (int32_t oc_block_c13 = 0; oc_block_c13 < 4; ++oc_block_c13) {
          conv2d_NCHWc_global[((oc_block_c13 + 52))] = (conv2d_NCHWc_global[((oc_block_c13 + 52))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 52))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c13))]));
        }
        for (int32_t oc_block_c14 = 0; oc_block_c14 < 4; ++oc_block_c14) {
          conv2d_NCHWc_global[((oc_block_c14 + 56))] = (conv2d_NCHWc_global[((oc_block_c14 + 56))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 56))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c14))]));
        }
        for (int32_t oc_block_c15 = 0; oc_block_c15 < 4; ++oc_block_c15) {
          conv2d_NCHWc_global[((oc_block_c15 + 60))] = (conv2d_NCHWc_global[((oc_block_c15 + 60))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 60))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c15))]));
        }
        for (int32_t oc_block_c16 = 0; oc_block_c16 < 4; ++oc_block_c16) {
          conv2d_NCHWc_global[((oc_block_c16 + 64))] = (conv2d_NCHWc_global[((oc_block_c16 + 64))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 64))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c16))]));
        }
        for (int32_t oc_block_c17 = 0; oc_block_c17 < 4; ++oc_block_c17) {
          conv2d_NCHWc_global[((oc_block_c17 + 68))] = (conv2d_NCHWc_global[((oc_block_c17 + 68))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 68))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c17))]));
        }
        for (int32_t oc_block_c18 = 0; oc_block_c18 < 4; ++oc_block_c18) {
          conv2d_NCHWc_global[((oc_block_c18 + 72))] = (conv2d_NCHWc_global[((oc_block_c18 + 72))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 72))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c18))]));
        }
        for (int32_t oc_block_c19 = 0; oc_block_c19 < 4; ++oc_block_c19) {
          conv2d_NCHWc_global[((oc_block_c19 + 76))] = (conv2d_NCHWc_global[((oc_block_c19 + 76))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 76))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c19))]));
        }
        for (int32_t oc_block_c20 = 0; oc_block_c20 < 4; ++oc_block_c20) {
          conv2d_NCHWc_global[((oc_block_c20 + 80))] = (conv2d_NCHWc_global[((oc_block_c20 + 80))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 80))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c20))]));
        }
        for (int32_t oc_block_c21 = 0; oc_block_c21 < 4; ++oc_block_c21) {
          conv2d_NCHWc_global[((oc_block_c21 + 84))] = (conv2d_NCHWc_global[((oc_block_c21 + 84))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 84))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c21))]));
        }
        for (int32_t oc_block_c22 = 0; oc_block_c22 < 4; ++oc_block_c22) {
          conv2d_NCHWc_global[((oc_block_c22 + 88))] = (conv2d_NCHWc_global[((oc_block_c22 + 88))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 88))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c22))]));
        }
        for (int32_t oc_block_c23 = 0; oc_block_c23 < 4; ++oc_block_c23) {
          conv2d_NCHWc_global[((oc_block_c23 + 92))] = (conv2d_NCHWc_global[((oc_block_c23 + 92))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 92))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c23))]));
        }
        for (int32_t oc_block_c24 = 0; oc_block_c24 < 4; ++oc_block_c24) {
          conv2d_NCHWc_global[((oc_block_c24 + 96))] = (conv2d_NCHWc_global[((oc_block_c24 + 96))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 96))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c24))]));
        }
        for (int32_t oc_block_c25 = 0; oc_block_c25 < 4; ++oc_block_c25) {
          conv2d_NCHWc_global[((oc_block_c25 + 100))] = (conv2d_NCHWc_global[((oc_block_c25 + 100))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 100))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c25))]));
        }
        for (int32_t oc_block_c26 = 0; oc_block_c26 < 4; ++oc_block_c26) {
          conv2d_NCHWc_global[((oc_block_c26 + 104))] = (conv2d_NCHWc_global[((oc_block_c26 + 104))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 104))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c26))]));
        }
        for (int32_t oc_block_c27 = 0; oc_block_c27 < 4; ++oc_block_c27) {
          conv2d_NCHWc_global[((oc_block_c27 + 108))] = (conv2d_NCHWc_global[((oc_block_c27 + 108))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 108))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 1536) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c27))]));
        }
      }
    }
    for (int32_t ax2_inner = 0; ax2_inner < 2; ++ax2_inner) {
      for (int32_t ax3_inner = 0; ax3_inner < 14; ++ax3_inner) {
        for (int32_t ax4 = 0; ax4 < 4; ++ax4) {
          ((float*)T_add)[(((((ax0_ax1_fused_ax2_outer_fused * 112) + (ax2_inner * 56)) + (ax3_inner * 4)) + ax4))] = ((conv2d_NCHWc_global[((((ax2_inner * 56) + (ax3_inner * 4)) + ax4))] + ((float*)placeholder2)[((((ax0_ax1_fused_ax2_outer_fused / 7) * 4) + ax4))]) + ((float*)placeholder3)[(((((ax0_ax1_fused_ax2_outer_fused * 112) + (ax2_inner * 56)) + (ax3_inner * 4)) + ax4))]);
        }
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_contrib_conv2d_NCHWc_add_clip_2(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int32_t arg2_code = ((int32_t*)arg_type_ids)[(2)];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int32_t arg3_code = ((int32_t*)arg_type_ids)[(3)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* placeholder1 = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  void* placeholder2 = (((DLTensor*)arg2)[0].data);
  void* arg2_shape = (((DLTensor*)arg2)[0].shape);
  void* arg2_strides = (((DLTensor*)arg2)[0].strides);
  void* compute = (((DLTensor*)arg3)[0].data);
  void* arg3_shape = (((DLTensor*)arg3)[0].shape);
  void* arg3_strides = (((DLTensor*)arg3)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  if (!(arg2_strides == NULL)) {
  }
  if (!(arg3_strides == NULL)) {
  }
  for (int32_t i0_i1_fused_i2_outer_fused = 0; i0_i1_fused_i2_outer_fused < 1008; ++i0_i1_fused_i2_outer_fused) {
    float conv2d_NCHWc_global[112];
    for (int32_t oc_block_c_init = 0; oc_block_c_init < 4; ++oc_block_c_init) {
      conv2d_NCHWc_global[(oc_block_c_init)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init1 = 0; oc_block_c_init1 < 4; ++oc_block_c_init1) {
      conv2d_NCHWc_global[((oc_block_c_init1 + 4))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init2 = 0; oc_block_c_init2 < 4; ++oc_block_c_init2) {
      conv2d_NCHWc_global[((oc_block_c_init2 + 8))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init3 = 0; oc_block_c_init3 < 4; ++oc_block_c_init3) {
      conv2d_NCHWc_global[((oc_block_c_init3 + 12))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init4 = 0; oc_block_c_init4 < 4; ++oc_block_c_init4) {
      conv2d_NCHWc_global[((oc_block_c_init4 + 16))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init5 = 0; oc_block_c_init5 < 4; ++oc_block_c_init5) {
      conv2d_NCHWc_global[((oc_block_c_init5 + 20))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init6 = 0; oc_block_c_init6 < 4; ++oc_block_c_init6) {
      conv2d_NCHWc_global[((oc_block_c_init6 + 24))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init7 = 0; oc_block_c_init7 < 4; ++oc_block_c_init7) {
      conv2d_NCHWc_global[((oc_block_c_init7 + 28))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init8 = 0; oc_block_c_init8 < 4; ++oc_block_c_init8) {
      conv2d_NCHWc_global[((oc_block_c_init8 + 32))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init9 = 0; oc_block_c_init9 < 4; ++oc_block_c_init9) {
      conv2d_NCHWc_global[((oc_block_c_init9 + 36))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init10 = 0; oc_block_c_init10 < 4; ++oc_block_c_init10) {
      conv2d_NCHWc_global[((oc_block_c_init10 + 40))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init11 = 0; oc_block_c_init11 < 4; ++oc_block_c_init11) {
      conv2d_NCHWc_global[((oc_block_c_init11 + 44))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init12 = 0; oc_block_c_init12 < 4; ++oc_block_c_init12) {
      conv2d_NCHWc_global[((oc_block_c_init12 + 48))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init13 = 0; oc_block_c_init13 < 4; ++oc_block_c_init13) {
      conv2d_NCHWc_global[((oc_block_c_init13 + 52))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init14 = 0; oc_block_c_init14 < 4; ++oc_block_c_init14) {
      conv2d_NCHWc_global[((oc_block_c_init14 + 56))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init15 = 0; oc_block_c_init15 < 4; ++oc_block_c_init15) {
      conv2d_NCHWc_global[((oc_block_c_init15 + 60))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init16 = 0; oc_block_c_init16 < 4; ++oc_block_c_init16) {
      conv2d_NCHWc_global[((oc_block_c_init16 + 64))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init17 = 0; oc_block_c_init17 < 4; ++oc_block_c_init17) {
      conv2d_NCHWc_global[((oc_block_c_init17 + 68))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init18 = 0; oc_block_c_init18 < 4; ++oc_block_c_init18) {
      conv2d_NCHWc_global[((oc_block_c_init18 + 72))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init19 = 0; oc_block_c_init19 < 4; ++oc_block_c_init19) {
      conv2d_NCHWc_global[((oc_block_c_init19 + 76))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init20 = 0; oc_block_c_init20 < 4; ++oc_block_c_init20) {
      conv2d_NCHWc_global[((oc_block_c_init20 + 80))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init21 = 0; oc_block_c_init21 < 4; ++oc_block_c_init21) {
      conv2d_NCHWc_global[((oc_block_c_init21 + 84))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init22 = 0; oc_block_c_init22 < 4; ++oc_block_c_init22) {
      conv2d_NCHWc_global[((oc_block_c_init22 + 88))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init23 = 0; oc_block_c_init23 < 4; ++oc_block_c_init23) {
      conv2d_NCHWc_global[((oc_block_c_init23 + 92))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init24 = 0; oc_block_c_init24 < 4; ++oc_block_c_init24) {
      conv2d_NCHWc_global[((oc_block_c_init24 + 96))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init25 = 0; oc_block_c_init25 < 4; ++oc_block_c_init25) {
      conv2d_NCHWc_global[((oc_block_c_init25 + 100))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init26 = 0; oc_block_c_init26 < 4; ++oc_block_c_init26) {
      conv2d_NCHWc_global[((oc_block_c_init26 + 104))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init27 = 0; oc_block_c_init27 < 4; ++oc_block_c_init27) {
      conv2d_NCHWc_global[((oc_block_c_init27 + 108))] = 0.000000e+00f;
    }
    for (int32_t ic_outer = 0; ic_outer < 24; ++ic_outer) {
      for (int32_t ic_inner = 0; ic_inner < 4; ++ic_inner) {
        for (int32_t oc_block_c = 0; oc_block_c < 4; ++oc_block_c) {
          conv2d_NCHWc_global[(oc_block_c)] = (conv2d_NCHWc_global[(oc_block_c)] + (((float*)placeholder)[((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c))]));
        }
        for (int32_t oc_block_c1 = 0; oc_block_c1 < 4; ++oc_block_c1) {
          conv2d_NCHWc_global[((oc_block_c1 + 4))] = (conv2d_NCHWc_global[((oc_block_c1 + 4))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 4))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c1))]));
        }
        for (int32_t oc_block_c2 = 0; oc_block_c2 < 4; ++oc_block_c2) {
          conv2d_NCHWc_global[((oc_block_c2 + 8))] = (conv2d_NCHWc_global[((oc_block_c2 + 8))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 8))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c2))]));
        }
        for (int32_t oc_block_c3 = 0; oc_block_c3 < 4; ++oc_block_c3) {
          conv2d_NCHWc_global[((oc_block_c3 + 12))] = (conv2d_NCHWc_global[((oc_block_c3 + 12))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 12))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c3))]));
        }
        for (int32_t oc_block_c4 = 0; oc_block_c4 < 4; ++oc_block_c4) {
          conv2d_NCHWc_global[((oc_block_c4 + 16))] = (conv2d_NCHWc_global[((oc_block_c4 + 16))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 16))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c4))]));
        }
        for (int32_t oc_block_c5 = 0; oc_block_c5 < 4; ++oc_block_c5) {
          conv2d_NCHWc_global[((oc_block_c5 + 20))] = (conv2d_NCHWc_global[((oc_block_c5 + 20))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 20))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c5))]));
        }
        for (int32_t oc_block_c6 = 0; oc_block_c6 < 4; ++oc_block_c6) {
          conv2d_NCHWc_global[((oc_block_c6 + 24))] = (conv2d_NCHWc_global[((oc_block_c6 + 24))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 24))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c6))]));
        }
        for (int32_t oc_block_c7 = 0; oc_block_c7 < 4; ++oc_block_c7) {
          conv2d_NCHWc_global[((oc_block_c7 + 28))] = (conv2d_NCHWc_global[((oc_block_c7 + 28))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 28))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c7))]));
        }
        for (int32_t oc_block_c8 = 0; oc_block_c8 < 4; ++oc_block_c8) {
          conv2d_NCHWc_global[((oc_block_c8 + 32))] = (conv2d_NCHWc_global[((oc_block_c8 + 32))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 32))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c8))]));
        }
        for (int32_t oc_block_c9 = 0; oc_block_c9 < 4; ++oc_block_c9) {
          conv2d_NCHWc_global[((oc_block_c9 + 36))] = (conv2d_NCHWc_global[((oc_block_c9 + 36))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 36))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c9))]));
        }
        for (int32_t oc_block_c10 = 0; oc_block_c10 < 4; ++oc_block_c10) {
          conv2d_NCHWc_global[((oc_block_c10 + 40))] = (conv2d_NCHWc_global[((oc_block_c10 + 40))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 40))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c10))]));
        }
        for (int32_t oc_block_c11 = 0; oc_block_c11 < 4; ++oc_block_c11) {
          conv2d_NCHWc_global[((oc_block_c11 + 44))] = (conv2d_NCHWc_global[((oc_block_c11 + 44))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 44))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c11))]));
        }
        for (int32_t oc_block_c12 = 0; oc_block_c12 < 4; ++oc_block_c12) {
          conv2d_NCHWc_global[((oc_block_c12 + 48))] = (conv2d_NCHWc_global[((oc_block_c12 + 48))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 48))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c12))]));
        }
        for (int32_t oc_block_c13 = 0; oc_block_c13 < 4; ++oc_block_c13) {
          conv2d_NCHWc_global[((oc_block_c13 + 52))] = (conv2d_NCHWc_global[((oc_block_c13 + 52))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 52))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c13))]));
        }
        for (int32_t oc_block_c14 = 0; oc_block_c14 < 4; ++oc_block_c14) {
          conv2d_NCHWc_global[((oc_block_c14 + 56))] = (conv2d_NCHWc_global[((oc_block_c14 + 56))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 56))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c14))]));
        }
        for (int32_t oc_block_c15 = 0; oc_block_c15 < 4; ++oc_block_c15) {
          conv2d_NCHWc_global[((oc_block_c15 + 60))] = (conv2d_NCHWc_global[((oc_block_c15 + 60))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 60))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c15))]));
        }
        for (int32_t oc_block_c16 = 0; oc_block_c16 < 4; ++oc_block_c16) {
          conv2d_NCHWc_global[((oc_block_c16 + 64))] = (conv2d_NCHWc_global[((oc_block_c16 + 64))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 64))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c16))]));
        }
        for (int32_t oc_block_c17 = 0; oc_block_c17 < 4; ++oc_block_c17) {
          conv2d_NCHWc_global[((oc_block_c17 + 68))] = (conv2d_NCHWc_global[((oc_block_c17 + 68))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 68))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c17))]));
        }
        for (int32_t oc_block_c18 = 0; oc_block_c18 < 4; ++oc_block_c18) {
          conv2d_NCHWc_global[((oc_block_c18 + 72))] = (conv2d_NCHWc_global[((oc_block_c18 + 72))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 72))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c18))]));
        }
        for (int32_t oc_block_c19 = 0; oc_block_c19 < 4; ++oc_block_c19) {
          conv2d_NCHWc_global[((oc_block_c19 + 76))] = (conv2d_NCHWc_global[((oc_block_c19 + 76))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 76))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c19))]));
        }
        for (int32_t oc_block_c20 = 0; oc_block_c20 < 4; ++oc_block_c20) {
          conv2d_NCHWc_global[((oc_block_c20 + 80))] = (conv2d_NCHWc_global[((oc_block_c20 + 80))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 80))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c20))]));
        }
        for (int32_t oc_block_c21 = 0; oc_block_c21 < 4; ++oc_block_c21) {
          conv2d_NCHWc_global[((oc_block_c21 + 84))] = (conv2d_NCHWc_global[((oc_block_c21 + 84))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 84))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c21))]));
        }
        for (int32_t oc_block_c22 = 0; oc_block_c22 < 4; ++oc_block_c22) {
          conv2d_NCHWc_global[((oc_block_c22 + 88))] = (conv2d_NCHWc_global[((oc_block_c22 + 88))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 88))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c22))]));
        }
        for (int32_t oc_block_c23 = 0; oc_block_c23 < 4; ++oc_block_c23) {
          conv2d_NCHWc_global[((oc_block_c23 + 92))] = (conv2d_NCHWc_global[((oc_block_c23 + 92))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 92))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c23))]));
        }
        for (int32_t oc_block_c24 = 0; oc_block_c24 < 4; ++oc_block_c24) {
          conv2d_NCHWc_global[((oc_block_c24 + 96))] = (conv2d_NCHWc_global[((oc_block_c24 + 96))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 96))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c24))]));
        }
        for (int32_t oc_block_c25 = 0; oc_block_c25 < 4; ++oc_block_c25) {
          conv2d_NCHWc_global[((oc_block_c25 + 100))] = (conv2d_NCHWc_global[((oc_block_c25 + 100))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 100))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c25))]));
        }
        for (int32_t oc_block_c26 = 0; oc_block_c26 < 4; ++oc_block_c26) {
          conv2d_NCHWc_global[((oc_block_c26 + 104))] = (conv2d_NCHWc_global[((oc_block_c26 + 104))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 104))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c26))]));
        }
        for (int32_t oc_block_c27 = 0; oc_block_c27 < 4; ++oc_block_c27) {
          conv2d_NCHWc_global[((oc_block_c27 + 108))] = (conv2d_NCHWc_global[((oc_block_c27 + 108))] + (((float*)placeholder)[(((((ic_outer * 784) + ((i0_i1_fused_i2_outer_fused % 7) * 112)) + ic_inner) + 108))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 384) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c27))]));
        }
      }
    }
    for (int32_t i2_inner = 0; i2_inner < 2; ++i2_inner) {
      for (int32_t i3_inner = 0; i3_inner < 14; ++i3_inner) {
        for (int32_t i4 = 0; i4 < 4; ++i4) {
          float _1 = conv2d_NCHWc_global[((((i2_inner * 56) + (i3_inner * 4)) + i4))] + ((float*)placeholder2)[((((i0_i1_fused_i2_outer_fused / 7) * 4) + i4))];
          float _2 = (_1) < (6.000000e+00f) ? (_1) : (6.000000e+00f);
          ((float*)compute)[(((((i0_i1_fused_i2_outer_fused * 112) + (i2_inner * 56)) + (i3_inner * 4)) + i4))] = ((_2) > (0.000000e+00f) ? (_2) : (0.000000e+00f));
        }
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_contrib_conv2d_NCHWc_add_clip(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int32_t arg2_code = ((int32_t*)arg_type_ids)[(2)];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int32_t arg3_code = ((int32_t*)arg_type_ids)[(3)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* placeholder1 = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  void* placeholder2 = (((DLTensor*)arg2)[0].data);
  void* arg2_shape = (((DLTensor*)arg2)[0].shape);
  void* arg2_strides = (((DLTensor*)arg2)[0].strides);
  void* compute = (((DLTensor*)arg3)[0].data);
  void* arg3_shape = (((DLTensor*)arg3)[0].shape);
  void* arg3_strides = (((DLTensor*)arg3)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  if (!(arg2_strides == NULL)) {
  }
  if (!(arg3_strides == NULL)) {
  }
  for (int32_t i0_i1_fused_i2_outer_fused = 0; i0_i1_fused_i2_outer_fused < 2240; ++i0_i1_fused_i2_outer_fused) {
    float conv2d_NCHWc_global[28];
    for (int32_t oc_block_c_init = 0; oc_block_c_init < 4; ++oc_block_c_init) {
      conv2d_NCHWc_global[(oc_block_c_init)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init1 = 0; oc_block_c_init1 < 4; ++oc_block_c_init1) {
      conv2d_NCHWc_global[((oc_block_c_init1 + 4))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init2 = 0; oc_block_c_init2 < 4; ++oc_block_c_init2) {
      conv2d_NCHWc_global[((oc_block_c_init2 + 8))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init3 = 0; oc_block_c_init3 < 4; ++oc_block_c_init3) {
      conv2d_NCHWc_global[((oc_block_c_init3 + 12))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init4 = 0; oc_block_c_init4 < 4; ++oc_block_c_init4) {
      conv2d_NCHWc_global[((oc_block_c_init4 + 16))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init5 = 0; oc_block_c_init5 < 4; ++oc_block_c_init5) {
      conv2d_NCHWc_global[((oc_block_c_init5 + 20))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init6 = 0; oc_block_c_init6 < 4; ++oc_block_c_init6) {
      conv2d_NCHWc_global[((oc_block_c_init6 + 24))] = 0.000000e+00f;
    }
    for (int32_t ic_outer = 0; ic_outer < 80; ++ic_outer) {
      for (int32_t ic_inner = 0; ic_inner < 4; ++ic_inner) {
        for (int32_t oc_block_c = 0; oc_block_c < 4; ++oc_block_c) {
          conv2d_NCHWc_global[(oc_block_c)] = (conv2d_NCHWc_global[(oc_block_c)] + (((float*)placeholder)[((((ic_outer * 196) + ((i0_i1_fused_i2_outer_fused % 7) * 28)) + ic_inner))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 1280) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c))]));
        }
        for (int32_t oc_block_c1 = 0; oc_block_c1 < 4; ++oc_block_c1) {
          conv2d_NCHWc_global[((oc_block_c1 + 4))] = (conv2d_NCHWc_global[((oc_block_c1 + 4))] + (((float*)placeholder)[(((((ic_outer * 196) + ((i0_i1_fused_i2_outer_fused % 7) * 28)) + ic_inner) + 4))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 1280) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c1))]));
        }
        for (int32_t oc_block_c2 = 0; oc_block_c2 < 4; ++oc_block_c2) {
          conv2d_NCHWc_global[((oc_block_c2 + 8))] = (conv2d_NCHWc_global[((oc_block_c2 + 8))] + (((float*)placeholder)[(((((ic_outer * 196) + ((i0_i1_fused_i2_outer_fused % 7) * 28)) + ic_inner) + 8))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 1280) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c2))]));
        }
        for (int32_t oc_block_c3 = 0; oc_block_c3 < 4; ++oc_block_c3) {
          conv2d_NCHWc_global[((oc_block_c3 + 12))] = (conv2d_NCHWc_global[((oc_block_c3 + 12))] + (((float*)placeholder)[(((((ic_outer * 196) + ((i0_i1_fused_i2_outer_fused % 7) * 28)) + ic_inner) + 12))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 1280) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c3))]));
        }
        for (int32_t oc_block_c4 = 0; oc_block_c4 < 4; ++oc_block_c4) {
          conv2d_NCHWc_global[((oc_block_c4 + 16))] = (conv2d_NCHWc_global[((oc_block_c4 + 16))] + (((float*)placeholder)[(((((ic_outer * 196) + ((i0_i1_fused_i2_outer_fused % 7) * 28)) + ic_inner) + 16))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 1280) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c4))]));
        }
        for (int32_t oc_block_c5 = 0; oc_block_c5 < 4; ++oc_block_c5) {
          conv2d_NCHWc_global[((oc_block_c5 + 20))] = (conv2d_NCHWc_global[((oc_block_c5 + 20))] + (((float*)placeholder)[(((((ic_outer * 196) + ((i0_i1_fused_i2_outer_fused % 7) * 28)) + ic_inner) + 20))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 1280) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c5))]));
        }
        for (int32_t oc_block_c6 = 0; oc_block_c6 < 4; ++oc_block_c6) {
          conv2d_NCHWc_global[((oc_block_c6 + 24))] = (conv2d_NCHWc_global[((oc_block_c6 + 24))] + (((float*)placeholder)[(((((ic_outer * 196) + ((i0_i1_fused_i2_outer_fused % 7) * 28)) + ic_inner) + 24))] * ((float*)placeholder1)[((((((i0_i1_fused_i2_outer_fused / 7) * 1280) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c6))]));
        }
      }
    }
    for (int32_t i3_inner = 0; i3_inner < 7; ++i3_inner) {
      for (int32_t i4 = 0; i4 < 4; ++i4) {
        float _1 = conv2d_NCHWc_global[(((i3_inner * 4) + i4))] + ((float*)placeholder2)[((((i0_i1_fused_i2_outer_fused / 7) * 4) + i4))];
        float _2 = (_1) < (6.000000e+00f) ? (_1) : (6.000000e+00f);
        ((float*)compute)[((((i0_i1_fused_i2_outer_fused * 28) + (i3_inner * 4)) + i4))] = ((_2) > (0.000000e+00f) ? (_2) : (0.000000e+00f));
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_contrib_conv2d_NCHWc_add_add(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int32_t arg2_code = ((int32_t*)arg_type_ids)[(2)];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int32_t arg3_code = ((int32_t*)arg_type_ids)[(3)];
  void* arg4 = (((TVMValue*)args)[4].v_handle);
  int32_t arg4_code = ((int32_t*)arg_type_ids)[(4)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* placeholder1 = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  void* placeholder2 = (((DLTensor*)arg2)[0].data);
  void* arg2_shape = (((DLTensor*)arg2)[0].shape);
  void* arg2_strides = (((DLTensor*)arg2)[0].strides);
  void* placeholder3 = (((DLTensor*)arg3)[0].data);
  void* arg3_shape = (((DLTensor*)arg3)[0].shape);
  void* arg3_strides = (((DLTensor*)arg3)[0].strides);
  void* T_add = (((DLTensor*)arg4)[0].data);
  void* arg4_shape = (((DLTensor*)arg4)[0].shape);
  void* arg4_strides = (((DLTensor*)arg4)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  if (!(arg2_strides == NULL)) {
  }
  if (!(arg3_strides == NULL)) {
  }
  if (!(arg4_strides == NULL)) {
  }
  for (int32_t ax0_ax1_fused_ax2_outer_fused = 0; ax0_ax1_fused_ax2_outer_fused < 280; ++ax0_ax1_fused_ax2_outer_fused) {
    float conv2d_NCHWc_global[28];
    for (int32_t oc_block_c_init = 0; oc_block_c_init < 4; ++oc_block_c_init) {
      conv2d_NCHWc_global[(oc_block_c_init)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init1 = 0; oc_block_c_init1 < 4; ++oc_block_c_init1) {
      conv2d_NCHWc_global[((oc_block_c_init1 + 4))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init2 = 0; oc_block_c_init2 < 4; ++oc_block_c_init2) {
      conv2d_NCHWc_global[((oc_block_c_init2 + 8))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init3 = 0; oc_block_c_init3 < 4; ++oc_block_c_init3) {
      conv2d_NCHWc_global[((oc_block_c_init3 + 12))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init4 = 0; oc_block_c_init4 < 4; ++oc_block_c_init4) {
      conv2d_NCHWc_global[((oc_block_c_init4 + 16))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init5 = 0; oc_block_c_init5 < 4; ++oc_block_c_init5) {
      conv2d_NCHWc_global[((oc_block_c_init5 + 20))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init6 = 0; oc_block_c_init6 < 4; ++oc_block_c_init6) {
      conv2d_NCHWc_global[((oc_block_c_init6 + 24))] = 0.000000e+00f;
    }
    for (int32_t ic_outer = 0; ic_outer < 240; ++ic_outer) {
      for (int32_t ic_inner = 0; ic_inner < 4; ++ic_inner) {
        for (int32_t oc_block_c = 0; oc_block_c < 4; ++oc_block_c) {
          conv2d_NCHWc_global[(oc_block_c)] = (conv2d_NCHWc_global[(oc_block_c)] + (((float*)placeholder)[((((ic_outer * 196) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 28)) + ic_inner))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 3840) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c))]));
        }
        for (int32_t oc_block_c1 = 0; oc_block_c1 < 4; ++oc_block_c1) {
          conv2d_NCHWc_global[((oc_block_c1 + 4))] = (conv2d_NCHWc_global[((oc_block_c1 + 4))] + (((float*)placeholder)[(((((ic_outer * 196) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 28)) + ic_inner) + 4))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 3840) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c1))]));
        }
        for (int32_t oc_block_c2 = 0; oc_block_c2 < 4; ++oc_block_c2) {
          conv2d_NCHWc_global[((oc_block_c2 + 8))] = (conv2d_NCHWc_global[((oc_block_c2 + 8))] + (((float*)placeholder)[(((((ic_outer * 196) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 28)) + ic_inner) + 8))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 3840) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c2))]));
        }
        for (int32_t oc_block_c3 = 0; oc_block_c3 < 4; ++oc_block_c3) {
          conv2d_NCHWc_global[((oc_block_c3 + 12))] = (conv2d_NCHWc_global[((oc_block_c3 + 12))] + (((float*)placeholder)[(((((ic_outer * 196) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 28)) + ic_inner) + 12))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 3840) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c3))]));
        }
        for (int32_t oc_block_c4 = 0; oc_block_c4 < 4; ++oc_block_c4) {
          conv2d_NCHWc_global[((oc_block_c4 + 16))] = (conv2d_NCHWc_global[((oc_block_c4 + 16))] + (((float*)placeholder)[(((((ic_outer * 196) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 28)) + ic_inner) + 16))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 3840) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c4))]));
        }
        for (int32_t oc_block_c5 = 0; oc_block_c5 < 4; ++oc_block_c5) {
          conv2d_NCHWc_global[((oc_block_c5 + 20))] = (conv2d_NCHWc_global[((oc_block_c5 + 20))] + (((float*)placeholder)[(((((ic_outer * 196) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 28)) + ic_inner) + 20))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 3840) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c5))]));
        }
        for (int32_t oc_block_c6 = 0; oc_block_c6 < 4; ++oc_block_c6) {
          conv2d_NCHWc_global[((oc_block_c6 + 24))] = (conv2d_NCHWc_global[((oc_block_c6 + 24))] + (((float*)placeholder)[(((((ic_outer * 196) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 28)) + ic_inner) + 24))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 3840) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c6))]));
        }
      }
    }
    for (int32_t ax3_inner = 0; ax3_inner < 7; ++ax3_inner) {
      for (int32_t ax4 = 0; ax4 < 4; ++ax4) {
        ((float*)T_add)[((((ax0_ax1_fused_ax2_outer_fused * 28) + (ax3_inner * 4)) + ax4))] = ((conv2d_NCHWc_global[(((ax3_inner * 4) + ax4))] + ((float*)placeholder2)[((((ax0_ax1_fused_ax2_outer_fused / 7) * 4) + ax4))]) + ((float*)placeholder3)[((((ax0_ax1_fused_ax2_outer_fused * 28) + (ax3_inner * 4)) + ax4))]);
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_contrib_depthwise_conv2d_NCHWc_add_clip_4(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int32_t arg2_code = ((int32_t*)arg_type_ids)[(2)];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int32_t arg3_code = ((int32_t*)arg_type_ids)[(3)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* placeholder1 = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  void* placeholder2 = (((DLTensor*)arg2)[0].data);
  void* arg2_shape = (((DLTensor*)arg2)[0].shape);
  void* arg2_strides = (((DLTensor*)arg2)[0].strides);
  void* compute = (((DLTensor*)arg3)[0].data);
  void* arg3_shape = (((DLTensor*)arg3)[0].shape);
  void* arg3_strides = (((DLTensor*)arg3)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  if (!(arg2_strides == NULL)) {
  }
  if (!(arg3_strides == NULL)) {
  }
  void* PaddedInput = TVMBackendAllocWorkspace(1, dev_id, (uint64_t)645888, 2, 32);
  if (PaddedInput == NULL) {
    return -1;
  }
  for (int32_t i0_i1_fused_i2_fused = 0; i0_i1_fused_i2_fused < 1392; ++i0_i1_fused_i2_fused) {
    for (int32_t i3 = 0; i3 < 29; ++i3) {
      for (int32_t i4 = 0; i4 < 4; ++i4) {
        ((float*)PaddedInput)[((((i0_i1_fused_i2_fused * 116) + (i3 * 4)) + i4))] = ((((i0_i1_fused_i2_fused % 29) < 28) && (i3 < 28)) ? ((float*)placeholder)[((((((i0_i1_fused_i2_fused / 29) * 3136) + ((i0_i1_fused_i2_fused % 29) * 112)) + (i3 * 4)) + i4))] : 0.000000e+00f);
      }
    }
  }
  for (int32_t i1_i2_fused = 0; i1_i2_fused < 672; ++i1_i2_fused) {
    float DepthwiseConv2d_global[56];
    for (int32_t oci_c_init = 0; oci_c_init < 4; ++oci_c_init) {
      DepthwiseConv2d_global[(oci_c_init)] = 0.000000e+00f;
    }
    for (int32_t oci_c_init1 = 0; oci_c_init1 < 4; ++oci_c_init1) {
      DepthwiseConv2d_global[((oci_c_init1 + 4))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init2 = 0; oci_c_init2 < 4; ++oci_c_init2) {
      DepthwiseConv2d_global[((oci_c_init2 + 8))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init3 = 0; oci_c_init3 < 4; ++oci_c_init3) {
      DepthwiseConv2d_global[((oci_c_init3 + 12))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init4 = 0; oci_c_init4 < 4; ++oci_c_init4) {
      DepthwiseConv2d_global[((oci_c_init4 + 16))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init5 = 0; oci_c_init5 < 4; ++oci_c_init5) {
      DepthwiseConv2d_global[((oci_c_init5 + 20))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init6 = 0; oci_c_init6 < 4; ++oci_c_init6) {
      DepthwiseConv2d_global[((oci_c_init6 + 24))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init7 = 0; oci_c_init7 < 4; ++oci_c_init7) {
      DepthwiseConv2d_global[((oci_c_init7 + 28))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init8 = 0; oci_c_init8 < 4; ++oci_c_init8) {
      DepthwiseConv2d_global[((oci_c_init8 + 32))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init9 = 0; oci_c_init9 < 4; ++oci_c_init9) {
      DepthwiseConv2d_global[((oci_c_init9 + 36))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init10 = 0; oci_c_init10 < 4; ++oci_c_init10) {
      DepthwiseConv2d_global[((oci_c_init10 + 40))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init11 = 0; oci_c_init11 < 4; ++oci_c_init11) {
      DepthwiseConv2d_global[((oci_c_init11 + 44))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init12 = 0; oci_c_init12 < 4; ++oci_c_init12) {
      DepthwiseConv2d_global[((oci_c_init12 + 48))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init13 = 0; oci_c_init13 < 4; ++oci_c_init13) {
      DepthwiseConv2d_global[((oci_c_init13 + 52))] = 0.000000e+00f;
    }
    for (int32_t kh = 0; kh < 3; ++kh) {
      for (int32_t kw = 0; kw < 3; ++kw) {
        for (int32_t oci_c = 0; oci_c < 4; ++oci_c) {
          DepthwiseConv2d_global[(oci_c)] = (DepthwiseConv2d_global[(oci_c)] + (((float*)PaddedInput)[(((((((i1_i2_fused / 14) * 3364) + ((i1_i2_fused % 14) * 232)) + (kh * 116)) + (kw * 4)) + oci_c))] * ((float*)placeholder1)[((((((i1_i2_fused / 14) * 36) + (kh * 12)) + (kw * 4)) + oci_c))]));
        }
        for (int32_t oci_c1 = 0; oci_c1 < 4; ++oci_c1) {
          DepthwiseConv2d_global[((oci_c1 + 4))] = (DepthwiseConv2d_global[((oci_c1 + 4))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 14) * 3364) + ((i1_i2_fused % 14) * 232)) + (kh * 116)) + (kw * 4)) + oci_c1) + 8))] * ((float*)placeholder1)[((((((i1_i2_fused / 14) * 36) + (kh * 12)) + (kw * 4)) + oci_c1))]));
        }
        for (int32_t oci_c2 = 0; oci_c2 < 4; ++oci_c2) {
          DepthwiseConv2d_global[((oci_c2 + 8))] = (DepthwiseConv2d_global[((oci_c2 + 8))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 14) * 3364) + ((i1_i2_fused % 14) * 232)) + (kh * 116)) + (kw * 4)) + oci_c2) + 16))] * ((float*)placeholder1)[((((((i1_i2_fused / 14) * 36) + (kh * 12)) + (kw * 4)) + oci_c2))]));
        }
        for (int32_t oci_c3 = 0; oci_c3 < 4; ++oci_c3) {
          DepthwiseConv2d_global[((oci_c3 + 12))] = (DepthwiseConv2d_global[((oci_c3 + 12))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 14) * 3364) + ((i1_i2_fused % 14) * 232)) + (kh * 116)) + (kw * 4)) + oci_c3) + 24))] * ((float*)placeholder1)[((((((i1_i2_fused / 14) * 36) + (kh * 12)) + (kw * 4)) + oci_c3))]));
        }
        for (int32_t oci_c4 = 0; oci_c4 < 4; ++oci_c4) {
          DepthwiseConv2d_global[((oci_c4 + 16))] = (DepthwiseConv2d_global[((oci_c4 + 16))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 14) * 3364) + ((i1_i2_fused % 14) * 232)) + (kh * 116)) + (kw * 4)) + oci_c4) + 32))] * ((float*)placeholder1)[((((((i1_i2_fused / 14) * 36) + (kh * 12)) + (kw * 4)) + oci_c4))]));
        }
        for (int32_t oci_c5 = 0; oci_c5 < 4; ++oci_c5) {
          DepthwiseConv2d_global[((oci_c5 + 20))] = (DepthwiseConv2d_global[((oci_c5 + 20))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 14) * 3364) + ((i1_i2_fused % 14) * 232)) + (kh * 116)) + (kw * 4)) + oci_c5) + 40))] * ((float*)placeholder1)[((((((i1_i2_fused / 14) * 36) + (kh * 12)) + (kw * 4)) + oci_c5))]));
        }
        for (int32_t oci_c6 = 0; oci_c6 < 4; ++oci_c6) {
          DepthwiseConv2d_global[((oci_c6 + 24))] = (DepthwiseConv2d_global[((oci_c6 + 24))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 14) * 3364) + ((i1_i2_fused % 14) * 232)) + (kh * 116)) + (kw * 4)) + oci_c6) + 48))] * ((float*)placeholder1)[((((((i1_i2_fused / 14) * 36) + (kh * 12)) + (kw * 4)) + oci_c6))]));
        }
        for (int32_t oci_c7 = 0; oci_c7 < 4; ++oci_c7) {
          DepthwiseConv2d_global[((oci_c7 + 28))] = (DepthwiseConv2d_global[((oci_c7 + 28))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 14) * 3364) + ((i1_i2_fused % 14) * 232)) + (kh * 116)) + (kw * 4)) + oci_c7) + 56))] * ((float*)placeholder1)[((((((i1_i2_fused / 14) * 36) + (kh * 12)) + (kw * 4)) + oci_c7))]));
        }
        for (int32_t oci_c8 = 0; oci_c8 < 4; ++oci_c8) {
          DepthwiseConv2d_global[((oci_c8 + 32))] = (DepthwiseConv2d_global[((oci_c8 + 32))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 14) * 3364) + ((i1_i2_fused % 14) * 232)) + (kh * 116)) + (kw * 4)) + oci_c8) + 64))] * ((float*)placeholder1)[((((((i1_i2_fused / 14) * 36) + (kh * 12)) + (kw * 4)) + oci_c8))]));
        }
        for (int32_t oci_c9 = 0; oci_c9 < 4; ++oci_c9) {
          DepthwiseConv2d_global[((oci_c9 + 36))] = (DepthwiseConv2d_global[((oci_c9 + 36))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 14) * 3364) + ((i1_i2_fused % 14) * 232)) + (kh * 116)) + (kw * 4)) + oci_c9) + 72))] * ((float*)placeholder1)[((((((i1_i2_fused / 14) * 36) + (kh * 12)) + (kw * 4)) + oci_c9))]));
        }
        for (int32_t oci_c10 = 0; oci_c10 < 4; ++oci_c10) {
          DepthwiseConv2d_global[((oci_c10 + 40))] = (DepthwiseConv2d_global[((oci_c10 + 40))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 14) * 3364) + ((i1_i2_fused % 14) * 232)) + (kh * 116)) + (kw * 4)) + oci_c10) + 80))] * ((float*)placeholder1)[((((((i1_i2_fused / 14) * 36) + (kh * 12)) + (kw * 4)) + oci_c10))]));
        }
        for (int32_t oci_c11 = 0; oci_c11 < 4; ++oci_c11) {
          DepthwiseConv2d_global[((oci_c11 + 44))] = (DepthwiseConv2d_global[((oci_c11 + 44))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 14) * 3364) + ((i1_i2_fused % 14) * 232)) + (kh * 116)) + (kw * 4)) + oci_c11) + 88))] * ((float*)placeholder1)[((((((i1_i2_fused / 14) * 36) + (kh * 12)) + (kw * 4)) + oci_c11))]));
        }
        for (int32_t oci_c12 = 0; oci_c12 < 4; ++oci_c12) {
          DepthwiseConv2d_global[((oci_c12 + 48))] = (DepthwiseConv2d_global[((oci_c12 + 48))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 14) * 3364) + ((i1_i2_fused % 14) * 232)) + (kh * 116)) + (kw * 4)) + oci_c12) + 96))] * ((float*)placeholder1)[((((((i1_i2_fused / 14) * 36) + (kh * 12)) + (kw * 4)) + oci_c12))]));
        }
        for (int32_t oci_c13 = 0; oci_c13 < 4; ++oci_c13) {
          DepthwiseConv2d_global[((oci_c13 + 52))] = (DepthwiseConv2d_global[((oci_c13 + 52))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 14) * 3364) + ((i1_i2_fused % 14) * 232)) + (kh * 116)) + (kw * 4)) + oci_c13) + 104))] * ((float*)placeholder1)[((((((i1_i2_fused / 14) * 36) + (kh * 12)) + (kw * 4)) + oci_c13))]));
        }
      }
    }
    for (int32_t i3_inner = 0; i3_inner < 14; ++i3_inner) {
      for (int32_t i41 = 0; i41 < 4; ++i41) {
        float _1 = DepthwiseConv2d_global[(((i3_inner * 4) + i41))] + ((float*)placeholder2)[((((i1_i2_fused / 14) * 4) + i41))];
        float _2 = (_1) < (6.000000e+00f) ? (_1) : (6.000000e+00f);
        ((float*)compute)[((((i1_i2_fused * 56) + (i3_inner * 4)) + i41))] = ((_2) > (0.000000e+00f) ? (_2) : (0.000000e+00f));
      }
    }
  }
  if (TVMBackendFreeWorkspace(1, dev_id, PaddedInput) != 0) {
    return -1;
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_contrib_depthwise_conv2d_NCHWc_add_clip_5(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int32_t arg2_code = ((int32_t*)arg_type_ids)[(2)];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int32_t arg3_code = ((int32_t*)arg_type_ids)[(3)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* placeholder1 = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  void* placeholder2 = (((DLTensor*)arg2)[0].data);
  void* arg2_shape = (((DLTensor*)arg2)[0].shape);
  void* arg2_strides = (((DLTensor*)arg2)[0].strides);
  void* compute = (((DLTensor*)arg3)[0].data);
  void* arg3_shape = (((DLTensor*)arg3)[0].shape);
  void* arg3_strides = (((DLTensor*)arg3)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  if (!(arg2_strides == NULL)) {
  }
  if (!(arg3_strides == NULL)) {
  }
  void* PaddedInput = TVMBackendAllocWorkspace(1, dev_id, (uint64_t)691200, 2, 32);
  if (PaddedInput == NULL) {
    return -1;
  }
  for (int32_t i0_i1_fused_i2_fused = 0; i0_i1_fused_i2_fused < 1440; ++i0_i1_fused_i2_fused) {
    for (int32_t i3 = 0; i3 < 30; ++i3) {
      for (int32_t i4 = 0; i4 < 4; ++i4) {
        ((float*)PaddedInput)[((((i0_i1_fused_i2_fused * 120) + (i3 * 4)) + i4))] = (((((1 <= (i0_i1_fused_i2_fused % 30)) && ((i0_i1_fused_i2_fused % 30) < 29)) && (1 <= i3)) && (i3 < 29)) ? ((float*)placeholder)[(((((((i0_i1_fused_i2_fused / 30) * 3136) + ((i0_i1_fused_i2_fused % 30) * 112)) + (i3 * 4)) + i4) - 116))] : 0.000000e+00f);
      }
    }
  }
  for (int32_t i1_i2_fused = 0; i1_i2_fused < 1344; ++i1_i2_fused) {
    float DepthwiseConv2d_global[112];
    for (int32_t oci_c_init = 0; oci_c_init < 4; ++oci_c_init) {
      DepthwiseConv2d_global[(oci_c_init)] = 0.000000e+00f;
    }
    for (int32_t oci_c_init1 = 0; oci_c_init1 < 4; ++oci_c_init1) {
      DepthwiseConv2d_global[((oci_c_init1 + 4))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init2 = 0; oci_c_init2 < 4; ++oci_c_init2) {
      DepthwiseConv2d_global[((oci_c_init2 + 8))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init3 = 0; oci_c_init3 < 4; ++oci_c_init3) {
      DepthwiseConv2d_global[((oci_c_init3 + 12))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init4 = 0; oci_c_init4 < 4; ++oci_c_init4) {
      DepthwiseConv2d_global[((oci_c_init4 + 16))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init5 = 0; oci_c_init5 < 4; ++oci_c_init5) {
      DepthwiseConv2d_global[((oci_c_init5 + 20))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init6 = 0; oci_c_init6 < 4; ++oci_c_init6) {
      DepthwiseConv2d_global[((oci_c_init6 + 24))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init7 = 0; oci_c_init7 < 4; ++oci_c_init7) {
      DepthwiseConv2d_global[((oci_c_init7 + 28))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init8 = 0; oci_c_init8 < 4; ++oci_c_init8) {
      DepthwiseConv2d_global[((oci_c_init8 + 32))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init9 = 0; oci_c_init9 < 4; ++oci_c_init9) {
      DepthwiseConv2d_global[((oci_c_init9 + 36))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init10 = 0; oci_c_init10 < 4; ++oci_c_init10) {
      DepthwiseConv2d_global[((oci_c_init10 + 40))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init11 = 0; oci_c_init11 < 4; ++oci_c_init11) {
      DepthwiseConv2d_global[((oci_c_init11 + 44))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init12 = 0; oci_c_init12 < 4; ++oci_c_init12) {
      DepthwiseConv2d_global[((oci_c_init12 + 48))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init13 = 0; oci_c_init13 < 4; ++oci_c_init13) {
      DepthwiseConv2d_global[((oci_c_init13 + 52))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init14 = 0; oci_c_init14 < 4; ++oci_c_init14) {
      DepthwiseConv2d_global[((oci_c_init14 + 56))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init15 = 0; oci_c_init15 < 4; ++oci_c_init15) {
      DepthwiseConv2d_global[((oci_c_init15 + 60))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init16 = 0; oci_c_init16 < 4; ++oci_c_init16) {
      DepthwiseConv2d_global[((oci_c_init16 + 64))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init17 = 0; oci_c_init17 < 4; ++oci_c_init17) {
      DepthwiseConv2d_global[((oci_c_init17 + 68))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init18 = 0; oci_c_init18 < 4; ++oci_c_init18) {
      DepthwiseConv2d_global[((oci_c_init18 + 72))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init19 = 0; oci_c_init19 < 4; ++oci_c_init19) {
      DepthwiseConv2d_global[((oci_c_init19 + 76))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init20 = 0; oci_c_init20 < 4; ++oci_c_init20) {
      DepthwiseConv2d_global[((oci_c_init20 + 80))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init21 = 0; oci_c_init21 < 4; ++oci_c_init21) {
      DepthwiseConv2d_global[((oci_c_init21 + 84))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init22 = 0; oci_c_init22 < 4; ++oci_c_init22) {
      DepthwiseConv2d_global[((oci_c_init22 + 88))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init23 = 0; oci_c_init23 < 4; ++oci_c_init23) {
      DepthwiseConv2d_global[((oci_c_init23 + 92))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init24 = 0; oci_c_init24 < 4; ++oci_c_init24) {
      DepthwiseConv2d_global[((oci_c_init24 + 96))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init25 = 0; oci_c_init25 < 4; ++oci_c_init25) {
      DepthwiseConv2d_global[((oci_c_init25 + 100))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init26 = 0; oci_c_init26 < 4; ++oci_c_init26) {
      DepthwiseConv2d_global[((oci_c_init26 + 104))] = 0.000000e+00f;
    }
    for (int32_t oci_c_init27 = 0; oci_c_init27 < 4; ++oci_c_init27) {
      DepthwiseConv2d_global[((oci_c_init27 + 108))] = 0.000000e+00f;
    }
    for (int32_t kh = 0; kh < 3; ++kh) {
      for (int32_t kw = 0; kw < 3; ++kw) {
        for (int32_t oci_c = 0; oci_c < 4; ++oci_c) {
          DepthwiseConv2d_global[(oci_c)] = (DepthwiseConv2d_global[(oci_c)] + (((float*)PaddedInput)[(((((((i1_i2_fused / 28) * 3600) + (kh * 120)) + ((i1_i2_fused % 28) * 120)) + (kw * 4)) + oci_c))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c))]));
        }
        for (int32_t oci_c1 = 0; oci_c1 < 4; ++oci_c1) {
          DepthwiseConv2d_global[((oci_c1 + 4))] = (DepthwiseConv2d_global[((oci_c1 + 4))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 3600) + (kh * 120)) + ((i1_i2_fused % 28) * 120)) + (kw * 4)) + oci_c1) + 4))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c1))]));
        }
        for (int32_t oci_c2 = 0; oci_c2 < 4; ++oci_c2) {
          DepthwiseConv2d_global[((oci_c2 + 8))] = (DepthwiseConv2d_global[((oci_c2 + 8))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 3600) + (kh * 120)) + ((i1_i2_fused % 28) * 120)) + (kw * 4)) + oci_c2) + 8))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c2))]));
        }
        for (int32_t oci_c3 = 0; oci_c3 < 4; ++oci_c3) {
          DepthwiseConv2d_global[((oci_c3 + 12))] = (DepthwiseConv2d_global[((oci_c3 + 12))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 3600) + (kh * 120)) + ((i1_i2_fused % 28) * 120)) + (kw * 4)) + oci_c3) + 12))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c3))]));
        }
        for (int32_t oci_c4 = 0; oci_c4 < 4; ++oci_c4) {
          DepthwiseConv2d_global[((oci_c4 + 16))] = (DepthwiseConv2d_global[((oci_c4 + 16))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 3600) + (kh * 120)) + ((i1_i2_fused % 28) * 120)) + (kw * 4)) + oci_c4) + 16))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c4))]));
        }
        for (int32_t oci_c5 = 0; oci_c5 < 4; ++oci_c5) {
          DepthwiseConv2d_global[((oci_c5 + 20))] = (DepthwiseConv2d_global[((oci_c5 + 20))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 3600) + (kh * 120)) + ((i1_i2_fused % 28) * 120)) + (kw * 4)) + oci_c5) + 20))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c5))]));
        }
        for (int32_t oci_c6 = 0; oci_c6 < 4; ++oci_c6) {
          DepthwiseConv2d_global[((oci_c6 + 24))] = (DepthwiseConv2d_global[((oci_c6 + 24))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 3600) + (kh * 120)) + ((i1_i2_fused % 28) * 120)) + (kw * 4)) + oci_c6) + 24))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c6))]));
        }
        for (int32_t oci_c7 = 0; oci_c7 < 4; ++oci_c7) {
          DepthwiseConv2d_global[((oci_c7 + 28))] = (DepthwiseConv2d_global[((oci_c7 + 28))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 3600) + (kh * 120)) + ((i1_i2_fused % 28) * 120)) + (kw * 4)) + oci_c7) + 28))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c7))]));
        }
        for (int32_t oci_c8 = 0; oci_c8 < 4; ++oci_c8) {
          DepthwiseConv2d_global[((oci_c8 + 32))] = (DepthwiseConv2d_global[((oci_c8 + 32))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 3600) + (kh * 120)) + ((i1_i2_fused % 28) * 120)) + (kw * 4)) + oci_c8) + 32))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c8))]));
        }
        for (int32_t oci_c9 = 0; oci_c9 < 4; ++oci_c9) {
          DepthwiseConv2d_global[((oci_c9 + 36))] = (DepthwiseConv2d_global[((oci_c9 + 36))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 3600) + (kh * 120)) + ((i1_i2_fused % 28) * 120)) + (kw * 4)) + oci_c9) + 36))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c9))]));
        }
        for (int32_t oci_c10 = 0; oci_c10 < 4; ++oci_c10) {
          DepthwiseConv2d_global[((oci_c10 + 40))] = (DepthwiseConv2d_global[((oci_c10 + 40))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 3600) + (kh * 120)) + ((i1_i2_fused % 28) * 120)) + (kw * 4)) + oci_c10) + 40))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c10))]));
        }
        for (int32_t oci_c11 = 0; oci_c11 < 4; ++oci_c11) {
          DepthwiseConv2d_global[((oci_c11 + 44))] = (DepthwiseConv2d_global[((oci_c11 + 44))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 3600) + (kh * 120)) + ((i1_i2_fused % 28) * 120)) + (kw * 4)) + oci_c11) + 44))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c11))]));
        }
        for (int32_t oci_c12 = 0; oci_c12 < 4; ++oci_c12) {
          DepthwiseConv2d_global[((oci_c12 + 48))] = (DepthwiseConv2d_global[((oci_c12 + 48))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 3600) + (kh * 120)) + ((i1_i2_fused % 28) * 120)) + (kw * 4)) + oci_c12) + 48))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c12))]));
        }
        for (int32_t oci_c13 = 0; oci_c13 < 4; ++oci_c13) {
          DepthwiseConv2d_global[((oci_c13 + 52))] = (DepthwiseConv2d_global[((oci_c13 + 52))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 3600) + (kh * 120)) + ((i1_i2_fused % 28) * 120)) + (kw * 4)) + oci_c13) + 52))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c13))]));
        }
        for (int32_t oci_c14 = 0; oci_c14 < 4; ++oci_c14) {
          DepthwiseConv2d_global[((oci_c14 + 56))] = (DepthwiseConv2d_global[((oci_c14 + 56))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 3600) + (kh * 120)) + ((i1_i2_fused % 28) * 120)) + (kw * 4)) + oci_c14) + 56))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c14))]));
        }
        for (int32_t oci_c15 = 0; oci_c15 < 4; ++oci_c15) {
          DepthwiseConv2d_global[((oci_c15 + 60))] = (DepthwiseConv2d_global[((oci_c15 + 60))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 3600) + (kh * 120)) + ((i1_i2_fused % 28) * 120)) + (kw * 4)) + oci_c15) + 60))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c15))]));
        }
        for (int32_t oci_c16 = 0; oci_c16 < 4; ++oci_c16) {
          DepthwiseConv2d_global[((oci_c16 + 64))] = (DepthwiseConv2d_global[((oci_c16 + 64))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 3600) + (kh * 120)) + ((i1_i2_fused % 28) * 120)) + (kw * 4)) + oci_c16) + 64))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c16))]));
        }
        for (int32_t oci_c17 = 0; oci_c17 < 4; ++oci_c17) {
          DepthwiseConv2d_global[((oci_c17 + 68))] = (DepthwiseConv2d_global[((oci_c17 + 68))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 3600) + (kh * 120)) + ((i1_i2_fused % 28) * 120)) + (kw * 4)) + oci_c17) + 68))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c17))]));
        }
        for (int32_t oci_c18 = 0; oci_c18 < 4; ++oci_c18) {
          DepthwiseConv2d_global[((oci_c18 + 72))] = (DepthwiseConv2d_global[((oci_c18 + 72))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 3600) + (kh * 120)) + ((i1_i2_fused % 28) * 120)) + (kw * 4)) + oci_c18) + 72))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c18))]));
        }
        for (int32_t oci_c19 = 0; oci_c19 < 4; ++oci_c19) {
          DepthwiseConv2d_global[((oci_c19 + 76))] = (DepthwiseConv2d_global[((oci_c19 + 76))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 3600) + (kh * 120)) + ((i1_i2_fused % 28) * 120)) + (kw * 4)) + oci_c19) + 76))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c19))]));
        }
        for (int32_t oci_c20 = 0; oci_c20 < 4; ++oci_c20) {
          DepthwiseConv2d_global[((oci_c20 + 80))] = (DepthwiseConv2d_global[((oci_c20 + 80))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 3600) + (kh * 120)) + ((i1_i2_fused % 28) * 120)) + (kw * 4)) + oci_c20) + 80))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c20))]));
        }
        for (int32_t oci_c21 = 0; oci_c21 < 4; ++oci_c21) {
          DepthwiseConv2d_global[((oci_c21 + 84))] = (DepthwiseConv2d_global[((oci_c21 + 84))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 3600) + (kh * 120)) + ((i1_i2_fused % 28) * 120)) + (kw * 4)) + oci_c21) + 84))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c21))]));
        }
        for (int32_t oci_c22 = 0; oci_c22 < 4; ++oci_c22) {
          DepthwiseConv2d_global[((oci_c22 + 88))] = (DepthwiseConv2d_global[((oci_c22 + 88))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 3600) + (kh * 120)) + ((i1_i2_fused % 28) * 120)) + (kw * 4)) + oci_c22) + 88))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c22))]));
        }
        for (int32_t oci_c23 = 0; oci_c23 < 4; ++oci_c23) {
          DepthwiseConv2d_global[((oci_c23 + 92))] = (DepthwiseConv2d_global[((oci_c23 + 92))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 3600) + (kh * 120)) + ((i1_i2_fused % 28) * 120)) + (kw * 4)) + oci_c23) + 92))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c23))]));
        }
        for (int32_t oci_c24 = 0; oci_c24 < 4; ++oci_c24) {
          DepthwiseConv2d_global[((oci_c24 + 96))] = (DepthwiseConv2d_global[((oci_c24 + 96))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 3600) + (kh * 120)) + ((i1_i2_fused % 28) * 120)) + (kw * 4)) + oci_c24) + 96))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c24))]));
        }
        for (int32_t oci_c25 = 0; oci_c25 < 4; ++oci_c25) {
          DepthwiseConv2d_global[((oci_c25 + 100))] = (DepthwiseConv2d_global[((oci_c25 + 100))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 3600) + (kh * 120)) + ((i1_i2_fused % 28) * 120)) + (kw * 4)) + oci_c25) + 100))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c25))]));
        }
        for (int32_t oci_c26 = 0; oci_c26 < 4; ++oci_c26) {
          DepthwiseConv2d_global[((oci_c26 + 104))] = (DepthwiseConv2d_global[((oci_c26 + 104))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 3600) + (kh * 120)) + ((i1_i2_fused % 28) * 120)) + (kw * 4)) + oci_c26) + 104))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c26))]));
        }
        for (int32_t oci_c27 = 0; oci_c27 < 4; ++oci_c27) {
          DepthwiseConv2d_global[((oci_c27 + 108))] = (DepthwiseConv2d_global[((oci_c27 + 108))] + (((float*)PaddedInput)[((((((((i1_i2_fused / 28) * 3600) + (kh * 120)) + ((i1_i2_fused % 28) * 120)) + (kw * 4)) + oci_c27) + 108))] * ((float*)placeholder1)[((((((i1_i2_fused / 28) * 36) + (kh * 12)) + (kw * 4)) + oci_c27))]));
        }
      }
    }
    for (int32_t i3_inner = 0; i3_inner < 28; ++i3_inner) {
      for (int32_t i41 = 0; i41 < 4; ++i41) {
        float _1 = DepthwiseConv2d_global[(((i3_inner * 4) + i41))] + ((float*)placeholder2)[((((i1_i2_fused / 28) * 4) + i41))];
        float _2 = (_1) < (6.000000e+00f) ? (_1) : (6.000000e+00f);
        ((float*)compute)[((((i1_i2_fused * 112) + (i3_inner * 4)) + i41))] = ((_2) > (0.000000e+00f) ? (_2) : (0.000000e+00f));
      }
    }
  }
  if (TVMBackendFreeWorkspace(1, dev_id, PaddedInput) != 0) {
    return -1;
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_layout_transform_layout_transform(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* T_layout_trans = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  for (int32_t ax0_ax1_fused_ax2_fused = 0; ax0_ax1_fused_ax2_fused < 224; ++ax0_ax1_fused_ax2_fused) {
    for (int32_t ax3 = 0; ax3 < 224; ++ax3) {
      for (int32_t ax4_inner = 0; ax4_inner < 3; ++ax4_inner) {
        ((float*)T_layout_trans)[((((ax0_ax1_fused_ax2_fused * 672) + (ax3 * 3)) + ax4_inner))] = ((float*)placeholder)[((((ax0_ax1_fused_ax2_fused * 672) + (ax3 * 3)) + ax4_inner))];
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_contrib_conv2d_NCHWc_add_add_1(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int32_t arg2_code = ((int32_t*)arg_type_ids)[(2)];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int32_t arg3_code = ((int32_t*)arg_type_ids)[(3)];
  void* arg4 = (((TVMValue*)args)[4].v_handle);
  int32_t arg4_code = ((int32_t*)arg_type_ids)[(4)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* placeholder1 = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  void* placeholder2 = (((DLTensor*)arg2)[0].data);
  void* arg2_shape = (((DLTensor*)arg2)[0].shape);
  void* arg2_strides = (((DLTensor*)arg2)[0].strides);
  void* placeholder3 = (((DLTensor*)arg3)[0].data);
  void* arg3_shape = (((DLTensor*)arg3)[0].shape);
  void* arg3_strides = (((DLTensor*)arg3)[0].strides);
  void* T_add = (((DLTensor*)arg4)[0].data);
  void* arg4_shape = (((DLTensor*)arg4)[0].shape);
  void* arg4_strides = (((DLTensor*)arg4)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  if (!(arg2_strides == NULL)) {
  }
  if (!(arg3_strides == NULL)) {
  }
  if (!(arg4_strides == NULL)) {
  }
  for (int32_t ax0_ax1_fused_ax2_outer_fused = 0; ax0_ax1_fused_ax2_outer_fused < 168; ++ax0_ax1_fused_ax2_outer_fused) {
    float conv2d_NCHWc_global[112];
    for (int32_t oc_block_c_init = 0; oc_block_c_init < 4; ++oc_block_c_init) {
      conv2d_NCHWc_global[(oc_block_c_init)] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init1 = 0; oc_block_c_init1 < 4; ++oc_block_c_init1) {
      conv2d_NCHWc_global[((oc_block_c_init1 + 4))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init2 = 0; oc_block_c_init2 < 4; ++oc_block_c_init2) {
      conv2d_NCHWc_global[((oc_block_c_init2 + 8))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init3 = 0; oc_block_c_init3 < 4; ++oc_block_c_init3) {
      conv2d_NCHWc_global[((oc_block_c_init3 + 12))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init4 = 0; oc_block_c_init4 < 4; ++oc_block_c_init4) {
      conv2d_NCHWc_global[((oc_block_c_init4 + 16))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init5 = 0; oc_block_c_init5 < 4; ++oc_block_c_init5) {
      conv2d_NCHWc_global[((oc_block_c_init5 + 20))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init6 = 0; oc_block_c_init6 < 4; ++oc_block_c_init6) {
      conv2d_NCHWc_global[((oc_block_c_init6 + 24))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init7 = 0; oc_block_c_init7 < 4; ++oc_block_c_init7) {
      conv2d_NCHWc_global[((oc_block_c_init7 + 28))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init8 = 0; oc_block_c_init8 < 4; ++oc_block_c_init8) {
      conv2d_NCHWc_global[((oc_block_c_init8 + 32))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init9 = 0; oc_block_c_init9 < 4; ++oc_block_c_init9) {
      conv2d_NCHWc_global[((oc_block_c_init9 + 36))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init10 = 0; oc_block_c_init10 < 4; ++oc_block_c_init10) {
      conv2d_NCHWc_global[((oc_block_c_init10 + 40))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init11 = 0; oc_block_c_init11 < 4; ++oc_block_c_init11) {
      conv2d_NCHWc_global[((oc_block_c_init11 + 44))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init12 = 0; oc_block_c_init12 < 4; ++oc_block_c_init12) {
      conv2d_NCHWc_global[((oc_block_c_init12 + 48))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init13 = 0; oc_block_c_init13 < 4; ++oc_block_c_init13) {
      conv2d_NCHWc_global[((oc_block_c_init13 + 52))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init14 = 0; oc_block_c_init14 < 4; ++oc_block_c_init14) {
      conv2d_NCHWc_global[((oc_block_c_init14 + 56))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init15 = 0; oc_block_c_init15 < 4; ++oc_block_c_init15) {
      conv2d_NCHWc_global[((oc_block_c_init15 + 60))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init16 = 0; oc_block_c_init16 < 4; ++oc_block_c_init16) {
      conv2d_NCHWc_global[((oc_block_c_init16 + 64))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init17 = 0; oc_block_c_init17 < 4; ++oc_block_c_init17) {
      conv2d_NCHWc_global[((oc_block_c_init17 + 68))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init18 = 0; oc_block_c_init18 < 4; ++oc_block_c_init18) {
      conv2d_NCHWc_global[((oc_block_c_init18 + 72))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init19 = 0; oc_block_c_init19 < 4; ++oc_block_c_init19) {
      conv2d_NCHWc_global[((oc_block_c_init19 + 76))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init20 = 0; oc_block_c_init20 < 4; ++oc_block_c_init20) {
      conv2d_NCHWc_global[((oc_block_c_init20 + 80))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init21 = 0; oc_block_c_init21 < 4; ++oc_block_c_init21) {
      conv2d_NCHWc_global[((oc_block_c_init21 + 84))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init22 = 0; oc_block_c_init22 < 4; ++oc_block_c_init22) {
      conv2d_NCHWc_global[((oc_block_c_init22 + 88))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init23 = 0; oc_block_c_init23 < 4; ++oc_block_c_init23) {
      conv2d_NCHWc_global[((oc_block_c_init23 + 92))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init24 = 0; oc_block_c_init24 < 4; ++oc_block_c_init24) {
      conv2d_NCHWc_global[((oc_block_c_init24 + 96))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init25 = 0; oc_block_c_init25 < 4; ++oc_block_c_init25) {
      conv2d_NCHWc_global[((oc_block_c_init25 + 100))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init26 = 0; oc_block_c_init26 < 4; ++oc_block_c_init26) {
      conv2d_NCHWc_global[((oc_block_c_init26 + 104))] = 0.000000e+00f;
    }
    for (int32_t oc_block_c_init27 = 0; oc_block_c_init27 < 4; ++oc_block_c_init27) {
      conv2d_NCHWc_global[((oc_block_c_init27 + 108))] = 0.000000e+00f;
    }
    for (int32_t ic_outer = 0; ic_outer < 144; ++ic_outer) {
      for (int32_t ic_inner = 0; ic_inner < 4; ++ic_inner) {
        for (int32_t oc_block_c = 0; oc_block_c < 4; ++oc_block_c) {
          conv2d_NCHWc_global[(oc_block_c)] = (conv2d_NCHWc_global[(oc_block_c)] + (((float*)placeholder)[((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 2304) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c))]));
        }
        for (int32_t oc_block_c1 = 0; oc_block_c1 < 4; ++oc_block_c1) {
          conv2d_NCHWc_global[((oc_block_c1 + 4))] = (conv2d_NCHWc_global[((oc_block_c1 + 4))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 4))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 2304) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c1))]));
        }
        for (int32_t oc_block_c2 = 0; oc_block_c2 < 4; ++oc_block_c2) {
          conv2d_NCHWc_global[((oc_block_c2 + 8))] = (conv2d_NCHWc_global[((oc_block_c2 + 8))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 8))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 2304) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c2))]));
        }
        for (int32_t oc_block_c3 = 0; oc_block_c3 < 4; ++oc_block_c3) {
          conv2d_NCHWc_global[((oc_block_c3 + 12))] = (conv2d_NCHWc_global[((oc_block_c3 + 12))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 12))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 2304) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c3))]));
        }
        for (int32_t oc_block_c4 = 0; oc_block_c4 < 4; ++oc_block_c4) {
          conv2d_NCHWc_global[((oc_block_c4 + 16))] = (conv2d_NCHWc_global[((oc_block_c4 + 16))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 16))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 2304) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c4))]));
        }
        for (int32_t oc_block_c5 = 0; oc_block_c5 < 4; ++oc_block_c5) {
          conv2d_NCHWc_global[((oc_block_c5 + 20))] = (conv2d_NCHWc_global[((oc_block_c5 + 20))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 20))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 2304) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c5))]));
        }
        for (int32_t oc_block_c6 = 0; oc_block_c6 < 4; ++oc_block_c6) {
          conv2d_NCHWc_global[((oc_block_c6 + 24))] = (conv2d_NCHWc_global[((oc_block_c6 + 24))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 24))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 2304) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c6))]));
        }
        for (int32_t oc_block_c7 = 0; oc_block_c7 < 4; ++oc_block_c7) {
          conv2d_NCHWc_global[((oc_block_c7 + 28))] = (conv2d_NCHWc_global[((oc_block_c7 + 28))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 28))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 2304) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c7))]));
        }
        for (int32_t oc_block_c8 = 0; oc_block_c8 < 4; ++oc_block_c8) {
          conv2d_NCHWc_global[((oc_block_c8 + 32))] = (conv2d_NCHWc_global[((oc_block_c8 + 32))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 32))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 2304) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c8))]));
        }
        for (int32_t oc_block_c9 = 0; oc_block_c9 < 4; ++oc_block_c9) {
          conv2d_NCHWc_global[((oc_block_c9 + 36))] = (conv2d_NCHWc_global[((oc_block_c9 + 36))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 36))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 2304) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c9))]));
        }
        for (int32_t oc_block_c10 = 0; oc_block_c10 < 4; ++oc_block_c10) {
          conv2d_NCHWc_global[((oc_block_c10 + 40))] = (conv2d_NCHWc_global[((oc_block_c10 + 40))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 40))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 2304) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c10))]));
        }
        for (int32_t oc_block_c11 = 0; oc_block_c11 < 4; ++oc_block_c11) {
          conv2d_NCHWc_global[((oc_block_c11 + 44))] = (conv2d_NCHWc_global[((oc_block_c11 + 44))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 44))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 2304) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c11))]));
        }
        for (int32_t oc_block_c12 = 0; oc_block_c12 < 4; ++oc_block_c12) {
          conv2d_NCHWc_global[((oc_block_c12 + 48))] = (conv2d_NCHWc_global[((oc_block_c12 + 48))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 48))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 2304) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c12))]));
        }
        for (int32_t oc_block_c13 = 0; oc_block_c13 < 4; ++oc_block_c13) {
          conv2d_NCHWc_global[((oc_block_c13 + 52))] = (conv2d_NCHWc_global[((oc_block_c13 + 52))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 52))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 2304) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c13))]));
        }
        for (int32_t oc_block_c14 = 0; oc_block_c14 < 4; ++oc_block_c14) {
          conv2d_NCHWc_global[((oc_block_c14 + 56))] = (conv2d_NCHWc_global[((oc_block_c14 + 56))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 56))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 2304) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c14))]));
        }
        for (int32_t oc_block_c15 = 0; oc_block_c15 < 4; ++oc_block_c15) {
          conv2d_NCHWc_global[((oc_block_c15 + 60))] = (conv2d_NCHWc_global[((oc_block_c15 + 60))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 60))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 2304) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c15))]));
        }
        for (int32_t oc_block_c16 = 0; oc_block_c16 < 4; ++oc_block_c16) {
          conv2d_NCHWc_global[((oc_block_c16 + 64))] = (conv2d_NCHWc_global[((oc_block_c16 + 64))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 64))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 2304) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c16))]));
        }
        for (int32_t oc_block_c17 = 0; oc_block_c17 < 4; ++oc_block_c17) {
          conv2d_NCHWc_global[((oc_block_c17 + 68))] = (conv2d_NCHWc_global[((oc_block_c17 + 68))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 68))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 2304) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c17))]));
        }
        for (int32_t oc_block_c18 = 0; oc_block_c18 < 4; ++oc_block_c18) {
          conv2d_NCHWc_global[((oc_block_c18 + 72))] = (conv2d_NCHWc_global[((oc_block_c18 + 72))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 72))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 2304) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c18))]));
        }
        for (int32_t oc_block_c19 = 0; oc_block_c19 < 4; ++oc_block_c19) {
          conv2d_NCHWc_global[((oc_block_c19 + 76))] = (conv2d_NCHWc_global[((oc_block_c19 + 76))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 76))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 2304) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c19))]));
        }
        for (int32_t oc_block_c20 = 0; oc_block_c20 < 4; ++oc_block_c20) {
          conv2d_NCHWc_global[((oc_block_c20 + 80))] = (conv2d_NCHWc_global[((oc_block_c20 + 80))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 80))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 2304) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c20))]));
        }
        for (int32_t oc_block_c21 = 0; oc_block_c21 < 4; ++oc_block_c21) {
          conv2d_NCHWc_global[((oc_block_c21 + 84))] = (conv2d_NCHWc_global[((oc_block_c21 + 84))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 84))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 2304) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c21))]));
        }
        for (int32_t oc_block_c22 = 0; oc_block_c22 < 4; ++oc_block_c22) {
          conv2d_NCHWc_global[((oc_block_c22 + 88))] = (conv2d_NCHWc_global[((oc_block_c22 + 88))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 88))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 2304) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c22))]));
        }
        for (int32_t oc_block_c23 = 0; oc_block_c23 < 4; ++oc_block_c23) {
          conv2d_NCHWc_global[((oc_block_c23 + 92))] = (conv2d_NCHWc_global[((oc_block_c23 + 92))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 92))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 2304) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c23))]));
        }
        for (int32_t oc_block_c24 = 0; oc_block_c24 < 4; ++oc_block_c24) {
          conv2d_NCHWc_global[((oc_block_c24 + 96))] = (conv2d_NCHWc_global[((oc_block_c24 + 96))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 96))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 2304) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c24))]));
        }
        for (int32_t oc_block_c25 = 0; oc_block_c25 < 4; ++oc_block_c25) {
          conv2d_NCHWc_global[((oc_block_c25 + 100))] = (conv2d_NCHWc_global[((oc_block_c25 + 100))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 100))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 2304) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c25))]));
        }
        for (int32_t oc_block_c26 = 0; oc_block_c26 < 4; ++oc_block_c26) {
          conv2d_NCHWc_global[((oc_block_c26 + 104))] = (conv2d_NCHWc_global[((oc_block_c26 + 104))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 104))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 2304) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c26))]));
        }
        for (int32_t oc_block_c27 = 0; oc_block_c27 < 4; ++oc_block_c27) {
          conv2d_NCHWc_global[((oc_block_c27 + 108))] = (conv2d_NCHWc_global[((oc_block_c27 + 108))] + (((float*)placeholder)[(((((ic_outer * 784) + ((ax0_ax1_fused_ax2_outer_fused % 7) * 112)) + ic_inner) + 108))] * ((float*)placeholder1)[((((((ax0_ax1_fused_ax2_outer_fused / 7) * 2304) + (ic_outer * 16)) + (ic_inner * 4)) + oc_block_c27))]));
        }
      }
    }
    for (int32_t ax2_inner = 0; ax2_inner < 2; ++ax2_inner) {
      for (int32_t ax3_inner = 0; ax3_inner < 14; ++ax3_inner) {
        for (int32_t ax4 = 0; ax4 < 4; ++ax4) {
          ((float*)T_add)[(((((ax0_ax1_fused_ax2_outer_fused * 112) + (ax2_inner * 56)) + (ax3_inner * 4)) + ax4))] = ((conv2d_NCHWc_global[((((ax2_inner * 56) + (ax3_inner * 4)) + ax4))] + ((float*)placeholder2)[((((ax0_ax1_fused_ax2_outer_fused / 7) * 4) + ax4))]) + ((float*)placeholder3)[(((((ax0_ax1_fused_ax2_outer_fused * 112) + (ax2_inner * 56)) + (ax3_inner * 4)) + ax4))]);
        }
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_nn_contrib_depthwise_conv2d_NCHWc_add_clip_9(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode, void* resource_handle) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int32_t arg2_code = ((int32_t*)arg_type_ids)[(2)];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int32_t arg3_code = ((int32_t*)arg_type_ids)[(3)];
  void* placeholder = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].device.device_id);
  void* placeholder1 = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  void* placeholder2 = (((DLTensor*)arg2)[0].data);
  void* arg2_shape = (((DLTensor*)arg2)[0].shape);
  void* arg2_strides = (((DLTensor*)arg2)[0].strides);
  void* compute = (((DLTensor*)arg3)[0].data);
  void* arg3_shape = (((DLTensor*)arg3)[0].shape);
  void* arg3_strides = (((DLTensor*)arg3)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  if (!(arg2_strides == NULL)) {
  }
  if (!(arg3_strides == NULL)) {
  }
  void* PaddedInput = TVMBackendAllocWorkspace(1, dev_id, (uint64_t)1663488, 2, 32);
  if (PaddedInput == NULL) {
    return -1;
  }
  for (int32_t i0_i1_fused_i2_fused = 0; i0_i1_fused_i2_fused < 912; ++i0_i1_fused_i2_fused) {
    for (int32_t i3 = 0; i3 < 114; ++i3) {
      for (int32_t i4 = 0; i4 < 4; ++i4) {
        ((float*)PaddedInput)[((((i0_i1_fused_i2_fused * 456) + (i3 * 4)) + i4))] = (((((1 <= (i0_i1_fused_i2_fused % 114)) && ((i0_i1_fused_i2_fused % 114) < 113)) && (1 <= i3)) && (i3 < 113)) ? ((float*)placeholder)[(((((((i0_i1_fused_i2_fused / 114) * 50176) + ((i0_i1_fused_i2_fused % 114) * 448)) + (i3 * 4)) + i4) - 452))] : 0.000000e+00f);
      }
    }
  }
  for (int32_t i1_i2_fused = 0; i1_i2_fused < 896; ++i1_i2_fused) {
    void* DepthwiseConv2d = TVMBackendAllocWorkspace(1, dev_id, (uint64_t)1792, 2, 32);
    if (DepthwiseConv2d == NULL) {
      return -1;
    }
    float DepthwiseConv2d_global[112];
    for (int32_t ow_outer = 0; ow_outer < 4; ++ow_outer) {
      for (int32_t oci_c_init = 0; oci_c_init < 4; ++oci_c_init) {
        DepthwiseConv2d_global[(oci_c_init)] = 0.000000e+00f;
      }
      for (int32_t oci_c_init1 = 0; oci_c_init1 < 4; ++oci_c_init1) {
        DepthwiseConv2d_global[((oci_c_init1 + 4))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init2 = 0; oci_c_init2 < 4; ++oci_c_init2) {
        DepthwiseConv2d_global[((oci_c_init2 + 8))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init3 = 0; oci_c_init3 < 4; ++oci_c_init3) {
        DepthwiseConv2d_global[((oci_c_init3 + 12))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init4 = 0; oci_c_init4 < 4; ++oci_c_init4) {
        DepthwiseConv2d_global[((oci_c_init4 + 16))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init5 = 0; oci_c_init5 < 4; ++oci_c_init5) {
        DepthwiseConv2d_global[((oci_c_init5 + 20))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init6 = 0; oci_c_init6 < 4; ++oci_c_init6) {
        DepthwiseConv2d_global[((oci_c_init6 + 24))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init7 = 0; oci_c_init7 < 4; ++oci_c_init7) {
        DepthwiseConv2d_global[((oci_c_init7 + 28))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init8 = 0; oci_c_init8 < 4; ++oci_c_init8) {
        DepthwiseConv2d_global[((oci_c_init8 + 32))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init9 = 0; oci_c_init9 < 4; ++oci_c_init9) {
        DepthwiseConv2d_global[((oci_c_init9 + 36))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init10 = 0; oci_c_init10 < 4; ++oci_c_init10) {
        DepthwiseConv2d_global[((oci_c_init10 + 40))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init11 = 0; oci_c_init11 < 4; ++oci_c_init11) {
        DepthwiseConv2d_global[((oci_c_init11 + 44))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init12 = 0; oci_c_init12 < 4; ++oci_c_init12) {
        DepthwiseConv2d_global[((oci_c_init12 + 48))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init13 = 0; oci_c_init13 < 4; ++oci_c_init13) {
        DepthwiseConv2d_global[((oci_c_init13 + 52))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init14 = 0; oci_c_init14 < 4; ++oci_c_init14) {
        DepthwiseConv2d_global[((oci_c_init14 + 56))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init15 = 0; oci_c_init15 < 4; ++oci_c_init15) {
        DepthwiseConv2d_global[((oci_c_init15 + 60))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init16 = 0; oci_c_init16 < 4; ++oci_c_init16) {
        DepthwiseConv2d_global[((oci_c_init16 + 64))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init17 = 0; oci_c_init17 < 4; ++oci_c_init17) {
        DepthwiseConv2d_global[((oci_c_init17 + 68))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init18 = 0; oci_c_init18 < 4; ++oci_c_init18) {
        DepthwiseConv2d_global[((oci_c_init18 + 72))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init19 = 0; oci_c_init19 < 4; ++oci_c_init19) {
        DepthwiseConv2d_global[((oci_c_init19 + 76))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init20 = 0; oci_c_init20 < 4; ++oci_c_init20) {
        DepthwiseConv2d_global[((oci_c_init20 + 80))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init21 = 0; oci_c_init21 < 4; ++oci_c_init21) {
        DepthwiseConv2d_global[((oci_c_init21 + 84))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init22 = 0; oci_c_init22 < 4; ++oci_c_init22) {
        DepthwiseConv2d_global[((oci_c_init22 + 88))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init23 = 0; oci_c_init23 < 4; ++oci_c_init23) {
        DepthwiseConv2d_global[((oci_c_init23 + 92))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init24 = 0; oci_c_init24 < 4; ++oci_c_init24) {
        DepthwiseConv2d_global[((oci_c_init24 + 96))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init25 = 0; oci_c_init25 < 4; ++oci_c_init25) {
        DepthwiseConv2d_global[((oci_c_init25 + 100))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init26 = 0; oci_c_init26 < 4; ++oci_c_init26) {
        DepthwiseConv2d_global[((oci_c_init26 + 104))] = 0.000000e+00f;
      }
      for (int32_t oci_c_init27 = 0; oci_c_init27 < 4; ++oci_c_init27) {
        DepthwiseConv2d_global[((oci_c_init27 + 108))] = 0.000000e+00f;
      }
      for (int32_t kh = 0; kh < 3; ++kh) {
        for (int32_t kw = 0; kw < 3; ++kw) {
          for (int32_t oci_c = 0; oci_c < 4; ++oci_c) {
            DepthwiseConv2d_global[(oci_c)] = (DepthwiseConv2d_global[(oci_c)] + (((float*)PaddedInput)[((((((((i1_i2_fused / 112) * 51984) + (kh * 456)) + ((i1_i2_fused % 112) * 456)) + (ow_outer * 112)) + (kw * 4)) + oci_c))] * ((float*)placeholder1)[((((((i1_i2_fused / 112) * 36) + (kh * 12)) + (kw * 4)) + oci_c))]));
          }
          for (int32_t oci_c1 = 0; oci_c1 < 4; ++oci_c1) {
            DepthwiseConv2d_global[((oci_c1 + 4))] = (DepthwiseConv2d_global[((oci_c1 + 4))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 112) * 51984) + (kh * 456)) + ((i1_i2_fused % 112) * 456)) + (ow_outer * 112)) + (kw * 4)) + oci_c1) + 4))] * ((float*)placeholder1)[((((((i1_i2_fused / 112) * 36) + (kh * 12)) + (kw * 4)) + oci_c1))]));
          }
          for (int32_t oci_c2 = 0; oci_c2 < 4; ++oci_c2) {
            DepthwiseConv2d_global[((oci_c2 + 8))] = (DepthwiseConv2d_global[((oci_c2 + 8))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 112) * 51984) + (kh * 456)) + ((i1_i2_fused % 112) * 456)) + (ow_outer * 112)) + (kw * 4)) + oci_c2) + 8))] * ((float*)placeholder1)[((((((i1_i2_fused / 112) * 36) + (kh * 12)) + (kw * 4)) + oci_c2))]));
          }
          for (int32_t oci_c3 = 0; oci_c3 < 4; ++oci_c3) {
            DepthwiseConv2d_global[((oci_c3 + 12))] = (DepthwiseConv2d_global[((oci_c3 + 12))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 112) * 51984) + (kh * 456)) + ((i1_i2_fused % 112) * 456)) + (ow_outer * 112)) + (kw * 4)) + oci_c3) + 12))] * ((float*)placeholder1)[((((((i1_i2_fused / 112) * 36) + (kh * 12)) + (kw * 4)) + oci_c3))]));
          }
          for (int32_t oci_c4 = 0; oci_c4 < 4; ++oci_c4) {
            DepthwiseConv2d_global[((oci_c4 + 16))] = (DepthwiseConv2d_global[((oci_c4 + 16))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 112) * 51984) + (kh * 456)) + ((i1_i2_fused % 112) * 456)) + (ow_outer * 112)) + (kw * 4)) + oci_c4) + 16))] * ((float*)placeholder1)[((((((i1_i2_fused / 112) * 36) + (kh * 12)) + (kw * 4)) + oci_c4))]));
          }
          for (int32_t oci_c5 = 0; oci_c5 < 4; ++oci_c5) {
            DepthwiseConv2d_global[((oci_c5 + 20))] = (DepthwiseConv2d_global[((oci_c5 + 20))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 112) * 51984) + (kh * 456)) + ((i1_i2_fused % 112) * 456)) + (ow_outer * 112)) + (kw * 4)) + oci_c5) + 20))] * ((float*)placeholder1)[((((((i1_i2_fused / 112) * 36) + (kh * 12)) + (kw * 4)) + oci_c5))]));
          }
          for (int32_t oci_c6 = 0; oci_c6 < 4; ++oci_c6) {
            DepthwiseConv2d_global[((oci_c6 + 24))] = (DepthwiseConv2d_global[((oci_c6 + 24))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 112) * 51984) + (kh * 456)) + ((i1_i2_fused % 112) * 456)) + (ow_outer * 112)) + (kw * 4)) + oci_c6) + 24))] * ((float*)placeholder1)[((((((i1_i2_fused / 112) * 36) + (kh * 12)) + (kw * 4)) + oci_c6))]));
          }
          for (int32_t oci_c7 = 0; oci_c7 < 4; ++oci_c7) {
            DepthwiseConv2d_global[((oci_c7 + 28))] = (DepthwiseConv2d_global[((oci_c7 + 28))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 112) * 51984) + (kh * 456)) + ((i1_i2_fused % 112) * 456)) + (ow_outer * 112)) + (kw * 4)) + oci_c7) + 28))] * ((float*)placeholder1)[((((((i1_i2_fused / 112) * 36) + (kh * 12)) + (kw * 4)) + oci_c7))]));
          }
          for (int32_t oci_c8 = 0; oci_c8 < 4; ++oci_c8) {
            DepthwiseConv2d_global[((oci_c8 + 32))] = (DepthwiseConv2d_global[((oci_c8 + 32))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 112) * 51984) + (kh * 456)) + ((i1_i2_fused % 112) * 456)) + (ow_outer * 112)) + (kw * 4)) + oci_c8) + 32))] * ((float*)placeholder1)[((((((i1_i2_fused / 112) * 36) + (kh * 12)) + (kw * 4)) + oci_c8))]));
          }
          for (int32_t oci_c9 = 0; oci_c9 < 4; ++oci_c9) {
            DepthwiseConv2d_global[((oci_c9 + 36))] = (DepthwiseConv2d_global[((oci_c9 + 36))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 112) * 51984) + (kh * 456)) + ((i1_i2_fused % 112) * 456)) + (ow_outer * 112)) + (kw * 4)) + oci_c9) + 36))] * ((float*)placeholder1)[((((((i1_i2_fused / 112) * 36) + (kh * 12)) + (kw * 4)) + oci_c9))]));
          }
          for (int32_t oci_c10 = 0; oci_c10 < 4; ++oci_c10) {
            DepthwiseConv2d_global[((oci_c10 + 40))] = (DepthwiseConv2d_global[((oci_c10 + 40))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 112) * 51984) + (kh * 456)) + ((i1_i2_fused % 112) * 456)) + (ow_outer * 112)) + (kw * 4)) + oci_c10) + 40))] * ((float*)placeholder1)[((((((i1_i2_fused / 112) * 36) + (kh * 12)) + (kw * 4)) + oci_c10))]));
          }
          for (int32_t oci_c11 = 0; oci_c11 < 4; ++oci_c11) {
            DepthwiseConv2d_global[((oci_c11 + 44))] = (DepthwiseConv2d_global[((oci_c11 + 44))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 112) * 51984) + (kh * 456)) + ((i1_i2_fused % 112) * 456)) + (ow_outer * 112)) + (kw * 4)) + oci_c11) + 44))] * ((float*)placeholder1)[((((((i1_i2_fused / 112) * 36) + (kh * 12)) + (kw * 4)) + oci_c11))]));
          }
          for (int32_t oci_c12 = 0; oci_c12 < 4; ++oci_c12) {
            DepthwiseConv2d_global[((oci_c12 + 48))] = (DepthwiseConv2d_global[((oci_c12 + 48))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 112) * 51984) + (kh * 456)) + ((i1_i2_fused % 112) * 456)) + (ow_outer * 112)) + (kw * 4)) + oci_c12) + 48))] * ((float*)placeholder1)[((((((i1_i2_fused / 112) * 36) + (kh * 12)) + (kw * 4)) + oci_c12))]));
          }
          for (int32_t oci_c13 = 0; oci_c13 < 4; ++oci_c13) {
            DepthwiseConv2d_global[((oci_c13 + 52))] = (DepthwiseConv2d_global[((oci_c13 + 52))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 112) * 51984) + (kh * 456)) + ((i1_i2_fused % 112) * 456)) + (ow_outer * 112)) + (kw * 4)) + oci_c13) + 52))] * ((float*)placeholder1)[((((((i1_i2_fused / 112) * 36) + (kh * 12)) + (kw * 4)) + oci_c13))]));
          }
          for (int32_t oci_c14 = 0; oci_c14 < 4; ++oci_c14) {
            DepthwiseConv2d_global[((oci_c14 + 56))] = (DepthwiseConv2d_global[((oci_c14 + 56))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 112) * 51984) + (kh * 456)) + ((i1_i2_fused % 112) * 456)) + (ow_outer * 112)) + (kw * 4)) + oci_c14) + 56))] * ((float*)placeholder1)[((((((i1_i2_fused / 112) * 36) + (kh * 12)) + (kw * 4)) + oci_c14))]));
          }
          for (int32_t oci_c15 = 0; oci_c15 < 4; ++oci_c15) {
            DepthwiseConv2d_global[((oci_c15 + 60))] = (DepthwiseConv2d_global[((oci_c15 + 60))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 112) * 51984) + (kh * 456)) + ((i1_i2_fused % 112) * 456)) + (ow_outer * 112)) + (kw * 4)) + oci_c15) + 60))] * ((float*)placeholder1)[((((((i1_i2_fused / 112) * 36) + (kh * 12)) + (kw * 4)) + oci_c15))]));
          }
          for (int32_t oci_c16 = 0; oci_c16 < 4; ++oci_c16) {
            DepthwiseConv2d_global[((oci_c16 + 64))] = (DepthwiseConv2d_global[((oci_c16 + 64))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 112) * 51984) + (kh * 456)) + ((i1_i2_fused % 112) * 456)) + (ow_outer * 112)) + (kw * 4)) + oci_c16) + 64))] * ((float*)placeholder1)[((((((i1_i2_fused / 112) * 36) + (kh * 12)) + (kw * 4)) + oci_c16))]));
          }
          for (int32_t oci_c17 = 0; oci_c17 < 4; ++oci_c17) {
            DepthwiseConv2d_global[((oci_c17 + 68))] = (DepthwiseConv2d_global[((oci_c17 + 68))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 112) * 51984) + (kh * 456)) + ((i1_i2_fused % 112) * 456)) + (ow_outer * 112)) + (kw * 4)) + oci_c17) + 68))] * ((float*)placeholder1)[((((((i1_i2_fused / 112) * 36) + (kh * 12)) + (kw * 4)) + oci_c17))]));
          }
          for (int32_t oci_c18 = 0; oci_c18 < 4; ++oci_c18) {
            DepthwiseConv2d_global[((oci_c18 + 72))] = (DepthwiseConv2d_global[((oci_c18 + 72))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 112) * 51984) + (kh * 456)) + ((i1_i2_fused % 112) * 456)) + (ow_outer * 112)) + (kw * 4)) + oci_c18) + 72))] * ((float*)placeholder1)[((((((i1_i2_fused / 112) * 36) + (kh * 12)) + (kw * 4)) + oci_c18))]));
          }
          for (int32_t oci_c19 = 0; oci_c19 < 4; ++oci_c19) {
            DepthwiseConv2d_global[((oci_c19 + 76))] = (DepthwiseConv2d_global[((oci_c19 + 76))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 112) * 51984) + (kh * 456)) + ((i1_i2_fused % 112) * 456)) + (ow_outer * 112)) + (kw * 4)) + oci_c19) + 76))] * ((float*)placeholder1)[((((((i1_i2_fused / 112) * 36) + (kh * 12)) + (kw * 4)) + oci_c19))]));
          }
          for (int32_t oci_c20 = 0; oci_c20 < 4; ++oci_c20) {
            DepthwiseConv2d_global[((oci_c20 + 80))] = (DepthwiseConv2d_global[((oci_c20 + 80))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 112) * 51984) + (kh * 456)) + ((i1_i2_fused % 112) * 456)) + (ow_outer * 112)) + (kw * 4)) + oci_c20) + 80))] * ((float*)placeholder1)[((((((i1_i2_fused / 112) * 36) + (kh * 12)) + (kw * 4)) + oci_c20))]));
          }
          for (int32_t oci_c21 = 0; oci_c21 < 4; ++oci_c21) {
            DepthwiseConv2d_global[((oci_c21 + 84))] = (DepthwiseConv2d_global[((oci_c21 + 84))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 112) * 51984) + (kh * 456)) + ((i1_i2_fused % 112) * 456)) + (ow_outer * 112)) + (kw * 4)) + oci_c21) + 84))] * ((float*)placeholder1)[((((((i1_i2_fused / 112) * 36) + (kh * 12)) + (kw * 4)) + oci_c21))]));
          }
          for (int32_t oci_c22 = 0; oci_c22 < 4; ++oci_c22) {
            DepthwiseConv2d_global[((oci_c22 + 88))] = (DepthwiseConv2d_global[((oci_c22 + 88))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 112) * 51984) + (kh * 456)) + ((i1_i2_fused % 112) * 456)) + (ow_outer * 112)) + (kw * 4)) + oci_c22) + 88))] * ((float*)placeholder1)[((((((i1_i2_fused / 112) * 36) + (kh * 12)) + (kw * 4)) + oci_c22))]));
          }
          for (int32_t oci_c23 = 0; oci_c23 < 4; ++oci_c23) {
            DepthwiseConv2d_global[((oci_c23 + 92))] = (DepthwiseConv2d_global[((oci_c23 + 92))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 112) * 51984) + (kh * 456)) + ((i1_i2_fused % 112) * 456)) + (ow_outer * 112)) + (kw * 4)) + oci_c23) + 92))] * ((float*)placeholder1)[((((((i1_i2_fused / 112) * 36) + (kh * 12)) + (kw * 4)) + oci_c23))]));
          }
          for (int32_t oci_c24 = 0; oci_c24 < 4; ++oci_c24) {
            DepthwiseConv2d_global[((oci_c24 + 96))] = (DepthwiseConv2d_global[((oci_c24 + 96))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 112) * 51984) + (kh * 456)) + ((i1_i2_fused % 112) * 456)) + (ow_outer * 112)) + (kw * 4)) + oci_c24) + 96))] * ((float*)placeholder1)[((((((i1_i2_fused / 112) * 36) + (kh * 12)) + (kw * 4)) + oci_c24))]));
          }
          for (int32_t oci_c25 = 0; oci_c25 < 4; ++oci_c25) {
            DepthwiseConv2d_global[((oci_c25 + 100))] = (DepthwiseConv2d_global[((oci_c25 + 100))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 112) * 51984) + (kh * 456)) + ((i1_i2_fused % 112) * 456)) + (ow_outer * 112)) + (kw * 4)) + oci_c25) + 100))] * ((float*)placeholder1)[((((((i1_i2_fused / 112) * 36) + (kh * 12)) + (kw * 4)) + oci_c25))]));
          }
          for (int32_t oci_c26 = 0; oci_c26 < 4; ++oci_c26) {
            DepthwiseConv2d_global[((oci_c26 + 104))] = (DepthwiseConv2d_global[((oci_c26 + 104))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 112) * 51984) + (kh * 456)) + ((i1_i2_fused % 112) * 456)) + (ow_outer * 112)) + (kw * 4)) + oci_c26) + 104))] * ((float*)placeholder1)[((((((i1_i2_fused / 112) * 36) + (kh * 12)) + (kw * 4)) + oci_c26))]));
          }
          for (int32_t oci_c27 = 0; oci_c27 < 4; ++oci_c27) {
            DepthwiseConv2d_global[((oci_c27 + 108))] = (DepthwiseConv2d_global[((oci_c27 + 108))] + (((float*)PaddedInput)[(((((((((i1_i2_fused / 112) * 51984) + (kh * 456)) + ((i1_i2_fused % 112) * 456)) + (ow_outer * 112)) + (kw * 4)) + oci_c27) + 108))] * ((float*)placeholder1)[((((((i1_i2_fused / 112) * 36) + (kh * 12)) + (kw * 4)) + oci_c27))]));
          }
        }
      }
      for (int32_t ow_inner = 0; ow_inner < 28; ++ow_inner) {
        for (int32_t oci = 0; oci < 4; ++oci) {
          ((float*)DepthwiseConv2d)[((((ow_outer * 112) + (ow_inner * 4)) + oci))] = DepthwiseConv2d_global[(((ow_inner * 4) + oci))];
        }
      }
    }
    for (int32_t i3_outer = 0; i3_outer < 4; ++i3_outer) {
      for (int32_t i3_inner = 0; i3_inner < 28; ++i3_inner) {
        for (int32_t i41 = 0; i41 < 4; ++i41) {
          float _1 = ((float*)DepthwiseConv2d)[((((i3_outer * 112) + (i3_inner * 4)) + i41))] + ((float*)placeholder2)[((((i1_i2_fused / 112) * 4) + i41))];
          float _2 = (_1) < (6.000000e+00f) ? (_1) : (6.000000e+00f);
          ((float*)compute)[(((((i1_i2_fused * 448) + (i3_outer * 112)) + (i3_inner * 4)) + i41))] = ((_2) > (0.000000e+00f) ? (_2) : (0.000000e+00f));
        }
      }
    }
    if (TVMBackendFreeWorkspace(1, dev_id, DepthwiseConv2d) != 0) {
      return -1;
    }
  }
  if (TVMBackendFreeWorkspace(1, dev_id, PaddedInput) != 0) {
    return -1;
  }
  return 0;
}

