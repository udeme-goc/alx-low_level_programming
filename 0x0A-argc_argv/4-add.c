#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 if successful, 1 otherwise.
 */

int main(int argc, char *argv[])
{
    int i, j, sum = 0;

    /* Check if no arguments were provided */
    if (argc == 1)
    {
        printf("0\n");
        return (0);
    }

    /* Iterate through each argument starting from index 1 */
    for (i = 1; i < argc; i++)
    {
        /* Check if each character of the argument is a digit */
        for (j = 0; argv[i][j] != '\0'; j++)
        {
            if (!isdigit(argv[i][j]))
            {
                /* Print error message if non-digit character found */
                printf("Error\n");
                return (1);
            }
        }
        /* Convert the argument to an integer and add it to the sum */
        sum += atoi(argv[i]);
    }

    /* Print the final sum */
    printf("%d\n", sum);

    return (0);
}
