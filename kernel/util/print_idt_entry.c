#ifdef __arch_x86
#include <util/dmp_util.h>

void print_idt_entry(idt_entry_t *entry){
	printf("%x%x%x%x%x at %x\n",
				entry->base_low,
				entry->selector,
				entry->zero,
				entry->flags,
				entry->base_high,
				entry);
}
#endif
