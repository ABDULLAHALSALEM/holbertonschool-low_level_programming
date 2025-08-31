#include "main.h"

/**
 * print_triangle - prints a right-aligned triangle using '#'
 * @size: size of the triangle (height and base length)
 *
 * Description: For size > 0, each row starts with spaces to align
 * the triangle to the right, then hashes '#'. If size <= 0, only
 * a newline is printed.
 *
 * Return: void
 */
void print_triangle(int size)
{
	int row, col;

	if (size > 0)
	{
		for (row = 0; row < size; row++)
		{
			/* print leading spaces: size - row - 1 */
			for (col = 0; col < size - row - 1; col++)
				_putchar(' ');

			/* print hashes: row + 1 */
			for (col = 0; col < row + 1; col++)
				_putchar('#');

			_putchar('\n');
		}
	}
	else
	{
		_putchar('\n');
	}
}
