#include "main.h"

/**
 * _puts_recursion - output char recursively to standard output with new line.
 * @s: character string.
 * code by Udeme Harrison
 * Return: 0
 */

void _puts_recursion(char *s)
{
	if (*s != '\0')
	{
		_putchar(*s);
		_puts_recursion(s + 1);
	}
	else
		_putchar('\n');
}
