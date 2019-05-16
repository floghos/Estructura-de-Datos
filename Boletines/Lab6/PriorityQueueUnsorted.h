#include "ADTPriorityQueue.h"

class PriorityQueueUnsorted: public ADTPriorityQueue {
private:
    vector<int> unsortedQ;
public:
	PriorityQueueUnsorted();
    int top();
    void pop();
    void push(int data);
    int size();
    bool empty();
};
