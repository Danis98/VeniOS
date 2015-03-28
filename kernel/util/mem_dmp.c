#include <dmp_util.h>

void mem_dmp(uint32_t start, uint32_t final, uint8_t gran){
	printf("Dumping!");
	gran/=8;
	uint32_t i;
	for(i=start;i<final;i+=gran){
		uint32_t* addr=(uint32_t*)i;
		if((i-start)%16==0)
			printf("\n[0x%x]\t", addr);
		if(*addr<0x1000)
			printf("0x%x\t\t", *addr);
		else if((i-start)%16!=15)
			printf("0x%x\t", *addr);
		else
			printf("0x%x", *addr);
	}
	printf("\n");
}
