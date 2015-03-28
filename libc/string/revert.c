#include <string.h>

const char* revert(const char* str){
	char* rev;
	size_t size=strlen(str);
	int i;
	str+=size;
	for(i=0;i<size;i++){
		char ch=*(str--);
		print((const char*)&ch, 1);
		rev[i]=ch;
	}
	rev[size]='\0';
	return (const char*)rev;
}

