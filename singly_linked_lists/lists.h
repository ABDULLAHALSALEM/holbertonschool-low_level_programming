#ifndef LISTS_H
#define LISTS_H

#include <stddef.h> /* size_t */

/**
 * struct list_s - singly linked list node
 * @str: string (may be NULL)
 * @len: length of the string
 * @next: pointer to the next node
 *
 * Description: node type for singly linked list project.
 */
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

/* Prototypes */
size_t print_list(const list_t *h);
size_t list_len(const list_t *h);
list_t *add_node(list_t **head, const char *str);
list_t *add_node_end(list_t **head, const char *str);

#endif /* LISTS_H */
