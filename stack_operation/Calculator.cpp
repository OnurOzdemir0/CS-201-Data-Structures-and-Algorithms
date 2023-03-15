#include <stack>

#include "Calculator.h"
#include "Stack.h"
#include "StackItem.h"

Calculator::Calculator(string infixExpression) {
	//stacks are created from first to last, but used as last to first. So we need to reverse the string
	reverse(infixExpression.begin(), infixExpression.end());
	this->stack = new Stack();
	this->infixExpression = infixExpression;
	string res;
}

string Calculator::getPrefix() {		
	return infixExpression;
}

int Calculator::calculate()
{
	string myInput = infixExpression;
	int tempi = 0;
	string temps;
	int b = 0; //used in merge digits
	
	for (int i = 0; i <= myInput.length(); i++) 
	{
		char c = myInput[i];
		if (i != 0)
			temps = myInput.substr(i - 1, i);
		else {
			temps = myInput.substr(0, 1);
		}
		stack->push(new StackItem({c}));
	}

	while (!stack->isEmpty()) {
		if (stack->top()->op == 0) {
			string temp = stack->top()->toString();
			
			tempi = (int)*stack->top()->toString().c_str();
			
			//concatenation stuff
				b = 10*b + tempi;
				cout << b << endl;
				
			//end concat stuff
			stack->pop();
		}
		if(stack->top()->op > 0){
			stack->top()->toString();
			cout << "operator" << endl;
		}
		StackItem* myItem = stack->pop();
	}
	
	return -1;
}