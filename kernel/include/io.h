#ifndef _KERNEL_IO_H
#define _KERNEL_IO_H

#include <stdint.h>

#define COM1 0x3f8

uint8_t byte_in(uint16_t);
uint16_t word_in(uint16_t);
void byte_out(uint16_t, uint8_t);
void word_out(uint16_t, uint16_t);

#endif
