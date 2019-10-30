#include "holberton.h"

/**
 * create_buffer - Fill buffer with null characters.
 * @buffer: The buffer.
 * Return: Void variable.
 */

void create_buffer(char buffer[])
{
	int i;

	i = 0;
	while (i < 2048)
	{
		buffer[i] = 0;
		i++;
	}
	buffer[i] = '\0';
}
