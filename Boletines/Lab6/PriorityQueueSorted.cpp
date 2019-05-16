#include "PriorityQueueSorted.h"
#include <bits/stdc++.h>

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
    }

}

void PriorityQueueSorted::push(int data) {
    node *temp = new node;
    temp->data = data;
    if (_size) {
        node *current = NULL;
        node *prev = NULL;
        current = head;
        while (current->data < data) {
            prev = current;
            current = current->next;
        }
        if (prev == NULL) { //smaller than the first element
            temp->next = head;
            head = temp;
        } else { //somewhere within the list, between "prev" and "current"
			temp->next = current;
			prev->next = temp;
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
