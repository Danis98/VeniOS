#ifndef _KERNEL_DESCRIPTOR_TABLES_H
#define _KERNEL_DESCRIPTOR_TABLES_H

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

struct idt_entry_struct{
	uint16_t base_low;
	uint16_t selector;
	uint8_t zero;
	uint8_t flags;
	uint16_t base_high;
}__attribute__((packed));

struct idt_ptr_struct{
	uint16_t limit;
	uint32_t base;
}__attribute__((packed));

struct tss_struct{

}__attribute__((packed));

typedef struct gdt_entry_struct gdt_entry_t;
typedef struct gdt_ptr_struct gdt_ptr_t;
typedef struct idt_entry_struct idt_entry_t;
typedef struct idt_ptr_struct idt_ptr_t;
typedef struct tss_struct tss_t;

extern gdt_entry_t gdt_entries[5];
extern gdt_ptr_t gdt_ptr;
extern idt_entry_t idt_entries[256];
extern idt_ptr_t idt_ptr;

void init_desctables();

extern void isr0();
extern void isr1();
extern void isr2();
extern void isr3();
extern void isr4();
extern void isr5();
extern void isr6();
extern void isr7();
extern void isr8();
extern void isr9();
extern void isr10();
extern void isr11();
extern void isr12();
extern void isr13();
extern void isr14();
extern void isr15();
extern void isr16();
extern void isr17();
extern void isr18();
extern void isr19();
extern void isr20();
extern void isr21();
extern void isr22();
extern void isr23();
extern void isr24();
extern void isr25();
extern void isr26();
extern void isr27();
extern void isr28();
extern void isr29();
extern void isr30();
extern void isr31();

#endif
