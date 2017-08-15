#pragma once
class CNode0
{
public:
	CNode0();
	~CNode0();
	
	void SetNext(CNode0* next);
	void SetPrevious(CNode0* previous);
	void SetData(int data);
	int GetData();
	CNode0 *GetNext();
	CNode0 *GetPrevious();	

private:
	int m_iData;
	CNode0 *next = nullptr;
	CNode0 *previous = nullptr;
};

