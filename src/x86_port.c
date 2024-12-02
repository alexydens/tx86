/* Implements x86/port.h */
#include <x86/port.h>

/* Get a byte from a port */
u8 port_inb(u16 port) {
  u8 data;
  __asm__ __volatile__ ("inb %1, %0" : "=a" (data) : "dN" (port));
  return data;
}
/* Get two bytes from a port */
u16 port_inw(u16 port) {
  u16 data;
  __asm__ __volatile__ ("inw %1, %0" : "=a" (data) : "dN" (port));
  return data;
}

/* Send a byte to a port */
void port_outb(u16 port, u8 data) {
  __asm__ __volatile__ ("outb %1, %0" : : "dN" (port), "a" (data));
}
/* Send two bytes to a port */
void port_outw(u16 port, u16 data) {
  __asm__ __volatile__ ("outw %1, %0" : : "dN" (port), "a" (data));
}
