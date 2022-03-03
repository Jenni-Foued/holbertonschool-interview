#include "binary_trees.h"

/**
 * check_branch_node - check if a branch of the tree is also a bst.
 *
 * @node: node of the tree.
 * @all_right: 1 if the branch is a bst otherwise -1.
 * @m: value in the root node.
 * @side: -1 to check a left branch, 1 to check a right branch
 */

void check_branch_node(binary_tree_t *node, int *all_right, int m, int side)
{
	if (node == NULL || *all_right == -1)
		return;

	if (side == 1)
	{
		if (node->n <= m)
		{
			*all_right = -1;
			return;
		}
		if (node->left != NULL)
			check_branch_node(node->left, all_right, m, 1);

		if (node->right != NULL)
			check_branch_node(node->right, all_right, m, 1);
	}
	else if (side == -1)
	{
		if (node->n >= m)
		{
			*all_right = -1;
			return;
		}

		if (node->left != NULL)
			check_branch_node(node->left, all_right, m, -1);

		if (node->right != NULL)
			check_branch_node(node->right, all_right, m, -1);
	}
}

/**
 * height - function for obtain the height of a binary tree.
 *
 * @tree: pointer to the root node of the tree to measure the height.
 * @ptr_height: pointer to height variable.
 * @value: height of current branch.
 */

void height(const binary_tree_t *tree, int *ptr_height, int value)
{
	if (*ptr_height < value)
		*ptr_height = value;

	if (tree->left != NULL)
		height(tree->left, ptr_height, value + 1);

	if (tree->right != NULL)
		height(tree->right, ptr_height, value + 1);
}

/**
 * binary_tree_balance - function that measures the
 * balance factor of a binary tree
 *
 * @tree: pointer to the root node of the tree to
 * measure the balance factor
 *
 * Return: the balance factor
 * (diference between the left and the right subtrees height)
 * If tree is NULL, return 0
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int height_left = 0;
	int height_right = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
	{
		height_left++;
		height(tree->left, &height_left, 1);
	}
	if (tree->right)
	{
		height_right++;
		height(tree->right, &height_right, 1);
	}

	return (height_left - height_right);
}

/**
 * check_balance_and_bst - check balance for every subtree
 *
 * @tree: tree
 * @all_right: flag to detect when a subtree
 *
 * has balance is more than one
 */

void check_balance_and_bst(const binary_tree_t *tree, int *all_right)
{
	int balance;

	if (tree == NULL || *all_right == -1)
		return;

	balance = binary_tree_balance(tree);
	if (balance < -1 || balance > 1)
	{
		*all_right = -1;
		return;
	}
	/* */
	check_branch_node(tree->right, all_right, tree->n, 1);
	if (*all_right != 1)
		return;

	check_branch_node(tree->left, all_right, tree->n, -1);
	if (*all_right != 1)
		return;

	/* */
	if (tree->left != NULL)
		check_balance_and_bst(tree->left, all_right);

	if (*all_right == -1)
		return;

	if (tree->right != NULL)
		check_balance_and_bst(tree->right, all_right);
}

/**
 * binary_tree_is_avl - function that checks if a binary tree is
 * a valid AVL Tree
 *
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 * f tree is NULL, return 0
 * Properties of an AVL Tree:
 * - An AVL Tree is a BST
 * - The difference between heights of left and
 * right subtrees cannot be more than one
 * - The left and right subtree each must also be a binary search tree
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int all_right = 1;

	if (tree == NULL)
		return (0);

	check_balance_and_bst(tree, &all_right);

	if (all_right != 1)
		return (0);

	return (1);
}
