#include <stdarg.h>
#include <stdio.h>
#include "main.h"

int _format_printer(char spec, int str, va_list fspec)
{
        char character;
        const char *string;

        if (spec == 'c')
        {
                character = va_arg(fspec, int);
                putchar(character);
                str++;
        }
	else if (spec == 's')
        {
                string = va_arg(fspec, const char *);
                while (*string != '\0')
                {
                        putchar(*string);
                        str++;
                        string++;
                }
        }
	else if (spec == '%')
        {
                putchar('%');
                str++;
        }

        return (str);
}

int _printf(const char *format, ...)
{
        int i = 0, counter = 0;
        int update;
        char specifier;
        va_list fspec;

        va_start(fspec, format);

        while (format[i] != '\0')
        {
                if (format[i] != '%')
                {
                        putchar(format[i]);
                        counter++;
                }

                if (format[i] == '%')
                {
                        i++;
                        specifier = format[i];
                        update =  _format_printer(specifier, counter, fspec);
                        counter = update;
                }
                i++;
        }
        printf("Total characters printed: %d.\n", counter);
        va_end(fspec);
        return (counter);
}
