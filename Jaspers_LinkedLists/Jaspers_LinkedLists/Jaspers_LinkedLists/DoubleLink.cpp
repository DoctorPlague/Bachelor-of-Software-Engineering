#include "DoubleLink.h"
#include <iostream>



CDoubleLink::CDoubleLink()
{
	head = new CNode();
}

CDoubleLink::~CDoubleLink()
{
}

void CDoubleLink::InsertHead(int _iData)
{
	CNode *n = new CNode();   // create new Node	
	n->x = _iData;             // set value
	if (head == NULL)
	{
		head = n;
		n->next = nullptr;
	}
	else
	{
		n->next = head;
		head->previous = n;
	}
	head = n;
}

void CDoubleLink::InsertTail(int _iData)
{
	CNode *n = new CNode();   // create new Node	
	temp = new CNode();
	n->x = _iData;             // set value
	if (head == NULL)
	{
		head = n;
		n->next = nullptr;
	}
	else
	{
		temp->next = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = n;
		n->previous = temp;
	}
}

void CDoubleLink::Delete()
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

bool CDoubleLink::Search()
{
	if (head == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}
