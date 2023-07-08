#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 * @argc: The number of command line arguments
 * @argv: An array containing the command line arguments
 *
 * Return: 0 on success, 1 on incorrect number of arguments,
 *         2 on negative number of bytes.
 */

int main(int argc, char *argv[])
{
	int i, bytes;

	/* Check if the correct number of arguments is provided */
	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	/* Convert the number of bytes from command line argument to an integer */
	bytes = atoi(argv[1]);

	/* Check if the number of bytes is negative */
	if (bytes < 0)
	{
		printf("Error\n");
		return (2);
	}

	/* Obtain the starting address of the main function */
	unsigned char *ptr = (unsigned char *)main;

	/* Print the opcodes of the main function */
	for (i = 0; i < bytes; i++)
	printf("%02x ", ptr[i]);

	printf("\n");

	return (0);
}
