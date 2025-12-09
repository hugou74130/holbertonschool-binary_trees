#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Description: Calculates the height of the tree. The height is the number
 * of edges from the deepest leaf to the root. Returns 0 if tree is NULL.
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height;
	size_t right_height;

	if (tree == NULL)

		return (0);

	if (tree->left == NULL && tree->right == NULL)

		left_height = binary_tree_height(tree->left);
	right_height = binary_tree_heigh(tree->right);
	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}
