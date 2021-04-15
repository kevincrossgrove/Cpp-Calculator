#include "Stack.h"
#include "Queue.h"

bool checkIfOp(string value);
bool checkIfOp(char value);
int checkPrecedence(string value);
double doMath(double first, double second, string theOperator);

int main()
{
	Stack theStack;
	Queue theQueue;

	string mathProblem;
	int problemLength;
	string currentValue;

	cout << "Enter math problem: ";
	getline(cin, mathProblem);

	problemLength = mathProblem.length();

	char current;
	char next;

	string value = "";
	string enqueueValue;

	// ----------------- Converting Infix to Postfix -----------------------

	for (int i = 0; i < problemLength; i++)
	{
		current = mathProblem[i];

		next = (i < problemLength - 1) ? mathProblem[i + 1] : ' ';

		if (current != ' ')
			value += current;
		else
			continue;

		if (checkIfOp(value))
		{
			if (value == ")")
			{
				string pTemp = theStack.Pop();
				while (pTemp != "(")
				{
					theQueue.Enqueue(pTemp, true);
					pTemp = theStack.Pop();
				}
			}
			else if (value == "(")
				theStack.Push(value, true);
			else if (theStack.topPrecedence() >= checkPrecedence(value))
			{
				enqueueValue = theStack.Pop();
				theQueue.Enqueue(enqueueValue, true);
				theStack.Push(value, true);
			}
			else
				theStack.Push(value, true);

			value = "";
		}
		else if (next == ' ' || checkIfOp(next))
		{
			theQueue.Enqueue(value, false);

			value = "";
		}

	}

	if (!theStack.isEmpty())
	{
		while (!theStack.isEmpty())
		{
			enqueueValue = theStack.Pop();
			theQueue.Enqueue(enqueueValue, true);
		}
	}

	cout << "Infix converted to Postfix: ";
	theQueue.Print();

	// -------------- Evaluating postfix notation to find answer ---------------------

	qNodePtr qNode;

	string op;
	string second;
	string first;

	double secondConverted;
	double firstConverted;
	double pushValue;

	string stringPushValue;
	string answer;

	while (!theQueue.isEmpty())
	{
		qNode = theQueue.DequeueNode();

		if (qNode->isOp)
		{
			op = qNode->value;
			second = theStack.Pop();
			first = theStack.Pop();

			secondConverted = stod(second);
			firstConverted = stod(first);

			pushValue = doMath(firstConverted, secondConverted, op);

			stringPushValue = to_string(pushValue);

			theStack.Push(stringPushValue, false);
		}
		else
		{
			theStack.Push(qNode->value, false);
		}
	}

	answer = theStack.Pop();

	cout << "The answer is: " << answer << endl;

	system("PAUSE");         
	return 0;
}

bool checkIfOp(string value)
{
	if (value.length() > 1)
		return false;

	else if (value == "+" || value == "-" || value == "*" || value == "/"
		|| value == "(" || value == ")")
		return true;
	else
		return false;
}

bool checkIfOp(char value)
{
	if (value == '+' || value == '-' || value == '*' || value == '/'
		|| value == '(' || value == ')')
		return true;
	else
		return false;

}

int checkPrecedence(string value)
{
	char symbol = value[0];

	switch (symbol) {
	case '(': return 2;
		break;
	case ')': return 2;
		break;
	case '*': return 4;
		break;
	case '/': return 4;
		break;
	case '+': return 3;
		break;
	case '-': return 3;
		break;
	default: cout << "Error, operator not found." << endl;
	}
}

double doMath(double first, double second, string theOperator)
{
	double answer;

	if (theOperator == "*")
		answer = first * second;
	else if (theOperator == "/")
		answer = first / second;
	else if (theOperator == "+")
		answer = first + second;
	else
		answer = first - second;

	return answer;
}
