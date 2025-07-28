#ifndef NEIGHBOR_H
#define NEIGHBOR_H

#include "BST.h"

int countNodes(nodeType *root);
void populateList(nodeType *root, int *list, int *index);
nodeType* treeSuccesor (nodeType *root, nodeType *key);
nodeType* treePredecessor (nodeType *root, nodeType *key);

#endif
