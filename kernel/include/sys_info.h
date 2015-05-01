#ifndef _KERNEL_INFO_H
#define _KERNEL_INFO_H

#ifdef __arch_x86
#include <arch/i386/vga.h>
#include <arch/i386/tty.h>
#endif

/********
 * Machine stuff
********/

#define BDA_ADDR 0x0400

/********
 * VeniOS stuff
********/

#define NAME_UNSUPPORTED "unsupported_arch"
#define NAME_X86 "x86"

#define NAME_LINE1 "__      __        _  ____   _____ "
#define NAME_LINE2 "\\ \\    / /       (_)/ __ \\ / ____|"
#define NAME_LINE3 " \\ \\  / /__ _ __  _| |  | | (___  "
#define NAME_LINE4 "  \\ \\/ / _ \\ '_ \\| | |  | |\\___ \\"
#define NAME_LINE5 "   \\  /  __/ | | | | |__| |____) |"
#define NAME_LINE6 "    \\/ \\___|_| |_|_|\\____/|_____/"
                                   
#define RELEASE "alpha"
#define VERSION "0.1"


extern char *arch;

#define AUTHORS "Venio"
#define COPYRIGHT "Copyright (c) 2014-2015 Weird Lion Studios"

/*Print a header of unseen beauty and preserve the previous
 terminal color at the sam time! Wow*/
extern void print_header();

#endif
