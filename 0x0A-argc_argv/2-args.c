#include <stdio.h>

/**
 * main - program that prints all arguments passed it on separate lines.
 * @argc: argument counter
 * @argv: argument vector
 * code by Udeme Harrison
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}
	return (0);
}
