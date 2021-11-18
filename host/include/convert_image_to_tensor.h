#ifndef SIDE_LINUX_INCLUDE_CONVERT_TO_TENSOR_H_
#define SIDE_LINUX_INCLUDE_CONVERT_TO_TENSOR_H_

#include <string>
#include "dlpack/dlpack.h"

int32_t ConvertImageToTensor(const std::string& path, DLTensor** out_tensor);

#endif //  SIDE_LINUX_INCLUDE_CONVERT_TO_TENSOR_H_#define 