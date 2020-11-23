//Stack.cpp
#include "Classes.h"

//Constructor
Stack::Stack() {
    list = new LL;
}

//Destructor
Stack::~Stack() {
    delete list;
}

//Add value in start of Stack
void Stack::Push(int value) {
    list->Prepend(value);
}

//Remove first element and return value
void Stack::Pop() {
    return list->RemoveHead();
}

//Print elements in stack in the order they would be popped
void Stack::Print() {
    list->Print();
}