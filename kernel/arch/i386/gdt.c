#include <kernel/gdt.h>

#include <string.h>

gdt_entry_t gdt_entries[5];
gdt_ptr_t gdt_ptr;

void init_gdt(){
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

void gdt_set_gate(int32_t index, uint32_t base, uint32_t limit,
			uint8_t access, uint8_t granularity){
	gdt_entries[index].base_low	=base & 0xffff;
	gdt_entries[index].base_middle	=(base>>16) & 0xff;
	gdt_entries[index].base_high	=(base>>24) & 0xff;

	gdt_entries[index].limit_low	=limit & 0xffff;
	gdt_entries[index].granularity	=(limit>>16) & 0x0f;

	gdt_entries[index].granularity	|=granularity & 0xff;
	gdt_entries[index].access	=access;
	
}
