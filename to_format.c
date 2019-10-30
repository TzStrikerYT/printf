#include "holberton.h"

/**
 * to_format - finds the formatters function and print.
 * @format: The format character.
 * @opc: Struct for select format.
 * @buffer: Is a buffer.
 * @bufflenptr: length of the buffer
 * @buffposptr: position within the buffer
 * @print: variadic list.
 *
 * Return: Return the number of characters.
 */

int to_format(const char *format, va_list print, char buffer[],
		  int *bufflenptr, int *buffposptr, print_opc opc[])
{
	int i;
	int chr = 0;
	int _print;

	if (format == NULL)
		return (-1);

	for (i = 0; format[i] != '\0' && format != NULL; i++)
	{
		if (format[i] == '%')
		{
			i++;
			_print = opc_print(format[i], opc,
						 buffer, bufflenptr, buffposptr,
						 print);
			if (_print == 0)
				chr += copy_buffer(format[i], buffer,
							bufflenptr, buffposptr);
			chr += _print;
		}
		else
		{
			chr += copy_buffer(format[i], buffer, bufflenptr,
						buffposptr);
		}
	}
	return (chr);
}
