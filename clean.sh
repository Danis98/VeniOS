#!/bin/sh
set -e
. ./config.sh

for PROJECT in $PROJECTS; do
	$MAKE -C $PROJECT clean
done

rm -rfv sysroot
rm -rfv iso
rm -rfv venios.iso
rm -f venios.log
