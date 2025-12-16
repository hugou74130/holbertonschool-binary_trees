#include "binary_trees.h" /* Inclusion du fichier d'en-tête contenant les définitions des structures et prototypes */
/**
 *binary_tree_insert_right - Inserts a node as the *right-child of another node
 *@parent: Pointer to the node to insert the *right-child in
 *@value: Value to store in the new node
 *Description: Inserts a new node with the given *value as the right-child
 *of the parent node. If the parent already has a *right-child, the new node
 *takes its place and the old right-child becomes *the right-child of the
 *new node.
 *Return: Pointer to the created node, or NULL on *failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
/* Début de la fonction qui prend en paramètre un pointeur parent et une valeur entière */

{ /* Ouverture du bloc de la fonction */
	binary_tree_t *new_node; /* Déclaration d'un pointeur vers le nouveau nœud à créer */

	if (parent == NULL) /* Vérification si le pointeur parent est NULL */
		return (NULL); /* Si parent est NULL, impossible d'insérer, on retourne NULL */

	new_node = binary_tree_node(parent, value); /* Création d'un nouveau nœud avec la fonction binary_tree_node */
	if (new_node == NULL) /* Vérification si la création du nœud a échoué (allocation mémoire échouée) */
		return (NULL); /* Si la création a échoué, on retourne NULL */

	if (parent->right != NULL) /* Vérification si le parent a déjà un enfant droit */
	{ /* Si oui, on doit réorganiser les liens */
		new_node->right = parent->right; /* L'ancien enfant droit devient l'enfant droit du nouveau nœud */
		parent->right->parent = new_node; /* On met à jour le parent de l'ancien enfant droit pour pointer vers le nouveau nœud */
	}

	parent->right = new_node; /* On fait pointer l'enfant droit du parent vers le nouveau nœud */

	return (new_node); /* Retourne le pointeur vers le nouveau nœud créé et inséré */
}