#ifndef _STDIO_H
#define _STDIO_H

#include <sys/cdefs.h>
#include <string.h>

#ifdef __cplusplus
extern "C"{
#endif

int printf(const char* __restrict, ...);
int putchar(int);
int puts(const char*);

char* itoa(int n);

char* itostr(int n, int base);

#ifdef __cplusplus
}
#endif

#endif
