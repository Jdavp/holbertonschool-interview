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

	if ((*root) == NULL)
	{
		return (NULL);
	}
	node = binary_tree_node(*root, value);
	if ((*root)->right == NULL)
	{
		(*root)->right = node;
	}
	else if ((*root)->right != NULL)
	{
		node->right = (*root)->right;
		(*root)->right->parent = node;
		(*root)->right = node;
	}
	if ((*root)->left == NULL)
	{
		(*root)->left = node;
	}
	else
	{
		node->left = (*root)->left;
		(*root)->left->parent = node;
		(*root)->left = node;
	}
	return (node);
}
