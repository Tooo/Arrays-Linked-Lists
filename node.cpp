#include "node.h"

node_t * nodeCreate(int val, node_t * next) {
    node_t * newNode = new node_t;
    newNode->data = val;
    newNode->next = next;
    return newNode;
}

void nodeRemove(node_t * node) {
    node->data = 0;
    node->next = NULL;
    delete node;
}
