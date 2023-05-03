#include "variadic_functions.h"

/**
 * print_numbers - Prints numbers, followed by a new line
 *
 * @separator: The string to be printed between numbers
 * @n: The number of integers passed to the function
 * @...: The integers to print
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list args; /* Variable arguments list */
	unsigned int i; /* Loop counter */

	va_start(args, n); /* Start the variable arguments list */

	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(args, int)); /* Print the current integer */

		/* Print separator if not NULL and not at end of the list */
		if (separator != NULL && i != n - 1)
		{
			printf("%s", separator);
		}
	}

	va_end(args); /* End the variable arguments list */

	printf("\n"); /* Print a new line at the end of the function */
}
