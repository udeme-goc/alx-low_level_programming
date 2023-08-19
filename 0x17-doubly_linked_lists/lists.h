#ifndef LISTS_H
#define LISTS_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct dlistint_s - doubly linked list
 * @n: integer
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: doubly linked list node structure
 */

typedef struct dlistint_s
{
    int n;
    struct dlistint_s *prev;
    struct dlistint_s *next;
} dlistint_t;

/* Function prototypes */

/* Task 0: Prints all the elements of a dlistint_t list */
size_t print_dlistint(const dlistint_t *h);

/* Task 1: Adds a new node at the beginning of a dlistint_t list */
dlistint_t *add_dnodeint(dlistint_t **head, const int n);

/* Task 2: Adds a new node at the end of a dlistint_t list */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n);

/* Task 3: Frees a dlistint_t list */
void free_dlistint(dlistint_t *head);

/* Task 4: Returns the sum of all the data (n) of a dlistint_t list */
int sum_dlistint(dlistint_t *head);

/* Task 5: Inserts a new node at a given position */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n);

/* Task 6: Deletes the node at index index of a dlistint_t linked list */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index);

size_t dlistint_len(const dlistint_t *h);

#endif /* LISTS_H */

