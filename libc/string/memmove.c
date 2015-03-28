#include <string.h>

void* memmove(void* destination_pointer, const void* source_pointer, size_t size){
	unsigned char* dest=(unsigned char*) destination_pointer;
	const unsigned char* src=(const unsigned char*)source_pointer;
	if(dest<src)
		for(size_t i=0;i<size;i++)
			dest[i]=src[i];
	else
		for(size_t i=size;i>0;i--)
			dest[i-1]=src[i-1];
	return destination_pointer;
}
