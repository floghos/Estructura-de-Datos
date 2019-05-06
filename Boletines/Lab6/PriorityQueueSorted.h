#include "ADTPriorityQueue.h"

struct node {
    int data;
    node *next;
};

class PriorityQueueSorted: public ADTPriorityQueue {
private:
    node *head;
    int _size;
public:
    PriorityQueueSorted();
    int top();
    void pop();
    void push(int data);
    int size();
    bool empty();
};
