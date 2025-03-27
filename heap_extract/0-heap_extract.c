#include "binary_trees.h"
#include <stdlib.h>

/**
 * heapify_down - Rebuilds the heap by moving the node down
 * @node: Pointer to the node to heapify down
 */
void heapify_down(heap_t *node)
{
	heap_t *largest = node;
	heap_t *left = node->left;
	heap_t *right = node->right;

	if (left && left->n > largest->n)
		largest = left;
	if (right && right->n > largest->n)
		largest = right;

	if (largest != node)
	{
		int temp = node->n;

		node->n = largest->n;
		largest->n = temp;
		heapify_down(largest);
	}
}

/**
 * get_last_node - Gets the last node in level-order traversal
 * @root: Pointer to the root node of the heap
 *
 * Return: Pointer to the last node
 */
heap_t *get_last_node(heap_t *root)
{
	if (!root)
		return (NULL);

	heap_t **queue;
	size_t front = 0, back = 0, size = 1024;

	queue = malloc(sizeof(heap_t *) * size);
	if (!queue)
		return (NULL);

	queue[back++] = root;
	heap_t *last_node = NULL;

	while (front < back)
	{
		last_node = queue[front++];
		if (last_node->left)
			queue[back++] = last_node->left;
		if (last_node->right)
			queue[back++] = last_node->right;

		if (back >= size)
		{
			size *= 2;
			queue = realloc(queue, sizeof(heap_t *) * size);
			if (!queue)
				return (NULL);
		}
	}

	free(queue);
	return (last_node);
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 *
 * Return: Value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	if (!root || !*root)
		return (0);

	int value = (*root)->n;
	heap_t *last_node = get_last_node(*root);

	if (last_node == *root)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	(*root)->n = last_node->n;
	if (last_node->parent->left == last_node)
		last_node->parent->left = NULL;
	else
		last_node->parent->right = NULL;

	free(last_node);
	heapify_down(*root);

	return (value);
}
