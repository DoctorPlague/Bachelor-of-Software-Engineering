#include<iostream>
#include"conio.h"
#include"BubbleSort.h"
#include"InsertionSort.h"
#include"SelectionSort.h"
#include"QuickSort.h"
using namespace std;
int main(int args, char *arg[])
{
	cout << "Bubble Sort Algorithm" << endl;
	cout << "**********************" << endl << endl;
	BubbleSortAlgo<int> array(5);
	array.push(80);
	array.push(64);
	array.push(99);
	array.push(76);
	array.push(5);
	cout << "Before sort:";
	for (int i = 0; i < 5; i++)
	{
		cout << " " << array[i];
	}
	cout << endl;
	array.BubbleSort();
	cout << "After sort:";
	for (int i = 0; i < 5; i++)
	{
		cout << " " << array[i];
	}
	cout << endl << endl;


	cout << "Insertion Sort Algorithm" << endl;
	cout << "**********************" << endl << endl;
	InsertionSortAlgo<int> array1(5);
	array1.push(80);
	array1.push(64);
	array1.push(99);
	array1.push(76);
	array1.push(5);
	cout << "Before sort:";
	for (int i = 0; i < 5; i++)
	{
		cout << " " << array1[i];
	}
	cout << endl;
	array1.InsertionSort();
	cout << "After sort:";
	for (int i = 0; i < 5; i++)
	{
		cout << " " << array1[i];
	}
	cout << endl << endl;


	cout << "Selection Sort Algorithm" << endl;
	cout << "**********************" << endl << endl;
	SelectionSortAlgo<int> array2(5);
	array2.push(80);
	array2.push(64);
	array2.push(99);
	array2.push(76);
	array2.push(5);
	cout << "Before sort:";
	for (int i = 0; i < 5; i++)
	{
		cout << " " << array2[i];
	}
	cout << endl;
	array2.SelectionSort();
	cout << "After sort:";
	for (int i = 0; i < 5; i++)
	{
		cout << " " << array2[i];
	}
	cout << endl << endl;


	cout << "Quick Sort Algorithm" << endl;
	cout << "**********************" << endl << endl;
	QuickSortAlgo<int> array3(10);
	array3.push(80);
	array3.push(64);
	array3.push(99);
	array3.push(76);
	array3.push(5);
	array3.push(69);
	array3.push(62);
	array3.push(90);
	array3.push(73);
	array3.push(8);
	cout << "Before sort:";
	for (int i = 0; i < 10; i++)
	{
		cout << " " << array3[i];
	}
	cout << endl;
	array3.QuickSort(0, 9); // QuickSort(start of array, end of array);
	cout << "After sort:";
	for (int i = 0; i < 10; i++)
	{
		cout << " " << array3[i];
	}
	cout << endl << endl;

	_getch();
	return 0;
}