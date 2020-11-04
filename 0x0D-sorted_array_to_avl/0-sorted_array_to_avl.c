#include "binary_trees.h"

/**
 * create_node - create binary tree node
 * @n: value of node
 * @par: pointer to parent node
 *
 * Return: newly created node
 */
avl_t *create_node(int n, avl_t *par)
{
	avl_t *new = malloc(sizeof(*new));

	if (!new)
		return (NULL);
	new->n = n;
	new->parent = par;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

/**
 * processArray - process array with a  binary search and create nodes
 * @root: pointer to root node
 * @par: pointer to parent node
 * @ar: array of node values
 * @middle: middle index
 * @left: left index
 * @right: right index
 * @dir: specifies direction of child node to create, can be 'l' or  'r'
 *
 * Return: final created node, NULL on malloc failure
 */
avl_t *processArray(avl_t **root, avl_t *par, int *ar, int middle,
	int left, int right, char dir)
{
	if (left > right)
		return (par);
	middle = (left + right) / 2;
	if (dir == 'l')
		par = par->left = create_node(ar[middle], par);
	else if (dir == 'r')
		par = par->right = create_node(ar[middle], par);
	else
		par = *root = create_node(ar[middle], *root);
	if (!par)
	{
		*root = NULL;
		return (*root);
	}
	processArray(root, par, ar, middle, left, middle - 1, 'l');
	processArray(root, par, ar, middle, middle + 1, right, 'r');
	return (par);
}

/**
 * sorted_array_to_avl - function that builds an AVL tree from an array
 * @array:  is a pointer to the first element of the array to be converted
 * @size: is the number of element in the array
 *
 * Return: return a pointer to the root node of the created AVL tree,
 * or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL, *node = NULL;

	processArray(&root, node, array, (0 + size - 1) / 2, 0, size - 1, '\0');
	return (root);
}
