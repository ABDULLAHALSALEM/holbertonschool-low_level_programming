#include "lists.h"

/**
 * sum_dlistint - computes the sum of all `n` values in a dlistint_t list
 * @head: pointer to the head node of the list (may be NULL)
 *
 * Return: the sum of all node values; 0 if the list is empty
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
