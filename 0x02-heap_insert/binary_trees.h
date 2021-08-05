#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_
#include <stdlib.h>

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

/* Functions */
void binary_tree_print(const heap_t *);
heap_t *binary_tree_node(heap_t *parent, int value);

#endif /* _BINARY_TREES_H_ */
