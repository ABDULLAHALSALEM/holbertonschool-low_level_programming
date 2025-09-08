#include "main.h"
#include <stddef.h> /* for NULL */

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: the string to scan
 * @accept: the set of bytes to look for
 *
 * Return: pointer to the first byte in s that matches any in accept,
 *         or NULL if no such byte is found
 */
char *_strpbrk(char *s, char *accept)
{
	unsigned int i, j;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
				return (s + i);
		}
	}
	return (NULL);
}
