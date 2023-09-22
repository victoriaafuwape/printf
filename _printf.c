#include "main.h"

/**
 * print_item - Print a character or a string and update the character count.
 * @character: The character to print (-1 if printing a string).
 * @string: The string to print (NULL if printing a character).
 * @counter: A pointer to the character count to update.
 *
 * Return: Nothing or NULL or Void.
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
 * print_integer - prints integer
 * @num: first arg
 * @counter: second arg
 *
 * Return: nothing
 */

void print_integer(int num, int *counter)
{
	int num_digits = (num == 0) ? 1 : 0;
	int temp = num;
	char *num_str, *num_ptr, *num_cpy;

	if (num < 0)
	{
		print_item('-', NULL, counter);
		num = -num;
	}
	while (temp > 0)
	{
		temp /= 10;
		num_digits++;
	}
	num_str = (char *)malloc(num_digits + 1);
	if (num_str == NULL)
	{
		return;
	}
	num_ptr = num_str + num_digits;
	*num_ptr = '\0';
	if (num == 0)
	{
		*num_str = '0';
		num_cpy = strdup(num_str);
		print_item(-1, num_cpy, counter);
		free(num_cpy);
		return;
	}
	else
	{
		do {
			num_ptr--;
			*num_ptr = '0' + (num % 10);
			num /= 10;
		} while (num > 0);
	}
	num_cpy = strdup(num_ptr);
	print_item(-1, num_cpy, counter);
	free(num_cpy);
}

/**
 * specify_format - Parse the format string and print characters accordingly.
 * @format: The format string to parse.
 * @fspec: The list of arguments.
 * @counter: A pointer to the character count to update.
 *
 * Return: Nothing and void.
 */

void specify_format(const char *format, va_list fspec, int *counter)
{
	int i, num;
	char character;
	const char *string;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
			print_item(format[i], NULL, counter);
		else
		{
			i++;
			if (format[i] == 'c')
			{
				character = va_arg(fspec, int);
				print_item(character, NULL, counter);
			}
			else if (format[i] == 's')
			{
				string = va_arg(fspec, char *);
				if (string != NULL)
					print_item(-1, string, counter);
				else
					print_item(-1, NULL, counter);
			}
			else if (format[i] == '%')
				print_item('%', NULL, counter);
			else if (format[i] == 'd' || format[i] == 'i')
			{
				num = va_arg(fspec, int);
				print_integer(num, counter);
			}
			else if (format[i] == '\0')
				continue;
			else
			{
				print_item('%', NULL, counter);
				print_item(format[i], NULL, counter);
			}
		}
	}
}

/**
 * _printf - Print formatted output to the standard output.
 * @format: The format string specifying the output format.
 * @...: eclipse
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
