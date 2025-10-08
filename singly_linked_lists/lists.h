#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>  /* size_t */
#include <stdio.h>   /* printf */

/**
 * struct list_s - singly linked list node
 * @str: string (may be NULL)
 * @len: string length
 * @next: pointer to the next node
 *
 * Description: node type for singly linked list project
 */
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

/* Prototypes */
size_t print_list(const list_t *h);

#endif /* LISTS_H */
