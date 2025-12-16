#include "binary_trees.h" /* Inclusion du fichier d'en-tête contenant les définitions des structures et prototypes */

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node
 * @parent: pointer to the node to insert the left-child in
 * @value: value to store in the new node
 *
 * Description: This function creates a new node with the given value and
 * inserts it as the left-child of the parent node. If the parent already
 * has a left-child, the new node takes its place, and the old left-child
 * becomes the left-child of the new node.
 *
 * Return: pointer to the created node,
 * or NULL if parent is NULL or malloc fails
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{ /* Début de la fonction qui prend en paramètre un pointeur parent et une valeur entière */
	binary_tree_t *new_node; /* Déclaration d'un pointeur vers le nouveau nœud à créer */

	if (parent == NULL) /* Vérification si le pointeur parent est NULL */
		return (NULL); /* Si parent est NULL, impossible d'insérer, on retourne NULL */

	new_node = binary_tree_node(parent, value); /* Création d'un nouveau nœud avec la fonction binary_tree_node */
	if (new_node == NULL) /* Vérification si la création du nœud a échoué (allocation mémoire échouée) */
		return (NULL); /* Si la création a échoué, on retourne NULL */

	if (parent->left != NULL) /* Vérification si le parent a déjà un enfant gauche */
	{ /* Si oui, on doit réorganiser les liens */
		new_node->left = parent->left; /* L'ancien enfant gauche devient l'enfant gauche du nouveau nœud */
		parent->left->parent = new_node; /* On met à jour le parent de l'ancien enfant gauche pour pointer vers le nouveau nœud */
	}

	parent->left = new_node; /* On fait pointer l'enfant gauche du parent vers le nouveau nœud */

	return (new_node); /* Retourne le pointeur vers le nouveau nœud créé et inséré */
}