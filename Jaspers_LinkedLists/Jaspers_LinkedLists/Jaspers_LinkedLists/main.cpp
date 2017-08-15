#include <iostream>
#include "Stack.h"
#include "Deque.h"
#include "Queue.h"
#include "SingleLink.h"
#include "DoubleLink.h"
#include <conio.h>
using namespace std;

int main() {
	CStack stack;
	CDeque deque;
	CQueue queue;
	CSingleLink SinglyLinked;
	CDoubleLink DoublyLinked;

/// STACK TEST HARNESS
	std::cout << "~~~~~~ STACK TEST HARNESS ~~~~~~" << std::endl;
	std::cout << "Stack empty status: " << stack.isEmpty() << std::endl << "Adding node.. " << std::endl;
	stack.pushValue(5);
	stack.pushValue(10);
	stack.pushValue(20);
	std::cout << "Stack empty status: " << stack.isEmpty() << std::endl;
	stack.peekValue();
	stack.popValue();
	stack.peekValue();
	stack.popValue();
	stack.peekValue();
	stack.popValue();
	stack.peekValue();
	std::cout << std::endl;


/// DEQUE TEST HARNESS
	std::cout << "~~~~~~ DEQUE TEST HARNESS ~~~~~~" << std::endl;
	std::cout << std::endl << "Deque empty status: " << deque.isEmpty() << std::endl << "Adding node.. " << std::endl;
	deque.Push_front(5);
	deque.Push_front(10);
	deque.Push_front(20);
	deque.Push_front(30);
	deque.Push_front(40);
	deque.Push_front(50);
	deque.Push_back(1);
	deque.Push_back(2);
	deque.Push_back(3);
	deque.Push_back(4);
	deque.Push_back(5);
	deque.Push_back(6);
	std::cout << "Deque empty status: " << deque.isEmpty() << std::endl << std::endl;
	deque.Peek_front();
	deque.Peek_back();
	deque.Pop_front();
	deque.Pop_back();
	deque.Peek_front();
	deque.Peek_back();
	deque.Pop_front();
	deque.Pop_back();
	deque.Peek_front();
	deque.Peek_back();
	deque.Pop_front();
	deque.Pop_back();
	deque.Peek_front();
	deque.Peek_back();
	deque.Pop_front();
	deque.Pop_back();
	deque.Peek_front();
	deque.Peek_back();
	std::cout << std::endl;

/// QUEUE TEST HARNESS
	std::cout << "~~~~~~ QUEUE TEST HARNESS ~~~~~~" << std::endl;
	std::cout << std::endl << "Queue empty status: " << queue.isEmpty() << std::endl << "Adding node.. " << std::endl;
	queue.EnqueueValue(5);
	queue.EnqueueValue(10);
	queue.EnqueueValue(20);
	std::cout << "Queue empty status: " << queue.isEmpty() << std::endl;
	queue.peekValue();
	queue.DequeueValue();
	queue.peekValue();
	queue.DequeueValue();
	queue.peekValue();
	queue.DequeueValue();
	queue.peekValue();
	std::cout << std::endl;


/// SINGLY LINKED TEST HARNESS
	std::cout << "~~~~~~ SINGLY LINKED TEST HARNESS ~~~~~~" << std::endl;
	std::cout << std::endl << "Single linked list empty status: " << SinglyLinked.Search() << std::endl << "Adding nodes.. " << std::endl;
	SinglyLinked.Insert(5);
	SinglyLinked.Insert(6);
	SinglyLinked.Insert(7);
	SinglyLinked.Insert(8);
	SinglyLinked.Insert(9);
	std::cout << "Single linked list empty status: " << SinglyLinked.Search() << std::endl;
	std::cout << "Deleting all nodes.." << std::endl;
	SinglyLinked.Delete();
	SinglyLinked.Delete();
	SinglyLinked.Delete();
	SinglyLinked.Delete();
	SinglyLinked.Delete();
	std::cout << "Single linked list empty status: " << SinglyLinked.Search() << std::endl << std::endl;

	
/// DOUBLY LINKED TEST HARNESS
	std::cout << "~~~~~~ DOUBLY LINKED TEST HARNESS ~~~~~~" << std::endl;
	std::cout << std::endl << "Doubly linked list empty status: " << DoublyLinked.Search() << std::endl << "Adding nodes.. " << std::endl;
	DoublyLinked.InsertHead(5);
	DoublyLinked.InsertHead(6);
	DoublyLinked.InsertHead(7);
	DoublyLinked.InsertTail(8);
	DoublyLinked.InsertTail(9);
	DoublyLinked.InsertTail(10);
	std::cout << "Doubly linked list empty status: " << DoublyLinked.Search() << std::endl;
	std::cout << "Deleting all nodes.." << std::endl;
	DoublyLinked.Delete();
	DoublyLinked.Delete();
	DoublyLinked.Delete();
	DoublyLinked.Delete();
	DoublyLinked.Delete();
	DoublyLinked.Delete();
	std::cout << "Doubly linked list empty status: " << DoublyLinked.Search() << std::endl;
	_getch();
	return 0;
}