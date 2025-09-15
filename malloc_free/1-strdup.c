/* 1-strdup.c */
#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated string duplicate of @str
 * @str: source C-string to duplicate
 *
 * Return: pointer to the new duplicated string,
 *         or NULL if str is NULL or if malloc fails
 */
char *_strdup(char *str)
{
    char *dup;
    unsigned int len = 0, i;

    if (str == NULL)
        return (NULL);

    while (str[len] != '\0')
        len++;

    dup = malloc((len + 1) * sizeof(*dup));
    if (dup == NULL)
        return (NULL);

    for (i = 0; i <= len; i++)
        dup[i] = str[i];

    return (dup);
}
