#include "search.h"
#include "BST.h"

nodeType *search (nodeType *node, int key)
{
	if (node == NULL || node->key == key)
		return node;
	else if (key < node->key)
		return search(node->pLeft, key);
	else if (key > node->key)
		return search(node->pRight, key);

	return NULL; 
}
