#pragma once
#ifndef Queue_h
#define Queue_h

#include <iostream>
#include <string>

using namespace std;

struct qNode
{
	string value;
	bool isOp;
	qNode* next;
};

typedef qNode* qNodePtr;

class Queue
{
private:
	qNodePtr front;
	qNodePtr back;
public:
	Queue(void)
	{
		CreateQueue();
	}
	void Enqueue(string aValue, bool isOp);
	string Dequeue();
	qNodePtr DequeueNode();
	string Peek();
	void Print();
	void CreateQueue();
	bool isEmpty();
};

#endif

