#ifndef BTREE
#define BTREE

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};


typedef struct binary_tree_s heap_t;

void binary_tree_print(const heap_t *);

heap_t *binary_tree_node(heap_t *parent, int value);
#endif /*BTREE*/
