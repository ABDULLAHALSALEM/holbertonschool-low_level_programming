#include "main.h"

/**
 * append_text_to_file - Append a string at the end of a file.
 * @filename: Name of the file.
 * @text_content: NULL-terminated string to add (may be NULL).
 *
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	size_t len;
	ssize_t wcount;
	ssize_t written;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content == NULL)
	{
		close(fd);
		return (1);
	}

	for (len = 0; text_content[len] != '\0'; len++)
		;

	written = 0;
	while (written < (ssize_t)len)
	{
		wcount = write(fd, text_content + written, len - written);
		if (wcount == -1)
		{
			close(fd);
			return (-1);
		}
		written += wcount;
	}

	if (close(fd) == -1)
		return (-1);
	return (1);
}
