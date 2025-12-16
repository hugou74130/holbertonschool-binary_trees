#include "binary_trees.h" /* Inclusion du fichier d'en-tête contenant les définitions des structures et prototypes */

/**
 * binary_tree_delete - Deletes an entire binary tree
 * @tree: Pointer to the root node of the tree to delete
 *
 * Description: Recursively deletes all nodes in the binary tree and frees
 * the allocated memory. If tree is NULL, does nothing.
 *
 * Return: Nothing (void)
 */
void binary_tree_delete(binary_tree_t *tree)
{ /* Début de la fonction qui prend en paramètre un pointeur vers la racine de l'arbre */
	if (tree == NULL) /* Vérification si le pointeur tree est NULL (cas de base de la récursion) */
		return; /* Si tree est NULL, on sort de la fonction sans rien faire */

	binary_tree_delete(tree->left); /* Appel récursif pour supprimer tout le sous-arbre gauche */
	binary_tree_delete(tree->right); /* Appel récursif pour supprimer tout le sous-arbre droit */
	free(tree); /* Libération de la mémoire allouée pour le nœud courant après avoir supprimé ses enfants */
}