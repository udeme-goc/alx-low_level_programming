#include "main.h"

/**
 * _strncat - Concatenates two strings with a specified maximum number of bytes
 * @dest: The destination string
 * @src: The source string
 * @n: The maximum number of bytes from src to concatenate
 *
 * Return: A pointer to the resulting concatenated string in dest
 */

char *_strncat(char *dest, char *src, int n)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}

	j = 0;
	while (j < n && src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';

	return (dest);
}
