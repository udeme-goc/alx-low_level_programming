#include "main.h"
#include <stddef.h>

/**
 * _strpbrk - Searches a string for a set of bytes
 * @s: The string to search in
 * @accept: The set of bytes to search for
 *
 * Return: Pointer to the first occurrence of a byte from accept in s,
 *         or NULL if no match is found
 */

char *_strpbrk(char *s, char *accept)
{
	int k;

	while (*s)
	{
		for (k = 0; accept[k]; k++)
		{
			if (*s == accept[k])
				return (s);
		}
		s++;
	}
	return (NULL);
}
