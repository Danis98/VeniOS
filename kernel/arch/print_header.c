#include <sys_info.h>
#include <stdio.h>

void print_header(){
	uint8_t prev_color=terminal_getcolor();
	terminal_setcolor(COLOR_BLACK, COLOR_WHITE);
	printf(NAME_LINE1); terminal_fill_line();
	printf(NAME_LINE2); terminal_fill_line();
	printf(NAME_LINE3); terminal_fill_line();
	printf(NAME_LINE4); terminal_fill_line();
	printf(NAME_LINE5); terminal_fill_line();
	printf(NAME_LINE6); terminal_fill_line();
	terminal_fill_line();
	printf("Version: "RELEASE" "VERSION); terminal_fill_line();
	printf("Author: "AUTHORS); terminal_fill_line();
	terminal_fill_line();
	printf(COPYRIGHT); terminal_fill_line();
	printf("arch: %s", arch); terminal_fill_line();
	terminal_setcolor((enum vga_color)(prev_color&0xf),
			(enum vga_color)(prev_color>>4&0xf));
}
