#include "Deque.h"
#include <iostream>


CDeque::CDeque()
{
}


CDeque::~CDeque()
{
}

void CDeque::Push_back(int val)
{
	CNode *n = new CNode();   // create new Node	
	temp = new CNode();
	n->x = val;             // set value
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

void CDeque::Push_front(int val)
{
	CNode *n = new CNode();   // create new Node	
	n->x = val;             // set value
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

void CDeque::Pop_front()
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

void CDeque::Pop_back()
{
	CNode *n = head; // create node pointer
	temp = new CNode();
	if (head == NULL)
	{
		std::cout << "Head is null.";
	}
	else
	{
		temp->next = head;
		while (n->next != nullptr)
		{
			n = n->next;
		}
		while (temp->next != n)
		{
			temp = temp->next;
		}
		delete n;
		temp->next = nullptr;
	}
}

void CDeque::Peek_front()
{
	if (head != NULL)
	{
		std::cout << head->x << ". Peeked at front. " << std::endl;
	}
	else
	{
		std::cout << "Theres nothing there!" << std::endl;
	}
}

void CDeque::Peek_back()
{
	temp = new CNode();
	temp = head;
	if (head != NULL)
	{
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		std::cout << temp->x << ". Peeked at back. " << std::endl;
	}
	else
	{
		std::cout << "Theres nothing there!" << std::endl;
	}
}

bool CDeque::isEmpty()
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
