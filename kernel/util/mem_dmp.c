#include <dmp_util.h>

#include <math.h>

void mem_dmp(uint32_t start, uint32_t final){
	printf("Dumping!");
	uint32_t i;
	for(i=0;i<(final-start)/GRAN;i++){
		uint32_t* addr=(uint32_t*)(i*GRAN+start);
		if((i-start)%4==0)
			printf("\n[0x%x]\t", addr);
		printf("0x%x", *addr);
		//Omit tabs at last element in line
		if((i-start)%4!=3){
			//If num is too short
			if(abs(*addr)<0x10000)
				printf("\t\t", *addr);
			else 
				printf("\t", *addr);
		}
	}
	printf("\n");
}
