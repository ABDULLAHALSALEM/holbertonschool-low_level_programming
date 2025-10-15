#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1024

/**
 * close_fd - Close a file descriptor and handle errors.
 * @fd: File descriptor to close.
 */
static void close_fd(int fd)
{
	int c;

	c = close(fd);
	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copy the content of a file to another file.
 * @ac: Argument count.
 * @av: Argument vector.
 *
 * Return: 0 on success, exits with codes 97-100 on failure.
 */
int main(int ac, char **av)
{
	int fd_from, fd_to;
	ssize_t rcount, wcount, written;
	char buf[BUF_SIZE];

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		exit(98);
	}

	fd_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
		close_fd(fd_from);
		exit(99);
	}

	while ((rcount = read(fd_from, buf, BUF_SIZE)) > 0)
	{
		written = 0;
		while (written < rcount)
		{
			wcount = write(fd_to, buf + written, rcount - written);
			if (wcount == -1)
			{
				dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
				close_fd(fd_from);
				close_fd(fd_to);
				exit(99);
			}
			written += wcount;
		}
	}

	if (rcount == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		close_fd(fd_from);
		close_fd(fd_to);
		exit(98);
	}

	close_fd(fd_from);
	close_fd(fd_to);
	return (0);
}
