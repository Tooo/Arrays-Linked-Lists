//LL.cpp
#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "Classes.h"

//Constructor
LL::LL() {
    head = NULL;
    tail = NULL;
}

//Destructor
LL::~LL() {
    while (head != NULL) {
        node_t * removedNode = head;
        head = head->next;
        nodeRemove(removedNode);
    }
}

//Print all elements
void LL::Print(){
    // Empty Link List
    if (head == NULL) {
        printf("Linked List is empty\n");
        return;
    }
    node_t * curr = head;
    //Cycle through list
    while (curr != NULL) {
        printf("%d ",curr->data);
        curr = curr->next;
    }
    printf("\n");
}

//Get Head Node Pointer
node_t * LL::GetHead() {
    return head;
}

//Get Tail Node Pointer 
node_t * LL::GetTail() {
    return tail;
}

//Add Node at end of LL
void LL::Append(int val) {
    node_t * node = nodeCreate(val, NULL);
    //IF Empty
    if (head == NULL && tail == NULL) {
        head = node;
    } else { //Not Empty
        tail->next = node;
    }
    tail = node;
}

//Add Node at start of LL
void LL::Prepend(int val) {
    node_t * node = nodeCreate(val, NULL);
    //If Empty
    if (head == NULL && tail == NULL) {
        tail = node;
    } else { //Not Empty
        node->next = head;
    }
    head = node;
}

//Remove Head Node
void LL::RemoveHead() {
    //If not Empty
    if (head != NULL) {
        node_t * node = head;
        //If has only 1 node
        if (head == tail) {
            head = NULL;
            tail = NULL;
        } else { //2+ nodes
            head = head->next;
        }
        nodeRemove(node);
    }
}

//Remove Tail Node
void LL::RemoveTail() {
    //If not Empty
    if (tail != NULL) {
        node_t * node = tail;
        //If has only 1 node
        if (tail == head) {
            head = NULL;
            tail = NULL;
        } else { //2+ nodes
            node_t * curr = head;
            while (curr->next != tail) {
                curr = curr->next;
            }
            curr->next = NULL;
            tail = curr;
        }
        nodeRemove(node);
    }
}