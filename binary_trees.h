#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct binary_tree_s - Nœud d'arbre binaire
 *
 * @n: Entier stocké dans le nœud
 * @parent: Pointeur vers le nœud parent
 * @left: Pointeur vers le nœud enfant gauche
 * @right: Pointeur vers le nœud enfant droit
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);

void binary_tree_delete(binary_tree_t *tree);
int binary_tree_is_leaf(const binary_tree_t *node);
int binary_tree_is_root(const binary_tree_t *node);
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
size_t binary_tree_height(const binary_tree_t *tree);
size_t binary_tree_depth(const binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);
size_t binary_tree_leaves(const binary_tree_t *tree);
size_t binary_tree_nodes(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);

/* Déclarations de fonctions (à ajouter selon les tâches) */

/*

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

*/

#endif /* BINARY_TREES_H */
