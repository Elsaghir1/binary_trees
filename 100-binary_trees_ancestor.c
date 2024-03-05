#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: If no common ancestors return NULL, else return common ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *head, *pp;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	head = first->parent, pp = second->parent;
	if (first == pp || !head || (!head->parent && pp))
		return (binary_trees_ancestor(first, pp));
	else if (head == second || !pp || (!pp->parent && head))
		return (binary_trees_ancestor(head, second));
	return (binary_trees_ancestor(head, pp));
}
