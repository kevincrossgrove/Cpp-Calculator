#include "Queue.h"

void Queue::Enqueue(string aValue, bool isOp)
{
	qNodePtr aNode = new qNode;
	aNode->value = aValue;
	aNode->isOp = isOp;
	aNode->next = NULL;


	if (front == NULL)
	{
		front = aNode;
		back = aNode;
	}
	else
	{
		back->next = aNode;
		back = aNode;
	}

}

string Queue::Dequeue()
{
	string returnValue = front->value;
	front = front->next;

	return returnValue;
}

qNodePtr Queue::DequeueNode()
{
	qNodePtr temp = front;
	front = front->next;
	return temp;
}

string Queue::Peek()
{
	return front->value;
}

void Queue::Print()
{
	if (!isEmpty())
	{
		qNodePtr temp = front;

		while (temp != NULL)
		{
			cout << temp->value << " ";
			temp = temp->next;
		}

		cout << endl;
	}
	else
		cout << "The queue is currently empty." << endl;
}

void Queue::CreateQueue()
{
	front = NULL;
	back = NULL;
}

bool Queue::isEmpty()
{
	return front == NULL;
}
