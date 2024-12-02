/* Include guard */
#if !defined(__CORE_PRINTF_H__)
#define __CORE_PRINTF_H__

/* Includes */
#include <core/base.h>

/* Print formatted output using specified printf */
extern void _printf(void (*putc)(char), const char *format, ...);

#endif /* __CORE_PRINTF_H__ */
