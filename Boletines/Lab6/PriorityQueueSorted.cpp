#include "PriorityQueueSorted.h"
#include <bits/stdc++.h>
using namespace std;

PriorityQueueSorted::PriorityQueueSorted() {
    head = NULL;
    _size = 0;
}

int PriorityQueueSorted::top() {
    return head->data;
}

void PriorityQueueSorted::pop() {
    if (_size) {
        node *aux = head;
        head = head->next;
        delete aux;
        _size--;
    }
}

void PriorityQueueSorted::push(int newData) {
    node *temp = new node;
    temp->data = newData;
    if (_size) { //the list is not empty
        node *current = head;
        node *prev = NULL;
        while (current != NULL && current->data < newData) { //looking for where to insert the new node
            prev = current;
            current = current->next;
        }

        if (prev == NULL) { //the new data smaller than the first element
            temp->next = head;
            head = temp;
        } else { //somewhere within the list, between "prev" and "current"
			prev->next = temp;
			temp->next = current;
        }
    } else { //the list is empty
        temp->next = NULL;
        head = temp;
    }
    _size++;
}

int PriorityQueueSorted::size() {
    return _size;
}

bool PriorityQueueSorted::empty() {
    if (_size) return false;
    else return true;
}
