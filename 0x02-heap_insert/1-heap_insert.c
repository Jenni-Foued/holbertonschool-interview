#include "binary_trees.h"

/**
 * binary_tree_is_leaf - a function that checks if a node is a leaf
 *
 * @node: a pointer to the node to check
 *
 * Return: 1 if node is a leaf, otherwise 0 (including node is NULL)
 */
int binary_tree_is_leaf(const heap_t *node)
{
	if (node)
	{
		if (!(node->left) && !(node->right))
			return (1);
	}
	return (0);
}

/**
 * heap_insert - inserts a value into a Max Binary Heap
 *
 * @root: a double pointer to the root node of the Heap
 * @value: the value to store in the node to be inserted
 *
 * Return: a pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;

	if (root == NULL)
		return (NULL);
	if ((*root) == NULL)
	{
		new_node = binary_tree_node(NULL, value);
	}

	if (binary_tree_is_leaf(*root))
	{
		new_node = binary_tree_node(*root, value);
	}

	return (new_node);
}
