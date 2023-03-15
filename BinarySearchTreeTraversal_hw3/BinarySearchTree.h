//============================================================================
// Name        : BinarySearchTree.h
// Author      : Emre Sefer & Hasan Sozer
// Version     : 2.0
// Copyright   : (c) 2020 Ozyegin University
// Description : Includes the header file of the BinarySearchTree class 
//				 that will be used as part of the program to be submitted 
//				 as Homework 3, which is assigned in the context of  
//				 the course CS201, Data Structures and Algorithms.
//============================================================================

#ifndef __BINARYSEARCHTREE__
#define __BINARYSEARCHTREE__

#include "BinaryTreeNode.h"

using namespace std;

class BinarySearchTree {

public:
	BinarySearchTree();
	~BinarySearchTree();
	void insert(int);
	void remove(int);
	void printPreorder();
	void printInorder();
	void printPostOrder();

private:
	BinaryTreeNode *root;
	void insert(int, BinaryTreeNode * & n);
	void remove(int, BinaryTreeNode * & n);
	void traversePreorder(BinaryTreeNode * n);
	void traverseInorder(BinaryTreeNode * n);
	void traversePostorder(BinaryTreeNode * n);
	void deleteNodes(BinaryTreeNode * & n);

	//my functions
	BinaryTreeNode* returnMin(BinaryTreeNode*); //Had to declare it because, I am using it in a recursive function

};

#endif /* __BINARYSEARCHTREE__ */