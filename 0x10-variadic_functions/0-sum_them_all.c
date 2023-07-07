#include "variadic_functions.h"

/**
 * sum_them_all - returns the sum of all its parameters
 * @n: number of parameters to sum
 * @...: variable number of arguments to sum
 *
 * Return: sum of all parameters
 */

int sum_them_all(const unsigned int n, ...)
{
	/* Declare variables */
	va_list args;
	int sum = 0;
	unsigned int i;

	/* Initialize args to store all arguments after n */
	va_start(args, n);

	/* Loop through each argument and add to sum */
	for (i = 0; i < n; i++)
	{
		sum += va_arg(args, int);
	}

	/* Clean up arguments */
	va_end(args);

	/* Return sum */
	return (sum);
}
