#include "dog.h"
#include <stddef.h> /* for NULL */

/**
 * init_dog - initialize a variable of type struct dog
 * @d: pointer to the dog to initialize
 * @name: dog's name
 * @age: dog's age
 * @owner: owner's name
 *
 * Description: If d is NULL, do nothing (avoid dereferencing NULL).
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		return;

	d->name = name;
	d->age = age;
	d->owner = owner;
}
