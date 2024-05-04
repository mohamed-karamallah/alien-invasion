/*
this is a program that implements the queue abstract data type using a linked list.
the queue is implemented as a chain of linked nodes that has two pointers,
a frontPtr pointer for the front of the queue and a backPtr pointer for the back of the queue.
*/

/*

				the Node: item of type T and a "next" pointer
					-------------
					| item| next | --->
					-------------
General Queue case:

				 frontPtr																backPtr
					\											   						/
					 \											  					   /
					------------- 	  ------------- 	  ------------- 	  -------------
					| item| next |--->| item| next |--->  | item| next |--->  | item| next |---> NULL
					------------- 	  ------------- 	  ------------- 	  -------------

Empty Case:

				 frontptr	 backptr
						\	 /
						 \	/
					---- NULL ------


Single Node Case:
				 frontPtr	 backPtr
					\		/
					 \	   /
					-----------
					|item| next| -->NULL
					-----------

*/

#ifndef LINKED_QUEUE_
#define LINKED_QUEUE_


#include "Node.h"
#include "QueueADT.h"
#include<iostream>

template <typename T>
class LinkedQueue :public QueueADT<T>
{
private:
	Node<T>* backPtr;
	Node<T>* frontPtr;
	int size;
public:
	// Implement getFront function
	/*Node<T>* getFront() {
		// Check if the queue is empty
		if (isEmpty()) {
			// Print an error message or return a default value (depending on your preference)
			std::cout << "The doubleEQ is empty, there is no front element." << std::endl;
			// You can also throw an exception here if you prefer
			// throw std::runtime_error("doubleEQ: getFront called on empty queue");
		}
		else
		{
			return frontPtr->getItem(); // Return the data item from the front node
		}
	}*/
	// Function to get a pointer to the front node (if any)
		Node<T>* getFrontPtr() const {
			return frontPtr;
		}

		LinkedQueue();
		bool isEmpty() const;
		bool enqueue(const T & newEntry);
		bool dequeue(T & frntEntry);
		bool peek(T & frntEntry) const;
		int getlength();
		void print();
		~LinkedQueue();
		int getSize()const;
		
	};
	/////////////////////////////////////////////////////////////////////////////////////////

	/*
	Function: Queue()
	the constructor of the Queue class.

	*/



	template <typename T>
	LinkedQueue<T>::LinkedQueue()
	{
		backPtr = nullptr;
		frontPtr = nullptr;
		size = 0;
	}
	/////////////////////////////////////////////////////////////////////////////////////////

	/*
	Function: isEmpty
	Sees whether this queue is empty.

	Input: None.
	Output: true if the queue is empty; otherwise false.
	*/
	template <typename T>
	bool LinkedQueue<T>::isEmpty() const
	{
		return (frontPtr == nullptr);
	}

	/////////////////////////////////////////////////////////////////////////////////////////

	/*Function:enqueue
	Adds newEntry at the back of this queue.

	Input: newEntry .
	Output: true if the operation is successful; otherwise false.
	*/

	template <typename T>
	bool LinkedQueue<T>::enqueue(const T& newEntry)
	{
		Node<T>* newNodePtr = new Node<T>(newEntry);
		if (isEmpty()) { // Special case if this is the first node to insert
			frontPtr = newNodePtr;
			backPtr = newNodePtr; // Update both front and back pointers
		}
		else {
			backPtr->setNext(newNodePtr);
			backPtr = newNodePtr; // Update only the back pointer
		}
		size++;
		return true;
	}


	/////////////////////////////////////////////////////////////////////////////////////////////////////////

	/*Function: dequeue
	Removes the front of this queue. that is, removes the item that was added
	earliest.

	Input: None.
	Output: true if the operation is successful; otherwise false.
	*/

	template <typename T>
	bool LinkedQueue<T>::dequeue(T& frntEntry)
	{
		if (isEmpty())
			return false;

		Node<T>* nodetoDeletePtr = frontPtr;
		frntEntry = frontPtr->getItem();
		frontPtr = frontPtr->getNext();
		// Queue is not empty; remove front
		if (nodetoDeletePtr == backPtr)	 // Special case: last node in the queue
			backPtr = nullptr;

		// Free memory reserved for the dequeued node
		delete nodetoDeletePtr;
		size--;
		return true;
	}



	/////////////////////////////////////////////////////////////////////////////////////////

	/*
	Function: peek
	copies the front of this queue to the passed param. the operation does not modify the queue.

	Input: None.
	Output: the front of the queue.
	*/
	template <typename T>
	int LinkedQueue<T>::getSize()const
	{
		return size;
	}
	template <typename T>
	bool LinkedQueue<T>::peek(T& frntEntry) const
	{
		if (isEmpty())
			return false;

		frntEntry = frontPtr->getItem();
		return true;

	}
	template <typename T>

	int LinkedQueue<T>::getlength() {
		return size;
	}
	template <typename T>
	void LinkedQueue<T>::print() {
		if (isEmpty()) {

			return;
		}
		Node<T>* current = frontPtr;
		/*while (current != nullptr) {
			 std::cout<<current->getItem()->getID() << ", ";;


			current = current->getNext();
		}*/
		while (current->getNext()!=NULL)
		{
			std::cout << current->getItem()->getID() << ", ";;


			current = current->getNext();
		}
		if (current != nullptr)
		{
			std::cout << current->getItem()->getID();
		}
	}
	///////////////////////////////////////////////////////////////////////////////////

	template <typename T>
	LinkedQueue<T>::~LinkedQueue()
	{
		//Note that the cout statements here is just for learning purpose
		//they should be normally removed from the destructor

		//Free all nodes in the queue
		T temp;
		while (dequeue(temp));


	}


#endif