#include <stdio.h>
/**
 * main - Program that prints all single digits of base 10 from 0.
 * code by Udeme Harrison
 * Return: 0
*/
int main(void)
{
	int n;

	for (n = 0; n <= 9; n++)
	{
		putchar(n + 48);
	}
	putchar('\n');
	return (0);
}
