#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - prints the sums of the two diagonals of a square matrix
 * @a: pointer to the first element of the matrix (row-major, size x size)
 * @size: the dimension of the square matrix
 *
 * Return: void
 */
void print_diagsums(int *a, int size)
{
	int row, main_sum = 0, second_sum = 0;

	for (row = 0; row < size; row++)
	{
		main_sum += a[row * size + row];
		second_sum += a[row * size + (size - 1 - row)];
	}

	printf("%d, %d\n", main_sum, second_sum);
}
