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
    if (!tree)
        return;

    int stack_i = 0;
    const binary_tree_t *stack[2048];
    int depth[2048];

    stack[0] = tree;
    depth[0] = 0;
    stack_i = 1;

    while (stack_i > 0)
    {
        stack_i--;
        const binary_tree_t *node = stack[stack_i];
        int d = depth[stack_i];

        if (d == 0)
            printf("%d\n", node->n);
        else
        {
            int len = d * 4;
            for (int i = 0; i < len; i++)
                putchar('-');
            printf(". %d\n", node->n);
        }

        if (node->right)
        {
            stack[stack_i] = node->right;
            depth[stack_i] = d + 1;
            stack_i++;
        }
        if (node->left)
        {
            stack[stack_i] = node->left;
            depth[stack_i] = d + 1;
            stack_i++;
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
