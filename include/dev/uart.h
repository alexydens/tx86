/* Include guard */
#if !defined(__DEV_UART_H__)
#define __DEV_UART_H__

/* Includes */
#include <core/base.h>

/* Setup the COM1 port (the default baud rate is 115200) */
extern bool uart_init(u16 divisor);

/* Send a character to the COM1 port */
extern void uart_putc(u8 c);
/* Send a string to the COM1 port */
extern void uart_puts(const char *s);

/* Get a character from the COM1 port */
extern u8 uart_getc(void);
/* Get a string fromm the COM1 port (returns chars in) */
extern size_t uart_gets(char *s, size_t max);

#endif /* __DEV_UART_H__ */
