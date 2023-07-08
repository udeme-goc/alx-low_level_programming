#include "main.h"

/**
 * string_nconcat - Concatenates two strings up to n bytes.
 * @s1: Pointer to the first string.
 * @s2: Pointer to the second string.
 * @n: Number of bytes to concatenate from s2.
 * code by Udeme Harrison
 * Return: Pointer to a newly allocated space in memory with the concatenated
 *         string or NULL on failure.
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int i, j;
	char *s_concat;
	unsigned int s1_len = 0, s2_len = 0;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	/* Calculate the length of the strings */
	while (*(s1 + s1_len))
		s1_len++;

	while (*(s2 + s2_len))
		s2_len++;

	/* Allocate memory for the concatenated string */
	if (n >= s2_len)
		n = s2_len;
	s_concat = malloc(sizeof(char) * (s1_len + n + 1));
	if (s_concat == NULL)
		return (NULL);

	/* Copy s1 to s_concat */
	for (i = 0; i < s1_len; i++)
		*(s_concat + i) = *(s1 + i);

	/* Copy up to n bytes of s2 to s_concat */
	for (j = 0; j < n; j++)
		*(s_concat + i + j) = *(s2 + j);

	*(s_concat + i + j) = '\0';

	return (s_concat);
}

