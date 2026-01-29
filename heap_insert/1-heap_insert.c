#include "binary_trees.h"

/**
 * count_nodes - counts nodes in binary tree
 * @root: pointer to the root node
 *
 * Return: number of nodes
 */
static int count_nodes(heap_t *root)
{
	if (!root)
		return (0);
	return (1 + count_nodes(root->left) + count_nodes(root->right));
}

/**
 * get_parent - gets the parent node for insertion
 * @root: pointer to the root node
 * @index: index of node to insert (1-based)
 *
 * Return: pointer to parent node
 */
static heap_t *get_parent(heap_t *root, int index)
{
	int path, mask, height = 0, tmp = index;

	if (index == 1)
		return (NULL);

	while (tmp > 0)
	{
		tmp >>= 1;
		height++;
	}

	path = index;
	mask = 1 << (height - 2);

	while (mask > 1)
	{
		if (path & mask)
			root = root->right;
		else
			root = root->left;
		mask >>= 1;
	}
	return (root);
}

/**
 * heapify_up - maintains max heap property by bubbling up
 * @node: pointer to the inserted node
 *
 * Return: pointer to the final position of the node
 */
static heap_t *heapify_up(heap_t *node)
{
	int tmp;

	while (node->parent && node->n > node->parent->n)
	{
		tmp = node->n;
		node->n = node->parent->n;
		node->parent->n = tmp;
		node = node->parent;
	}
	return (node);
}

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value to store in the node to be inserted
 *
 * Return: pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;
	int index;

	if (!root)
		return (NULL);

	new_node = binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);

	if (!*root)
	{
		*root = new_node;
		return (new_node);
	}

	index = count_nodes(*root) + 1;
	parent = get_parent(*root, index);

	if (index % 2 == 0)
		parent->left = new_node;
	else
		parent->right = new_node;
	new_node->parent = parent;

	return (heapify_up(new_node));
}
