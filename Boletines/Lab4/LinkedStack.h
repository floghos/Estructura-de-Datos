#include "StackADT.h"

struct node {
    int data;
    node *next;
};

class LinkedStack: public StackADT {
private:
	int _size;
	node *_top;
public:
	LinkedStack();
	void push(int data);
	int pop();
	bool isEmpty();
};
