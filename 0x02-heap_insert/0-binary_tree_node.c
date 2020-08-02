#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
/**
 *binary_tree_node - create a node in a binary tree
 *@parent: pointer to parent of node to create
 *@value: value int to the node
 *Return: pointer to new node
 *On Error: retur null
 */

heap_t *binary_tree_node(heap_t *parent, int value)
{

	heap_t *newnode;

	(void) (*newnode);
	(void) (value);

	newnode = malloc(sizeof(heap_t));
	if (newnode == NULL)
		return (NULL);

	newnode->n = value;
	newnode->parent = parent;
	newnode->left = NULL;
	newnode->right = NULL;

	return (newnode);

}
