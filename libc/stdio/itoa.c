#include <stdio.h>

char* itoa(int n, char c[]){
	return itostr(n, c, 10);
}

char* itostr(int n, char c[], int base){
	const char* digits="0123456789abcdef";
	char* ptr=c;
	int shift=n;
	do{
		++ptr;
		shift/=base;
	}
	while(shift);
	*ptr='\0';
	do{
		*--ptr=digits[n%base];
		n/=base;
	}
	while(n);
	return c;
}
