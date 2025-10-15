#include "main.h"

/**
 * read_textfile - Read a text file and print to POSIX stdout.
 * @filename: File path.
 * @letters: Max bytes to read and print.
 *
 * Return: Printed byte count, or 0 on any failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t rcount, wcount, total;
	char *buf;

	if (filename == NULL || letters == 0)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
	{
		close(fd);
		return (0);
	}

	rcount = read(fd, buf, letters);
	if (rcount <= 0)
	{
		free(buf);
		close(fd);
		return (0);
	}

	for (total = 0; total < rcount; total += wcount)
	{
		wcount = write(STDOUT_FILENO, buf + total, rcount - total);
		if (wcount == -1)
		{
			free(buf);
			close(fd);
			return (0);
		}
	}

	free(buf);
	close(fd);
	return (total);
}
