#include <iostream>
#include <string>
#include "bst.hpp"
using namespace std;
BST::BST() {
	root = NULL;
}

BST::~BST() {
	deleteTree(root);
	root = NULL;
}
void BST::deleteTree(Node* node) {
	if (node != NULL) {
		deleteTree(node->leftChild);
		deleteTree(node->rightChild);
		delete node;
	}
}

/*
** Implement the following function to return the count of comparisons, 
**   you may implement helper functions.
*/
void traverse(Node* n, int &counter, int target)
{
	if (n == NULL)
	{
		return;
	}
	else 
	{
		if (target>n->key)
		{
			counter++;
			traverse(n->rightChild, counter, target);
		}
		else if (target < n->key)//search in the left subtree
		{
			counter++;
			traverse(n->leftChild, counter, target);
		}
		else if (n->key == target)//found the key
		{
			counter++;
			return;
		}
	}
}
int BST::searchCounter(int target) {
	//traverse tree if not empty
	Node* temp = root;
	int counter = 0;//tracks the num of comparisons 
	traverse(root, counter, target);
	return counter;
}
