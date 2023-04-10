#include <stdio.h>
#include <stdlib.h>

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
		x = atoi(argv[i]);

		/* real number check */
		if (x > 0)
		{
			sum += x;
		}
		else
		{
			printf("Error\n");
			return (1);
		}
	}
	printf("%d\n", sum);
	return (0);
}
