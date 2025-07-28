#ifndef BINTREE_H
#define BINTREE_H

#include "BST.h"

nodeType* create ();
nodeType* createNode (int key);
nodeType *Insert (nodeType *root, int key);
void freeTree(nodeType *root);

#endif
