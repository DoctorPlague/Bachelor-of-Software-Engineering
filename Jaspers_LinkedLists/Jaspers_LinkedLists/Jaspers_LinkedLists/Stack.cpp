#include "Stack.h"
#include "LinkedList.h"
#include <iostream>


CStack::CStack()
{
	head = new CNode();
}


CStack::~CStack()
{

}

void CStack::pushValue(int val)
{
	CNode *n = new CNode();   // create new Node
	temp = new CNode();
	n->x = val;             // set value
	n->next = head;         // make the node point to the head of the list	
	temp->next = head;      // make temp point to the head of the list					
	head = n;               // last but not least, make the head point at the new node.	
	temp->next = nullptr;   // set temp to nullptr
}

void CStack::popValue()
{
	CNode *n = head; // create node pointer to head of the list
	if (head->next == nullptr)
	{

	}
	else
	{
		head = head->next; // set the head of the list to be the next node
		delete n;	     // deallocate the memory of the previous head node
	}
}

void CStack::peekValue()
{
	if (head->next != nullptr)
	{
		std::cout << head->x << std::endl;
	}
	else
	{
		std::cout << "Theres nothing there!" << std::endl;
	}
}

bool CStack::isEmpty()
{
	if (head->next == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}
