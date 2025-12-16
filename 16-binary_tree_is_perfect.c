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
{ /* Début de la fonction qui calcule la hauteur de l'arbre */
	size_t left_height; /* Déclaration d'une variable pour stocker la hauteur du sous-arbre gauche */
	size_t right_height; /* Déclaration d'une variable pour stocker la hauteur du sous-arbre droit */

	if (tree == NULL) /* Vérification si le pointeur tree est NULL */
		return (0); /* Si tree est NULL, la hauteur est 0, on retourne 0 */

	if (tree->left == NULL && tree->right == NULL) /* Vérification si le nœud est une feuille (pas d'enfants) */
		return (0); /* Si c'est une feuille, la hauteur est 0, on retourne 0 */

	left_height = binary_tree_height(tree->left); /* Appel récursif pour calculer la hauteur du sous-arbre gauche */
	right_height = binary_tree_height(tree->right); /* Appel récursif pour calculer la hauteur du sous-arbre droit */

	if (left_height > right_height) /* Comparaison des hauteurs des deux sous-arbres */
		return (left_height + 1); /* Si le sous-arbre gauche est plus haut, on retourne sa hauteur + 1 */
	else /* Sinon, le sous-arbre droit est plus haut ou égal */
		return (right_height + 1); /* On retourne la hauteur du sous-arbre droit + 1 */
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Size of the tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
/* Début de la fonction qui calcule la taille (nombre de nœuds) de l'arbre */

{ /* Ouverture du bloc de la fonction */
	if (tree == NULL) /* Vérification si le pointeur tree est NULL */
		return (0); /* Si tree est NULL, la taille est 0, on retourne 0 */

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right)); 
	/* Retourne 1 (nœud courant) + taille du sous-arbre gauche + taille du sous-arbre droit */
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if yes, 0 if no, or 0 if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{ /* Début de la fonction qui vérifie si l'arbre binaire est parfait */
	size_t size, height, expected = 1, i; /* Déclaration des variables : taille, hauteur, nombre attendu de nœuds, compteur */

	if (!tree) /* Vérification si tree est NULL (équivalent à tree == NULL) */
		return (0); /* Si tree est NULL, ce n'est pas un arbre parfait, on retourne 0 */

	size = binary_tree_size(tree); /* Calcul de la taille réelle de l'arbre (nombre total de nœuds) */
	height = binary_tree_height(tree); /* Calcul de la hauteur de l'arbre */

	/* expected = 2^(height+1) - 1 */ /* Commentaire expliquant la formule pour calculer le nombre de nœuds attendu */
	for (i = 0; i < height + 1; i++) /* Boucle pour calculer 2^(height+1) en multipliant par 2 */
		expected *= 2; /* Multiplication de expected par 2 à chaque itération */

	expected -= 1; /* Soustraction de 1 pour obtenir la formule finale : 2^(height+1) - 1 */

	return (size == expected); /* Retourne 1 si la taille réelle égale la taille attendue, 0 sinon */
}