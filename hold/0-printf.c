#include "main.h"


/**
 * _format_printer - function that print format for c, s and %
 * @spec: Representing specifiers
 * @str: representing int
 * @fspec: va list
 *
 * Return: int
 */

int _format_printer(char spec, int str, va_list fspec)
{
	char character;
	const char *string;

	if (spec == 'c')
	{
		character = va_arg(fspec, int);
		_putchar(character);
		str++;
	}

	else if (spec == 's')
	{
		string = va_arg(fspec, const char *);
		while (*string != '\0')
		{
			_putchar(*string);
			str++;
			string++;
		}
		if (*string == '\0')
			_putchar('\0');
	}
	else if (spec == '%')
	{
		_putchar('%');
		str++;
	}
	return (str);
}

/**int _specifier_arrangement(char spec, char *form, va_list fspec)
{
	int i = 0;

	while (fspec[i] != 0)
	{
		if (sizeof(*fspec[i]) == sizeof(char))
			return (0);
		i++;
	}
	else
		return (-1);
}*/

/**
 * _printf - function that produces output according to a format
 * @format: Format String
 * @...: list of arguement
 *
 * Return: int
 */


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
			_putchar(format[i]);
			counter++;
		}

		if (format[i] == '%')
		{
			i++;
			specifier = format[i];
			result = _specifier_arrangement(char spec, char *form, va_list fspec);
		
				update =  _format_printer(specifier, counter, fspec);
				counter = update;
		}
		i++;
	}
	va_end(fspec);
	return (counter);
}
