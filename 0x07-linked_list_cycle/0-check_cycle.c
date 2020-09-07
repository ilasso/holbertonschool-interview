#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle  - check if list has a cycle
 * @list: pointer to head of list
 * Return: 1 if has cycle, 0 if doesnt have a cycle
 */
int check_cycle(listint_t *list)
{
	 listint_t *once;
	 listint_t *twice;

	once = list;
	twice = list;
	while (twice != NULL && once != NULL && twice->next)
	{
		twice = twice->next;
		twice = twice->next;
		once = once->next;
		if (twice == once)
			return (1);
	}
return (0);
}
