#include "dog.h"
#include <stdlib.h>

/**
 * _strlen - returns length of a string
 * @s: string
 * Return: length (number of characters before '\0')
 */
static int _strlen(const char *s)
{
	int i = 0;

	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * _strcpy - copies string from src to dest (including '\0')
 * @dest: destination buffer
 * @src: source string
 * Return: dest
 */
static char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	if (src == NULL)
	{
		dest[0] = '\0';
		return (dest);
	}
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * new_dog - creates a new dog, copying name and owner
 * @name: dog's name
 * @age: dog's age
 * @owner: owner's name
 *
 * Return: pointer to new dog_t on success, or NULL on failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;
	int ln, lo;

	if (name == NULL || owner == NULL)
		return (NULL);

	d = malloc(sizeof(*d));
	if (d == NULL)
		return (NULL);

	ln = _strlen(name);
	lo = _strlen(owner);

	d->name = malloc(ln + 1);
	if (d->name == NULL)
	{
		free(d);
		return (NULL);
	}

	d->owner = malloc(lo + 1);
	if (d->owner == NULL)
	{
		free(d->name);
		free(d);
		return (NULL);
	}

	_strcpy(d->name, name);
	_strcpy(d->owner, owner);
	d->age = age;

	return (d);
}
