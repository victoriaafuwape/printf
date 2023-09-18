#include <stdarg.h>
#include "main.h"

/**
 * _printf - function produces output according to a format
 * @format: string to be produced
 *
 * Return: total count of characters printed
 */

int _printf(const char *format, ...)
{
	int i, counter = 0;
	char specifier, character;
	const char *string;
	va_list fspec;

	va_start(fspec, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			counter++;
		} else
		{
			i++;
			specifier = format[i];
			if (specifier == 'c')
			{
				character = va_arg(fspec, int);
				_putchar(character);
				counter++;
			} else if (specifier == 's')
			{
				string = va_arg(fspec, const char *);
				for (; *string != '\0'; string++)
				{
					_putchar(*string);
					counter++;
				}
			} else if (specifier == '%')
			{
				_putchar('%');
				counter++;
			}
		}
	}
	va_end(fspec);
	return (counter);
}
