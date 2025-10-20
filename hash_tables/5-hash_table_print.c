#include <stdio.h>
#include "hash_tables.h"

/**
 * hash_table_print - Print a hash table in dictionary format
 * @ht: Pointer to the hash table
 *
 * Description: Prints pairs as: {'key': 'value', ...}
 * Order is by array index, then by node order within each list.
 * If @ht is NULL, nothing is printed.
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *node;
	int printed = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		for (node = ht->array[i]; node; node = node->next)
		{
			if (printed)
				printf(", ");
			printf("'%s': '%s'", node->key, node->value);
			printed = 1;
		}
	}
	printf("}\n");
}
