#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>

int _putchar(char c);

void print_item(int character, const char *string, int *counter);

void print_integer(int num, int *counter);

void specify_format(const char *format, va_list fspec, int *count);

int _printf(const char *format, ...);

#endif /* MAIN_H */
