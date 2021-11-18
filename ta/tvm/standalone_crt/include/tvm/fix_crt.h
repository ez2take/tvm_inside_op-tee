#ifndef __FIX_CRT_H_
#define __FIX_CRT_H_
#include <tvm/runtime/crt/platform.h>
#include <tvm/runtime/crt/error_codes.h>

__attribute__((format(printf, 1, 2))) int TVMAPIErrorf(const char* msg, ...);
#define fprintf(ignore, ...) TVMAPIErrorf(__VA_ARGS__)

#undef assert
#define assert(expr) \
    if(!(expr)){    \
        TVMPlatformAbort(kTvmErrorNoError); \
    }

#undef isspace
#define isspace(ch) \
    ((ch) == '\x20')

#endif // !__FIX_CRT_H_