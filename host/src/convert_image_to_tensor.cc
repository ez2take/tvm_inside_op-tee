#include "opencv2/imgcodecs.hpp"
#include "convert_image_to_tensor.h"
#include "dlpack/dlpack.h"

#include <string>
#include <cassert>
#include <memory>

namespace {

enum DataType
{
    kFloat32,
    kUInt32,
    kInt32
};
struct Shape
{
    int64_t width;
    int64_t height;
    int64_t channels;
};

template<class T>
std::unique_ptr<T> wrap_in_unique( T*&& t ) {
  auto* tmp = t;
  t = 0;
  return std::unique_ptr<T>(tmp);
}
/* 
 * return : u_char* data
 *   image data byte array. 
 *   the size can be infered from shape and datatype args.
 */
u_char* LoadImage(const std::string& path, 
                                  const Shape& shape, 
                                  const DataType datatype){

    auto cvmat = cv::imread(path, cv::IMREAD_COLOR);
    int32_t offset_w = (cvmat.rows - shape.width) / 2;
    int32_t offset_h = (cvmat.cols - shape.height) / 2;
    if(offset_w < 0 || offset_h < 0){
        return nullptr;
    }
    auto cropped_cvmat = cvmat(cv::Range(offset_w, offset_w + shape.width), 
                               cv::Range(offset_h, offset_h + shape.height));
    assert(cropped_cvmat.rows == shape.width
        && cropped_cvmat.cols == shape.height
        && cropped_cvmat.channels() == shape.channels);
    if(datatype == kFloat32)
        cropped_cvmat.convertTo(cropped_cvmat, CV_32F, 2.0 / 255, -1);
    int32_t size = shape.width*shape.height*shape.channels*4;
    assert(size == cropped_cvmat.dataend - cropped_cvmat.datastart);
    u_char* data = new u_char[size];
    std::memcpy(data,cropped_cvmat.data,size);
    return data;
}

void SetDLTensor(u_char* data, 
                    const Shape& shape,
                    const DataType datatype,
                    DLTensor* out_tensor) {
    out_tensor->data = data;
    out_tensor->device = DLDevice{kDLCPU,0};
    out_tensor->ndim = 3;
    if(datatype == kFloat32) out_tensor->dtype = DLDataType{kDLFloat,32,1};
    out_tensor->shape = new int64_t[4]{1, shape.width, shape.height, shape.channels};
    out_tensor->strides = nullptr;
    out_tensor->byte_offset = 0;
}
} // !namespace end

int32_t ConvertImageToTensor(const std::string& path, DLTensor** out_tensor){
    const Shape shape = {224,224,3};
    const DataType datatype = kFloat32;
    u_char* data = LoadImage(path, shape, datatype);
    if(data == nullptr){
        return -1;
    }
    DLTensor* prototype_tensor = new DLTensor();
    SetDLTensor(data, shape, datatype, prototype_tensor);
    if(prototype_tensor == nullptr){
        return -1;
    }
    *out_tensor = prototype_tensor;
    return 0;
}