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
	int x = 0;

	while ((dest[x] = src[x]) != '\0')
	{
		x++;
	}

	return (dest);
}
