#ifndef PQUEUE_H
#define PQUEUE_H

class ADTPriorityQueue {
public:
    virtual int top() = 0;
    virtual void pop() = 0;
    virtual void push(int) = 0;
    virtual int size() = 0;
    virtual bool empty() = 0;
};

#endif
