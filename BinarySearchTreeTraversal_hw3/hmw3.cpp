#include <iostream>
#include <list>
#include "BinarySearchTree.h"



using namespace std;

int main() {
	BinarySearchTree BST;

	int input = 0;

	cout << "Welcome to the HW3, BST generator & traverser! \nPressing -2 will start the delete mode, press -1 to finish your entry \nEnter values:" << endl;

	//In this program there are 3 input states (or meanings) : Insert, Delete, Exit
	
	while (input != -1 && input != -2) //First state (insert)
	{ 
		cin >> input;
		if(input != -2 && input != -1)		//this is an odd case because program prints -2 or -1 but doesnt insert
			BST.insert(input);
		
		
		if (input == -1) //Third state (exit), and also printing other values ordering etc.
		{
			cout << "Preorder: ";
			BST.printPreorder();
			cout << endl;
			cout << "Inorder: ";
			BST.printInorder();
			cout << endl;
			cout << "Postorder: ";
			BST.printPostOrder();
			cout << endl;
			break;
		}

	}

	if (input == -2) //Second state (delete)
	{
		cout << "-------------------\nEnter the values that you want to delete:" << endl;
		while (input != -1)
		{
			cin >> input;
			BST.remove(input);
		}
		if (input == -1) //Third state (exit), and also printing other values ordering etc.
		{
			cout << "Preorder: ";
			BST.printPreorder();
			cout << endl;
			cout << "Inorder: ";
			BST.printInorder();
			cout << endl;
			cout << "Postorder: ";
			BST.printPostOrder();
			cout << endl;
		}


	}

	
	return 0;
}

