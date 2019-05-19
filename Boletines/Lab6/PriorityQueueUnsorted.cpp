#include "PriorityQueueUnsorted.h"
#include <bits/stdc++.h>


PriorityQueueUnsorted::PriorityQueueUnsorted() {
	_size = 0;
}

int PriorityQueueUnsorted::top() {
    int min = unsortedQ.front();
    for (int i = 1; i < _size; ++i) {
        if (min > unsortedQ[i]) min = unsortedQ[i];
    }
    return min;
}

void PriorityQueueUnsorted::pop() {
    int min = unsortedQ.front();
    int pos = 0;
	int oldSize = _size;
    for (int i = 1; i < oldSize; ++i) {
        if (min > unsortedQ[i])  {
            min = unsortedQ[i];
            pos = i;
        }
    }
    for (int i = pos; i < oldSize-1; ++i) {
        unsortedQ[i] = unsortedQ[i + 1];
    }
	_size--;
}

void PriorityQueueUnsorted::push(int newData) {
    unsortedQ.push_back(newData);
	_size++;
}

int PriorityQueueUnsorted::size() {
    return _size;
}

bool PriorityQueueUnsorted::empty() {
    return !_size;
}

// public:
//     int top();
//     void pop();
//     void push(int data);
//     int size();
//     bool empty();
