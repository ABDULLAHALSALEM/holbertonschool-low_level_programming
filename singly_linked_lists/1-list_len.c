#include "lists.h"

/**
 * list_len - returns the number of elements in a list_t list
 * @h: pointer to the first node (head)
 *
 * Return: number of nodes in the list
 */
size_t list_len(const list_t *h)
{
	size_t n = 0;

	while (h != NULL)
	{
		n++;
		h = h->next;
	}
	return (n);
}
