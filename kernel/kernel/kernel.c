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
#include <kernel/desctables.h>
#include <kernel/sys_info.h>

//Are we targeting the host OS?
#if defined(__linux__)
#error "Not using a cross compiler! There will be trouble!"
#endif

void kernel_init(void){
	terminal_initialize(COLOR_LIGHT_GREY,COLOR_BLACK);
	//Nice header with infos
	print_header();
}

void kernel_main(void){
	//Initialize descriptor tables and print
	terminal_setcolor(COLOR_LIGHT_GREY,COLOR_BLACK);
	printf("\nInitializing gdt and idt...\n");
	init_desctables();
	printf("Done!\n");
	dmp_gdt(gdt_ptr, gdt_entries);

	//Memory dump test
	/*
	uint32_t mem_start=0x100000, mem_end=0x100100;
	printf("\nMemory dump test: from 0x%x to 0x%x\n", mem_start, mem_end);
	mem_dmp(mem_start, mem_end);*/
}
