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
	int i, j, k, len, count = 0, index = 0;

	if (str == NULL || *str == '\0')
		return (NULL);

	len = strlen(str);
	words = malloc(sizeof(char *) * (len + 1));

	if (words == NULL)
		return (NULL);

	/* Count the number of words in the string */
	for (i = 0; i < len; i++)
	{
		if (str[i] != ' ' && str[i] != '\n' && str[i] != '\r')
		{
			count++;
			while (str[i] != ' ' && str[i] != '\n' && str[i] != '\r' && str[i] != '\0')
				i++;
		}
	}

	/* Allocate memory for the words array */
	words[count] = NULL;

	for (i = 0; i < len; i++)
	{
		if (str[i] != ' ' && str[i] != '\n' && str[i] != '\r')
		{
			j = i;
			while (str[j] != ' ' && str[j] != '\n' && str[j] != '\r' && str[j] != '\0')
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

			/* Copy each word from the string */
			for (k = 0; i < j; i++, k++)
			{
				words[index][k] = str[i];
			}
			words[index][k] = '\0';
			index++;
		}
	}

	/* Null-terminate the last element of the words array */
	words[index] = NULL;

	/* Free memory for words if no words were found */
	if (count == 0)
	{
		free(words);
		words = NULL;
	}

	return (words);
}

/**
 * free_words - Frees the memory allocated for an array of words.
 * @words: The array of words to be freed.
 */

void free_words(char **words)
{
	int i;

	if (words == NULL)
		return;

	for (i = 0; words[i] != NULL; i++)
		free(words[i]);

	free(words);
}

