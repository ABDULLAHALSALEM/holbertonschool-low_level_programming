/* 4-free_grid.c */
#include "main.h"
#include <stdlib.h>

/**
 * free_grid - frees a 2D grid created by alloc_grid
 * @grid: pointer to the grid (array of row pointers)
 * @height: number of rows
 *
 * Return: Nothing.
 */
void free_grid(int **grid, int height)
{
	int r;

	if (grid == NULL || height <= 0)
		return;

	for (r = 0; r < height; r++)
		free(grid[r]);

	free(grid);
}
