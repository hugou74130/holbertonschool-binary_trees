#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

void binary_tree_print(const binary_tree_t *tree)
{
    int h = 0, i, j;
    const binary_tree_t *stack[1024];
    int level[1024], top = -1;

    if (!tree)
        return;

    stack[++top] = tree;
    level[top] = 0;

    while (top >= 0)
    {
        const binary_tree_t *node = stack[top];
        int l = level[top--];

        for (j = 0; j < l; j++)
            printf("│   ");

        if (l == 0)
            printf("Root: %d\n", node->n);
        else
            printf("├── %d\n", node->n);

        if (node->right)
        {
            stack[++top] = node->right;
            level[top] = l + 1;
        }
        if (node->left)
        {
            stack[++top] = node->left;
            level[top] = l + 1;
        }
    }
}

int main(void)
{
    binary_tree_t *root;
    size_t leaves;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);

    leaves = binary_tree_leaves(root);
    printf("Leaves in %d: %lu\n", root->n, leaves);
    leaves = binary_tree_leaves(root->right);
    printf("Leaves in %d: %lu\n", root->right->n, leaves);
    leaves = binary_tree_leaves(root->left->right);
    printf("Leaves in %d: %lu\n", root->left->right->n, leaves);
    return (0);
}
