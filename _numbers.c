#include "holberton.h"

/**
 * numbers - print integers
 * @n: integer to print.
 * @buffer: is a buffer.
 * @bufflen: length of the buffer.
 * @buffpos: position of the buffer.
 *
 * Return: Returns number of characters.
 */

int numbers(int n, char buffer[], int *bufflen, int *buffpos)
{
	int chr = 0;
	int sign = 0;

	if (n == 0)
	{
		buffer[*buffpos] = '0';
		*buffpos += 1;
		*bufflen += 1;
		if (*bufflen == 2048)
			write_buffer(buffer, bufflen, buffpos);
		return (1);
	}
	else if (n > 0)
		n *= -1;
	else
	{
		buffer[*buffpos] = '-';
		*buffpos += 1;
		*bufflen += 1;
		if (*bufflen == 2048)
			write_buffer(buffer, bufflen, buffpos);
		sign = 1;
	}

	if ((n / 10) != 0)
	{
		chr = numbers(((n / 10) * -1), buffer, bufflen, buffpos);
	}
	buffer[*buffpos] = (n % 10) * -1 + '0';
	*buffpos += 1;
	*bufflen += 1;

	if (*bufflen == 2048)
		write_buffer(buffer, bufflen, buffpos);

	if (sign > 0)
		chr += sign;

	chr++;
	return (chr);
}
