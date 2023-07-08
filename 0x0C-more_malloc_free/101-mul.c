#include "main.h"

/**
 * multiply - Multiplies two positive numbers
 * @num1: First number
 * @num2: Second number
 *
 * Return: The product of num1 and num2
 */

int multiply(int num1, int num2)
{
	return (num1 * num2);
}


/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: 0 on success, 1 on error
 */

int main(int argc, char *argv[])
{
	int num1, num2, result;

	/* Check if the correct number of arguments is provided */
	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	/* Convert the command-line arguments to integers */
	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);

	/* Check if the arguments are valid positive numbers */
	if (num1 <= 0 || num2 <= 0)
	{
		printf("Error\n");
		return (1);
	}

	/* Perform the multiplication */
	result = multiply(num1, num2);

	/* Print the result */
	printf("%d\n", result);

	return (0);
}
