#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * make_node - Allocate and fill a new hash node
 * @key: key string (non-empty)
 * @value: value string
 *
 * Return: pointer to node on success, NULL on failure
 */
static hash_node_t *make_node(const char *key, const char *value)
{
	hash_node_t *node;
	char *kdup, *vdup;

	node = malloc(sizeof(*node));
	if (node == NULL)
		return (NULL);

	kdup = strdup(key);
	vdup = strdup(value);
	if (kdup == NULL || vdup == NULL)
	{
		free(node);
		free(kdup);
		free(vdup);
		return (NULL);
	}

	node->key = kdup;
	node->value = vdup;
	node->next = NULL;
	return (node);
}

/**
 * hash_table_set - Add or update a key/value in a hash table
 * @ht: hash table
 * @key: key string (must not be empty)
 * @value: value string (duplicated)
 *
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	hash_node_t *cur, *node;
	char *vdup;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);

	/* update existing key */
	for (cur = ht->array[idx]; cur; cur = cur->next)
		if (strcmp(cur->key, key) == 0)
		{
			vdup = strdup(value);
			if (vdup == NULL)
				return (0);
			free(cur->value);
			cur->value = vdup;
			return (1);
		}

	/* insert new node at head */
	node = make_node(key, value);
	if (node == NULL)
		return (0);
	node->next = ht->array[idx];
	ht->array[idx] = node;
	return (1);
}
