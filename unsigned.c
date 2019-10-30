#include "holberton.h"

/**
 * print_u - prints unsigned ints
 *
 * @valist: the list of parameters
 *
 * Return: unsigned int
 */

int print_u(va_list valist)
{
	unsigned int unsign, p;
	char *str = NULL;

	unsign = va_arg(valist, unsigned int);
	str = convert(unsign, 10);

	p = _puts(str);

	return (p);
}

/**
 * _print_binary - converters a unsigned int to binary number
 *
 * @valist: the list of parameters
 *
 * Return: the number binary
 */

int _print_binary(va_list valist)
{
	unsigned int num, p;
	char *str;

	num = va_arg(valist, unsigned int);
	str = convert(num, 2);

	p = _puts(str);

	return (p);
}

/**
 * convert - converter to any base.
 *
 * @num: number
 * @base: base to convert
 * Return: base of numbers
 */

char *convert(unsigned long int num, int base)
{
	static char *rep;
	static char buffer[50];
	char *ptr;

	rep = "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = rep[num % base];
		num /= base;
	} while (num);

	return (ptr);
}
