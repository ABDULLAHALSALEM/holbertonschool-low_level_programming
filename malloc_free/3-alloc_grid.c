/* 3-alloc_grid.c */
#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - allocates a 2D grid of ints (height x width) filled with 0
 * @width: number of columns
 * @height: number of rows
 *
 * Return: pointer to the grid (int **), or NULL on failure/invalid size
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int r, c;

	if (width <= 0 || height <= 0)
		return (NULL);

	/* اطلب مؤشرات الصفوف */
	grid = malloc(height * sizeof(*grid));
	if (grid == NULL)
		return (NULL);

	/* اطلب كل صف على حدة */
	for (r = 0; r < height; r++)
	{
		grid[r] = malloc(width * sizeof(**grid));
		if (grid[r] == NULL)
		{
			/* فشل: حرر كل ما سبق ثم حرر المؤشر الرئيسي */
			while (r--)
				free(grid[r]);
			free(grid);
			return (NULL);
		}

		/* صفّر الخلايا */
		for (c = 0; c < width; c++)
			grid[r][c] = 0;
	}

	return (grid);
}
