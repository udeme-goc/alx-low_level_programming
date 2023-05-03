#include "dog.h"

/**
 * _strlen - returns length of string
 * @s: string to evaluate
 * Return: length of string
 */

int _strlen(char *s)
{
	int i;

	i = 0;

	/* loop through string until end character */
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _strcpy - copy string by pointed by src pointer including terminating
 *	null byte to buffer pointed to by dest
 *
 * @dest: pointer to the buffer, source of string
 * @src: string to be copied
 *
 * Return: pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int len, i;

	len = 0;

	/* determine length of string */
	while (src[len] != '\0')
	{
		len++;
	}

	/* copy character from src to dest */
	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * new_dog - create a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Return: pointer to the new dog (Success), NULL otherwise
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	/* Declare a pointer to a dog structure */
	dog_t *dog;
	/* Declare variables to store the length of the name and owner */
	int len1, len2;

	/* Calculate the length of the name and owner */
	len1 = _strlen(name);
	len2 = _strlen(owner);

	/* Allocate memory for the dog structure */
	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);

	/* Allocate memory for the name of the dog */
	dog->name = malloc(sizeof(char) * (len1 + 1));
	if (dog->name == NULL)
	{
		free(dog);
		return (NULL);
	}

	/* Allocate memory for the owner of the dog */
	dog->owner = malloc(sizeof(char) * (len2 + 1));
	if (dog->owner == NULL)
	{
		free(dog);
		free(dog->name);
		return (NULL);
	}

	/* Copy the name and owner to the dog structure */
	_strcpy(dog->name, name);
	_strcpy(dog->owner, owner);
	dog->age = age;

	/* Return a pointer to the dog struct */
	return (dog);
}
