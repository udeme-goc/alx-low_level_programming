#include "main.h"

/**
 * _strcpy - Copy a string pointed to by src to dest.
 * @dest: The buffer to copy to.
 * @src: The string to copy from.
 *
 * Return: Pointer to dest.
*/

char *_strcpy(char *dest, char *src)
{
	int l = 0;
	int x = 0;

	while (*(src + l) != '\0')
	{
		l++;
	}

	for (x < l; x++;)
	{
		dest[x] = src[x];
	}

	dest[l] = '\0';
	return (dest);
}
