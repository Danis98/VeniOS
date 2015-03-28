#include <stdio.h>

#if defined(__is_venios_kernel)
#include <kernel/tty.h>
#endif

int putchar(int integer_char){
	#if defined(__is_venios_kernel)
	char c=(char) integer_char;
	terminal_write(&c, sizeof(c));
	#else
	//Write system call
	#endif
	return integer_char;
}
