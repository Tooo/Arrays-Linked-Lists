//Queue.cpp
#include "Classes.h"

//Constructor
Queue::Queue() {
    list = new LL;
}

//Destructor
Queue::~Queue() {
    delete list;
}

void Queue::Enqueue(int val) {
    list->Append(val);
}

void Queue::Dequeue() {
    list->RemoveHead();
}

void Queue::Print() {
    list->Print();
}