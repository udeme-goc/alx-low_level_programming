#include "variadic_functions.h"

/**
 * print_strings - prints strings, followed by a new line
 * @separator: the string to be printed between the strings
 * @n: the number of strings passed to the function
 * @...: variable arguments list
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	char *str;

	/* initialize the variable arguments list */
	va_start(args, n);

	/* loop through the list of arguments */
	for (i = 0; i < n; i++)
	{
		/* get the next argument from the list */
		str = va_arg(args, char *);

		/* check if the argument is NULL */
		if (str == NULL)
		{
			/* if it is, print (nil) */
			printf("(nil)");
		}
		else
		{
			/* if it's not, print the string */
			printf("%s", str);
		}

		/* check if there are more arguments to print */
		if (i < n - 1 && separator != NULL)
		{
			/* if there are, print the separator */
			printf("%s", separator);
		}
	}

	/* end the variable arguments list */
	va_end(args);

	/* print a new line */
	printf("\n");
}
