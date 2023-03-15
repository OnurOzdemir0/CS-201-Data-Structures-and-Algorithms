#ifndef __STACK__
#define __STACK__

#include <string>
#include "StackItem.h"
//#include "Calculator.h"

using namespace std;

class Stack {
	
public:
	StackItem *onTop;
	
	void push(StackItem*);
	StackItem* pop();
	StackItem* top();
	bool isEmpty();
	Stack();
	~Stack();
private:
	StackItem *link;
	
};

#endif //__STACK__