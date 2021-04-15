#include "Stack.h"

string Stack::Peek()
{
	return top->value;
}

string Stack::Pop()
{
	string result = top->value;
	top = top->next;

	return result;
}

void Stack::Push(string value, bool isOp)
{
	nodePtr aNode = new node;
	aNode->value = value;
	aNode->next = NULL;
	aNode->isOp = isOp;

	if (isOp)
		setPrecedence(value, aNode);

	if (top == NULL)
		top = aNode;
	else
	{
		aNode->next = top;
		top = aNode;
	}
}

void Stack::Print()
{
	if (!isEmpty())
	{
		nodePtr temp = top;

		cout << "Here is the stack from top to bottom: ";

		while (temp != NULL)
		{
			cout << temp->value << " ";
			temp = temp->next;
		}

		cout << endl;
	}
	else
		cout << "The stack is currently empty." << endl;
}

void Stack::CreateStack()
{
	top = NULL;
}

bool Stack::isEmpty()
{
	return top == NULL;
}

void Stack::setPrecedence(string value, nodePtr aNode)
{
	char symbol = value[0];

	switch (symbol)
	{
	case '(': aNode->precedence = 2;
		break;
	case ')': aNode->precedence = 2;
		break;
	case '*': aNode->precedence = 4;
		break;
	case '/': aNode->precedence = 4;
		break;
	case '+': aNode->precedence = 3;
		break;
	case '-': aNode->precedence = 3;
		break;
	default: cout << "Error, operator not found." << endl;
	}
}

int Stack::topPrecedence()
{
	if (isEmpty())
		return 0;
	else
		return top->precedence;
}

void Stack::PushSwap(string value, bool isOp)
{
	nodePtr aNode = new node;
	aNode->value = value;
	aNode->isOp = isOp;

	aNode->next = top->next;
	top->next = aNode;

}
