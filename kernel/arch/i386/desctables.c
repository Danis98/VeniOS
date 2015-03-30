#include <stdint.h>
#include <string.h>

#include <kernel/desctables.h>

extern void gdt_flush(uint32_t);
extern void idt_flush(uint32_t);

static void init_gdt();
static void gdt_set_gate(int32_t, uint32_t, uint32_t, uint8_t, uint8_t);
static void init_idt();
static void idt_set_gate(uint8_t, uint32_t, uint16_t, uint8_t);

gdt_entry_t gdt_entries[5];
gdt_ptr_t gdt_ptr;
idt_entry_t idt_entries[256];
idt_ptr_t idt_ptr;

void init_desctables(){
	init_gdt();
	init_idt();
}

static void init_gdt(){
	gdt_ptr.limit=(sizeof(gdt_entry_t)*5)-1;
	gdt_ptr.base=(uint32_t)gdt_entries;
	
	gdt_set_gate(0, 0, 0, 0, 0);
	//10011010 11001111
	gdt_set_gate(1, 0, 0xffffffff, KERNEL_LEVEL|CODE_SEG, DEFAULT_FLAGS);
	//10010010 11001111
	gdt_set_gate(2, 0, 0xffffffff, KERNEL_LEVEL|DATA_SEG, DEFAULT_FLAGS);
	//11111010
	gdt_set_gate(3, 0, 0xffffffff, USER_LEVEL|CODE_SEG, DEFAULT_FLAGS);
	//11110010
	gdt_set_gate(4, 0, 0xffffffff, USER_LEVEL|DATA_SEG, DEFAULT_FLAGS);

	gdt_flush((uint32_t)&gdt_ptr);
}

static void init_idt(){
	idt_ptr.limit=sizeof(idt_entry_t)*256-1;
	idt_ptr.base=(uint32_t)&idt_entries;
	memset(&idt_entries, 0, sizeof(idt_entry_t)*256);

	idt_set_gate(0, (uint32_t)isr0, 0x08, 0x8e);
}

static void gdt_set_gate(int32_t index, uint32_t base, uint32_t limit,
			uint8_t access, uint8_t granularity){
	gdt_entries[index].base_low	=base & 0xffff;
	gdt_entries[index].base_middle	=(base>>16) & 0xff;
	gdt_entries[index].base_high	=(base>>24) & 0xff;

	gdt_entries[index].limit_low	=limit & 0xffff;
	gdt_entries[index].granularity	=(limit>>16) & 0x0f;

	gdt_entries[index].granularity	|=granularity & 0xff;
	gdt_entries[index].access	=access;
	
}

static void idt_set_gate(uint8_t index, uint32_t base, uint16_t selector,
			uint8_t flags){
	idt_entries[index].base_low	=base&0xffff;
	idt_entries[index].base_high	=(base>>16)&0xffff;

	idt_entries[index].selector	=selector;

	idt_entries[index].flags	=flags;

	idt_entries[index].zero		=0;
}
