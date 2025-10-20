#include "hash_tables.h"

/**
 * key_index - Computes the index of a key in a hash table array
 * @key: The key (string), must be a null-terminated string
 * @size: The size of the array of the hash table
 *
 * Return: The index at which the key/value pair should be stored
 *
 * Note: Uses djb2 hash, then maps it to [0, size - 1] via modulo.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
