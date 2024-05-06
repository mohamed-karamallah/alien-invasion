#pragma once
#include "DNode.h"
#include<iostream>
template <typename T>
class doubleEQ
{
private:
	DNode<T>* front;
	DNode<T>* rear;
	int size;
public:
	
	void print()
	{
		if (IsEmpty()) {

			return;
		}
		DNode<T>* current = front;
		while (current->getNext() != NULL)
		{
			std::cout << current->getItem()->getID() << ", ";;


			current = current->getNext();
		}
			std::cout << current->getItem()->getID();
		
	}
	doubleEQ() : front(nullptr), rear(nullptr) { size = 0; }
		bool IsEmpty() {
			if (front == nullptr && rear == nullptr)
				return true;
			else
				return false;
		}
		bool pushFront(const T & data) {
			DNode<T>* newNode = new DNode<T>(data);
			if (IsEmpty()) {
				front = rear = newNode;
				size++;
			}
			else {
				newNode->setNext(front);
				front->setprev(newNode);
				front = newNode;
				size++;
				return true;
			}
		}
		bool pushBack(const T & data) {
			DNode<T>* newNode = new DNode<T>(data);
			if (IsEmpty()) {
				front = rear = newNode;
				size++;
			}
			else {
				rear->setNext(newNode);
				newNode->setprev(rear);
				rear = newNode;
				size++;
				return true;
			}
		}

		int getSize()
		{
			return size;
		}


		bool popFront(T& frntEntry) {
			if (IsEmpty()) {

				return false;
			}


			if (front == rear) {
				frntEntry = front->getItem();
				front = rear = nullptr;
				size--;
			}
			else {
				DNode<T>* delptr = front;
				frntEntry = front->getItem();
				front = front->getNext();

				front->setprev(nullptr);
				delete delptr;
				size--;
				return true;

			}

		}

		bool popBack(T& frntEntry) {
			if (IsEmpty()) {

				return false;
			}


			if (front == rear) {
				frntEntry = front->getItem();
				front = rear = nullptr;
				size--;
			}
			else {
				DNode<T>* delptr = rear;
				frntEntry = rear->getItem();
				rear = rear->getprev();
				rear->setNext(nullptr);
				delete delptr;
				size--;
				return true;
			}


		}
		bool peekFront(T & frontdata) {
			if (IsEmpty())
			{
				frontdata = nullptr;
				return false;
			}
			else
			{
				frontdata = front->getItem();
				return true;

			}
		}
		bool peekBack(T & backdata) {
			if (IsEmpty())
			{
				backdata = nullptr;
				return false;
			}
			else
			{
				backdata = rear->getItem();
				return true;
			}
		}

		~doubleEQ() {
			while (!IsEmpty()) {
				T temp;
				popFront(temp);
			}
		}
	
	};