#include <string.h>

int memcmp(const void* a_pointer, const void* b_pointer, size_t size){
	const unsigned char* a=(const unsigned char*) a_pointer;
	const unsigned char* b=(const unsigned char*) b_pointer;
	for(size_t i=0;i<size;i++){
		if(a[i]>b[i]) return 1;
		else if(a[i]<b[i]) return -1;
	}
	return 0;
}
