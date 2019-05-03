#include "myQueue.h"

myQueue::myQueue() {
}

void myQueue::push(int data) {
    mainS.push_back(data);
}

void myQueue::pop() {
    int n = mainS.size();
    for (int i = 0; i < n; i++) {
        auxS.push_back(mainS.back() );
        mainS.pop_back();
    }
    auxS.pop_back();

    n = auxS.size();
    for (int i = 0; i < n; i++) {
        mainS.push_back(auxS.back() );
        auxS.pop_back();
    }
}

int myQueue::front() {
    int n = mainS.size();
    for (int i = 0; i < n; i++) {
        auxS.push_back(mainS.back() );
        mainS.pop_back();
    }
    int num = auxS.back();

    for (int i = 0; i < n; i++) {
        mainS.push_back(auxS.back() );
        auxS.pop_back();
    }
    return num;
}

int myQueue::back() {
    return mainS.back();
}

int myQueue::size() {
    return mainS.size();
}

bool myQueue::empty() {
    return mainS.empty();
}

// std::vector<int>::iterator myQueue::elements() {
//     return mainS.begin();
// }

class iterator {
    vector<int>::iterator it = mainS.begin();

    type operator*() const {
        return *it;
    }
    iterator& operator++() const {
        ++it;
    }
};
