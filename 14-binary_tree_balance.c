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
		return (0);
	
	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
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
    int balance;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_insert_left(root, 45);
    binary_tree_insert_right(root->left, 50);
    binary_tree_insert_left(root->left->left, 10);
    binary_tree_insert_left(root->left->left->left, 8);
    binary_tree_print(root);

    balance = binary_tree_balance(root);
    printf("Balance of %d: %+d\n", root->n, balance);
    balance = binary_tree_balance(root->right);
    printf("Balance of %d: %+d\n", root->right->n, balance);
    balance = binary_tree_balance(root->left->left->right);
    printf("Balance of %d: %+d\n", root->left->left->right->n, balance);
    return (0);
}
