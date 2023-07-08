#include "variadic_functions.h"

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 * c: char
 * i: integer
 * f: float
 * s: char * (if the string is NULL, print (nil) instead)
 *
 * Return: nothing
 */

void print_all(const char * const format, ...)
{
	va_list ap;
	unsigned int i = 0, j;
	char *str;

	/* array of format specifiers */
	print_t ops[] = {
		{'c', print_char},
		{'i', print_int},
		{'f', print_float},
		{'s', print_string},
		{'\0', NULL}
	};

	va_start(ap, format);

	while (format && format[i])
	{
		/* reset the index of print_t array */
		j = 0;

		while (ops[j].type)
		{
			/* if there is a match */
			if (format[i] == ops[j].type)
			{
				/* call corresponding function and print separator */
				ops[j].f(ap);
				if (format[i + 1])
				{
					printf("%s", separator);
				}
				break;
			}
			j++;
		}
		i++;
	}

	va_end(ap);
	printf("\n");
}

/**
 * print_char - prints a character
 * @ap: argument list
 *
 * Return: nothing
 */

void print_char(va_list ap)
{
	printf("%c", va_arg(ap, int));
}

/**
 * print_int - prints an integer
 * @ap: argument list
 *
 * Return: nothing
 */

void print_int(va_list ap)
{
	printf("%d", va_arg(ap, int));
}

/**
 * print_float - prints a float
 * @ap: argument list
 *
 * Return: nothing
 */

void print_float(va_list ap)
{
	printf("%f", va_arg(ap, double));
}

/**
 * print_string - prints a string
 * @ap: argument list
 *
 * Return: nothing
 */

void print_string(va_list ap)
{
	str = va_arg(ap, char *);
	if (!str)
	{
		str = "(nil)";
	}
	printf("%s", str);
}
