#include "main.h"

/**
 * rev_string - reverses a string in place
 * @s: pointer to a writable string buffer
 *
 * Description: Reverses the characters of s in place by swapping
 * characters from the ends moving toward the middle.
 * Return: nothing
 */
void rev_string(char *s)
{
	int i = 0;
	int j = 0;
	char tmp;

	/* get length (position after last char) */
	while (s[j] != '\0')
	{
		j++;
	}

	/* point to last character (not the null terminator) */
	j = j - 1;

	while (i < j)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i++;
		j--;
	}
}
