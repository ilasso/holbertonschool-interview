#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * insert_node  - adds a new node in a sorted single list
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *p, *new, *current;
	int count = 0;

	p = *head;
	new = new_node(number);
	if (new == NULL)
		return (NULL);
	if (p == NULL) /* empty list*/
	{	new->n = number;
		*head = new;
		p = *head;
		return (new); }
	if (p->next == NULL) /* if there is only a node*/
	{
		if (number >= p->n)
		{	p->next = new;
			return (new); }
		new->next = p;
		*head = new;
		p = *head;
		return (new); }
	while (p->next != NULL && p->n < number)
	{	current = p; /*search to insert node */
		p = p->next;
		count++; }
	if (p->next == NULL)
	{
		if (p->n > new->n)
		{	current->next = new; /* final of a list*/
			new->next = p;
			p->next = NULL; }
		current->next = p;
		p->next = new;
		new->next = NULL;
		return (new);
	}
	current->next = new;
	new->next = p;
	return (new);
}
/**
 * new_node  - alloc a new node in memory
 * @number: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */
listint_t *new_node(int number)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	new->next = NULL;
	return (new);
}

