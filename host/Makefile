CC      = $(CROSS_COMPILE)gcc
CXX     = $(CROSS_COMPILE)g++
LD      = $(CROSS_COMPILE)ld
AR      = $(CROSS_COMPILE)ar
NM      = $(CROSS_COMPILE)nm
OBJCOPY = $(CROSS_COMPILE)objcopy
OBJDUMP = $(CROSS_COMPILE)objdump
READELF = $(CROSS_COMPILE)readelf

TEEC_EXPORT ?= 
OPENCV_DIR ?= ../opencv
OBJS = src/main.o src/convert_image_to_tensor.o
CFLAGS += -Wall -I../ta/include -I./include
CFLAGS += -I$(TEEC_EXPORT)/include
CFLAGS += -I$(OPENCV_DIR)/include
DEBUGFLAGS = -g -O0
LDADD += -lopencv_imgcodecs -lopencv_imgproc -lopencv_core -lteec -L$(TEEC_EXPORT)/lib -L$(OPENCV_DIR)/lib
LDADD += -lm -lpthread -lz -ldl
BINARY = optee_ml_with_tee

.PHONY: all
all: $(BINARY)

$(BINARY): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDADD)

.PHONY: clean
clean:
	rm -f $(OBJS) $(BINARY)

%.o: %.cc
	$(CXX) $(CFLAGS) $(DEBUGFLAGS) -c $< -o $@

