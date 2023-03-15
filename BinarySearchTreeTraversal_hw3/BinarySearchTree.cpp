#include "BinarySearchTree.h"
#include <iostream>


BinarySearchTree::BinarySearchTree() {
	root = NULL;
}

BinarySearchTree::~BinarySearchTree() {
	delete root;
}

void BinarySearchTree::insert(int x, BinaryTreeNode* &t)
{
    if (t == NULL)
    {
        t = new BinaryTreeNode(x);
        t->element = x;
        t->left = t->right = NULL;
    }
	else if (x < t->element) {
		insert(x, t->left);
	}
	else if (x > t->element) {
		insert(x, t->right);
	}
}

void BinarySearchTree::insert(int x) {
	insert(x, root);
}

void BinarySearchTree::remove(int x, BinaryTreeNode*& n) {
	if (n == NULL) {
		return;
	}
	else if (x < n->element) {
		remove(x, n->left);
	}
	else if (x > n->element) {
		remove(x, n->right);
	}
	else if (n->left != NULL && n->right != NULL) {
		// two children
		n->element = returnMin(n->right)->element;	
		remove(n->element, n->right);
	}
	else {
		// one or zero children
		BinaryTreeNode* previousN = n;
		n = (n->left != NULL) ? n->left : n->right;
		delete previousN;
	}
}

BinaryTreeNode* BinarySearchTree::returnMin(BinaryTreeNode* n) {
	if (n == NULL) {
		return *&n;
	}
	else if (n->left == NULL) {
		return n;
	}
	else {
		return returnMin(n->left);
	}
}

void BinarySearchTree::remove(int x) {
	remove(x, root);
}

void BinarySearchTree::traversePreorder(BinaryTreeNode* n) {
	if (n != NULL) 
	{
		cout << n->element << " ";
		traversePreorder(n->left);
		traversePreorder(n->right);
	}
}

void BinarySearchTree::printPreorder() 
{
	traversePreorder(root);
	cout << endl;
}

void BinarySearchTree::traverseInorder(BinaryTreeNode* n) 
{
	if (n != NULL)
	{
		traverseInorder(n->left);
		cout << n->element << " ";
		traverseInorder(n->right);
	}
}

void BinarySearchTree::printInorder()
{
	traverseInorder(root);
	cout << endl;
}

void BinarySearchTree::traversePostorder(BinaryTreeNode* n)
{
	if (n != NULL)
	{
		traversePostorder(n->left);
		traversePostorder(n->right);
		cout << n->element << " ";
	}
}

void BinarySearchTree::printPostOrder()
{
	traversePostorder(root);
	cout << endl;
}

//it turns out traversal orders makes sense.
//PreOrder print the element before going to the left and right. 
//InOrder print the element after going to the left and before going to the right. 
//PostOrder print the element after going to the left and right.
