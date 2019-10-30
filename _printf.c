#include "holberton.h"

int copy_buffer(char formatter, char buffer[],
		   int *bufflenptr, int *buffposptr)
{
	int chr;

	chr = 0;
	buffer[*buffposptr] = formatter;
	*buffposptr += 1;
	*bufflenptr += 1;
	if (*bufflenptr == 2048)
	{
		write_buffer(buffer, bufflenptr, buffposptr);
	}
	chr++;
	return (chr);
}

/**
 *_printf - function thats prints anything.
 * @format: String that contains parametters to print
 * Return: Size of the String printed.
 *
 */

int _printf(const char *format, ...)
{
	va_list print;
	char buffer[2048];
	int chr, bufflen, buffpos, *bufflenptr, *buffposptr;
	print_opc opc[] = {{"c", print_c},
			   {"s", print_s},
			   {"i", print_int},
			   {"d", print_int},
			   {"b", _print_binary},
			   {"u", print_u},
	};

	create_buffer(buffer);
	chr = buffpos = 0;
	bufflen = 1;
	bufflenptr = &bufflen;
	buffposptr = &buffpos;
	va_start(print, format);

	if (format == NULL || print == NULL)
		return (-1);

	chr = to_format(format, print, buffer,
			      bufflenptr, buffposptr, opc);

	write_buffer(buffer, bufflenptr, buffposptr);
	va_end(print);
	return (chr);
}


/**
 * write_buffer - Print out the buffer of all characters to print
 * @buffer: is a buffer
 * @bufflen: length of buffer
 * @buffpos: postion inside buffer
 */

void write_buffer(char buffer[], int *bufflen, int *buffpos)
{
	write(1, buffer, *bufflen - 1);
	*buffpos = 0;
	*bufflen = 1;
}
