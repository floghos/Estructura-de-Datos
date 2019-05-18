#include "ADTPriorityQueue.h"
#include <vector>


class PriorityQueueHeap: public ADTPriorityQueue {
private:
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
