//	this is an updated version of code originally
//  created by Frank M. Carrano and timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** @file QueueADT.h */
#ifndef QUEUE_ADt_
#define QUEUE_ADt_

template<class T>
class QueueADT
{
public:
    /** Sees whether this queue is empty.
     @return  true if the queue is empty, or false if not. */
    virtual bool isEmpty() const = 0;

    /** Adds a new entry to the back of this queue.
     @post  If the operation was successful, newEntry is at the
        back of the queue.
     @param newEntry  the object to be added as a new entry.
     @return  true if the addition is successful or false if not. */
    virtual bool enqueue(const T& newEntry) = 0;

    /** Copies the front item of the queue to the passed parameter and removes it from queue
     @post  If the operation was successful, the front of the queue
        would be copied to FrontEntry parameter and removed from the queue.
     @return  true if the removal is successful or false if not. */
    virtual bool dequeue(T& FrontEntry) = 0;

    /** Copies the front item of the queue to the passed parameter without removing it from queue
     @pre  the queue is not empty.
     @post  the front of the queue has been copied to FrontEntry param , and the
        queue is unchanged.
     @return  the front of the queue. */
    virtual bool peek(T& FrontEntry) const = 0;

    /** Destroys this queue and frees its memory. */
    virtual ~QueueADT() { }
}; // end QueueADT
#endif