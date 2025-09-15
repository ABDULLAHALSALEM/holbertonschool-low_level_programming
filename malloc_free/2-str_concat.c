/* 2-str_concat.c */
#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings into a newly allocated buffer
 * @s1: first string (treated as "" if NULL)
 * @s2: second string (treated as "" if NULL)
 *
 * Return: pointer to new "s1+s2" string, or NULL if malloc fails
 */
char *str_concat(char *s1, char *s2)
{
	char *out;
	unsigned int l1 = 0, l2 = 0, i, j;

	/* احسب الأطوال يدويًا (ممنوع دوال مكتبة) */
	if (s1)
		while (s1[l1] != '\0')
			l1++;
	if (s2)
		while (s2[l2] != '\0')
			l2++;

	out = malloc((l1 + l2 + 1) * sizeof(*out));
	if (out == NULL)
		return (NULL);

	/* انسخ s1 */
	for (i = 0; i < l1; i++)
		out[i] = s1[i];

	/* ثم s2 مباشرة بعد s1 */
	for (j = 0; j < l2; j++)
		out[i + j] = s2[j];

	out[l1 + l2] = '\0';
	return (out);
}
