#include "Node0.h"

CNode0::CNode0()
{
}

CNode0::~CNode0()
{
}


void CNode0::SetNext(CNode0 * _next)
{
	this->next = next;
	//next = _next;
}

void CNode0::SetPrevious(CNode0 * previous)
{
	this->previous = previous;
}

void CNode0::SetData(int data)
{
	this->m_iData = data;
}

int CNode0::GetData()
{
	return this->m_iData;
}

CNode0 * CNode0::GetNext()
{
	return this->next;
}

CNode0 * CNode0::GetPrevious()
{
	return this->previous;
}
