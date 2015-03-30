#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <kernel/vga.h>

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer;

void terminal_initialize(enum vga_color fore, enum vga_color back){
	terminal_row=0;
	terminal_column=0;
	terminal_color=terminal_setcolor(fore,back);
	terminal_buffer=TERMINAL_MEMORY;

	//Clear terminal
	for(size_t index=0;index<VGA_HEIGHT*VGA_WIDTH;index++){
		terminal_buffer[index]=make_vgaentry(' ',terminal_color);
	}
}

void terminal_setcolor(enum vga_color fore, enum vga_color back){
	uint8_t color=make_color(fore,back);
	terminal_color=color;
}

void terminal_putentryat(char c, uint8_t color, size_t x, size_t y){
	
	const size_t index=y*VGA_WIDTH+x;
	terminal_buffer[index]=make_vgaentry(c,color);
}

void terminal_putchar(char c){
	if(c=='\n'){
		terminal_newline();
	}
	else if(c=='\t'){
		terminal_tab();
	}
	else{
		terminal_putentryat(c, terminal_color,
				terminal_column, terminal_row);
		if(++terminal_column==VGA_WIDTH){
			terminal_newline();
		}
	}
}

void terminal_tab(){
	if(terminal_column%8==0)
		if(++terminal_column==VGA_WIDTH)
			terminal_newline();
	while(terminal_column%8!=0)
		terminal_column++;
	if(terminal_column==VGA_WIDTH)
		terminal_newline();
}

void terminal_newline(){
	terminal_column=0;
	if(++terminal_row==VGA_HEIGHT)
		terminal_scroll();
}

void terminal_scroll(){
	for(size_t i=1;i<VGA_HEIGHT;i++){
		size_t dest=((int)i-1)*VGA_WIDTH+TERMINAL_MEMORY;
		size_t src=(int)i*VGA_WIDTH+TERMINAL_MEMORY;
		terminal_clearline(i-1);
		memmove((void*) dest, (const void*) src, VGA_WIDTH*2);
	}
	terminal_clearline(VGA_HEIGHT-1);
	terminal_row--;
}

void terminal_clearline(size_t row){
	size_t row_addr=row*VGA_WIDTH;
	for(size_t index=0;index<VGA_WIDTH;index++){
		terminal_buffer[row_addr+index]=make_vgaentry(' ',
							terminal_color);
	}
}

void terminal_write(const char* data, size_t size){
	for(size_t i=0;i<size;i++){
		terminal_putchar(data[i]);
	}
}

void terminal_writestring(const char* data){
	size_t str_length=strlen(data);
	terminal_write(data,str_length);
}

void terminal_fill_line(){
	do{
		terminal_putchar(' ');
	}
	while(terminal_column!=0);
}

uint8_t terminal_getcolor(){
	return terminal_color;
}
