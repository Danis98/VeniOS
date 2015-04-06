#ifdef __arch_x86
#include <util/dmp_util.h>

void dmp_gdt(gdt_ptr_t ptr, gdt_entry_t* entries){
	uint64_t* entries_ptr=(uint64_t*)entries;
	uint64_t i;
	printf("Dumping gdt entries... 5 %d-bit entries at %x \n",
		(uint64_t)(sizeof i*8), entries_ptr);
	printf("gdt_ptr: base -> %x\n\tlimit -> %x\n", ptr.base, ptr.limit);
	for(i=0;i<5;i++){
		printf("Addr: %x \t", entries_ptr);
		//mem_dmp(entries_ptr, entries_ptr+8, 32);
		printf("Expected entry: ");
		print_gdt_entry(entries[i]);
		entries_ptr+=sizeof i;
	}
}
#endif
