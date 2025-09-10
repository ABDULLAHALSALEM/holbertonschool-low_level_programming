#include "main.h"

/**
 * _strlen_recursion - Returns the length of a string.
 * @s: pointer to the string
 *
 * Description: Recursively counts characters until the null terminator.
 * Return: length of @s
 */
int _strlen_recursion(char *s)
{
	if (s == 0 || *s == '\0') /* Base case: NULL or end of string */
		return (0);

	return (1 + _strlen_recursion(s + 1)); /* Count current + rest */
}
