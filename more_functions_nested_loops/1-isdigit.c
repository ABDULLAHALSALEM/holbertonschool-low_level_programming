#include "main.h"

/**
 * _isdigit - checks if a character code is a digit (0..9)
 * @c: int representing the character code to check
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
