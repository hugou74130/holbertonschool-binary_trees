#include "binary_trees.h" /* Inclusion du fichier d'en-tête contenant les définitions des structures et prototypes */

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if yes, 0 if no, or 0 if tree is NULL
 */
int binary_tree_is_full(const binary_tree_t *tree)
{ /* Début de la fonction qui vérifie si l'arbre binaire est complet (full) */
	if (tree == NULL) /* Vérification si le pointeur tree est NULL */
		return (0); /* Si tree est NULL, on retourne 0 (faux) */

	if (tree->left == NULL && tree->right == NULL) /* Vérification si le nœud est une feuille (pas d'enfants) */
		return (1); /* Une feuille respecte la propriété d'arbre complet, on retourne 1 (vrai) */

	if (tree->left && tree->right) /* Vérification si le nœud a DEUX enfants (gauche ET droit) */
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
		/* Appel récursif pour vérifier si le sous-arbre gauche est complet */
		/* ET (opérateur &&) vérifier si le sous-arbre droit est complet */
		/* Retourne 1 seulement si les deux sous-arbres sont complets */

	return (0); /* Si le nœud a un seul enfant (gauche OU droit mais pas les deux), ce n'est pas un arbre complet, on retourne 0 */
}