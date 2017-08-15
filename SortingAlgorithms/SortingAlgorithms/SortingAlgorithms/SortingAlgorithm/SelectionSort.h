#include<cassert>
#ifndef _SELECTION_SORT_H
#define _SELECTION_SORT_H
template<typename T>
class SelectionSortAlgo
{
public:
	SelectionSortAlgo(int size, int growBy = 1) :
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
	~SelectionSortAlgo()
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
	void SelectionSort()
	{
		// In-place selection sorting algorithm.		
		// Only uses one array.
		/// Declaring Neccessary Variables
		int i = 0;
		int j = 0;
		int iMin = 0;
		int iTemp = 0;

		/// Starting Sorting Algorithm
		// Loop/Itterate the same amount of times as the number of elements in the array.
		for (i; i < m_numElements; i++)
		{
			iMin = i; // Set iMin to equal 'i'
			for (j = i + 1; j < m_numElements; j++) // 'j' equals 'i' plus one, loop (m_numElements - 1) times.
			{
				// Loop until a value lower than iMin is found.
				if (m_array[j] < m_array[iMin]) // If the element at index j is less than the minimum
				{
					iMin = j; // Update iMin with the index of the minimum element 
				}
			}

			/// Swap the values at the indexed locations.
			iTemp = m_array[i]; // Temp variable used for swapping the values.			
			m_array[i] = m_array[iMin]; 
			m_array[iMin] = iTemp;
		}
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
