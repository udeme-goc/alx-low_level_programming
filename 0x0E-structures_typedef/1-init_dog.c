#include "dog.h"

/**
 * init_dog - Initialize a struct dog with given values
 *
 * @d: Pointer to a struct dog to be initialized
 * @name: Pointer to a character array representing the dog's name
 * @age: Float representing the dog's age
 * @owner: Pointer to a character array representing the dog's owner
 * code by Udeme Harrison
 * Description: Function initializes a struct dog with specified name, age & owner.
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	/* Check if d is NULL */
	if (d == NULL)
	{
		return;
	}

	/* Set the value of the struct members */
	d->name = name;
	d->age = age;
	d->owner = owner;
}

