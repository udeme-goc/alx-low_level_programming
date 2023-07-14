#include "main.h"

/**
 * append_text_to_file - Append text at the end of a file.
 * @filename: Name of the file to create.
 * @text_content: Text to write inside the file.
 *
 * Return: 1 if text_content was appended, -1 otherwise.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fd_open, fd_write;

	if (filename == NULL)
		return (-1);

	/* Open the file for reading and appending */
	fd_open = open(filename, O_RDWR | O_APPEND);
	if (fd_open == -1)
		return (-1);

	if (text_content != NULL)
	{
		/* Write the text_content to the file */
		fd_write = write(fd_open, text_content, _strlen(text_content));
		if (fd_write == -1)
			return (-1);
	}

	/* Close the file */
	close(fd_open);
	return (1);
}


/**
 * _strlen - Calculate the length of a string.
 * @str: Array of characters.
 *
 * Return: Length of the string.
 */

int _strlen(char *str)
{
	int count = 0;

	while (*str++)
		count++;
	return (count);
}
