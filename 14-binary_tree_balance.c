#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Balance factor of the tree, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return 0;

	int left_height = 0;
	int right_height = 0;

	if (tree->left)
	{
		int h = 1 + binary_tree_balance(tree->left);
		left_height = (h > left_height) ? h : left_height;
	}

	if (tree->right)
	{
		int h = 1 + binary_tree_balance(tree->right);
		right_height = (h > right_height) ? h : right_height;
	}

	return left_height - right_height;
}
