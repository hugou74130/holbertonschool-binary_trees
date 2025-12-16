#include "binary_trees.h" /* Inclusion du fichier d'en-tête contenant les définitions des structures et prototypes */

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Number of leaves in the tree, or 0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{ /* Début de la fonction qui prend un pointeur constant vers la racine de l'arbre */
	if (tree == NULL) /* Vérification si le pointeur tree est NULL (cas de base de la récursion) */
		return (0); /* Si tree est NULL, il n'y a pas de feuille, on retourne 0 */

	if (tree->left == NULL && tree->right == NULL) /* Vérification si le nœud est une feuille (pas d'enfants) */
		return (1); /* Si c'est une feuille, on compte ce nœud, on retourne 1 */
	else /* Sinon, le nœud a au moins un enfant */
		return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
		/* Appel récursif pour compter les feuilles dans le sous-arbre gauche */
		/* + appel récursif pour compter les feuilles dans le sous-arbre droit */
		/* La somme donne le nombre total de feuilles dans l'arbre */
}
```

**Note importante :** 
- Une feuille (leaf) est un nœud qui n'a **ni enfant gauche ni enfant droit** (les deux pointeurs sont NULL).
- La fonction parcourt récursivement tout l'arbre et compte uniquement les nœuds qui sont des feuilles.
- Les nœuds internes (avec au moins un enfant) ne sont pas comptés, mais la fonction continue à explorer leurs sous-arbres.

**Exemple :**
```
        1           <- nœud interne (pas une feuille)
       / \
      2   3         <- 2 est interne, 3 est une feuille
     / \
    4   5           <- 4 et 5 sont des feuilles

Nombre de feuilles = 3 (nœuds 3, 4, et 5)