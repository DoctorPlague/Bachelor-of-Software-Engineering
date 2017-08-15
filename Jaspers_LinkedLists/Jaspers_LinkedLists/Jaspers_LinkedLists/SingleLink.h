#include "LinkedList.h"
#pragma once
class CSingleLink
{
public:
	CSingleLink();
	~CSingleLink();
		
	void Insert(int _iData);
	void Delete();
	bool Search();

private:
	CLinkedList *m_pContainer = new CLinkedList();
	CNode *head; // this is the private member variable. It is just a pointer to the first Node	
	CNode *temp; // temporary pointer
};

