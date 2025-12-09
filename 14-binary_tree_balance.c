#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Balance factor of the tree, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left = tree->left ? 1 + binary_tree_balance(tree->left) : 1;
	int right = tree->right ? 1 + binary_tree_balance(tree->right) : 1;

	if (!tree)
		return 0;

	return left - right;
}
