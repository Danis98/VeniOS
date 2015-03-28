#Multiboot header constants
.set ALIGN,	1<<0		#Page align
.set MEMINFO,	1<<1		#Provide memory map
.set FLAGS,	ALIGN|MEMINFO	#Flag field
.set MAGIC,	0x1BADB002	#Multiboot magic number
.set CHECKSUM,	-(MAGIC+FLAGS)	#Checksum

#Multiboot header, to load first
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

#Temporary stack, 16 KiB
.section .bootstrap_stack, "aw", @nobits
stack_bottom:
.skip 16384	#Exactly 16 KiB
stack_top:

#Kernel entry point
.section .text
.global _start
.type _start, @function
_start:
	#Setup temporary stack
	movl $stack_top,%esp

	#Call core kernel initialization
	call kernel_early

	#Call globl constructors
	call _init

	#Call kernel
	call kernel_main
	#In case the kernel returns, disable interrupts, stop the cpu and loop
	cli
	hlt
.loop:
	jmp .loop
.size _start, . - _start
