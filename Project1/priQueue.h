#pragma once
#include "priNode.h"


//this class impelements the priority queue as a sorted list (Linked List)
//the item with highest priority is at the front of the queue
template <typename T>
class priQueue
{
    priNode<T>* head;
    int size;
public:
   priNode<T>* getFront() 
      {
        // Check if the queue is empty
        if (isEmpty())
        {
            // Print an error message or return a default value (depending on your preference)
        
            // You can also throw an exception here if you prefer
            // throw std::runtime_error("doubleEQ: getFront called on empty queue");
        }
        else
        {
            return head->getItem(); // Return the data item from the front node
        }
   }
   //template <typename T>
   void print()
   {
       if (isEmpty()) {

           return;
       }
       priNode<T>* current = head;
       while (current->getNext()!= nullptr) {
           int pri = current->getPri();
           std::cout << current->getItem(pri)->getID() << ", ";


           current = current->getNext();
       }
       if (current != NULL)
       {
           int pri = current->getPri();
           std::cout << current->getItem(pri)->getID() ;

       }
   }
   //template<typename T>
   int getSize()
   {
       return size;
   }
    priQueue() : head(nullptr) {}

    ~priQueue() {
        T tmp;
        int p;
        while (dequeue(tmp, p));
    }

    //insert the new node in its correct position according to its priority
    void enqueue(const T& data, int priority) {
        priNode<T>* newNode = new priNode<T>(data, priority);

        if (head == nullptr || priority > head->getPri()) {

            newNode->setNext(head);
            head = newNode;
            size++;
            return;
        }

        priNode<T>* current = head;
        while (current->getNext() && priority <= current->getNext()->getPri()) {
            current = current->getNext();
        }
        newNode->setNext(current->getNext());
        current->setNext(newNode);
        size++;
    }

    bool dequeue(T& topEntry, int& pri) {
        if (isEmpty())
            return false;

        topEntry = head->getItem(pri);
        priNode<T>* temp = head;
        head = head->getNext();
        delete temp;
        size--;
        return true;
    }

    bool peek(T& topEntry) {
        if (isEmpty())
            return false;
        int pri = head->getPri();
        topEntry = head->getItem(pri);
        pri = head->getPri();
        return true;
    }
 
    bool isEmpty() const {
        return head == nullptr;
    }
};
