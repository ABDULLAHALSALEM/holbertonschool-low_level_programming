#include "lists.h"

/**
 * print_list - prints all elements of a list_t list
 * @h: pointer to the first node (head)
 *
 * Return: number of nodes printed
 *
 * Format per requirement:
 * - If h->str is NULL, print "[0] (nil)"
 * - Else print "[len] str"
 */
size_t print_list(const list_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", h->len, h->str);

		h = h->next;
		count++;
	}
	return (count);
}
