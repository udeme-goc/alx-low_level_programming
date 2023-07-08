#include "dog.h"

/**
 * free_dog - frees the memory allocated for a dog struct
 * @d: pointer to the dog struct to free
 *
 * Return: void
 */

void free_dog(dog_t *d)
{
	/* Check if d is not NULL */
	if (d != NULL)
	{
		/* Free memory allocated for name */
		free(d->name);
		/* Free memory allocated for owner */
		free(d->owner);
		/* Free memory allocated for the dog struct */
		free(d);
	}
}
