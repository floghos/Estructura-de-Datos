#include "myQueue.h"

myQueue::myQueue() {
}

void myQueue::push(int data) {
    mainS.push(data);
}

void myQueue::pop() {
    int n = mainS.size();
    for (int i = 0; i < n; i++) {
        auxS.push(mainS.top() );
        mainS.pop();
    }
    auxS.pop();

    n = auxS.size();
    for (int i = 0; i < n; i++) {
        mainS.push(auxS.top() );
        auxS.pop();
    }
}

int myQueue::front() {
    int n = mainS.size();
    for (int i = 0; i < n; i++) {
        auxS.push(mainS.top() );
        mainS.pop();
    }
    int num = auxS.top();

    for (int i = 0; i < n; i++) {
        mainS.push(auxS.top() );
        auxS.pop();
    }
    return num;
}

int myQueue::back() {
    return mainS.top();
}

int myQueue::size() {
    return mainS.size();
}

bool myQueue::empty() {
    return mainS.empty();
}
