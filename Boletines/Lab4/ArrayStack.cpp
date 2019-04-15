#include "ArrayStack.h"

ArrayStack::ArrayStack() {
    array = new int[10000000]; //10⁷
    _size = 0;
}

void ArrayStack::push(int data) {
    array[_size] = data;
    _size++;
}

int ArrayStack::pop() {
    // if (this.isEmpty()) {
    //     throw int a;
    // } else {
    // }
    _size--;
    return array[_size+1];
}

bool ArrayStack::isEmpty() {
    if (_size) return false;
    else return true;
}

// private:
//     int *array;
//     int _size;
// public:
//     ArrayStack();
//     void push(int data);
//     int pop();
//     bool isEmpty();
