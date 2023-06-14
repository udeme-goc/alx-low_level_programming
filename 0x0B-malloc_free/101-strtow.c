#include "main.h"

/**
 * count_words - Counts the number of words in a string.
 * @str: The input string.
 *
 * Return: The number of words.
 */

int count_words(char *str)
{
	int count = 0;
	int is_word = 0;

	while (*str)
	{
		if (*str != ' ')
		{
			if (!is_word)
			{
				count++;
				is_word = 1;
			}
		}
		else
		{
			is_word = 0;
		}
		str++;
	}

	return (count);
}


/**
 * strtow - Splits a string into words.
 * @str: The input string.
 *
 * Return: Pointer to an array of strings (words) or NULL if it fails.
 */

char **strtow(char *str)
{
	if (str == NULL || *str == '\0')
		return (NULL);

	int i, j, k, len, word_count;
	char **words;

	/* Count the number of words in the string */
	word_count = count_words(str);

	/* Allocate memory for the array of words */
	words = malloc((word_count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	i = 0;
	while (*str)
	{
		if (*str != ' ')
		{
			len = 0;
			while (str[len] && str[len] != ' ')
				len++;

			/* Allocate memory for each word */
			words[i] = malloc((len + 1) * sizeof(char));
			if (words[i] == NULL)
			{
				/* Free previously allocated memory and return NULL if allocation fails */
				for (j = 0; j < i; j++)
					free(words[j]);
				free(words);
				return (NULL);
			}

			/* Copy the characters of the word */
			for (k = 0; k < len; k++)
				words[i][k] = str[k];
			words[i][k] = '\0';

			i++;
			str += len;
		}
		else
		{
			str++;
		}
	}

	/* Set the last element of the array to NULL */
	words[i] = NULL;

	return (words);
}
