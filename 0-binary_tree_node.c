#include "binary_trees.h" /* Inclusion du fichier d'en-tête contenant les définitions des structures et prototypes */

/**
 * binary_tree_node - Creates a new node in a binary tree
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 *
 * Description: This function allocates memory for a new binary tree node,
 * initializes it with the given value and parent pointer, and sets its
 * left and right child pointers to NULL.
 *
 * Return: pointer to the new node, or NULL if malloc fails
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{ /* Début de la fonction qui prend en paramètre un pointeur parent et une valeur entière */
	binary_tree_t *new_node; /* Déclaration d'un pointeur vers le nouveau nœud à créer */

	new_node = malloc(sizeof(binary_tree_t)); /* Allocation dynamique de mémoire pour un nouveau nœud */

	if (new_node == NULL) /* Vérification si l'allocation a échoué (malloc retourne NULL en cas d'échec) */
		return (NULL); /* Si l'allocation a échoué, on retourne NULL pour signaler l'erreur */

	new_node->n = value; /* Initialisation du champ 'n' du nouveau nœud avec la valeur passée en paramètre */
	new_node->parent = parent; /* Assignation du pointeur parent au nouveau nœud */
	new_node->left = NULL; /* Initialisation du pointeur vers l'enfant gauche à NULL (pas d'enfant gauche initialement) */
	new_node->right = NULL; /* Initialisation du pointeur vers l'enfant droit à NULL (pas d'enfant droit initialement) */

	return (new_node); /* Retourne le pointeur vers le nouveau nœud créé et initialisé */
}