#include<cassert>
#ifndef _QUICK_SORT_H
#define _QUICK_SORT_H
template<typename T>
class QuickSortAlgo
{
public:
	QuickSortAlgo(int size, int growBy = 1) :
		m_array(NULL), m_maxSize(0),
		m_growSize(0), m_numElements(0)
	{
		if (size)
		{
			m_maxSize = size;
			m_array = new T[m_maxSize];
			memset(m_array, 0, sizeof(T) * m_maxSize);
			m_growSize = ((growBy > 0) ? growBy : 0);
		}
	}
	~QuickSortAlgo()
	{
		if (m_array != NULL)
		{
			delete[] m_array;
			m_array = NULL;
		}
	}
	void push(T val)
	{
		assert(m_array != NULL);
		if (m_numElements >= m_maxSize)
		{
			Expand();
		}
		m_array[m_numElements] = val;
		m_numElements++;
	}
	void pop()
	{
		if (m_numElements > 0)
			m_numElements--;

	}
	void remove(int index)
	{
		assert(m_array != NULL);
		if (index >= m_maxSize)
		{
			return;
		}
		for (int k = index; k < m_maxSize - 1; k++)
			m_array[k] = m_array[k + 1];
		m_maxSize--;
		if (m_numElements >= m_maxSize)
			m_numElements = m_maxSize - 1;

	}
	T& operator[](int index)
	{
		assert(m_array != NULL && index <= m_numElements);
		return m_array[index];
	}
	int search(T val)
	{
		assert(m_array != NULL);
		for (int i = 0; i < m_numElements; i++)
		{
			if (m_array[i] == val)
				return i;

		}
		return -1;
	}
	void QuickSort(int iStart, int iEnd)
	{			
		if (iStart < iEnd) 
		{
			int pIndex = Partition(iStart, iEnd); // Calling partition function
			QuickSort(iStart, pIndex - 1); // Recursion, - 1 from pIndex. Only does something if iStart is < iEnd
			QuickSort(pIndex + 1, iEnd); // Recursion, + 1 on pIndex. Only does something if iStart is < iEnd
		}		
	}
	int Partition(int iStart, int iEnd) // Lomuto partition scheme
	{	
		int pivot = m_array[iEnd]; // The pivot is always the far-right/end of the array
		int pIndex = iStart; // set the partition index as the start initially
		int temp; // Temp variable used for swapping.
		int temp2; // Temp variable used for swapping.
		int i = 0; 
		for (int j = 0; j < 10; j++)
		{
			cout << " " << m_array[j];
		}
		cout << endl;
		cout << "Partition Index: " << m_array[pIndex] << endl;		
		cout << "End/Pivot: " << m_array[iEnd] << endl;
		cout << "Start: " << m_array[iStart] << endl << endl;
		for (i = iStart; i < iEnd; i++) // itterate from the start to the end, incrementing i each loop.
		{
			if (m_array[i] <= pivot) // If the value at index 'i' is less than or equal to the pivot value
			{
				
				// Swap m_array[i] and m_array[pIndex]
				temp = m_array[i];
				m_array[i] = m_array[pIndex];
				m_array[pIndex] = temp;
				pIndex = pIndex + 1; // Increment the partition index by one.					
			}
		}
		// Swap pivot with element at partition index		
		temp2 = m_array[pIndex];
		m_array[pIndex] = m_array[iEnd];
		m_array[iEnd] = temp2;		
		return pIndex; // return the partition index.
	}
	void clear() { m_numElements = 0; }
	int GetSize() { return m_numElements; }
	int GetMaxSize() { return m_maxSize; }
	int GetGrowSize() { return m_growSize; }
	void SetGrowSize(int val)
	{
		assert(val >= 0);
		m_growSize = val;
	}
private:
	bool Expand()
	{
		if (m_growSize <= 0)
			return false;
		T *temp = new T[m_maxSize + m_growSize];
		assert(temp != NULL);
		memcpy(temp, m_array, sizeof(T) * m_maxSize);
		delete[] m_array;
		m_array = temp;
		m_maxSize += m_growSize;
		return true;
	}
private:
	T *m_array;
	int m_maxSize;
	int m_growSize;
	int m_numElements;
};
#endif#pragma once
