#include "main.h"

/**
 * print_most_numbers - prints digits from 0 to 9
 * except 2 and 4, followed by a newline
 *
 * Return: void
 */
void print_most_numbers(void)
{
	char d;

	for (d = '0'; d <= '9'; d++)
	{
		if (d == '2' || d == '4')
			continue;      /* Skip 2 and 4 */
		_putchar(d);       /* Print the current digit */
	}

	_putchar('\n');        /* Print newline at the end */
}
