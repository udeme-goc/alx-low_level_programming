#include "main.h"

/**
 * _strdup - Creates a duplicate of a string.
 * @str: The string to duplicate.
 *
 * Return: On success, returns a pointer to the newly allocated string.
 *         On failure, returns NULL.
 */

char *_strdup(char *str)
{
	/* Declare a pointer to store the duplicated string */
	char *dup;
	/* Declare variables for iteration and length calculation */
	unsigned int i, len = 0;

	/* Check if the input string is NULL */
	if (str == NULL)
		return (NULL);

	/* Calculate the length of the string */
	while (str[len])
		len++;

	/* Allocate memory for the duplicated string (+1 for the null terminator) */
	dup = malloc(sizeof(char) * (len + 1));

	/* Check if memory allocation was successful */
	if (dup == NULL)
		return (NULL);

	/* Copy the characters from the original string to the duplicated string */
	for (i = 0; i < len; i++)
		dup[i] = str[i];

	/* Add null terminator to the end of the duplicated string */
	dup[i] = '\0';

	/* Return the pointer to the duplicated string */
	return (dup);
}
