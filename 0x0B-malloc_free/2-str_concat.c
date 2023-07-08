#include "main.h"

/**
 * str_concat - Concatenates two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: A pointer to the concatenated string,
 *         or NULL on failure.
 */

char *str_concat(char *s1, char *s2)
{
	char *concatenated;
	unsigned int len1 = 0, len2 = 0, i, j;

	/* Check if s1 is NULL, if so, set it to an empty string */
	if (s1 == NULL)
		s1 = "";

	/* Check if s2 is NULL, if so, set it to an empty string */
	if (s2 == NULL)
		s2 = "";

	/* Calculate the length of s1 */
	while (s1[len1] != '\0')
		len1++;

	/* Calculate the length of s2 */
	while (s2[len2] != '\0')
		len2++;

	/* Allocate memory for the concatenated string */
	concatenated = malloc((len1 + len2 + 1) * sizeof(char));
	if (concatenated == NULL)
		return (NULL);

	/* Copy the characters from s1 to the concatenated string */
	for (i = 0; i < len1; i++)
		concatenated[i] = s1[i];

	/* Copy the characters from s2 to the concatenated string */
	for (j = 0; j < len2; j++)
		concatenated[i++] = s2[j];

	/* Add the null-terminating character at the end of the concatenated string */
	concatenated[i] = '\0';

	/* Return the pointer to the concatenated string */
		return (concatenated);
}
