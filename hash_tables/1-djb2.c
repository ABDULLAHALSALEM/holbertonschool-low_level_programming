#include "hash_tables.h"

/**
 * hash_djb2 - Implements the djb2 hash algorithm
 * @str: Pointer to a null-terminated string
 *
 * Return: The computed hash as an unsigned long int
 *
 * Description:
 * Start from 5381, then for each character:
 * hash = hash * 33 + c. The multiply by 33 is written as
 * (hash << 5) + hash for speed.
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash = 5381;
	int c;

	if (str == NULL)
		return (0);

	while ((c = *str++))
		hash = ((hash << 5) + hash) + c;

	return (hash);
}
