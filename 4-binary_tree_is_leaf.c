#include "binary_trees.h" /* Inclusion du fichier d'en-tête contenant les définitions des structures et prototypes */

/**
 * binary_tree_is_leaf - Checks if a node is a leaf
 * @node: Pointer to the node to check
 *
 * Description: A leaf is a node with no left-child and no right-child.
 * Returns 1 if node is a leaf, 0 otherwise. Returns 0 if node is NULL.
 *
 * Return: 1 if node is a leaf, 0 otherwise
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{ /* Début de la fonction qui prend en paramètre un pointeur constant vers un nœud */
	if (node == NULL) /* Vérification si le pointeur node est NULL */
		return (0); /* Si node est NULL, ce n'est pas une feuille, on retourne 0 (faux) */

	if (node->left == NULL && node->right == NULL) /* Vérification si le nœud n'a ni enfant gauche ni enfant droit */
		return (1); /* Si les deux enfants sont NULL, c'est une feuille, on retourne 1 (vrai) */
	else /* Sinon, le nœud a au moins un enfant */
		return (0); /* Ce n'est pas une feuille, on retourne 0 (faux) */
}