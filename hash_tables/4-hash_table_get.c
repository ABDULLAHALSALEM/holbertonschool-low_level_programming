#include <string.h>
#include "hash_tables.h"

/**
 * hash_table_get - Retrieve the value associated with a key
 * @ht: Pointer to the hash table
 * @key: Key to look for (must not be empty)
 *
 * Return: Pointer to the value if found, otherwise NULL
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int idx;
	hash_node_t *node;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	idx = key_index((const unsigned char *)key, ht->size);

	for (node = ht->array[idx]; node; node = node->next)
		if (strcmp(node->key, key) == 0)
			return (node->value);

	return (NULL);
}
