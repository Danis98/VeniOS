#include <string.h>

size_t strlen(const char* string){
	size_t size=0;
	while(string[size])
		size++;
	return size;
}
