#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUF_SIZE 1024
#define PERMS 0664

/**
 * create_buffer - Allocate a 1KB buffer.
 * @file_to: Destination file name (for error message).
 *
 * Return: Pointer to the new buffer.
 */
static char *create_buffer(const char *file_to)
{
	char *buf;

	buf = malloc(BUF_SIZE);
	if (buf == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		exit(99);
	}
	return (buf);
}

/**
 * close_file - Close a file descriptor with error handling.
 * @fd: The file descriptor to close.
 */
static void close_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copy the content of a file to another file.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Return: 0 on success,
 * 97/98/99/100 on specific failures (printed to STDERR).
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t rcount, wcount;
	char *buf;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		return (97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		return (98);
	}

	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, PERMS);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close_file(fd_from);
		return (99);
	}

	buf = create_buffer(argv[2]);

	while ((rcount = read(fd_from, buf, BUF_SIZE)) > 0)
	{
		wcount = write(fd_to, buf, rcount);
		if (wcount != rcount)
		{
			free(buf);
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close_file(fd_from);
			close_file(fd_to);
			return (99);
		}
	}
	if (rcount == -1)
	{
		free(buf);
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		close_file(fd_from);
		close_file(fd_to);
		return (98);
	}

	free(buf);
	close_file(fd_from);
	close_file(fd_to);
	return (0);
}
