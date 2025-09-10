#include "main.h"

/**
 * _puts_recursion - Prints a string, followed by a new line.
 * @s: pointer to the string
 *
 * Description: Recursively prints each character in @s. When the
 * null terminator is reached, it prints a newline and returns.
 * Return: void
 */
void _puts_recursion(char *s)
{
	if (*s == '\0') /* Base case: end of string */
	{
		_putchar('\n');
		return;
	}

	_putchar(*s);           /* Print current character */
	_puts_recursion(s + 1); /* Recurse on the rest of the string */
}
