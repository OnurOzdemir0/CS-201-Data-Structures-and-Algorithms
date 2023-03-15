#include "Stack.h"

 

Stack::Stack() 
{
	onTop = NULL; 
}

void Stack::push(StackItem *item)
{
	if (onTop == NULL)
	{
		onTop = item;
	}
	else
	{
		item->next = onTop;
		onTop = item;
	}
}

StackItem* Stack::top() 
{
		return onTop;
}

bool Stack::isEmpty()
{
	return onTop == NULL;
}

StackItem* Stack::pop()
{
	if (onTop == NULL)
	{
		return NULL;
	}
	else
	{
		StackItem* temp = onTop;
		onTop = onTop->next;
		delete temp;
		return onTop;
	}
}

Stack::~Stack() {
		while (onTop != NULL)
		{
			StackItem* temp = onTop;
			onTop = onTop->next;
			delete temp;
		}
}


