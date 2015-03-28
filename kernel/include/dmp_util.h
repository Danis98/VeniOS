#ifndef _DBG_UTIL_H
#define _DBG_UTIL_H

#include <stdint.h>
#include <stdio.h>

#include <kernel/desctables.h>

void mem_dmp(uint32_t addr, uint32_t limit, uint8_t gran);
void dmp_gdt(gdt_ptr_t ptr, gdt_entry_t* entries);
void print_gdt_entry(gdt_entry_t entry);

#endif
