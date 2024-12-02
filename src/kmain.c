/* Includes */
#include <core/base.h>
#include <x86/port.h>

/* Kernel entry point */
void kmain(void) {
  port_outb(0x3f8, 'A');

  while (1) __asm__ __volatile__ ("cli; hlt");
}
