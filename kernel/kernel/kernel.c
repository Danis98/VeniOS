/***********************************************************
 * VeniOS Alpha kernel
 * Made by Venio
 * Copyright (c) 2014 Weird Lion Studios 
***********************************************************/

#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdio.h>

#include <sys_info.h>
#include <util/dmp_util.h>
#include <arch/macros.h>

//Platform-specific includes
#ifdef __arch_x86
#include <arch/i386/vga.h>
#include <arch/i386/tty.h>
#include <arch/i386/gdt.h>
#include <arch/i386/idt.h>
#endif

//Are we targeting the host OS?
#if defined(__linux__)
#error "Not using a cross compiler! There will be trouble!"
#endif

void kernel_init(void){
	terminal_initialize(COLOR_LIGHT_GREY,COLOR_BLACK);
	if(!check_arch_macros()){
		printf("Invalid architecture selected during compile-time.\n"
			"How did you get it to work in the first place?\n"
			"Panicking...\n");
		while(1);
	}
	#ifdef __arch_x86
	init_gdt();
	init_idt();
	arch=NAME_X86;
	#else
	arch=NAME_UNSUPPORTED
	#endif
}

void kernel_main(void){
	//Nice header with infos
	print_header();
}
