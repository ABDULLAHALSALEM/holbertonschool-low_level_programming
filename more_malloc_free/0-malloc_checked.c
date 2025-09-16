/* 0-malloc_checked.c */
#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked - allocate memory and exit with 98 on failure
 * @b: number of bytes to allocate
 *
 * Return: pointer to allocated memory (never NULL).
 *         On failure, the process terminates with status 98.
 */
void *malloc_checked(unsigned int b)
{
	void *p;

	p = malloc(b);
	if (p == NULL)
		exit(98);

	return (p);
}
