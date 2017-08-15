#include "LinkedList.h"
#pragma once
class CDeque
{
public:
	CDeque();
	~CDeque();

	void Push_back(int val);
	void Push_front(int val);
	// pops first node off linked list
	void Pop_front();
	void Pop_back();
	// returns the value at the head of the list
	void Peek_front();
	void Peek_back();
	// checks if the list is empty
	bool isEmpty();

private:
	CLinkedList *m_pContainer = new CLinkedList();
	CNode *head = nullptr; // this is the private member variable. It is just a pointer to the first Node
	CNode *temp = nullptr; // temporary pointer
};

