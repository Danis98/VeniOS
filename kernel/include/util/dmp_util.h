#ifndef _DBG_UTIL_H
#define _DBG_UTIL_H

#include <stdint.h>
#include <stdio.h>

#ifdef __arch_x86
#include <arch/i386/gdt.h>
#include <arch/i386/idt.h>
#endif

//Granularity of mem_dmp
#define GRAN_BYTE 1
#define GRAN_WORD 2
#define GRANULARITY(g) g==0?GRAN_BYTE:GRAN_WORD

void mem_dmp(uint32_t addr, uint32_t limit, uint8_t mode);
#ifdef __arch_x86
void dmp_gdt(gdt_ptr_t ptr, gdt_entry_t* entries);
void print_gdt_entry(gdt_entry_t entry);
#endif

#endif
