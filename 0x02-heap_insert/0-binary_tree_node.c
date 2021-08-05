#include"binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 *
 * @parent: a pointer to the parent node of the node to create
 * @value: a pointer to the parent node of the node to create
 *
 * Return: a pointer to the new node, or NULL on failure
 */
heap_t *binary_tree_node(heap_t *parent, int value)
{
	heap_t *node;

	node = malloc(sizeof(heap_t));
	if (node == NULL)
		return (NULL);
	node->left = NULL;
	node->right = NULL;
	node->parent = parent;
	node->n = value;
	return (node);
}
