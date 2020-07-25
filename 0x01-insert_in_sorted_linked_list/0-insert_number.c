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
	listint_t *p;
	listint_t *new;
	listint_t *current;
	int count = 0;

	p = *head;

	if (head == NULL)
		return (NULL);
	new = new_node(number);
	if (new == NULL)
		return (NULL);
	if (p == NULL) /* empty list*/
	{	new->n = number;
		*head = new;
		return (new); }
	if (p->next == NULL) /* if there is only a node*/
	{
		if (number >= p->n)
		{	p->next = new;
			return (new); }
		new->next = p;
		*head = new;
		return (new); }
	while (p != NULL && p->n < number)
	{	current = p; /*search to insert node */
		p = p->next;
		count++; }
	if (current->next == NULL)
	{	current->next = new; /* final of a list*/
		return (new); }
	if ((p->n > number) && (p->next != NULL) && (count == 0))
	{	new->next = p; /* new node its > firts node of a list */
		*head = new;
		return (new); }
	if (p->next != NULL) /* if not is the last node of a list */
	{	new->next = current->next;
		current->next = new;
		return (new); }
return (NULL);
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

