set -e

PREFIX="arm-linux-gnueabihf-"
${PREFIX}gcc -fPIC -I ../include -c -o default_lib0.o mlf/codegen/host/src/default_lib0.c
${PREFIX}gcc -fPIC -I ../include -c -o default_lib1.o mlf/codegen/host/src/default_lib1.c
${PREFIX}ar rcs libtvm_model_ops.a default_lib0.o default_lib1.o

rm -rf standalone_crt/build
make --directory=standalone_crt PREFIX=${PREFIX} CRT_CONFIG="../../include/crt_config.h" all
