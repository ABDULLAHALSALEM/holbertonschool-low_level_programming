#include "main.h"

/**
 * print_chessboard - prints an 8x8 chessboard
 * @a: pointer to an array of 8 chars (each row has 8 columns)
 *
 * Return: void
 */
void print_chessboard(char (*a)[8])
{
	int row, col;

	for (row = 0; row < 8; row++)
	{
		for (col = 0; col < 8; col++)
			_putchar(a[row][col]);
		_putchar('\n');
	}
}
