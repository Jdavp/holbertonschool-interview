#include "binary_trees.h"
#include <stdio.h>


/**
 * heap_insert - inserts a value into a Max Binary Heap
 *@root: double pointer to the root node of the Heap
 *@value: value store in the node to be inserted
 * Return: 0 on success, error code on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node;

	node = binary_tree_node(*root, value);
	if (*root == NULL)
	{
		*root = node;
		return (node);
	}
	if ((*root)->right == NULL)
	{
		(*root)->right = node;
		return (node);
	}
	if ((*root)->left == NULL)
	{
		(*root)->left = node;
		return (node);
	}
	if (node->n > (*root)->n)
	{
		int temp = 0;

		if ((*root)->right != NULL)
		{
			temp = (*root)->right->n;
			(*root)->right->n = node->n;
			node->n = temp;
			return (node);
		}
		if ((*root)->left != NULL)
		{
			temp = (*root)->left->n;
			(*root)->left->n = node->n;
			node->n = temp;
			return (node);
		}
	}
	heap_insert(&node->right, value);
	heap_insert(&node->left, value);
	return (node);
}
