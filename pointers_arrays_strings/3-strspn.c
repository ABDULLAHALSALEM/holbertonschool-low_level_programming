#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: the input string to scan from its beginning
 * @accept: the set of allowed bytes
 *
 * Return: number of bytes from the start of s that are only in accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, j, count = 0;
	int match;

	for (i = 0; s[i] != '\0'; i++)
	{
		match = 0;
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				match = 1;
				break;
			}
		}
		if (!match)
			break;
		count++;
	}

	return (count);
}
