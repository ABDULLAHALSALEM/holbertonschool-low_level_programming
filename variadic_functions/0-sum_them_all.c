/*
 * File: 0-sum_them_all.c
 * Desc: Implementation of sum_them_all using stdarg macros.
 */

#include <stdarg.h>
#include "variadic_functions.h"

/**
 * sum_them_all - Return the sum of all its parameters.
 * @n: Number of integer arguments that follow.
 *
 * Return: The sum of the numbers, or 0 if @n is 0.
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list ap;
	unsigned int i;
	int sum = 0;

	if (n == 0)
		return (0);

	va_start(ap, n);
	for (i = 0; i < n; i++)
		sum += va_arg(ap, int);
	va_end(ap);

	return (sum);
}
