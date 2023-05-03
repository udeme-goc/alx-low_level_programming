#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints name of file it was compiled from, then a new line.
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	printf("%s\n", __FILE__); /* Print name of the file it was compiled from */
	return (0);
}
