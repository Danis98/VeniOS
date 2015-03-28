#!/bin/sh
set -e
. ./build.sh

mkdir -p iso
mkdir -p iso/boot
mkdir -p iso/boot/grub

cp sysroot/boot/venios.kernel iso/boot/venios.kernel
cat > iso/boot/grub/grub.cfg << EOF
menuentry "VeniOS" {
	multiboot /boot/venios.kernel
}
EOF
grub-mkrescue -o VeniOS.iso iso
