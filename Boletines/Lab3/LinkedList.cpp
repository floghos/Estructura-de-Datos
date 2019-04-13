#include "LinkedList.h"
#include <cstddef>
#include <iostream>

using namespace std;
//properties:
// node *last;
// int _size;

LinkedList:: LinkedList() {
	last = NULL;
	_size = 0;
}

void LinkedList::push_back(int num) {
	node *newNode = new node;
	newNode->data = num;
	newNode->next = last;
	last = newNode;
	_size++;
}

int LinkedList::at(int i){
	// if (i < _size && i >= 0) { //checks if "i" is within the usable margin
	//
	// } else {
	// 	int e;
	// 	throw e;
	// }

	node *aux = last;

	for (int k = 0; k < _size-1-i; k++) {
		aux = aux->next;
	}
	return aux->data;
}

int LinkedList::size() {
	return _size;
}

void LinkedList::remove(int i) {
	node *aux = last;
	node *prev = NULL;

	for (int k = 0; k < _size-1-i; k++) {
		prev = aux;
		aux = aux->next;
	}
	if (prev == NULL) {
		last = aux->next;
	} else {
		prev->next = aux->next;
	}
	delete aux;
	_size--;
}
