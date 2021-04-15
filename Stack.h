#pragma once
#ifndef Stack_h
#define Stack_h

#include <iostream>
#include <string>

using namespace std;

struct node
{
	string value;
	bool isOp;
	int precedence;
	node* next;
};

typedef node* nodePtr;

class Stack
{
private:
	nodePtr top;

public:
	Stack(void)
	{
		CreateStack();
	}

	string Peek();
	string Pop();
	void Push(string value, bool isOp);
	void Print();
	void CreateStack();
	bool isEmpty();
	void setPrecedence(string value, nodePtr aNode);
	int topPrecedence();
	void PushSwap(string value, bool isOp);

};

#endif

