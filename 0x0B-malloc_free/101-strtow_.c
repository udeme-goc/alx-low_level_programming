#include "main.h"

/**
 * strtow - Splits a string into words.
 * @str: The string to be split.
 *
 * Return: If str == NULL or str == "" or memory allocation fails - NULL.
 *         Otherwise - a pointer to an array of strings (words).
 */

char **strtow(char *str)
{
	char **words;
	int i, j, k, l, len, count = 0, index = 0;

	if (str == NULL || *str == '\0')
		return (NULL);

	len = strlen(str);
	words = malloc(sizeof(char *) * (len + 1));

	if (words == NULL)
		return (NULL);

	/* Count the number of words in the string */
	for (i = 0; i < len; i++)
	{
		if (str[i] != ' ')
		{
			count++;
			while (str[i] != ' ' && str[i] != '\0')
				i++;
		}
	}

	/* Allocate memory for the words array */
	words[count] = NULL;

	for (i = 0; i < len; i++)
	{
		if (str[i] != ' ')
		{
			j = i;
			while (str[j] != ' ' && str[j] != '\0')
				j++;

			/* Allocate memory for each word */
			words[index] = malloc(sizeof(char) * (j - i + 1));
			if (words[index] == NULL)
			{
				/* Free memory if allocation fails */
				for (k = 0; k < index; k++)
					free(words[k]);
				free(words);
				return (NULL);
			}

			/* Initialize the allocated memory */
			for (l = 0; l < (j - i + 1); l++)
			{
				words[index][l] = '\0';
			}

			/* Copy each word from the string */
			for (; i < j; i++)
			{
				words[index][i - j] = str[i];
			}
			words[index][i - j] = '\0';
			index++;
		}
	}

	return (words);
}

