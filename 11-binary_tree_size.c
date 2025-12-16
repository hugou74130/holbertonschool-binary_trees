#include "binary_trees.h" /* Inclusion du fichier d'en-tête contenant les définitions des structures et prototypes */

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Size of the tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
/* Début de la fonction qui prend un pointeur constant vers la racine de l'arbre */

{ /* Ouverture du bloc de la fonction */
	if (tree == NULL) /* Vérification si le pointeur tree est NULL (cas de base de la récursion) */
		return (0); /* Si tree est NULL, il n'y a pas de nœud, on retourne 0 */

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right)); 
	/* Retourne 1 (le nœud courant) + la taille du sous-arbre gauche + la taille du sous-arbre droit */
	/* Les appels récursifs calculent la taille de chaque sous-arbre */
	/* La somme totale donne le nombre total de nœuds dans l'arbre */
}