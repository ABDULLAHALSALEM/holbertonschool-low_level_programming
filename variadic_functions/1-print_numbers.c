/*
 * File: 1-print_numbers.c
 * Desc: Print a variable number of integers with an optional separator.
 */

#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_numbers - prints numbers separated by a string, followed by a newline
 * @separator: the string to print between numbers (if NULL, print nothing)
 * @n: number of integers passed to the function
 *
 * Return: Nothing
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list ap;
	unsigned int i;

	va_start(ap, n);

	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(ap, int));

		/* اطبع الفاصل فقط بين الأرقام وليس بعد آخر رقم */
		if (separator != NULL && i < n - 1)
			printf("%s", separator);
	}

	printf("\n");
	va_end(ap);
}
