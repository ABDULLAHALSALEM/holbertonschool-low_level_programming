#include "main.h"

/**
 * print_square - prints a square using the character '#'
 * @size: size of the square (number of rows and columns)
 *
 * Return: void
 */
void print_square(int size)
{
	int r, c;

	if (size > 0)
	{
		for (r = 0; r < size; r++)      /* rows */
		{
			for (c = 0; c < size; c++)  /* columns */
				_putchar('#');
			_putchar('\n');
		}
	}
	else
	{
		_putchar('\n');
	}
}
