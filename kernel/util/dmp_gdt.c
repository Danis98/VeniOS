#ifdef __arch_x86
#include <util/dmp_util.h>

void dmp_gdt(gdt_ptr_t ptr, gdt_entry_t* entries){
	uint64_t i;
	//Header
	printf("Dumping gdt entries... 5 %d-bit entries at %x \n",
		(uint64_t)(sizeof i*8), (uint32_t*)entries);
	printf("gdt_ptr: base -> %x\n\tlimit -> %x\n", ptr.base, ptr.limit);
	//Individual entries
	for(i=0;i<5;i++){
		printf("[%x] ", &entries[i]);
		mem_dmp(&entries[i], 8, 2);
		printf("Expected entry: ");
		print_gdt_entry(&entries[i]);
	}
}
#endif
