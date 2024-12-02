/* Include guard */
#if !defined(__X86_PORT_H__)
#define __X86_PORT_H__

/* Includes */
#include <core/base.h>

/* Get a byte from a port */
extern u8 port_inb(u16 port);
/* Get two bytes from a port */
extern u16 port_inw(u16 port);

/* Send a byte to a port */
extern void port_outb(u16 port, u8 data);
/* Send two bytes to a port */
extern void port_outw(u16 port, u16 data);

#endif /* __X86_PORT_H__ */
