/* 1-string_nconcat.c */
#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - concatenates s1 and the first n bytes of s2
 * @s1: left string (treated as "" if NULL)
 * @s2: right string (treated as "" if NULL)
 * @n:  number of bytes to take from s2
 *
 * Return: pointer to new "s1 + s2[0..n-1]" string,
 *         or NULL if malloc fails.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *out;
	unsigned int l1 = 0, l2 = 0, i, j, take;

	if (s1)
		while (s1[l1] != '\0')
			l1++;
	if (s2)
		while (s2[l2] != '\0')
			l2++;

	take = (n >= l2) ? l2 : n;

	out = malloc((l1 + take + 1) * sizeof(*out));
	if (out == NULL)
		return (NULL);

	for (i = 0; i < l1; i++)
		out[i] = s1[i];

	for (j = 0; j < take; j++)
		out[i + j] = s2[j];

	out[l1 + take] = '\0';
	return (out);
}
