#include "main.h"

/**
 * count_words - Counts the number of words in a string.
 * @str: The string to count words from.
 *
 * Return: The number of words in the string.
 */

static int count_words(char *str)
{
	int count = 0;
	int i = 0;

	while (str[i] != '\0')
	{
		/* Skip leading spaces */
		while (str[i] == ' ')
			i++;

		if (str[i] != '\0')
		{
			count++;
			/* Skip word characters */
			while (str[i] != ' ' && str[i] != '\0')
				i++;
		}
	}

	return (count);
}


/**
 * split_string - Splits a string into words.
 * @str: The string to be split.
 * @words: An array to store the split words.
 *
 * Return: 1 if successful, 0 otherwise.
 */

static int split_string(char *str, char **words)
{
	int i = 0;
	int j = 0;
	int index = 0;

	while (str[i] != '\0')
	{
		/* Skip leading spaces */
		while (str[i] == ' ')
			i++;

		if (str[i] != '\0')
		{
			j = i;
			/* Count word characters */
			while (str[j] != ' ' && str[j] != '\0')
				j++;

			words[index] = malloc((j - i + 1) * sizeof(char));
			if (words[index] == NULL)
			{
				/* Free memory if allocation fails */
				for (j = 0; j < index; j++)
					free(words[j]);
				return (0);
			}

			/* Copy word from string */
			for (; i < j; i++)
				words[index][i - index] = str[i];
			words[index][i - index] = '\0';
			index++;
		}
	}

	return (1);
}


/**
 * strtow - Splits a string into words.
 * @str: The string to be split.
 *
 * Return: A pointer to an array of strings (words), or NULL if failed.
 */

char **strtow(char *str)
{
	char **words;
	int word_count;

	if (str == NULL || *str == '\0')
		return (NULL);

	word_count = count_words(str);
	words = malloc((word_count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	words[word_count] = NULL;

	if (!split_string(str, words))
	{
		free(words);
		return (NULL);
	}

	return (words);
}


/**
 * free_words - Frees the memory allocated for words.
 * @words: The array of words.
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


/**
 * print_words - Prints the array of words.
 * @words: The array of words.
 */

void print_words(char **words)
{
	int i;

	if (words == NULL)
		return;

	for (i = 0; words[i] != NULL; i++)
		printf("%s\n", words[i]);
}
