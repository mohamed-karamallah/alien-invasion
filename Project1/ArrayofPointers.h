#pragma once
#include<iostream>
#include"Unit.h"
#include"AlienMonsters.h"
#define MAX 100

class ArrayofPointers
{
private:

    int counter;

    AlienMonsters* elements[MAX];
public:
    ArrayofPointers() {
        counter = 0;


    }
    bool IsEmpty() {
        return counter == 0;
    }

    void addElement(AlienMonsters *element) {
        if (counter < MAX) {
            elements[counter++] = element;
        }
        else {
            return;
        }
    }

    void removeElementrandomly(AlienMonsters* element) {
       /* if (counter > 0) {
            int index = rand() % counter;
            element = elements[index];
            elements[index] = elements[--counter];
        }
        else {
            element=nullptr;
        }
        for (int i = 0; i < counter; i++) {
            if (elements[i] == element)
                delete elements[i];
        }*/
        for (int i = 0; i < counter; i++) {
            if (elements[i] == element) {
                 elements[i]=nullptr;
                elements[i] = elements[counter - 1]; // Replace with last element
                counter--; // Decrement the counter since an element is removed
                break; // Exit loop after first occurrence is removed
            }
        }
    }
    
    int getSize() {
        return counter;
    }

    AlienMonsters* peek() {
        if (counter > 0) {
            int index = rand() % counter;
            
            return elements[index];
        }
        else {
            return nullptr;
        }
    }




    ~ArrayofPointers() {
        // Deallocate memory for each stored element
        for (int i = 0; i < counter; i++) {
            delete elements[i];
        }
    }
    
    void print() {
        if (IsEmpty()) {

            return;
        }
        for (int i = 0; i < counter; i++) {
             
            cout << elements[i]->getID();

            if (i < counter - 1) {
                cout << ", ";
            }
        }
    }
};





