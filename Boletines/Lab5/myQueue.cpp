#include "myQueue.h"
// #include "iterador.h"
#include <bits/stdc++.h>


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

qIterator* myQueue::elements() {
	return new qIterator(this);
}

qIterator::qIterator(myQueue *cola) {
	first = true;
	v = &(cola->mainS);
	it = v->begin();
}

bool qIterator::hasNext() {
	std::vector<int>::iterator aux = it;
	++aux;
	return (aux != v->end());
}

int qIterator::next() {
	if (first) {
		first = false;
	} else {
		++it;
	}
	return *it;
}

void qIterator::reset() {
	it = v->begin();
	first = true;
}
