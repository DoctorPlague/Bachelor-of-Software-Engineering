#pragma once
#include "Node.h"
class CLinkedList {
public:
	// constructor
	CLinkedList();
	~CLinkedList();	

private:
	CNode *head = nullptr; // this is the private member variable. It is just a pointer to the first Node
	CNode *temp = nullptr; // temporary pointer
};

