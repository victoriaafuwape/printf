#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int _format_printer(char spec, int str, va_list fspec);
int _putchar(char c);

#endif /* MAIN_H */
