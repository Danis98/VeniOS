#include <stdio.h>

char* itoa(int n){
	return itostr(n, 10);
}

char* itostr(int n, int base){
	const char* digits="0123456789abcdef";
	int l;
	int shift=n;
	do{
		++l;
		shift/=base;
	}
	while(shift);
	char *ptr[l];
	ptr[l-1]='\0';
	l-=2;
	do{
		ptr[l--]=digits[n%base];
		n/=base;
	}
	while(n);
	return ptr;
}
