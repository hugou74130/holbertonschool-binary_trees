#include "binary_trees.h" /* Inclusion du fichier d'en-tête contenant les définitions des structures et prototypes */

/**
 * binary_tree_inorder - Goes through a binary tree using pre-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Description: Traverses the tree in pre-order (node, left, right).
 * Calls func with the value of each node.
 *  Does nothing if tree or func is NULL.
 * Return: Nothing (void)
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{ /* Début de la fonction qui prend un pointeur vers l'arbre et un pointeur de fonction en paramètres */
	if (tree == NULL || func == NULL) /* Vérification si tree ou func est NULL */
		return; /* Si l'un des deux est NULL, on sort de la fonction sans rien faire */

	binary_tree_inorder(tree->left, func); /* Appel récursif pour parcourir d'abord le sous-arbre gauche */
	func(tree->n); /* Appel de la fonction func avec la valeur du nœud courant (traitement du nœud) */
	binary_tree_inorder(tree->right, func); /* Appel récursif pour parcourir ensuite le sous-arbre droit */
}