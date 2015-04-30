HOST?=$(shell ../default-host.sh)
HOSTARCH:=$(shell ../target-triplet-to-arch.sh $(HOST))

CFLAGS?=-O2 -g
CPPFLAGS?=
LDFLAGS?=
LIBS?=

DESTDIR?=
PREFIX?=/usr/local
EXEC_PREFIX?=$(PREFIX)
BOOTDIR?=$(EXEC_PREFIX)/boot
INCLUDEDIR?=$(PREFIX)/include

CFLAGS:=$(CFLAGS) -ffreestanding -fbuiltin -Wall -Wextra
CPPFLAGS:=$(CPPFLAGS) -Iinclude -D__is_venios_kernel -D__DEBUG
LDFLAGS:=$(LDFLAGS)
LIBS:=$(LIBS) -nostdlib -lk -lgcc

ARCHDIR:=arch/$(HOSTARCH)
UTILDIR:=util
DRIVERDIR:=drivers

include $(ARCHDIR)/make.config
include $(UTILDIR)/make.config
include $(DRIVERDIR)/make.config

CFLAGS:=$(CFLAGS) $(KERNEL_ARCH_CFLAGS) $(KERNEL_UTIL_CFLAGS) $(KERNEL_DRIVER_CFLAGS)
CPPFLAGS:=$(CPPFLAGS) -D$(TARGET) $(KERNEL_ARCH_CPPFLAGS) $(KERNEL_UTIL_CPPFLAGS) $(KERNEL_DRIVER_CPPFLAGS) 
LDFLAGS:=$(LDFLAGS) $(KERNEL_ARCH_LDFLAGS) $(KERNEL_UTIL_LDFLAGS) $(KERNEL_DRIVER_LDFLAGS)
LIBS:=$(LIBS) $(KERNEL_ARCH_LIBS) $(KERNEL_UTIL_LIBS) $(KERNEL_DRIVER_LIBS)

OBJS:=		\
$(KERNEL_ARCH_OBJS)\
$(KERNEL_UTIL_OBJS)\
$(KERNEL_DRIVER_OBJS)\
kernel/kernel.o \
kernel/io.o	\
boot/boot.o	\
arch/macros.o	\

CRTI_OBJ:=$(ARCHDIR)/crti.o
CRTBEGIN_OBJ:=$(shell $(CC) $(CFLAGS) $(LDFLAGS) -print-file-name=crtbegin.o)
CRTEND_OBJ:=$(shell $(CC) $(CFLAGS) $(LDFLAGS) -print-file-name=crtend.o)
CRTN_OBJ:=$(ARCHDIR)/crtn.o

OBJS_OUR:=\
$(CRTI_OBJ) \
$(OBJS) \
$(CRTN_OBJ) \

OBJ_LINK_LIST:= \
$(CRTI_OBJ)	\
$(CRTBEGIN_OBJ)	\
$(OBJS)		\
$(CRTEND_OBJ)	\
$(CRTN_OBJ)	\

all: venios.kernel

.PHONY: all clean install install-headers install-kernel

venios.kernel: $(OBJ_LINK_LIST) $(ARCHDIR)/linker.ld
	$(CC) -T $(ARCHDIR)/linker.ld -o $@ $(CFLAGS) $(OBJ_LINK_LIST) $(LDFLAGS) $(LIBS)

%.o: %.c
	$(CC) -c $< -o $@ -std=gnu11 $(CFLAGS) $(CPPFLAGS)

%.o:%.S
	$(CC) -c $< -o $@ $(CFLAGS) $(CPPFLAGS)

clean:
	rm -rf venios.kernel $(OBJS) $(OBJS_OUR) *.o *~

install: install-headers install-kernel

install-headers:
	mkdir -p $(DESTDIR)$(INCLUDEDIR)
	cp -RTv include $(DESTDIR)$(INCLUDEDIR)

install-kernel: venios.kernel
	mkdir -p $(DESTDIR)$(BOOTDIR)
	cp venios.kernel $(DESTDIR)$(BOOTDIR)
