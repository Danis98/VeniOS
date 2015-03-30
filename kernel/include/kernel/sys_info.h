#ifndef _KERNEL_INFO_H
#define _KERNEL_INFO_H

#include <kernel/vga.h>
#include <kernel/tty.h>

#define NAME_LINE1 "__      __        _  ____   _____ "
#define NAME_LINE2 "\\ \\    / /       (_)/ __ \\ / ____|"
#define NAME_LINE3 " \\ \\  / /__ _ __  _| |  | | (___  "
#define NAME_LINE4 "  \\ \\/ / _ \\ '_ \\| | |  | |\\___ \\"
#define NAME_LINE5 "   \\  /  __/ | | | | |__| |____) |"
#define NAME_LINE6 "    \\/ \\___|_| |_|_|\\____/|_____/"
                                   
#define RELEASE "alpha"
#define VERSION "0.1"

#define AUTHORS "Venio"
#define COPYRIGHT "Copyright (c) 2014-2015 Weird Lion Studios"

void print_header(){
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
}

#endif
