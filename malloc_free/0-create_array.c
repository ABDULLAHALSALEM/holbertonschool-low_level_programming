/* 0-create_array.c */
#include "main.h"
#include <stdlib.h>

/**
 * create_array - creates an array of chars and fills it with a specific char
 * @size: number of elements to allocate
 * @c: the char to fill the array with
 *
 * Return: pointer to the new array, or NULL if size == 0 or malloc fails
 */
char *create_array(unsigned int size, char c)
{
	char *arr;
	unsigned int i;

	if (size == 0)
		return (NULL);

	arr = malloc(size * sizeof(*arr));
	if (arr == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		arr[i] = c;

	return (arr);
}
