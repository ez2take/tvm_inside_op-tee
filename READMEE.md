# Ml inference in trustzone with tvm

## Evaluation Board Setup

### Replace rootfs with more useful one
The rootfs provided by buildroot of op-tee has so poor compornents that cannot connect to internet and do any useful commands which are avaiable in ordinal linux pc. So here is a demonstration to replace the root filesystem with more rich and useful one, though not really needed for the final goal but strongly recommended.

1.Compile the OP-TEE and Project  
Follow the instructions of OP-TEE document linked below.  
When you want to compile trusted app and client app of my project, patch "build/common.mk" with "optee_ml_with_tee_common.mk.patch" before compiling entire op-tee project.
https://optee.readthedocs.io/en/latest/building/devices/rpi3.html#build-instructions

1. Download and decompress arch linux rootfs image
There is no need for choosing arch linux but the rootfs must have glibc which is version > 2.30.
> $ wget  http://os.archlinuxarm.org/os/ArchLinuxARM-rpi-aarch64-latest.tar.gz
> $ mkdir rpi-rootfs
> $ sudo tar zxvf ArchLinuxARM-rpi-aarch64-latest.tar.gz -C rpi-rootfs

2. Copy files from built op-tee image
my repository has a install script
> $ cd <optee_ml_with_tee>
> $ ./install_optee.sh -f ../out-br/target -t /path/to/rootfs

3. Partition and format the SD card
Follow the instructions as "<op-tee>/build$ make img-help" command tells. But when you finally put the rootfs files, you have to copy the files of "rpi-rootfs" directory

4. (optional) Setup NFS
It is optional but strongly needed for debugging. Follow the instructions of OP-TEE Documentation linked below.
https://optee.readthedocs.io/en/latest/building/devices/rpi3.html#nfs-boot


## References


* https://github.com/gagachang/Debian-based_rootfs_with_OPTEE ... when installing files


