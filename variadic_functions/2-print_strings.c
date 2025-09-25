/*
 * File: 2-print_strings.c
 * Desc: Print strings with an optional separator, then newline.
 */

#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_strings - print strings separated by @separator, then newline
 * @separator: string printed between items (ignored if NULL)
 * @n:        count of strings to print
 *
 * Return: Nothing
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list ap;
	unsigned int i;
	const char *s;

	va_start(ap, n);

	for (i = 0; i < n; i++)
	{
		s = va_arg(ap, const char *);
		if (s == NULL)
			printf("(nil)");
		else
			printf("%s", s);

		/* print separator only between items */
		if (separator && (i + 1) < n)
			printf("%s", separator);
	}

	printf("\n");
	va_end(ap);
}
