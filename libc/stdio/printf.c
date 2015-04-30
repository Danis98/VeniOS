#include <stdbool.h>
#include <stdarg.h>

#include <stdio.h>
#include <string.h>
#include <math.h>

#if defined(__is_venios_kernel)
#include <arch/i386/tty.h>
#endif

void printNum(int n, int base);

void print(const char* data, size_t size){
	for(size_t i=0;i<size;i++)
		putchar((int)((const unsigned char*)data)[i]);
}

void printNum(int n, int base){
	if(n<0){
		printf("-");
		n=-n;
	}
	const char* str=(const char*)itostr(n, str, base);
	print(str, strlen(str));
}

int printf(const char* restrict format, ...){
	va_list params;
	va_start(params, format);

	int written=0;
	size_t amount;
	bool rejected_bad_specifier=false;

	while(*format!='\0'){
		if(*format!='%'){
			print_c:
			amount=1;
			while(format[amount]&&format[amount]!='%')
				amount++;
			print(format,amount);
			format+=amount;
			written+=amount;
			continue;
		}
		const char* format_begin=format;
		if(*(++format)=='%')
			goto print_c;
		if(rejected_bad_specifier){
			incomprehensible_conversion:
				rejected_bad_specifier=true;
				format=format_begin;
				goto print_c;
		}

		if(*format=='c'){
			format++;
			char c=(char) va_arg(params,int);
			print(&c,sizeof(c));
		}
		else if(*format=='s'){
			format++;
			const char* s=va_arg(params,const char*);
			print(s,strlen(s));
		}
		else if(*format=='d'){
			format++;
			int n=va_arg(params, int);
			printNum(n, 10);
		}
		else if(*format=='x'){
			format++;
			int n=va_arg(params, int);
			printNum(n, 16);
		}
		else{
			goto incomprehensible_conversion;
		}
	}
	va_end(params);
	return written;
}
