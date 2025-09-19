#ifndef DOG_H
#define DOG_H

/**
 * struct dog - basic info about a dog
 * @name: dog's name (string)
 * @age: dog's age
 * @owner: owner's name (string)
 *
 * Description: Defines a dog with a name, age and owner.
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

/* New alias for struct dog (Task 3) */
typedef struct dog dog_t;

/* Prototypes for previous tasks */
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);

#endif /* DOG_H */
