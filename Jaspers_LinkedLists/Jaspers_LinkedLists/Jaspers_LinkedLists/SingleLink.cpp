#include "SingleLink.h"



CSingleLink::CSingleLink()
{
	head = new CNode();
}


CSingleLink::~CSingleLink()
{
}

void CSingleLink::Insert(int _iData)
{
	CNode *n = new CNode();   // create new Node
	temp = new CNode();
	n->x = _iData;             // set value
	n->next = head;         // make the node point to the head of the list	
	temp->next = head;      // make temp point to the head of the list					
	head = n;               // last but not least, make the head point at the new node.	
	temp->next = nullptr;   // set temp to nullptr
}

void CSingleLink::Delete()
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

bool CSingleLink::Search()
{
	if (head->next == nullptr)
	{
		return false;
	}
	else
	{
		return true;
	}
}
