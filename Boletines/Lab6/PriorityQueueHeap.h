#include "ADTPriorityQueue.h"

class PriorityQueueHeap: public ADTPriorityQueue {
private:
    vector<int> heap;
public:
    int top();
    void pop();
    void push(int data);
    int size();
    bool empty();
};
