#ifdef __arch_x86
#include <util/dmp_util.h>

void print_gdt_entry(gdt_entry_t entry){
	printf("%x%x%x%x%x%x at %x\n", entry.limit_low,
					entry.base_low,
					entry.base_middle,
					entry.access,
					entry.granularity,
					entry.base_high,
					&entry);
}
#endif
