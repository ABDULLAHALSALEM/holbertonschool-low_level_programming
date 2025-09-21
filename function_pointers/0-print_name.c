#include "function_pointers.h"

/**
 * print_name - Call a user-supplied printer for a name.
 * @name: The name to print.
 * @f: Pointer to a function that takes (char *) and returns void.
 *
 * Return: Nothing.
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == 0 || f == 0)
		return;

	f(name);
}
