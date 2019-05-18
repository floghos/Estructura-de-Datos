#include "PriorityQueueHeap.h"
#include <bits/stdc++.h>


void PriorityQueueHeap::upheap(int node) {
    int parent = node / 2;
    if (parent && heap[node] < heap[parent]) {
        std::swap(heap[node], heap[parent]);
        upheap(parent);
    }
}

void PriorityQueueHeap::downheap(int node) {
    int child = node * 2;
    if (child <= _size) {
        if (heap[child] < heap[child + 1]) {
            std::swap(heap[node], heap[child]);
            downheap(child);
        } else {
            std::swap(heap[node], heap[child + 1]);
            downheap(child + 1);
        }
    }
}

PriorityQueueHeap::PriorityQueueHeap() {
    _size = 0;
    heap.push_back(0);
}

int PriorityQueueHeap::top() {
    if (heap.size()) {
		return heap[1];
	} else {
		std::cout << "Priority Queue is Empty.\nReturning 0 as default..." << '\n';
		return 0;
	}

}

void PriorityQueueHeap::pop() {
    if (_size) {
        heap[1] = heap[_size];
        _size--;
        downheap(1);
    }
}

void PriorityQueueHeap::push(int newData) {
    heap.push_back(newData);
    _size++;
    upheap(_size);
}

int PriorityQueueHeap::size() {
    return _size;
}

bool PriorityQueueHeap::empty() {
    return !_size;
}
