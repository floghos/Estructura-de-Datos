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
    _size--;
    return array[_size];
}

bool ArrayStack::isEmpty() {
    if (_size) return false;
    else return true;
}
