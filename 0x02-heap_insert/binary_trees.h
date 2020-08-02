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

typedef struct binary_tree_s binary_tree_t;

/**
 * struct queue- queue to temporary process
 *
 * @next: next element of a queue
 * @element: Pointer to the node in the binary tree
 */
typedef struct queue
{
	struct queue *next;
	binary_tree_t *element;
} queue;

void binary_tree_print(const binary_tree_t *);

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

queue *get_a_queue(binary_tree_t *element);
void free_queue(queue **q);
void queue_put(binary_tree_t *n, queue **last);
/*void heap_insert(binary_tree_t** root, int x);*/
heap_t *heap_insert(heap_t **root, int value);

#endif /*BTREE*/
