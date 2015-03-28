#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

__attribute__((__noreturn__))
void abort(void){
	printf("Help! Something went wrong! PANIC!\n");
	while(1){}
	__builtin_unreachable();
}
