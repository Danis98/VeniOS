/* Kernel entry point */
ENTRY(_start)

SECTIONS{
	/* Start loading at 1 MiB */
	. = 1M;
	/* The first section must be the multiboot header */
	.text BLOCK(4K) : ALIGN(4K){
		*(.multiboot)
		*(.text)
	}

	/* Read-only data */
	.rodata BLOCK(4K) : ALIGN(4K){
		*(.rodata)
	}

	/* Data */
	.data BLOCK(4K) : ALIGN(4K){
		*(.data)
	}

	/* Uninitialized data and stack */
	.bss BLOCK(4K) : ALIGN(4K){
		*(COMMON)
		*(.bss)
		*(.bootstrap_stack)
	}
}
