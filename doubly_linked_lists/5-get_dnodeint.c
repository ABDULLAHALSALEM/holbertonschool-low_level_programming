#include "lists.h"

/**
 * get_dnodeint_at_index - returns the node at a given index in a DLL
 * @head: pointer to the head of the list (may be NULL)
 * @index: zero-based index of the node to return
 *
 * Return: pointer to the node at @index, or NULL if it doesn't exist
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i = 0;

	while (head != NULL && i < index)
	{
		head = head->next;
		i++;
	}

	/* if head is NULL here, index was out of range */
	return (head);
}
