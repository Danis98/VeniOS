#include <arch/i386/isr.h>
#include <io.h>
#include <stdio.h>

const char *err_messages[32]={
	"Division by 0",
	"Debug exception",
	"Non maskable interrupt",
	"Breakpoint exception",
	"'Into detected overflow'",
	"Out of bounds exception",
	"Invalid opcode exception",
	"No coprocessor expression",
	"Double fault",
	"Coprocessor segment overrun",
	"Bad TSS",
	"Segment not present",
	"Stack fault",
	"General protection fault",
	"Page fault",
	"Unknown interrupt exception",
	"Coprocessor fault",
	"Alignment check exception",
	"Machine check exception"
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved"
};

void isr_handler(registers_t regs){
	printf("Received interrupt [%d]: %s\n", regs.int_n, err_messages[regs.int_n]);
	#ifdef __DEBUG
	log("-------INTERRUPT-------\n");
	log("Interrupt num: ");
	log(itoa(regs.int_n));
	log("\nErr message:\n");
	log(err_messages[regs.int_n]);
	log("\n---END OF INTERRUPT---\n");
	#endif
}
