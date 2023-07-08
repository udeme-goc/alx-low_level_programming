#include "dog.h"

/**
 * new_dog - creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Return: pointer to the new dog, or NULL if it fails
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog;
	char *name_copy, *owner_copy;
	int name_len = 0, owner_len = 0;

	/* Calculate the length of the name */
	while (name[name_len] != '\0')
		name_len++;

	/* Calculate the length of the owner's name */
	while (owner[owner_len] != '\0')
		owner_len++;

	/* Allocate memory for the new dog */
	new_dog = malloc(sizeof(dog_t));
	if (new_dog == NULL)
		return (NULL);

	/* Allocate memory for the name and owner's name */
	name_copy = malloc(sizeof(char) * (name_len + 1));
	if (name_copy == NULL)
	{
		free(new_dog);
		return (NULL);
	}

	owner_copy = malloc(sizeof(char) * (owner_len + 1));
	if (owner_copy == NULL)
	{
		free(name_copy);
		free(new_dog);
		return (NULL);
	}

	/* Copy the name and owner's name to the allocated memory */
	for (int i = 0; i <= name_len; i++)
		name_copy[i] = name[i];

	for (int i = 0; i <= owner_len; i++)
		owner_copy[i] = owner[i];

	/* Assign the name, age, and owner to the new dog */
	new_dog->name = name_copy;
	new_dog->age = age;
	new_dog->owner = owner_copy;

	return (new_dog);
}
