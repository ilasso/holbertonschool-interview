#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
/**
 *heap_insert - function that inserts a value into a Max Binary Heap
 *@root: is a double pointer to the root node of the Heap
 *@value: is the value store in the node to be inserted
 *Return: return a pointer to the inserted node, or NULL on failure
 *On Error: retur null
 */
heap_t  *heap_insert(heap_t **root, int value)
{	binary_tree_t *new_node = NULL;

	if (*root == NULL) /*insert new node if the heap is empty*/
	{	*root = binary_tree_node(NULL, value);
	new_node = *root; }
	else /* search for a proper insert point */
	{
		queue *q = get_a_queue(*root);
		queue *current_q = q;
		queue *last_q = q;
		binary_tree_t *current_node;

		while (current_q != NULL) /*get one node out of queue*/
		{	current_node = current_q->element;
			if (current_node->left == NULL)
			{	current_node->left =
				binary_tree_node(current_node, value);
				current_node = current_node->left;
			new_node = current_node; }
			else if (current_node->right == NULL)
			{	current_node->right =
				binary_tree_node(current_node, value);
				current_node = current_node->right;
			new_node = current_node; }
			else /*increment the current pointer*/
			{	queue_put(current_node, &last_q);
				current_q = current_q->next;
			continue; }
			/*put the node to proper point*/
			while (current_node->parent != NULL &&
				current_node->parent->n < current_node->n)
			{	/*swap the value*/
				int temp = current_node->parent->n;

				current_node->parent->n = current_node->n;
				current_node->n = temp;
			current_node = current_node->parent; }
		break; }
	free_queue(&q); }
	return (new_node);
}


/**
 *get_a_queue- function that create a queue element
 *@element: is a double pointer to the root node of the Heap
 *Return: return a pointer to the created element
 */

queue *get_a_queue(binary_tree_t *element)
{
	queue *q = malloc(sizeof(queue));

	q->next = NULL;
	q->element = element;
	return (q);
}

/**
 *queue_put- put nodes into queue
 *@n: value node to insert
 *@last: last element inserted
 *Return: void
 */

void queue_put(binary_tree_t *n, queue **last)
{
	if (n->left != NULL)
	{
		(*last)->next = get_a_queue(n->left);
		(*last) = (*last)->next;
	}
	if (n->right != NULL)
	{
		(*last)->next = get_a_queue(n->right);
		(*last) = (*last)->next;
	}
}

/**
 *free_queue- free queue
 *@q: pointer to queue
 *Return: void
 */
void free_queue(queue **q)
{
	queue *current_q = *q;

	while (current_q != NULL)
	{
		*q = current_q->next;
		free(current_q);
		current_q = *q;
	}
}
