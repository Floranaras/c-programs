#include "binTree.h"
#include "BST.h"

nodeType* create ()
{
	return NULL;
}

nodeType* createNode (int key)
{
	nodeType *temp;
	temp = malloc(sizeof(nodeType));

	if (temp != NULL)
	{
		temp->key = key;
		temp->pLeft = NULL;
		temp->pRight = NULL;
	}

	return temp;
}

nodeType *Insert (nodeType *root, int key)
{
	if (root == NULL)
		root = createNode(key);
	else if (root->key > key)
		root->pLeft = Insert(root->pLeft, key);
	else 
		root->pRight = Insert(root->pRight, key);

	return root;
}

void freeTree(nodeType *root)
{
	if (root != NULL)
	{
		freeTree(root->pLeft);   
		freeTree(root->pRight);  
		free(root);              
	}
}
