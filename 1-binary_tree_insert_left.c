#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node
 * @parent: pointer to the node to insert the left-child in
 * @value: value to store in the new node
 *
 * Description: This function creates a new node with the given value and
 * inserts it as the left-child of the parent node. If the parent already
 * has a left-child, the new node takes its place, and the old left-child
 * becomes the left-child of the new node.
 *
 * Return: pointer to the created node,
 * or NULL if parent is NULL or malloc fails
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		new_node->left = parent->left;
		parent->left->parent = new_node;
	}

	parent->left = new_node;

	return (new_node);
}
