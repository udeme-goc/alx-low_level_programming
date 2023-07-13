#include "main.h"

/**
 * close_file - Closes an opened file.
 * @FD: File descriptor to close.
 *
 * Return: None.
 */

void close_file(int FD)
{
	/* Close the file descriptor */
	if (close(FD) == -1)
	{
		/* Error occurred while closing file descriptor */
		dprintf(STDERR_FILENO, "Error: Can't close fd %i\n", FD);
		exit(100);
	}
}


/**
 * main - Entry point.
 * @argc: Number of arguments passed to the function.
 * @argv: Two files.
 *
 * Return: 0 on success, other values on failure.
 */

int main(int argc, char *argv[])
{
	int inputFD, outputFD, nBytes_read, nBytes_write;
	char text[BUF_SIZE];

	/* Check if the correct number of arguments is provided */
	if (argc != 3)
	{
		/* Incorrect number of arguments, display error message */
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	/* Open the input file for reading */
	inputFD = open(argv[1], O_RDONLY);
	if (inputFD == -1)
	{
		/* Error opening the input file, display error message */
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	/* Open the output file for writing, create if it doesn't exist */
	outputFD = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (outputFD == -1)
	{
		/* Error opening the output file, display error message */
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}

	/* Read data from the input file and write to the output file */
	while ((nBytes_read = read(inputFD, text, BUF_SIZE)) > 0)
	{
		nBytes_write = write(outputFD, text, nBytes_read);
		if (nBytes_write == -1)
		{
			/* Error occurred while writing to the output file, display error message */
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	}

	if (nBytes_read == -1)
	{
		/* Error occurred while reading from the input file, display error message */
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	/* Close the input and output files */
	close_file(inputFD);
	close_file(outputFD);

	return (0);
}
