#include "main.h"

/**
 * helper - Recursive helper function to calculate square root.
 * @n: The number to calculate the square root of.
 * @guess: The current guess for the square root.
 *
 * Return: The natural square root of the number, or -1 if it doesn't exist.
 */

int helper(int n, int guess);


/**
 * _sqrt_recursion - Calculates the natural square root of a number.
 * @n: The number to calculate the square root of.
 *
 * Return: The natural square root of the number, or -1 if it doesn't exist.
 */

int _sqrt_recursion(int n)
{
	/* Check if n is negative */
	if (n < 0)
		return (-1);

	/* Call the helper function to calculate square root */
	return (helper(n, 1));
}


/**
 * helper - Recursive helper function to calculate square root.
 * @n: The number to calculate the square root of.
 * @guess: The current guess for the square root.
 *
 * Return: The natural square root of the number, or -1 if it doesn't exist.
 */

int helper(int n, int guess)
{
	/* Base case: square of guess equals n */
	if (guess * guess == n)
		return (guess);

	/* Base case: square of guess exceeds n */
	else if (guess * guess > n)
		return (-1);

	/* Recursive case: increment guess and call helper function again */
	else
		return (helper(n, guess + 1));
}


/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int result = _sqrt_recursion(25);

	/* Print the calculated square root */
	printf("Square root: %d\n", result);

	return (0);
}
