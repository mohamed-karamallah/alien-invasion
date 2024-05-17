#ifndef LINKED_STACK_
#define LINKED_STACK_
#include<iostream>
#include "Node.h" // Include the Node class
#include"StackADT.h"

using namespace std;

template <typename T>
class LinkedStack {
private:
    Node<T>* top;
    int size;
public:
    LinkedStack();
    bool isEmpty() const;
    bool push(const T& element);
    bool pop(T& stacktop);
    bool peek(T& stacktop)  const;
    int getlength();
    void print();
    ~LinkedStack();
    int getSize();
};
template <typename T>

LinkedStack<T>::LinkedStack() {
    top = nullptr;
    size = 0;
}
template <typename T>
bool LinkedStack<T>::isEmpty() const {
    return top == nullptr;
}
template <typename T>
bool LinkedStack<T>::push(const T& element) { 
    Node<T>* newnodeptr = new Node<T>(element); 
    if (newnodeptr == nullptr) {
        return false;
    }
    else {
        newnodeptr->setNext(top);
        top = newnodeptr;
        size++;
        return true;
    }
}
template <typename T>

bool LinkedStack<T>::pop(T& stacktop) {
    if (isEmpty()) {

        return false;
    }
    else {
        stacktop = top->getItem();
        Node<T>* current = top;
        top = top->getNext();
        delete current;
        size--;
        return true;
    }
}
template <typename T>
bool LinkedStack<T>::peek(T& stacktop) const { // Implement peek function
    if (isEmpty()) {
 
        return false;
    }
    else {
        stacktop = top->getItem();
        return true;
    }
}

template <typename T>
int LinkedStack<T>::getlength() {
    return size;
}
template <typename T>
LinkedStack<T>::~LinkedStack() {
   /* while (!isEmpty()) {
        pop();
    }*/
}
template<typename T>
inline int LinkedStack<T>::getSize()
{
    return size;
}
template <typename T>
void LinkedStack<T>::print()
{
    if (isEmpty()) {
  
        return;
    }

    Node<T>* current = top;
    
    while (current->getNext() != NULL)
    {
        std::cout << current->getItem()->getID() << ", ";;


        current = current->getNext();
    }
    if (current != nullptr)
    {
        std::cout << current->getItem()->getID();
    }
 
}

#endif


