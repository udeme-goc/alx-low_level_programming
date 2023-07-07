#include "variadic_functions.h"

/**
 * print_all - prints anything
 * @format: a string containing the format for the values to be printed
 *
 * Return: void
 */

void print_all(const char * const format, ...)
{
	va_list vl;
	char *string;
	int i = 0;

	va_start(vl, format);

	while (format != NULL && format[i] != '\0')
	{
		/* select format char */
		switch (format[i])
		{
			case 'c':
				printf("%c", va_arg(vl, int));
				break;
			case 'i':
				printf("%i", va_arg(vl, int));
				break;
			case 'f':
				printf("%f", va_arg(vl, double));
				break;
			case 's':
				/* get the string argument */
				string = va_arg(vl, char *);
				/* handle NULL argument */
				if (string == NULL)
				{
					printf("(nil)");
					break;
				}
				printf("%s", string);
				break;
			default:
				/* ignore any format char other than c, i, f, s */
				i++;
				continue;
		}
		/* print separator if necessary */
		if (format[(i + 1)] != '\0' && (format[i] == 'c' || format[i] == 'i' ||
				format[i] == 'f' || format[i] == 's'))
			printf(", ");
		i++;
	}

	/* print newline character */
	printf("\n");
	va_end(vl);
}
