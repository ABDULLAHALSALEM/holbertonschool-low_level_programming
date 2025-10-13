#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at a given index in a DLL
 * @head: address of pointer to the head of the list
 * @index: zero-based index of the node to delete
 *
 * Return: 1 on success, -1 on failure (invalid index or empty list)
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *node;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	/* delete the head */
	if (index == 0)
	{
		node = *head;
		*head = node->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(node);
		return (1);
	}

	/* walk to the node at `index` */
	node = *head;
	for (i = 0; node != NULL && i < index; i++)
		node = node->next;

	if (node == NULL) /* index is out of range */
		return (-1);

	/* relink neighbors around `node` */
	if (node->prev != NULL)
		node->prev->next = node->next;
	if (node->next != NULL)
		node->next->prev = node->prev;

	free(node);
	return (1);
}
