#include <stdio.h>
/**
 * main - Program that prints all base 16 numbers in lowercase.
 * code by Udeme Harrison
 * Return: 0
*/
int main(void)
{
	int m;
	int n;

	for (m = 48; m <= 57; m++)
	{
		putchar(m);
	}
	for (n = 97; n <= 102; n++)
	{
		putchar(n);
	}
	putchar('\n');
	return (0);
}
