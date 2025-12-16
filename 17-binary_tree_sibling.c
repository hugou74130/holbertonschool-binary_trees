#include "binary_trees.h" /* Inclusion du fichier d'en-tête contenant les définitions des structures et prototypes */

/**
 * binary_tree_sibling - Finds the sibling of a node
 * @node: Pointer to the node of the tree
 *
 * Return: The pointer to the sibling node, or 0 if tree is NULL,
 * or NULL if node or parent is NULL or if no sibling
 *
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{ /* Début de la fonction qui trouve le frère (sibling) d'un nœud */
	if (node == NULL || node->parent == NULL) /* Vérification si node est NULL OU si node n'a pas de parent */
		return (NULL); /* Si node est NULL ou racine (pas de parent), il n'y a pas de frère possible, on retourne NULL */

	if (node->parent->left && node->parent->left != node) /* Vérification si le parent a un enfant gauche ET que ce n'est pas le nœud actuel */
		return (node->parent->left); /* Si oui, l'enfant gauche du parent est le frère du nœud, on le retourne */

	if (node->parent->right && node->parent->right != node) /* Vérification si le parent a un enfant droit ET que ce n'est pas le nœud actuel */
		return (node->parent->right); /* Si oui, l'enfant droit du parent est le frère du nœud, on le retourne */

	return (NULL); /* Si aucun frère n'est trouvé (le nœud est enfant unique), on retourne NULL */
}