#ifndef DOG_H
#define DOG_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct dog - A type describing a dog
 *
 * @name: Pointer to a character array representing the dog's name
 * @age: Float representing the dog's age
 * @owner: Pointer to a character array representing the dog's owner
 *
 * Description: header file.
 */

struct dog
{
	char *name;
	float age;
	char *owner;
};
/**
 * dog_t - go around for function error
 *
 */
typedef struct dog dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);

#endif
