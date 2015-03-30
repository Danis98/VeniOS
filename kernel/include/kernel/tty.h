#ifndef _KERNEL_TTY_H
#define _KERNEL_TTY_H

#include <stddef.h>
#include <stdint.h>

void terminal_initialize(enum vga_color,enum vga_color);
void terminal_setcolor(enum vga_color,enum vga_color);
uint8_t terminal_getcolor();
void terminal_putchar(uint16_t c);
void terminal_putentryat(char ch, uint8_t color, size_t x, size_t y);
void terminal_write(const char* data, size_t size);
void terminal_writestring(const char* data);
void terminal_scroll(void);
void terminal_tab(void);
void terminal_newline(void);
void terminal_clearline(size_t row);

//Special functions for fancyness
void terminal_fill_line();

extern size_t terminal_row;
extern size_t terminal_column;
extern uint8_t terminal_color;

#endif
