#include <math.h>

#include <stdbool.h>

int pow(int base, int exponent){
	bool isInverse=exponent<0;
	if(isInverse) exponent=abs(exponent);
	if(exponent==0) return 1;
	int n=base;
	for(int i=1;i<exponent;i++)
		n*=base;
	if(isInverse) n=1/n;
	return n;
}
