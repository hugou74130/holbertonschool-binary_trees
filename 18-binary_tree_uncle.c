#include "binary_trees.h" /* Inclusion du fichier d'en-tête contenant les définitions des structures et prototypes */

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: Pointer to the node of the tree
 *
 * Return: The pointer to the sibling node, or 0 if tree is NULL,
 * or NULL if node is NULL or if no uncle
 *
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{ /* Début de la fonction qui trouve l'oncle (uncle) d'un nœud */
	binary_tree_t *parent, *grandparent; /* Déclaration de pointeurs pour le parent et le grand-parent du nœud */

	if (!node || !node->parent) /* Vérification si node est NULL OU si node n'a pas de parent */
		return (NULL); /* Si node est NULL ou n'a pas de parent, il n'y a pas d'oncle possible, on retourne NULL */

	parent = node->parent; /* Récupération du pointeur vers le parent du nœud */
	grandparent = parent->parent; /* Récupération du pointeur vers le grand-parent (parent du parent) */

	if (!grandparent) /* Vérification si le grand-parent existe (s'il est NULL) */
		return (NULL); /* Si le grand-parent n'existe pas, il n'y a pas d'oncle, on retourne NULL */

	/* retourner le frère du parent */ /* Commentaire expliquant qu'on cherche le frère du parent (= l'oncle du nœud) */
	if (grandparent->left == parent) /* Vérification si le parent est l'enfant gauche du grand-parent */
		return (grandparent->right); /* Si oui, l'oncle est l'enfant droit du grand-parent, on le retourne */
	else /* Sinon, le parent est l'enfant droit du grand-parent */
		return (grandparent->left); /* L'oncle est l'enfant gauche du grand-parent, on le retourne */
}
```

**Note importante :**

**Oncle (Uncle) :**
- L'oncle d'un nœud est le **frère de son parent**
- Pour avoir un oncle, un nœud doit avoir :
  - Un parent
  - Un grand-parent
  - Le grand-parent doit avoir deux enfants

**Exemple :**
```
        1           <- grand-parent
       / \
      2   3         <- 2 est le parent, 3 est l'oncle
     / \
    4   5           <- 4 et 5 ont 3 comme oncle

uncle(4) = 3
uncle(5) = 3
uncle(2) = NULL (pas de grand-parent)
uncle(1) = NULL (racine)