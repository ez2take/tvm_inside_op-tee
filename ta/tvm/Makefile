CC      ?= $(CROSS_COMPILE)gcc
CXX     ?= $(CROSS_COMPILE)g++
LD      ?= $(CROSS_COMPILE)ld
AR      ?= $(CROSS_COMPILE)ar
NM      ?= $(CROSS_COMPILE)nm
OBJCOPY ?= $(CROSS_COMPILE)objcopy
OBJDUMP ?= $(CROSS_COMPILE)objdump
READELF ?= $(CROSS_COMPILE)readelf

TVM_DIR = /home/ez2take/projects/ml_with_tee/arch_rpi3/optee_ml_with_tee/ta/tvm
TA_DIR = $(TVM_DIR)/..
TA_INCLUDE_DIR = $(TA_DIR)/include


MODEL_LIB_DIR = $(TVM_DIR)/mlf
MODEL_LIB_OBJS = $(MODEL_LIB_DIR)/codegen/host/src/default_lib0.o $(MODEL_LIB_DIR)/codegen/host/src/default_lib1.o
MODEL_LIB_CFLAGS += -Wall -fPIC -c -I$(TA_INCLUDE_DIR)
MODEL_LIB_TARGET = libtvm_model_ops.a


TVM_C_RUNTIME_LIB_DIR = $(TVM_DIR)/standalone_crt
TVM_C_RUNTIME_LIB_MAKE_ARGS += "PREFIX=$(CROSS_COMPILE)"
TVM_C_RUNTIME_LIB_MAKE_ARGS += "CRT_CONFIG=$(TA_INCLUDE_DIR)/crt_config.h"
TVM_C_RUNTIME_LIB_TARGET = crt

TARGETS = $(MODEL_LIB_TARGET) $(TVM_C_RUNTIME_LIB_TARGET)
.PHONY: tvm_libraries
tvm_libraries: $(TARGETS)

$(MODEL_LIB_TARGET): $(MODEL_LIB_OBJS)
	$(AR) rcs $@ $^

%.o: %.c
	$(CC) $(MODEL_LIB_CFLAGS) $< -o $@

$(TVM_C_RUNTIME_LIB_TARGET):
	make -C $(TVM_C_RUNTIME_LIB_DIR) $(TVM_C_RUNTIME_LIB_MAKE_ARGS) all

.PHONY: clean
clean:
	rm $(MODEL_LIB_TARGET) $(MODEL_LIB_OBJS)
	make -C $(TVM_C_RUNTIME_LIB_DIR) $(TVM_C_RUNTIME_LIB_MAKE_ARGS) clean


