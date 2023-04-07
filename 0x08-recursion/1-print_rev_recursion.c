#include "main.h"

/**
 * _print_rev_recursion - recursively print string in reverse.
 * @s: string to be printed.
 * code by Udeme Harrison
 * Return: 0
 */

void _print_rev_recursion(char *s)
{
	if (*s != '\0')
	{
		_print_rev_recursion(s + 1);
		_putchar(*s);
	}
	else
		_putchar('\n');
}
