#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node
 *
 * @parent: Pointer to the parent node of the node
 * to create
 * @value: The value to insert in the new node
 *
 * Return: Pointer to the created node or
 * NULL if the function fails
 **/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);
	node->left = NULL;
	node->right = NULL;
	node->parent = parent;
	node->n = value;
	return (node);
}

/**
 * array_to_avl_rec - builds an AVL tree from an array
 *
 * @array: The array to be printed
 * @parent: A pointer to the parent node of the node to create
 * @start: Index of the first element
 * @end: Index of the last element
 *
 * Return: binary tree on success, NULL on failure
 */
avl_t *array_to_avl_rec(int *array, size_t start, size_t end,
						avl_t *parent)
{
	size_t mid;
	avl_t *root;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	root = binary_tree_node(parent, array[mid]);
	if (!root)
		return (NULL);

	if (mid != start)
		root->left = array_to_avl_rec(array, start, mid - 1, root);

	if (mid != end)
		root->right = array_to_avl_rec(array, mid + 1, end, root);

	return (root);
}

/**
 * sorted_array_to_avl -  builds an AVL tree from an array
 *
 * @array: Sorted array to be used
 * @size: Array size
 * Return: Pointer to the root node of the created AVL tree
 * or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;

	if (!array || !size)
		return (NULL);

	root = array_to_avl_rec(array, 0, size - 1, NULL);
	return (root);
}
