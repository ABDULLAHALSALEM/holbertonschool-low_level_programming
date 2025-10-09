#include <stdlib.h>
#include "lists.h"

/**
 * free_list - frees a list_t linked list
 * @head: pointer to the first node
 *
 * Description:
 * Walks the list node by node, frees each node->str (if any),
 * then frees the node itself. Safe for empty lists.
 */
void free_list(list_t *head)
{
	list_t *next;

	while (head != NULL)
	{
		next = head->next; /* keep where to go next */
		free(head->str);   /* strdup'ed earlier, so free it */
		free(head);        /* free the node itself */
		head = next;       /* move on */
	}
}
