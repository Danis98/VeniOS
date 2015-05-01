#ifdef __arch_x86
#include <util/dmp_util.h>

void dmp_idt(idt_ptr_t ptr, idt_entry_t* entries){
	uint64_t* entries_ptr=(uint64_t*)entries;
	uint64_t i;
	printf("Dumping idt entries... 5 %d-bit entries at %x \n",
		(uint64_t)(sizeof i*8), entries_ptr);
	printf("idt_ptr: base -> %x\n\tlimit -> %x\n", ptr.base, ptr.limit);
	for(i=0;i<5;i++){
		entries_ptr=&entries[i];
		mem_dmp(entries_ptr, 8, 0);
		printf("Expected entry: ");
		print_idt_entry(&entries[i]);
	}
}
#endif
