#include <stdlib.h>
#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position in a DLL
 * @h: address of pointer to the head of the list
 * @idx: zero-based index where the new node should be inserted
 * @n: value to store in the new node
 *
 * Return: address of the new node, or NULL if it failed or index is invalid
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *curr, *new_node;
	unsigned int i;

	if (h == NULL)
		return (NULL);

	if (idx == 0)
		return (add_dnodeint(h, n)); /* insert at beginning */

	curr = *h;
	for (i = 0; curr != NULL && i < idx - 1; i++)
		curr = curr->next;

	if (curr == NULL)
		return (NULL); /* idx is past the end (cannot insert) */

	if (curr->next == NULL)
		return (add_dnodeint_end(h, n)); /* inserting exactly at the end */

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = curr;
	new_node->next = curr->next;
	curr->next->prev = new_node;
	curr->next = new_node;

	return (new_node);
}
