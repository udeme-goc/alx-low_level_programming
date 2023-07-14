#include "main.h"

/**
 * create_file - Create a file.
 * @filename: Name of the file to create.
 * @text_content: Text to write inside the file.
 *
 * Return: 1 if the file was created, -1 otherwise.
 */

int create_file(const char *filename, char *text_content)
{
	int fd_open, fd_write;

	/* Check if filename is NULL */
	if (filename == NULL)
		return (-1);

	/* Open the file with specified permissions */
	fd_open = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0600);
	if (fd_open == -1)
		return (-1);

	/* Check if text_content is not NULL and write it into the file */
	if (text_content != NULL)
	{
		fd_write = write(fd_open, text_content, _strlen(text_content));
		if (fd_write == -1)
			return (-1);
	}

	/* Close the file descriptor */
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

	/* Iterate through the string until the null terminator */
	while (*str++)
		count++;

	return (count);
}
