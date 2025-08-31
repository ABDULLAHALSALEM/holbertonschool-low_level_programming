#include "main.h"

/**
 * _isupper - checks if a character code is uppercase (A..Z)
 * @c: int representing the character code to check
 *
 * Return: 1 if c is uppercase, 0 otherwise
 */
int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}
