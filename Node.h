#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <iostream>

using namespace std;

class Node
{
private:
	Node* next;
	int childID;

public:
	Node(): next(NULL)
	{
		//
	}
	~Node(){}

	Node* getNext()	
	{
		return next;
	}

	void setNext(Node *_next)
	{
		next = _next;
	}

	int getID()
	{
		return childID;
	}

	void setID(int _id)
	{
		childID =_id;
	}
};


#endif // NODE_H_INCLUDED