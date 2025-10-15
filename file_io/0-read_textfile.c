#include "main.h"

/**
 * read_textfile - Read a text file and print it to POSIX standard output.
 * @filename: Path to the text file.
 * @letters:  Number of bytes to read and print.
 *
 * Return: The actual number of bytes printed,
 *         or 0 on any failure (open/read/write error, or filename is NULL).
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t rcount;
	ssize_t wcount;
	ssize_t total;
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

	total = 0;
	while (total < rcount)
	{
		wcount = write(STDOUT_FILENO, buf + total, rcount - total);
		if (wcount == -1)
		{
			free(buf);
			close(fd);
			return (0);
		}
		total += wcount;
	}

	free(buf);
	close(fd);
	return (total);
}
