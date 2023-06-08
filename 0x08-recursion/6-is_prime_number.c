#include "main.h"

/**
 * is_prime_recursive - Helper function to check if number is prime recursively
 * @n: The number to check for primality.
 * @divisor: The current divisor to check.
 *
 * Return: 1 if n is prime, 0 otherwise.
 */

int is_prime_recursive(int n, int divisor)
{
	if (n < 2 || n % divisor == 0)
		return (0);
	else if (divisor > n / 2)
		return (1);
	else
		return (is_prime_recursive(n, divisor + 1));
}

/**
 * is_prime_number - Checks if a number is prime.
 * @n: The number to check.
 *
 * Return: 1 if n is prime, 0 otherwise.
 */

int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	else
		return (is_prime_recursive(n, 2));
}
