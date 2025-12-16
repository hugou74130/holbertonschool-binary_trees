#include "binary_trees.h" /* Inclusion du fichier d'en-tête contenant les définitions des structures et prototypes */

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{ /* Début de la fonction qui calcule la hauteur de l'arbre */
	size_t left_h = 0, right_h = 0; /* Déclaration et initialisation des variables pour les hauteurs gauche et droite */

	if (!tree) /* Vérification si tree est NULL (équivalent à tree == NULL) */
		return (0); /* Si tree est NULL, la hauteur est 0, on retourne 0 */

	if (tree->left) /* Vérification si le nœud a un enfant gauche */
		left_h = 1 + binary_tree_height(tree->left); /* Calcul récursif de la hauteur du sous-arbre gauche + 1 */
	if (tree->right) /* Vérification si le nœud a un enfant droit */
		right_h = 1 + binary_tree_height(tree->right); /* Calcul récursif de la hauteur du sous-arbre droit + 1 */

	return (left_h > right_h ? left_h : right_h); /* Retourne la hauteur maximale entre gauche et droite (opérateur ternaire) */
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Balance factor, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{ /* Début de la fonction qui calcule le facteur d'équilibre de l'arbre */
	int left_h = 0, right_h = 0; /* Déclaration et initialisation des variables pour les hauteurs gauche et droite (type int car peuvent être négatifs) */

	if (!tree) /* Vérification si tree est NULL (équivalent à tree == NULL) */
		return (0); /* Si tree est NULL, le facteur d'équilibre est 0, on retourne 0 */

	if (tree->left) /* Vérification si le nœud a un enfant gauche */
		left_h = (int)binary_tree_height(tree->left) + 1; /* Calcul de la hauteur du sous-arbre gauche + 1, avec cast en int */
	if (tree->right) /* Vérification si le nœud a un enfant droit */
		right_h = (int)binary_tree_height(tree->right) + 1; /* Calcul de la hauteur du sous-arbre droit + 1, avec cast en int */

	return (left_h - right_h); /* Retourne le facteur d'équilibre (différence entre hauteur gauche et hauteur droite) */
}