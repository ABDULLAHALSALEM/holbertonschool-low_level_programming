#include "function_pointers.h"

/**
 * print_name - call a function to print a name
 * @name: pointer to the name string
 * @f: function pointer that takes a char * and returns void
 *
 * Return: Nothing
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}
