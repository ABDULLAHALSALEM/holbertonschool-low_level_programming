#include <stdlib.h>
#include "lists.h"

/**
 * free_dlistint - frees a dlistint_t doubly linked list
 * @head: pointer to the head node of the list
 *
 * Description: iterates through the list and frees each node.
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *tmp;

	while (head != NULL)
	{
		tmp = head->next; /* احفظ التالي قبل التحرير */
		free(head);
		head = tmp;
	}
}
