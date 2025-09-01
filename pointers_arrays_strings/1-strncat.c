#include "main.h"

/**
 * _strncat - concatenates two strings, using at most n bytes from src
 * @dest: destination string (must have enough space)
 * @src: source string
 * @n: maximum number of bytes to copy from src
 *
 * Return: pointer to dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0;
	int j = 0;

	/* find the end of dest */
	while (dest[i] != '\0')
	{
		i++;
	}

	/* copy at most n characters from src */
	while (j < n && src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	/* always null-terminate */
	dest[i] = '\0';

	return (dest);
}
