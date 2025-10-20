#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * hash_table_set - Adds or updates a key/value in the hash table
 * @ht: Pointer to the hash table
 * @key: Non-empty string key
 * @value: String value to duplicate (can be empty string)
 *
 * Return: 1 on success, 0 on failure
 *
 * Steps:
 * 1) Validate inputs (ht, key not NULL/empty, value not NULL).
 * 2) Compute index via key_index(djb2).
 * 3) If key exists in the list, free old value and set new dup.
 * 4) Else create a new node, dup key and value, insert at head.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	hash_node_t *node, *cur;
	char *kdup, *vdup;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);
	cur = ht->array[idx];

	/* Update if key already exists */
	while (cur)
	{
		if (strcmp(cur->key, key) == 0)
		{
			vdup = strdup(value);
			if (vdup == NULL)
				return (0);
			free(cur->value);
			cur->value = vdup;
			return (1);
		}
		cur = cur->next;
	}

	/* Create new node and insert at head */
	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
		return (0);

	kdup = strdup(key);
	vdup = strdup(value);
	if (kdup == NULL || vdup == NULL)
	{
		free(node);
		free(kdup);
		free(vdup);
		return (0);
	}

	node->key = kdup;
	node->value = vdup;
	node->next = ht->array[idx];
	ht->array[idx] = node;

	return (1);
}
