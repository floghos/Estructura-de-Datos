#include "PriorityQueueUnsorted.h"
#include <bits/stdc++.h>

int PriorityQueueUnsorted::top() {
    int min = unsortedQ.front();
    for (int i = 1; i < unsortedQ.size(); ++i) {
        if (min > unsortedQ[i]) min = unsortedQ[i];
    }
    return min;
}

void PriorityQueueUnsorted::pop() {
    int min = unsortedQ.front();
    int pos = 0;
    for (int i = 1; i < unsortedQ.size(); ++i) {
        if (min > unsortedQ[i])  {
            min = unsortedQ[i];
            pos = i;
        }
    }
    for (int i = pos; i < unsortedQ.size()-1; ++i) {
        unsortedQ[i] = unsortedQ[i+1];
    }
}

void PriorityQueueUnsorted::push(int data) {
    unsortedQ.push_back(data);
}

int PriorityQueueUnsorted::size() {
    return unsortedQ.size();
}

bool PriorityQueueUnsorted::empty() {
    return unsortedQ.empty();
}

// public:
//     int top();
//     void pop();
//     void push(int data);
//     int size();
//     bool empty();
