#include "function_pointers.h"

/**
 * print_name - calls a function to print a name
 * @name: pointer to the name string
 * @f: pointer to a function that takes a char * and returns void
 *
 * Return: Always nothing.
 */
void print_name(char *name, void (*f)(char *))
{
	if (!name || !f)
		return;

	f(name);
}
