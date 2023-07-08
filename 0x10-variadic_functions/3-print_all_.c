#include "variadic_functions.h"

/**
 * print_char - Prints a char.
 *
 * @valist: A va_list containing the char to print.
 */

void print_char(va_list valist)
{
	printf("%c", va_arg(valist, int));
}

/**
 * print_integer - Prints an integer.
 *
 * @valist: A va_list containing the integer to print.
 */

void print_integer(va_list valist)
{
	printf("%d", va_arg(valist, int));
}

/**
 * print_float - Prints a float.
 *
 * @valist: A va_list containing the float to print.
 */

void print_float(va_list valist)
{
	printf("%f", va_arg(valist, double));
}

/**
 * print_string - Prints a string.
 *
 * @valist: A va_list containing the string to print.
 */

void print_string(va_list valist)
{
	char *s = va_arg(valist, char *);

	if (s == NULL)
		printf("(nil)");
	else
		printf("%s", s);
}

/**
 * print_all - Prints anything.
 *
 * @format: A list of types of arguments passed to the function.
 */

void print_all(const char * const format, ...)
{
	va_list valist;
	int i = 0, j;
	char *separator = "";

	/* Declare the list of function pointers. */
	void (*print_fn[])(va_list) = {
		print_char,
		print_integer,
		print_float,
		print_string
	};

	/* Declare the list of formats. */
	char formats[] = "cifs";

	/* Start the va_list. */
	va_start(valist, format);

	/* Loop through the format string. */
	while (format != NULL && format[i] != '\0')
	{
		j = 0;

		/* Loop through the list of formats. */
		while (formats[j] != '\0')
		{
			/* Check if current format matches format in the list. */
			if (format[i] == formats[j])
			{
				/* Print the separator, if necessary. */
				printf("%s", separator);

				/* Call the appropriate print function. */
				print_fn[j](valist);

				/* Set the separator for the next iteration. */
				separator = ", ";
				break;
			}
			j++;
		}
		i++;
	}

	/* End the va_list. */
	va_end(valist);

	/* Print a new line. */
	printf("\n");
}
