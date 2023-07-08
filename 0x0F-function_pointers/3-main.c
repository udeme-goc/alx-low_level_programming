#include "3-calc.h"

/**
 * main - Entry point
 *
 * @argc: The number of arguments passed to the program.
 * @argv: An array of strings containing the arguments passed to the program.
 *
 * Return: 0 on success, 98 on incorrect number of arguments, 99 on invalid
 *         operator, and 100 on division/modulo by 0.
 */

int main(int argc, char *argv[])
{
	int num1, num2, result;
	char *operator;

	/* check if the number of arguments is correct */
	if (argc != 4)
	{
		printf("Error\n");
		return (98);
	}

	/* get the first and second numbers */
	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);

	/* get the operator */
	operator = argv[2];

	/* check for division or modulo by 0 */
	if ((*operator == '/' || *operator == '%') && num2 == 0)
	{
		printf("Error\n");
		return (100);
	}

	/* get the function corresponding to the operator */
	result = (*get_op_func(operator))(num1, num2);

	/* check if operator is valid */
	if (result == -1)
	{
		printf("Error\n");
		return (99);
	}

	/* print the result */
	printf("%d\n", result);

	return (0);
}

