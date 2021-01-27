#include "lists.h"

/**
* find_listint_loop - checks if a linked list has a cycle
* @head: pointer to a linked list
*
* Return: NULL if false or
* the pointer to the head of the loop
**/
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tortuga = head;
	listint_t *rabbit = head;

	if (!head)
		return (NULL);
	while (tortuga->next && rabbit->next->next)
	{
		tortuga = tortuga->next;
		rabbit = rabbit->next->next;
		if (tortuga == rabbit)
		{
			tortuga = head;
			while (tortuga != rabbit)
			{
				tortuga = tortuga->next;
				rabbit = rabbit->next;
			}
			return (rabbit);
		}
	}
	return (NULL);
}
