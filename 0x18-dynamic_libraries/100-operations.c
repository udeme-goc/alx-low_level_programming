#include <stdio.h>

/**
 * add - Adds two integers.
 * @a: The first integer.
 * @b: The second integer.
 * Return: The sum of a and b.
 */

int add(int a, int b)
{
	return (a + b);
}


/**
 * sub - Subtracts two integers.
 * @a: The first integer.
 * @b: The second integer.
 * Return: The result of a minus b.
 */

int sub(int a, int b)
{
	return (a - b);
}


/**
 * mul - Multiplies two integers.
 * @a: The first integer.
 * @b: The second integer.
 * Return: The product of a and b.
 */

int mul(int a, int b)
{
	return (a * b);
}


/**
 * div - Divides two integers.
 * @a: The first integer.
 * @b: The second integer (non-zero).
 * Return: The result of a divided by b.
 */

int div(int a, int b)
{
	if (b == 0)
	{
		printf("Error: Division by zero\n");
		return (0);
	}
	return (a / b);
}


/**
 * mod - Computes the remainder of division.
 * @a: The first integer.
 * @b: The second integer (non-zero).
 * Return: The remainder of the division of a by b.
 */

int mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error: Modulo by zero\n");
		return (0);
	}
	return (a % b);
}

