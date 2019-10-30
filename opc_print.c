#include "holberton.h"

/**
 * opc_print - select format to print
 * it's a conversion specifier
 * @formatter: The format character.
 * @opc: selector into the structure.
 * @buffer: is a buffer.
 * @bufflenptr: length of the buffer.
 * @buffposptr: the position within the buffer.
 * @print: variadic list.
 * Return: the format for can print.
 */

int opc_print(char formatter, print_opc opc[], char buffer[],
	      int *bufflenptr, int *buffposptr, va_list print)
{
	int i;
	int chr = 0;

	for (i = 0; i < 6; i++)
	{
		if (formatter == *opc[i].c)
		{
			chr += opc[i].f(print, buffer, bufflenptr,
						  buffposptr);
			return (chr);
		}
	}
	return (0);
}
