#include "holberton.h"

/**
 * _puts - prints a string to stdout
 * @str: pointer to the string to print
 * Return: number of chars written
 */

int _puts(char *str)
{
	int i;
	char *ans = "(null)";


	if (str != NULL)
	{
		i = 0;
		while (str[i] != '\0')
			buffchar(str[i++]);

		return (i);
	}
	i = 0;
	while (ans[i] != '\0')
		buffchar(ans[i++]);
	return (i);
	return (i);
}

/**
 * buffchar - Juan's create buffer
 * @c: contains a character
 * Return: character to print.
 */

int buffchar(char c)
{

	static char buf[1024];
	static int i;

	if (c == -1 || i >= 1024)
	{
		write(1, &buf, i);
		i = 0;
	} else
	{
		buf[i] = c;
		i++;
	}
	return (1);
}
