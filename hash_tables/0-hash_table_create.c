#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_table_create - Creates a new hash table
 * @size: The size of the array inside the table
 *
 * Return: Pointer to the newly created hash table, or NULL on failure
 *
 * Steps:
 * 1) Validate size.
 * 2) Malloc the table struct.
 * 3) Malloc the array of pointers (size elements).
 * 4) Initialize each array cell to NULL.
 * 5) Store size and return the table pointer.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;
	unsigned long int i;

	if (size == 0)
		return (NULL);

	ht = malloc(sizeof(hash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->array = malloc(sizeof(hash_node_t *) * size);
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	ht->size = size;

	return (ht);
}
