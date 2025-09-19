#include "dog.h"
#include <stdlib.h>

/**
 * free_dog - frees memory allocated for a dog_t
 * @d: pointer to the dog to free
 *
 * Description:
 * Frees name, owner, then the struct itself.
 * If d is NULL, does nothing.
 */
void free_dog(dog_t *d)
{
	if (d == NULL)
		return;

	free(d->name);
	free(d->owner);
	free(d);
}
