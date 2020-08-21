#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_node - function that adds a new node at the beginning of a list_t list.
 * @head:  pointer to last node created, or inic list
 * @n:  int to store to node
 * Return:  pointer to new element
 * On error, return NULL
 */

listint_t *add_node(listint_t **head, int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
	{
		printf("Error\n");
		return (NULL);
	}
	new->n = n;
	new->next = *head;
	*head = new;
	return (new);
}

/**
 * is_palindrome - function in C that checks if a singly linked list is
 *                 a palindrome.
 * @head:  head of a list
 * Return:  0 if it is not a palindrome, 1 if it is a palindrome
 * On error, return NULL
 */
int is_palindrome(listint_t **head)
{

	listint_t *temp;
	listint_t *temp2;
	listint_t *head2 = NULL;

	temp = *head;

	if (head == NULL || *head == NULL)
		return (1);

	while (temp != NULL)
	{
		add_node(&head2, temp->n);
		temp = temp->next;
	}

	temp2 = head2;
	temp = *head;

	while (temp != NULL)
	{
		if (temp->n != temp2->n)
		{
			free_listint(head2);
			return (0);
		}
		temp = temp->next;
		temp2 = temp2->next;
	}

	free_listint(head2);
	return (1);
}
