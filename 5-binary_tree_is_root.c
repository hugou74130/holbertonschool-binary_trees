#include "binary_trees.h" /* Inclusion du fichier d'en-tête contenant les définitions des structures et prototypes */

/**
 * binary_tree_is_root - Checks if a node is a root
 * @node: Pointer to the node to check
 *
 * Description: A root is a node with no parent. Returns 1 if node is a root,
 * 0 otherwise. Returns 0 if node is NULL.
 *
 * Return: 1 if node is a root, 0 otherwise
 */
int binary_tree_is_root(const binary_tree_t *node)
{ /* Début de la fonction qui prend en paramètre un pointeur constant vers un nœud */
	if (node == NULL) /* Vérification si le pointeur node est NULL */
		return (0); /* Si node est NULL, ce n'est pas une racine, on retourne 0 (faux) */

	if (node->parent == NULL) /* Vérification si le nœud n'a pas de parent */
		return (1); /* Si le parent est NULL, c'est une racine, on retourne 1 (vrai) */
	else /* Sinon, le nœud a un parent */
		return (0); /* Ce n'est pas une racine, on retourne 0 (faux) */
}