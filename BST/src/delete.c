#include "delete.h"
#include "BST.h"
#include "neighbor.h"


nodeType* findParent (nodeType *root, nodeType *victim)
{
	if (root == NULL || victim == NULL)
		return NULL;

	if (root == victim)
		return NULL;

	if ((root->pLeft == victim) || (root->pRight == victim))
		return root;

	if (victim->key < root->key)
		return findParent(root->pLeft, victim);
	else
		return findParent(root->pRight, victim);
}

nodeType* killNode(nodeType *root, nodeType *victim)
{
    if (victim == NULL) 
        return root;
    
    nodeType* parent = findParent(root, victim);
    nodeType* successor = treeSuccesor(root, victim);
    
    if (parent == NULL) // victim IS root
    {
        if (victim->pLeft == NULL && victim->pRight == NULL)
        {
            free(victim);
            return NULL; // Tree becomes empty
        }
        else if (victim->pLeft != NULL && victim->pRight == NULL)
        {
            nodeType* newRoot = victim->pLeft;
            free(victim);
            return newRoot;
        }
        else if (victim->pLeft == NULL && victim->pRight != NULL)
        {
            nodeType* newRoot = victim->pRight;
            free(victim);
            return newRoot;
        }
        else // Two children
        {
            victim->key = successor->key;
            return killNode(root, successor);
        }
    }
    else // victim is NOT root
    {
        if (victim->pLeft == NULL && victim->pRight == NULL)
        {
            if (parent->pLeft == victim)
                parent->pLeft = NULL;
            else
                parent->pRight = NULL; 
            free(victim);
        }
        else if (victim->pLeft != NULL && victim->pRight == NULL)
        {
            if (parent->pLeft == victim)
                parent->pLeft = victim->pLeft;
            else
                parent->pRight = victim->pLeft;
            free(victim);
        }
        else if (victim->pLeft == NULL && victim->pRight != NULL)
        {
            if (parent->pLeft == victim)
                parent->pLeft = victim->pRight;
            else
                parent->pRight = victim->pRight;
            free(victim);
        }
        else // Two children
        {
            victim->key = successor->key;
            root = killNode(root, successor);
        }
        return root; // Root unchanged
    }
}
