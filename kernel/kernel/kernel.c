/***********************************************************
 * VeniOS Alpha kernel
 * Made by Venio
 * Copyright (c) 2014 Weird Lion Studios 
***********************************************************/

#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include <dmp_util.h>

#include <kernel/vga.h>
#include <kernel/tty.h>
#include <kernel/sys_info.h>

//Platform-specific includes
#ifdef __x86
#include <kernel/gdt.h>
#include <kernel/idt.h>
#endif

//Are we targeting the host OS?
#if defined(__linux__)
#error "Not using a cross compiler! There will be trouble!"
#endif

void kernel_init(void){
	terminal_initialize(COLOR_LIGHT_GREY,COLOR_BLACK);
	#ifdef __x86
	init_gdt();
	init_idt();
	#endif
}

void kernel_main(void){
	//Nice header with infos
	print_header();
	#ifdef __x86
	//Check supposed gdt entries
	dmp_gdt(gdt_ptr, gdt_entries);
	#endif
}
