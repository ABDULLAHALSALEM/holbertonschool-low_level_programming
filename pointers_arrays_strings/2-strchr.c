#include "main.h"
#include <stddef.h> /* NULL */

/**
 * _strchr - locates the first occurrence of character c in string s
 * @s: the string to search in
 * @c: the character to look for
 *
 * Return: pointer to the first occurrence in s, or NULL if not found
 */
char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}

	/* handle searching for the null terminator */
	if (c == '\0')
		return (s);

	return (NULL);
}
