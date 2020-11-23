//node.h
#ifndef Node_h
#define Node_h
#include <stdlib.h>

typedef struct _node {
    struct _node * next;
    int data;
} node_t;  

node_t * nodeCreate(int val, node_t * next);
void nodeRemove(node_t * node);

#endif