#include "main.h"

/**
 * print_alphabet_x10 - prints the alphabet in lowercase 10 times,
 * followed by a new line each time
 */
void print_alphabet_x10(void)
{
	int i;
	char c;

	for (i = 0; i < 10; i++)
	{
		for (c = 'a'; c <= 'z'; c++)
		{
			_putchar(c);   /* 1) سطر _putchar الأول */
		}
		_putchar('\n');     /* 2) سطر _putchar الثاني */
	}
}
