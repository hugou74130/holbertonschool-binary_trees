#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Balance factor of the tree, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return 0;

	if (tree->left || tree->right)
	{
		if (tree->left && tree->right)
			return (1 + binary_tree_balance(tree->left) - (1 + binary_tree_balance(tree->right)));
		if (tree->left)
			return (1 + binary_tree_balance(tree->left));
		if (tree->right)
			return (-1 - binary_tree_balance(tree->right));
	}

	return (0);
}
