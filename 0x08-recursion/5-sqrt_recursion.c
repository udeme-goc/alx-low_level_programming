#include "main.h"

/**
 * calculate_sqrt - Helper function to calculate the square root recursively.
 * @n: The number to find the square root of.
 * @guess: The current guess for the square root.
 *
 * Return: Square root of n, or -1 if it does not have a natural square root.
 */

int calculate_sqrt(int n, int guess)
{
	if (guess * guess == n)
		return (guess);
	else if (guess * guess > n)
		return (-1);
	else
		return (calculate_sqrt(n, guess + 1));
}

/**
 * _sqrt_recursion - Returns the natural square root of a number.
 * @n: The number to find the square root of.
 *
 * Return: Square root of n, or -1 if it does not have a natural square root.
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	else if (n == 0 || n == 1)
		return (n);
	else
		return (calculate_sqrt(n, 1));
}