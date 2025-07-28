#ifndef DELETE_H 
#define DELETE_H

#include "BST.h"

nodeType* findParent (nodeType *root, nodeType *victim);
nodeType* killNode (nodeType *root, nodeType *victim);

#endif
