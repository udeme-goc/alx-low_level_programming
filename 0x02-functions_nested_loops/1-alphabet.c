#include "main.h"
/**
 * print_alphabet - print lowercase alphabets using _putchar
 * code by Udeme Harrison
*/

void print_alphabet(void)
{
	char n;

	for (n = 'a'; n <= 'z'; n++)
	{
		_putchar(n);
	}
	_putchar('\n');
}
