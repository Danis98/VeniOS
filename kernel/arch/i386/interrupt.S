.intel_syntax noprefix

.extern isr_handler
isr_common:
	pusha

	push ds
	push es
	push fs
	push gs

	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax

	mov eax, esp
	push eax

	call isr_handler

	pop eax
	pop gs
	pop fs
	pop es
	pop ds
	popa
	
	add esp, 8
	sti
	iret

.macro isr_noerr num
.global isr\num
isr\num:
	cli
	push 0
	push \num
	jmp isr_common
.endm

.macro isr_err num
.global isr\num
isr\num:
	cli
	push \num
	jmp isr_common
.endm

isr_noerr 0
isr_noerr 1
isr_noerr 2
isr_noerr 3
isr_noerr 4
isr_noerr 5
isr_noerr 6
isr_noerr 7
isr_err 8
isr_noerr 9
isr_err 10
isr_err 11
isr_err 12
isr_err 13
isr_err 14
isr_noerr 15
isr_noerr 16
isr_noerr 17
isr_noerr 18
isr_noerr 19
isr_noerr 20
isr_noerr 21
isr_noerr 22
isr_noerr 23
isr_noerr 24
isr_noerr 25
isr_noerr 26
isr_noerr 27
isr_noerr 28
isr_noerr 29
isr_noerr 30
isr_noerr 31

.att_syntax noprefix
