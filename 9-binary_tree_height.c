#include "binary_trees.h" /* Inclusion du fichier d'en-tête contenant les définitions des structures et prototypes */

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Description: Calculates the height of the tree. The height is the number
 * of edges from the deepest leaf to the root. Returns 0 if tree is NULL.
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{ /* Début de la fonction qui prend un pointeur constant vers la racine de l'arbre */
	size_t left_height; /* Déclaration d'une variable pour stocker la hauteur du sous-arbre gauche */
	size_t right_height; /* Déclaration d'une variable pour stocker la hauteur du sous-arbre droit */

	if (tree == NULL) /* Vérification si le pointeur tree est NULL */
		return (0); /* Si tree est NULL, la hauteur est 0, on retourne 0 */

	if (tree->left == NULL && tree->right == NULL) /* Vérification si le nœud est une feuille (pas d'enfants) */
		return (0); /* Si c'est une feuille, la hauteur est 0 (pas d'arêtes en dessous), on retourne 0 */

	left_height = binary_tree_height(tree->left); /* Appel récursif pour calculer la hauteur du sous-arbre gauche */
	right_height = binary_tree_height(tree->right); /* Appel récursif pour calculer la hauteur du sous-arbre droit */

	if (left_height > right_height) /* Comparaison des hauteurs des deux sous-arbres */
		return (left_height + 1); /* Si le sous-arbre gauche est plus haut, on retourne sa hauteur + 1 (pour l'arête courante) */
	else /* Sinon, le sous-arbre droit est plus haut ou égal */
		return (right_height + 1); /* On retourne la hauteur du sous-arbre droit + 1 (pour l'arête courante) */
}