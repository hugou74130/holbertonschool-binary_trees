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

/* Déclarations de fonctions (à ajouter selon les tâches) */

#endif /* BINARY_TREES_H */
