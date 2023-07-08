#include "main.h"
#include <stddef.h>

/**
 * _strchr - Locates the first occurrence of a character in a string
 * @s: The input string to search
 * @c: The character to search for
 *
 * Return: A pointer to the first occurrence of the character in the string,
 * or NULL if the character is not found
 */

char *_strchr(char *s, char c)
{
	int i = 0;

	for (; s[i] != '\0'; i++)
	{
		if (s[i] == c)
			return (&s[i]);
	}
	return (NULL);
}
