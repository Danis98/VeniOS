#ifndef _DBG_UTIL_H
#define _DBG_UTIL_H

#include <stdint.h>
#include <stdio.h>

#ifdef __arch_x86
#include <arch/i386/gdt.h>
#include <arch/i386/idt.h>
#endif

#define BITS_PER_BYTE 8
#define BITS_PER_WORD 32
#define BITS_PER_LONG 64

//Granularity of mem_dmp
#define GRAN_BYTE 1
#define GRAN_WORD BITS_PER_WORD/BITS_PER_BYTE
#define GRAN_LONG BITS_PER_LONG/BITS_PER_BYTE
#define GRANULARITY(g) g==0?GRAN_BYTE:(g==1?GRAN_WORD:GRAN_LONG)

#define BYTES_PER_LINE 8

void mem_dmp(uint32_t addr, uint32_t limit, uint8_t mode);
#ifdef __arch_x86
void dmp_gdt(gdt_ptr_t ptr, gdt_entry_t* entries);
void print_gdt_entry(gdt_entry_t *entry);
void dmp_idt(idt_ptr_t ptr, idt_entry_t *entries);
void print_idt_entry(idt_entry_t *entry);
#endif

#endif
