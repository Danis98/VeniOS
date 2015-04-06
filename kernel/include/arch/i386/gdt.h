#ifndef _KERNEL_GDT_H
#define _KERNEL_GDT_H

#include <stdint.h>

#define CODE_SEG 0xA
#define DATA_SEG 0x2
#define KERNEL_LEVEL 0x90
#define USER_LEVEL 0xF0
#define DEFAULT_FLAGS 0xCF

struct gdt_entry_struct{
	uint16_t limit_low;
	uint16_t base_low;
	uint8_t  base_middle;
	uint8_t  access;
	uint8_t  granularity;
	uint8_t  base_high;
}__attribute__((packed));

struct gdt_ptr_struct{
	uint16_t limit;
	uint32_t base;
}__attribute__((packed));

typedef struct gdt_entry_struct gdt_entry_t;
typedef struct gdt_ptr_struct gdt_ptr_t;

extern gdt_entry_t gdt_entries[5];
extern gdt_ptr_t gdt_ptr;

void init_gdt();
void gdt_set_gate(int32_t, uint32_t, uint32_t, uint8_t, uint8_t);

extern void gdt_flush(uint32_t);

#endif
