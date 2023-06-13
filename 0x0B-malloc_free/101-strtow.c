#include "main.h"

/**
 * count_words - Counts the number of words in a string.
 * @str: The string to count words from.
 *
 * Return: The number of words.
 */

int count_words(char *str)
{
	int i, count = 0;
	int len = strlen(str);

	for (i = 0; i < len; i++)
	{
		if (str[i] != ' ')
		{
			count++;
			while (str[i] != ' ' && str[i] != '\0')
				i++;
		}
	}

	return (count);
}


/**
 * allocate_memory - Allocates memory for the words array.
 * @str: The string to split into words.
 * @words: The array to store the words.
 * @count: The number of words.
 *
 * Return: 1 on success, 0 on failure.
 */

int allocate_memory(char *str, char **words, int count)
{
	int i, j, index = 0;
	int len = strlen(str);

	words[count] = NULL;

	for (i = 0; i < len; i++)
	{
		if (str[i] != ' ')
		{
			j = i;
			while (str[j] != ' ' && str[j] != '\0')
				j++;

			words[index] = malloc(sizeof(char) * (j - i + 1));
			if (words[index] == NULL)
				return (0);

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
 * Return: If str == NULL or str == "" or memory allocation fails - NULL.
 *         Otherwise - a pointer to an array of strings (words).
 */

char **strtow(char *str)
{
	char **words;
	int count;

	/* Check for empty string or NULL input */
	if (str == NULL || *str == '\0')
		return (NULL);

	/* Count the number of words in the string */
	count = count_words(str);

	/* Allocate memory for the words array */
	words = malloc(sizeof(char *) * (count + 1));
	if (words == NULL)
		return (NULL);

	/* Allocate memory for each word and copy it from the string */
	if (!allocate_memory(str, words, count))
	{
		/* Free memory if allocation fails */
		for (int i = 0; i < count; i++)
			free(words[i]);
		free(words);
		return (NULL);
	}

	return (words);
}
