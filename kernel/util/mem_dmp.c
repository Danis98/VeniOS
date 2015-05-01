#include <util/dmp_util.h>

void mem_dmp(uint32_t start, uint32_t limit, uint8_t mode){
	uint8_t gran=GRANULARITY(mode);	
	uint8_t num_lines=limit/BYTES_PER_LINE;
	if(limit%BYTES_PER_LINE!=0) num_lines++;

	uint32_t *cur_ptr=start;
	uint8_t cur_val;
	uint8_t off=0;

	for(int i=0;i<num_lines*BYTES_PER_LINE;i++){
		if(off%BYTES_PER_LINE==0)
			printf("[%x]\t", cur_ptr);
		if(off%gran==0)
			printf("0x");
		cur_val=(uint8_t)(*cur_ptr);
		printf("%x", cur_val);
		if(off%gran==gran-1)
			printf(" ");
		if(off%BYTES_PER_LINE==BYTES_PER_LINE-1)
			printf("\n");
		cur_ptr++;
		off++;
	}
	if(off%BYTES_PER_LINE!=0)
		printf("\n");
}
