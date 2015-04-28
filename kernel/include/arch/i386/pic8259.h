#ifndef _PIC8259_H
#define _PIC8259_H

/**
 * Programmable interrupt chip, essential for interrupt handling
**/

//Ports for communication
#define PIC_MASTER_PORT	0x20
#define PIC_SLAVE_PORT	0xA0
#define PIC_MASTER_CMD	PIC_MASTER_PORT
#define PIC_MASTER_DATA	PIC_MASTER_PORT+1
#define PIC_SLAVE_CMD	PIC_SLAVE_PORT
#define PIC_SLAVE_DATA	PIC_SLAVE_PORT+1

#define PIC_EOI		0x20

#endif
