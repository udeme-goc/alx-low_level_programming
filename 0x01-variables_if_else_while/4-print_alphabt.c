#include <stdio.h>
/**
 * main - Program that prints the alphabet in lower case, excluding e and q.
 * code by Udeme Harrison
 * Return: 0
*/

int main(void)
{
	int n = 97;

	while (n <= 122)
	{
		while (n == 101 || n == 113)
		{
			n++;
			continue;
		}
		putchar(n);
		n++;
	}
	putchar('\n');
	return (0);
}
