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
	int r = 0;
	unsigned int i = n;

	for (; r < i; r++)
	{
		dest[r] = src[r];
		n--;
	}
	return (dest);
}
