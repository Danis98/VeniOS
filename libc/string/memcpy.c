#include <string.h>

void* memcpy(void* destination_pointer, const void* source_pointer, size_t size){
	unsigned char* dest=(unsigned char*) destination_pointer;
	const unsigned char* src=(const unsigned char*) source_pointer;
	for(size_t i=0;i<size;i++)
		dest[i]=src[i];
	return destination_pointer;
}
