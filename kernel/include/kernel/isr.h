#ifndef _KERNEL_IRS_H
#define _KERNEL_IRS_H

#include <stdint.h>

typedef struct registers_struct{
	uint32_t ds;
	uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
	uint32_t int_n, err_code;
	uint32_t eip, cs, eflags, useresp, ss;
}registers_t;

#endif
