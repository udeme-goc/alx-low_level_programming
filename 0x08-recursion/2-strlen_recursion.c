#include "main.h"

/**
 * _strlen_recursion - recursive function that returns length of string.
 * @s: string for which length is to be found.
 * code by Udeme Harrison
 * Return: 0
 */

int _strlen_recursion(char *s)
{
	if (*s == '\0')
	{
		return (0);
	}
	s++;
	return (_strlen_recursion(s) + 1);
}
