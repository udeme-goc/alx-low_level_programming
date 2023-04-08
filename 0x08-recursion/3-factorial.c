#include "main.h"

/**
 * factorial - function to find factorial of given input.
 * @n: given input.
 * code by Udeme Harrison
 * Return: 0
 */

int factorial(int n)
{
	if (n == 0)
	{
		return (1);
	}
	else if (n < 0)
	{
		return (-1);
	}
	else
	{
		return (n * factorial(n - 1));
	}
}
