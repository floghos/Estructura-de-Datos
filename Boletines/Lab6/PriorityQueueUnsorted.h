#include "ADTPriorityQueue.h"

class PriorityQueueUnsorted: public ADTPriorityQueue {
private:
    vector<int> unsortedQ;
public:
    int top();
    void pop();
    void push(int data);
    int size();
    bool empty();
};
