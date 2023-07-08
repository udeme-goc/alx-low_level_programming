#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * calculate_minimum_coins - Calculates the minimum number of coins required
 *                           to make change for the given amount of cents.
 * @cents: The amount of cents to make change for.
 *
 * Return: The minimum number of coins required.
 */

int calculate_minimum_coins(int cents)
{
    int coins = 0;

    if (cents <= 0)
        return (0);

    while (cents >= 25)
    {
        cents -= 25;
        coins++;
    }

    while (cents >= 10)
    {
        cents -= 10;
        coins++;
    }

    while (cents >= 5)
    {
        cents -= 5;
        coins++;
    }

    while (cents >= 2)
    {
        cents -= 2;
        coins++;
    }

    while (cents >= 1)
    {
        cents -= 1;
        coins++;
    }

    return (coins);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 if successful, 1 otherwise.
 */

int main(int argc, char *argv[])
{
    int cents, coins;

    if (argc != 2)
    {
        printf("Error\n");
        return (1);
    }

    cents = atoi(argv[1]);

    if (cents < 0)
    {
        printf("0\n");
        return (0);
    }

    coins = calculate_minimum_coins(cents);

    printf("%d\n", coins);

    return (0);
}
