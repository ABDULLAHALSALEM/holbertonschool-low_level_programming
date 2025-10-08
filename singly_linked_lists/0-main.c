#include <stdlib.h>
#include <string.h>
#include "lists.h"

int main(void)
{
	list_t hello = {"World", 5, NULL};
	list_t *head = &hello;
	list_t *new = malloc(sizeof(*new));
	size_t n;

	if (!new)
		return (1);

	new->str = strdup("Hello");
	new->len = 5;
	new->next = head;
	head = new;

	n = print_list(head);
	printf("-> %lu elements\n", (unsigned long)n);

	printf("\n");
	free(new->str);
	new->str = NULL; /* جرّب حالة (nil) */
	n = print_list(head);
	printf("-> %lu elements\n", (unsigned long)n);

	free(new);
	return (0);
}
