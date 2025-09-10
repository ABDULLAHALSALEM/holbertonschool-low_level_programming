#include "main.h"

/**
 * _print_rev_recursion - Prints a string in reverse order.
 * @s: pointer to the string
 *
 * Description: Recursively walks to the end of @s, then prints
 * characters during the unwind, resulting in reversed output.
 * Return: void
 */
void _print_rev_recursion(char *s)
{
	if (s == 0 || *s == '\0') /* Base case: null or end of string */
		return;

	_print_rev_recursion(s + 1); /* Go deeper first */
	_putchar(*s);                /* Print on the way back */
}
