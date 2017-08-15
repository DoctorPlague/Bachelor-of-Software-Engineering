#include "Queue.h"
#include "LinkedList.h"
#include <iostream>

CQueue::CQueue()
{
}


CQueue::~CQueue()
{
}

void CQueue::EnqueueValue(int val)
{
	CNode *n = new CNode();   // create new Node
	temp = new CNode();
	n->x = val;             // set value
	if (head == NULL)
	{
		head = n;
		head->next = tail;
	}
	else
	{
		tail->next = n;
	}
	tail = n;
}

void CQueue::DequeueValue()
{
	CNode *n = head; // create node pointer to head of the list
	if (head == NULL)
	{
		std::cout << "Head is null.";
	}
	else
	{
		head = head->next; // set the head of the list to be the next node
		delete n;	     // deallocate the memory of the previous head node
	}
}

void CQueue::peekValue()
{
	if (head != NULL)
	{
		std::cout << head->x << std::endl;
	}
	else
	{
		std::cout << "Theres nothing there!" << std::endl;
	}
}

bool CQueue::isEmpty()
{
	if (head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
