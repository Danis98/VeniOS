#ifndef _KERNEL_VGA_H
#define _KERNEL_VGA_H

#include <stdint.h>

enum vga_color{
	COLOR_BLACK=0,
	COLOR_BLUE=1,
	COLOR_GREEN=2,
	COLOR_CYAN=3,
	COLOR_RED=4,
	COLOR_MAGENTA=5,
	COLOR_BROWN=6,
	COLOR_LIGHT_GREY=7,
	COLOR_DARK_GREY=8,
	COLOR_LIGHT_BLUE=9,
	COLOR_LIGHT_GREEN=10,
	COLOR_LIGHT_CYAN=11,
	COLOR_LIGHT_RED=12,
	COLOR_LIGHT_MAGENTA=13,
	COLOR_LIGHT_BROWN=14,
	COLOR_WHITE=15,
};

static inline uint8_t make_color(enum vga_color foreground, enum vga_color background){
	return foreground|background<<4;
}

static inline uint16_t make_vgaentry(char c, uint8_t color){
	return (uint16_t)c|(uint16_t)color<<8;
}

static const size_t VGA_WIDTH=80;
static const size_t VGA_HEIGHT=25;

static const uint16_t* TERMINAL_MEMORY=(uint16_t*)0xB8000;

#endif
