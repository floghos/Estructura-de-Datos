#include "StackADT.h"

class ArrayStack: public StackADT {
private:
    int *array;
    int _size;
public:
    ArrayStack();
    void push(int data);
    int pop();
    bool isEmpty();
};
