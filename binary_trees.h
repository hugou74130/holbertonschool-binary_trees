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

/* Déclarations de fonctions (à ajouter selon les tâches) */

/*

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

*/

#endif /* BINARY_TREES_H */
