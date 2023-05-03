#include "main.h"

/**
 * _sqrt_recursion - function to find square root recursively
 * @n: number whose square root is to be found.
 * code by Udeme Harrison
 * Return: 0
 */

int _sqrt_recursion(int n)
{
	/* Base cases */
	if (n == 0 || n == 1)
	{
		return (n);
	}

	/* Recursive case */
	int i;

	for (i = 1; i <= n / 2; i++)
	{
		int square = i * i;

		if (square == n)
		{
			return (i);
		}
		else if (square > n)
		{
			break;
		}
	}

	/* No exact square root, try next lower number */
	int lower_sqrt = _sqrt_recursion(n - 1);

	if (lower_sqrt < 0)
	{
		return (-1);
	}
	else if (lower_sqrt * lower_sqrt == n)
	{
		return (lower_sqrt);
	}
	else
	{
		return (-1);
	}
}
