#include "LinkedList.h"
#pragma once
class CQueue
{
public:
	CQueue();
	~CQueue();

	// adds new node to start of list
	void EnqueueValue(int val);
	// pops first node off linked list
	void DequeueValue();
	// returns the value at the head of the list
	void peekValue();
	// checks if the list is empty
	bool isEmpty();

private: 
	CLinkedList *m_pContainer = new CLinkedList();
	CNode *head; // this is the private member variable. It is just a pointer to the first Node]
	CNode *tail;
	CNode *temp; // temporary pointer
};

