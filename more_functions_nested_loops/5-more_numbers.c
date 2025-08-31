#include "main.h"

/**
 * more_numbers - prints 10 times the numbers from 0 to 14
 *
 * Return: void
 */
void more_numbers(void)
{
	int i, j;

	for (i = 0; i < 10; i++)        /* repeat 10 times */
	{
		for (j = 0; j <= 14; j++)   /* print from 0 to 14 */
		{
			if (j >= 10)
				_putchar('0' + j / 10); /* print tens digit */
			_putchar('0' + j % 10);     /* print ones digit */
		}
		_putchar('\n');                /* new line after each row */
	}
}
