#include "binary_trees.h" /* Inclusion du fichier d'en-tête contenant les définitions des structures et prototypes */

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Depth of the node, or 0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{ /* Début de la fonction qui prend un pointeur constant vers un nœud de l'arbre */
	if (tree == NULL) /* Vérification si le pointeur tree est NULL */
		return (0); /* Si tree est NULL, la profondeur est 0, on retourne 0 */

	if (tree->parent == NULL) /* Vérification si le nœud n'a pas de parent (c'est la racine) */
		return (0); /* Si c'est la racine, la profondeur est 0, on retourne 0 */

	return (1 + binary_tree_depth(tree->parent)); /* Appel récursif en remontant vers le parent + 1 pour compter l'arête courante */
}