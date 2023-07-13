#include "main.h"

/**
 * error_exit - Prints an error message and exits with a specific code.
 * @code: The exit code.
 * @message: The error message to print.
 */

void error_exit(int code, char *message)
{
	dprintf(STDERR_FILENO, "%s\n", message);
	exit(code);
}


/**
 * main - Copies the content of a file to another file.
 * @argc: The number of arguments.
 * @argv: The arguments array.
 *
 * Return: 0 on success.
 */

int main(int argc, char **argv)
{
	int fd_from, fd_to, bytes_read, bytes_written;
	char buffer[1024];

	if (argc != 3)
		error_exit(97, "Usage: cp file_from file_to");

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		error_exit(98, argv[1]);

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
		error_exit(99, argv[2]);

	while ((bytes_read = read(fd_from, buffer, sizeof(buffer))) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1)
			error_exit(99, argv[2]);
	}

	if (bytes_read == -1)
		error_exit(98, argv[1]);

	if (close(fd_from) == -1)
		error_exit(100, "Can't close fd_from");
	if (close(fd_to) == -1)
		error_exit(100, "Can't close fd_to");

	return (0);
}
