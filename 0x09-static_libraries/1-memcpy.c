#include "main.h"

/**
 * _memcpy - Copies memory area
 * @dest: Destination memory area
 * @src: Source memory area
 * @n: Number of bytes to copy
 *
 * Return: Pointer to the destination memory area
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;
	char *r = dest;

	for (i = 0; i < n; i++)
	{
		r[i] = src[i];
	}
	return (dest);
}
