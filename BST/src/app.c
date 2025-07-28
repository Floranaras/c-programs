#include "app.h"
#include "BST.h"
#include "binTree.h"
#include "search.h"
#include "transversal.h"
#include "minMax.h"
#include "neighbor.h"
#include "delete.h"

void run ()
{
	nodeType *root;
	nodeType *found;

	root = create();
	root = Insert(root, 22);
	root = Insert(root, 16);
	root = Insert(root, 13);
	root = Insert(root, 9);
	root = Insert(root, 20);
	root = Insert(root, 21);
	root = Insert(root, 55);
	root = Insert(root, 30);
	root = Insert(root, 25);
	root = Insert(root, 40);
	root = Insert(root, 90);

	printf("\n===BINARY SEARCH TREE===\n");

	printf("Inorder: ");
	Inorder(root);
	printf("\n");

	printf("Preorder: ");
	Preorder(root);
	printf("\n");

	printf("Postorder: ");
	Postorder(root);
	printf("\n");

	found = search(root, 55);
	printf("Expected: 55\n");
	printf("Key Found: %d\n", found->key);

	found = treeMax(root);
	printf("Max key: %d\n", found->key);
	found = treeMin(root);
	printf("Min key: %d\n", found->key);

	found = treePredecessor(root, search(root,55));
	printf("Predecessor to 55: %d\n", found->key);

	found = treeSuccesor(root, search(root,55));
	printf("Sucessor to 55: %d\n", found->key);

	printf("Deleting Node 55\n");
	root = killNode(root, search(root, 55));
	Inorder(root);	
	printf("\n");


	freeTree(root);
}
