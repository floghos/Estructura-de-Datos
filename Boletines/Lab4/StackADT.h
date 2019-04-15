#ifndef STACK_H
#define STACK_H

class StackADT {
public:
    virtual void push(int) = 0;
    virtual int pop() = 0;
    virtual bool isEmpty() = 0;
};
#endif
