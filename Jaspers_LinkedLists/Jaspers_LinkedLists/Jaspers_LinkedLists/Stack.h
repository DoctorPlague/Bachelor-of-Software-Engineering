#include "LinkedList.h"
#pragma once
class CStack
{
public:
	CStack();
	~CStack();

	// adds new node to start of list
	void pushValue(int val);
	// pops first node off linked list
	void popValue();
	// returns the value at the head of the list
	void peekValue();
	// checks if the list is empty
	bool isEmpty();

private:
	CLinkedList *m_pContainer = new CLinkedList();
	CNode *head = nullptr; // this is the private member variable. It is just a pointer to the first Node
	CNode *temp = nullptr; // temporary pointer
};

