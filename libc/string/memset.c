#include <string.h>

void* memset(void* destination_pointer, int value, size_t size){
	unsigned char* buffer=(unsigned char*) destination_pointer;
	for(size_t i=0;i<size;i++)
		buffer[i]=value;
	return destination_pointer;
}
