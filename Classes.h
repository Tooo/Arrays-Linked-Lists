//Classes.h
#include "node.h"

class LL
{
    private:
        node_t * head;
        node_t * tail;
    public:
        LL();
        ~LL();
        void Print();

        node_t * GetHead();
        node_t * GetTail();

        void Append(int val);
        void Prepend(int val);

        void RemoveHead();
        void RemoveTail();
};

class Stack {
	private:
		LL * list;
	public:
        Stack();
		~Stack();
        
		void Push(int value);
		void Pop();
		void Print();
};

class Queue {
    private:
        LL * list;
    public:
        Queue();
        ~Queue();

        void Enqueue(int val);
        void Dequeue();
        void Print();
};