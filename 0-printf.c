#include "main.h"

/**
 * print_item - Print a character or a string and update the character count.
 * @character: The character to print (-1 if printing a string).
 * @string: The string to print (NULL if printing a character).
 * @counter: A pointer to the character count to update.
 *
 * Return: Nothing.
 */

void print_item(int character, const char *string, int *counter)
{
	const char null_string[] = "(null)";
	const char *temp = null_string;

	if (character != -1)
	{
		_putchar(character);
		(*counter)++;
	}
	else if (string != NULL)
	{
		while (*string != '\0')
		{
			_putchar(*string);
			(*counter)++;
			string++;
		}
	}
	else
	{
		while (*temp != '\0')
		{
			_putchar(*temp);
			(*counter)++;
			temp++;
		}
	}
}

/**
 * specify_format - Parse the format string and print characters accordingly.
 * @format: The format string to parse.
 * @fspec: The list of arguments.
 * @counter: A pointer to the character count to update.
 *
 * Return: Nothing.
 */

void specify_format(const char *format, va_list fspec, int *counter)
{
	char specifier, character;
	const char *string;

	while (*format != '\0')
	{
		if (*format != '%')
			print_item(*format, NULL, counter);
		else
		{
			format++;
			specifier = *format;
			if (specifier == 'c')
			{
				character = va_arg(fspec, int);
				print_item(character, NULL, counter);
			}
			else if (specifier == 's')
			{
				string = va_arg(fspec, char *);
				if (string != NULL)
					print_item(-1, string, counter);
				else
					print_item(-1, NULL, counter);
			}
			else if (specifier == '%')
				print_item('%', NULL, counter);
			else
			{
				print_item('%', NULL, counter);
				print_item(specifier, NULL, counter);
			}
			if (specifier == '\0')
				break
		}
		format++;
	}
}

/**
 * _printf - Print formatted output to the standard output.
 * @format: The format string specifying the output format.
 *
 * Return: The number of characters printed.
 */

int _printf(const char *format, ...)
{
	int counter = 0;
	va_list fspec;

	va_start(fspec, format);

	if (format == NULL)
	{
		return (-1);
	}
	specify_format(format, fspec, &counter);
	va_end(fspec);

	return (counter);
}
