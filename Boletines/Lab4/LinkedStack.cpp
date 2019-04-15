#include "LinkedStack.h"
#include <cstddef>


LinkedStack::LinkedStack() {
	_top = NULL;
	_size = 0;
}

void LinkedStack::push(int data) {
	node *newNode = new node;
	newNode->data = data;
	newNode->next = _top;
	_top = newNode;
	_size++;
}

int LinkedStack::pop() {
    if (_top == NULL) return 0;

    node *aux = _top;
    int temp = _top->data;
    _top = _top->next;
    delete aux;
    return temp;
}

bool LinkedStack::isEmpty() {
    if (_top == NULL) return true;
    else return false;
}
