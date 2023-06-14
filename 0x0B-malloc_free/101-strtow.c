#include "main.h"

/**
 * count_words - Counts the number of words in a string
 * @str: The input string
 *
 * Return: The number of words
 */

int count_words(char *str);


/**
 * strtow - Splits a string into words
 * @str: The input string
 *
 * Return: A pointer to an array of strings (words), or NULL if it fails
 */

char **strtow(char *str)
{
	int i, j, k, len;
	int words_count = count_words(str);
	char **words = malloc((words_count + 1) * sizeof(char *));

	if (str == NULL || *str == '\0')
		return (NULL);

	if (words == NULL)
		return (NULL);

	i = 0;
	j = 0;
	k = 0;
	len = 0;

	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			len = 0;
			k = i;

			/* Count the length of the word */
			while (str[k] != ' ' && str[k] != '\0')
			{
				len++;
				k++;
			}

			/* Allocate memory for the word */
			words[j] = malloc((len + 1) * sizeof(char));
			if (words[j] == NULL)
			{
				/* Free previously allocated memory on failure */
				for (k = 0; k < j; k++)
					free(words[k]);
				free(words);
				return (NULL);
				}

			/* Copy the word into the array */
			for (k = 0; k < len; k++)
				words[j][k] = str[i++];
			words[j][k] = '\0';
			j++;
		}
		else
			i++;
	}
	words[j] = NULL;

	return (words);
}


/**
 * count_words - Counts the number of words in a string
 * @str: The input string
 *
 * Return: The number of words
 */

int count_words(char *str)
{
	int count = 0;
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			count++;
		i++;
	}

	return (count);
}
