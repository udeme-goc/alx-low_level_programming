#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - addition of argument passed in commandline
 * @argc: argument counter
 * @argv: argument vector
 * code by Udeme Harrison
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int sum = 0;
	int i;
	int x;

	/* case of no argument*/
	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	/* argument passed */
	for (i = 1; i < argc; i++)
	{
		/* check if argument is digit */
		for (j = 0; argv[i][x] != '\0'; x++)
		{
			if (!isdigit(argv[i][x]))
			{
				/* error message for non-digit character */
				printf("Error\n");
				return (1);
			}
		}
		/* convert argument to integer and add it to sum */
		sum += atoi(argv[i]);
	}
	
	/* print the final sum */
	printf("%d\n", sum);

	return (0);
}
