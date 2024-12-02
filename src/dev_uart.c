/* Implements dev/uart.h */
#include <dev/uart.h>

/* Includes */
#include <x86/port.h>

/* Consts */
#define PORT_COM1             0x3f8     /* The COM1 port */
#define DATA_OFFSET           0         /* The data port's offset */
#define DIVISOR_LOW_OFFSET    0         /* The divisor low port's offset */
#define DIVISOR_HIGH_OFFSET   1         /* The divisor high port's offset */
#define FIFO_CONTROL_OFFSET   2         /* The FIFO control port's offset */
#define LINE_CONTROL_OFFSET   3         /* The line control port's offset */
#define MODEM_CONTROL_OFFSET  4         /* The modem control port's offset */
#define LINE_STATUS_OFFSET    5         /* The line status port's offset */
#define MODEM_STATUS_OFFSET   6         /* The modem status port's offset */
#define SCRATCH_OFFSET        7         /* The scratch port's offset */

/* Setup the COM1 port (the default baud rate is 115200) */
bool uart_init(u16 divisor) {
  /* Set divisor */
  port_outb(PORT_COM1 + LINE_CONTROL_OFFSET, 0x80); /* Enable DLAB */
  port_outb(PORT_COM1 + DIVISOR_LOW_OFFSET, divisor & 0xff);
  port_outb(PORT_COM1 + DIVISOR_HIGH_OFFSET, divisor >> 8);
  /* Configure line, fifo and modem */
  port_outb(PORT_COM1 + LINE_CONTROL_OFFSET, 0x03);
  port_outb(PORT_COM1 + FIFO_CONTROL_OFFSET, 0xC7);
  port_outb(PORT_COM1 + MODEM_CONTROL_OFFSET, 0x0B);
  return true;
}

/* Send a character to the COM1 port */
void uart_putc(u8 c) {
  while (!(port_inb(PORT_COM1 + LINE_STATUS_OFFSET) & 0x20));
  port_outb(PORT_COM1 + DATA_OFFSET, c);
}
/* Send a string to the COM1 port */
void uart_puts(const char *s) {
  while (*s) uart_putc(*s++);
}

/* Get a character from the COM1 port */
u8 uart_getc(void) {
  while (!(port_inb(PORT_COM1 + LINE_STATUS_OFFSET) & 0x01));
  return port_inb(PORT_COM1 + DATA_OFFSET);
}
/* Get a string fromm the COM1 port (returns chars in) */
size_t uart_gets(char *s, size_t max) {
  size_t i = 0;
  while (i < max) {
    u8 c = uart_getc();
    if (c == '\r') continue;
    if (c == '\n') break;
    s[i++] = c;
  }
  s[i] = 0;
  return i;
}
