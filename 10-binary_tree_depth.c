#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 *
 * Return: Depth of the node, or 0 if tree is NULL
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->parent == NULL)
		return (0);

	return (1 + binary_tree_depth(tree->parent));
}

int main(void)
{
    binary_tree_t *root;
    size_t depth;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);

    depth = binary_tree_depth(root);
    printf("Depth of %d: %lu\n", root->n, depth);
    depth = binary_tree_depth(root->right);
    printf("Depth of %d: %lu\n", root->right->n, depth);
    depth = binary_tree_depth(root->left->right);
    printf("Depth of %d: %lu\n", root->left->right->n, depth);
    return (0);
}
