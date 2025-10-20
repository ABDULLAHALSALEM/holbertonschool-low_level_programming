#include <stdlib.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - Check the code for hash_table_create
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
	hash_table_t *ht;

	ht = hash_table_create(1024);
	printf("%p\n", (void *)ht);

	return (EXIT_SUCCESS);
}
