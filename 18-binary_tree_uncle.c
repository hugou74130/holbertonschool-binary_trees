#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: Pointer to the node of the tree
 *
 * Return: The pointer to the sibling node, or 0 if tree is NULL,
 * or NULL if node is NULL or if no uncle
 *
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent, *grandparent;

	if (!node || !node->parent)
		return NULL;

	parent = node->parent;
	grandparent = parent->parent;

	if (!grandparent)
		return NULL;

	/* retourner le frère du parent */
	if (grandparent->left == parent)
		return grandparent->right;
	else
		return grandparent->left;
}
