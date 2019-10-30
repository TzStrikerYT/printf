#include "holberton.h"

/**
 * print_c - print char
 * @args: variadic list.
 * @buffer: is a buffer.
 * @bufflen: length of the buffer.
 * @buffpos: position of the buffer.
 *
 * Return: Returns number of characters.
 */

int print_c(va_list args, char buffer[], int *bufflen, int *buffpos)
{
	if (*bufflen < 2048)
	{
		buffer[*buffpos] = va_arg(args, int);
		*buffpos += 1;
		*bufflen += 1;

		if (*bufflen == 2048)
			write_buffer(buffer, bufflen, buffpos);
	}
	else
	{
		write_buffer(buffer, bufflen, buffpos);

		buffer[*buffpos] = va_arg(args, int);
		*buffpos += 1;
		*bufflen += 1;
	}

	return (1);
}

/**
 * print_s - print String
 * @args: variadic list.
 * @buffer: is a buffer.
 * @bufflen: length of the buffer.
 * @buffpos: position of the buffer.
 *
 * Return: Returns number of characters.
 */


int print_s(va_list args, char buffer[], int *bufflen, int *buffpos)
{
	char *str;
	int i = 0;
	int chr = 0;

	str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";

	while (str[i] != '\0')
	{
		buffer[*buffpos] = str[i];

		*buffpos += 1;
		*bufflen += 1;

		if (*bufflen == 2048)
			write_buffer(buffer, bufflen, buffpos);
		i++;
		chr++;
	}

	return (chr);
}

/**
 * print_int - print integers
 * @args: variadic list.
 * @buffer: is a buffer.
 * @bufflen: length of the buffer.
 * @buffpos: position of the buffer.
 *
 * Return: Returns number of characters.
 */

int print_int(va_list args, char buffer[], int *bufflen, int *buffpos)
{
	int chr;
	int n;

	n = va_arg(args, int);

	chr = numbers(n, buffer, bufflen, buffpos);

	return (chr);
}
