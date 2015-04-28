#include <util/dmp_util.h>

#include <math.h>

void mem_dmp(uint32_t start, uint32_t limit, uint8_t mode){
	printf("Dumping!");
	uint8_t gran=GRANULARITY(mode);
	uint32_t i;
	for(i=0;i<limit;i++){
		uint32_t* addr=(uint32_t*)(start+i*gran);
		if(i%4==0)
			printf("\n[0x%x]\t", addr);
		printf("0x%x", *addr);
		//Omit tabs at last element in line
		if(i%4!=3){
			//If num is too short
			if(abs(*addr)<0x10000)
				printf("\t\t");
			else 
				printf("\t");
		}
	}
	printf("\n");
}
