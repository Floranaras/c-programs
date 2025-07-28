#include "minMax.h"
#include "BST.h"

nodeType *treeMax (nodeType *tree)
{
	if (tree->pRight == NULL)
		return tree;

	return treeMax(tree->pRight);
}

nodeType *treeMin (nodeType *tree)
{
	if (tree->pLeft == NULL)
		return tree;

	return treeMin(tree->pLeft);
}
