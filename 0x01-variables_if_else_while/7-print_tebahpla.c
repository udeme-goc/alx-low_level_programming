#include <stdio.h>
/**
 * main - Program that prints lowercase alphabet in reverse order
 * code by Udeme Harrison
 * Return: 0
*/
int main(void)
{
	int n = 122;

	while (n >= 97)
	{
		putchar(n);
		n--;
	}
	putchar('\n');
	return (0);
}
