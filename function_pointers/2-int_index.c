#include "function_pointers.h"

/**
 * int_index - finds index of first element that matches a condition
 * @array: pointer to the array of integers
 * @size: number of elements in the array
 * @cmp: pointer to a function that takes an int and returns non-zero
 *       when the element matches the condition
 *
 * Return: index of first matching element, or -1 on failure/no match
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || cmp == NULL || size <= 0)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (i);
	}
	return (-1);
}
