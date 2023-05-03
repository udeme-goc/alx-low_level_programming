#include "dog.h"

/**
 * print_dog - prints a dog struct
 * @d: pointer to dog struct to print
 *
 * Return: void
 */

void print_dog(struct dog *d)
{
	if (d == NULL)
		return;

	printf("Name: %s\n", (d->name == NULL) ? "(nil)" : d->name);
	printf("Age: %.6f\n", d->age);
	printf("Owner: %s\n", (d->owner == NULL) ? "(nil)" : d->owner);
}
