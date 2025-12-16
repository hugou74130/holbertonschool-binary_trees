#include "binary_trees.h" /* Inclusion du fichier d'en-tête contenant les définitions des structures et prototypes */

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Number of nodes with at least 1 child in the tree,
 * or 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{ /* Début de la fonction qui prend un pointeur constant vers la racine de l'arbre */
	if (tree == NULL) /* Vérification si le pointeur tree est NULL (cas de base de la récursion) */
		return (0); /* Si tree est NULL, il n'y a pas de nœud, on retourne 0 */

	if (tree->left == NULL && tree->right == NULL) /* Vérification si le nœud est une feuille (pas d'enfants) */
		return (0); /* Si c'est une feuille, on ne compte pas ce nœud, on retourne 0 */
	else /* Sinon, le nœud a au moins un enfant (gauche ou droit ou les deux) */
		return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
		/* Retourne 1 (pour compter le nœud courant qui a au moins un enfant) */
		/* + appel récursif pour compter les nœuds internes dans le sous-arbre gauche */
		/* + appel récursif pour compter les nœuds internes dans le sous-arbre droit */
}