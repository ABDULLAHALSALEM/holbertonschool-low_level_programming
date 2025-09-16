/* 2-calloc.c */
#include "main.h"
#include <stdlib.h>
#include <limits.h>

/**
 * _calloc - allocates zero-initialized memory for an array
 * @nmemb: number of elements
 * @size: size in bytes of each element
 *
 * Return: pointer to zeroed memory, or NULL on error/overflow
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;
	unsigned int i, total;
	unsigned char *bytes;

	if (nmemb == 0 || size == 0)
		return (NULL);

	/* overflow guard: nmemb * size must fit in unsigned int */
	if (size != 0 && nmemb > UINT_MAX / size)
		return (NULL);

	total = nmemb * size;

	ptr = malloc(total);
	if (ptr == NULL)
		return (NULL);

	/* manual zeroing (no memset allowed in project constraints) */
	bytes = (unsigned char *)ptr;
	for (i = 0; i < total; i++)
		bytes[i] = 0;

	return (ptr);
}
