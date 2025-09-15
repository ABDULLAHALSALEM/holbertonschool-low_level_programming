/* 3-alloc_grid.c */
#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - allocate a 2D grid (height x width) and fill with 0
 * @width: columns count
 * @height: rows count
 *
 * Return:
 *   pointer to the grid (int **),
 *   or NULL on failure or invalid size.
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int r, c;

	if (width <= 0 || height <= 0)
		return (NULL);

	/* allocate row pointers */
	grid = malloc(height * sizeof(*grid));
	if (grid == NULL)
		return (NULL);

	/* allocate each row */
	for (r = 0; r < height; r++)
	{
		grid[r] = malloc(width * sizeof(**grid));
		if (grid[r] == NULL)
		{
			/* free previous rows, then the grid */
			while (r--)
				free(grid[r]);
			free(grid);
			return (NULL);
		}

		/* init row to zeros */
		for (c = 0; c < width; c++)
			grid[r][c] = 0;
	}

	return (grid);
}
