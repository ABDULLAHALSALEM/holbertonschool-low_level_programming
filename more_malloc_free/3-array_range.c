/* 3-array_range.c */
#include "main.h"
#include <stdlib.h>

/**
 * array_range - creates an array of ints from min to max (inclusive)
 * @min: first value
 * @max: last value
 *
 * Return: pointer to the new array, or NULL on error (min > max / malloc)
 */
int *array_range(int min, int max)
{
	int *a;
	int len, i;

	if (min > max)
		return (NULL);

	len = max - min + 1;

	a = malloc(len * sizeof(*a));
	if (a == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		a[i] = min + i;

	return (a);
}
