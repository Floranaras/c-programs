#include "transversal.h"
#include "BST.h"

void Visit (nodeType *root)
{
	printf("%d ", root->key);
}

// LEFT - ROOT - RIGHT
void Inorder (nodeType *root)
{
	if (root != NULL)
	{
		Inorder (root->pLeft);
		Visit (root);
		Inorder (root->pRight);
	}
}

// ROOT - LEFT - RIGHT
void Preorder (nodeType *root)
{
	if (root != NULL)
	{
		Visit(root);
		Preorder(root->pLeft);
		Preorder(root->pRight);
	}
}

// LEFT - RIGHT - ROOT
void Postorder (nodeType *root)
{
	if (root != NULL)
	{
		Postorder (root->pLeft);
		Postorder (root->pRight);
		Visit (root);
	}
}
