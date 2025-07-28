#include "neighbor.h"
#include "BST.h"
#include "search.h"

int countNodes(nodeType *root) 
{
	if (root == NULL) 
		return 0;

	return 1 + countNodes(root->pLeft) + countNodes(root->pRight);
}

void populateList(nodeType *root, int *list, int *index) 
{
	if (root != NULL) 
	{
		populateList(root->pLeft, list, index);
		list[(*index)++] = root->key;  
		populateList(root->pRight, list, index);
	}
}

nodeType* treeSuccesor (nodeType *root, nodeType *key)
{
	int j = 0;
	int size = countNodes(root);
	int *list = malloc(size * sizeof(int));
	int index = 0;
	nodeType *result;
	populateList(root, list, &index);

	while (j < size && key->key != list[j])
		j++;

	if (j == size) 
		result = NULL;

	else if (j == 0) 
		result = NULL;

	else 
	{
		j++;
		result = search(root, list[j]);
	}

	free(list);  
	return result;
}

nodeType* treePredecessor (nodeType *root, nodeType *key)
{
	int j = 0;
	int size = countNodes(root);
	int *list = malloc(size * sizeof(int));
	int index = 0;
	nodeType *result;
	populateList(root, list, &index);

	while (j < size && key->key != list[j])
		j++;

	if (j == size) 
		result = NULL;

	else if (j == size - 1) 
		result = NULL;

	else 
	{
		j--;
		result = search(root, list[j]);
	}

	free(list);  
	return result;
}


