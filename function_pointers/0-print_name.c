#include "function_pointers.h"

/**
 * print_name - Calls a user-supplied function to print a name.
 * @name: Pointer to the name string.
 * @f: Pointer to a function that takes (char *) and returns void.
 *
 * Return: Nothing.
 */
void print_name(char *name, void (*f)(char *))
{
	if (!name || !f)
		return;

	f(name);
}
