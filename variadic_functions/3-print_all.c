/*
 * File: 3-print_all.c
 * Desc: Print anything based on a format string (c, i, f, s).
 */

#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_all - prints values according to @format, then a newline
 * @format: string of specifiers: c (char), i (int), f (float), s (char *)
 *
 * Return: Nothing
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	unsigned int i = 0;
	char *sep = "";
	char *str;

	va_start(ap, format);

	while (format && format[i])
	{
		switch (format[i])
		{
		case 'c':
			printf("%s%c", sep, (char)va_arg(ap, int));
			sep = ", ";
			break;
		case 'i':
			printf("%s%d", sep, va_arg(ap, int));
			sep = ", ";
			break;
		case 'f':
			printf("%s%f", sep, va_arg(ap, double));
			sep = ", ";
			break;
		case 's':
			str = va_arg(ap, char *);
			if (!str)
				str = "(nil)";
			printf("%s%s", sep, str);
			sep = ", ";
			break;
		default:
			i++;
			continue;
		}
		i++;
	}

	printf("\n");
	va_end(ap);
}
