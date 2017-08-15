#pragma once
class CNode
{
public:
	CNode();
	~CNode();
	int x; // the data contained in the node
	CNode *next = nullptr;
	CNode *previous = nullptr;
};
