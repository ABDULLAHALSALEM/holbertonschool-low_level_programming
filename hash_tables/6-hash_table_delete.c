#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_table_delete - Delete a hash table and free all memory
 * @ht: Pointer to the hash table
 *
 * Description: Frees every node (key, value, node), then frees the
 * array and the table structure itself. If @ht is NULL, do nothing.
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *node, *next;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node)
		{
			next = node->next;
			free(node->key);
			free(node->value);
			free(node);
			node = next;
		}
	}
	free(ht->array);
	free(ht);
}
