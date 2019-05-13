#include "ADTPriorityQueue.h"
#include <bits/stdc++.h>


class PriorityQueueHeap: public ADTPriorityQueue {
private:
    const int head = 1;
    std::vector<int> heap;
    int _size;

    void upheap(int node);
    void downheap(int node);
    
public:
    PriorityQueueHeap();
    int top();
    void pop();
    void push(int newData);
    int size();
    bool empty();
};
