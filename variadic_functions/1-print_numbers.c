/*
 * File: 1-print_numbers.c
 * Desc: Print a variable number of integers with an optional separator.
 */

#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_numbers - Print integers separated by @separator, then newline.
 * @separator: String printed between numbers (ignored if NULL).
 * @n:        Count of integers to print.
 *
 * Return: Nothing.
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list ap;
	unsigned int i;

	va_start(ap, n);

	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(ap, int));

		/* print the separator only between numbers, not after the last */
		if (separator && (i + 1) < n)
			printf("%s", separator);
	}

	printf("\n");
	va_end(ap);
}
