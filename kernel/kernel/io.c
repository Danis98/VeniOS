#include <stdint.h>

#include <kernel/io.h>

void byte_out(uint16_t port, uint8_t value){
	__asm__ __volatile__ ("outb %1, %0"::"dN"(port), "a"(value));
}

void word_out(uint16_t port, uint16_t value){
	__asm__ __volatile__ ("outw %1, %0"::"dN"(port), "a"(value));
}

uint8_t byte_in(uint16_t port){
	uint8_t ret;
	__asm__ __volatile__ ("inb %1, %0":"=a"(ret):"dN"(port));
	return ret;
}

uint16_t word_in(uint16_t port){
	uint16_t ret;
	__asm__ __volatile__ ("inw %1, %0":"=a"(ret):"dN"(port));
	return ret;
}

