#include "ADTQueue.h"
#include <bits/stdc++.h>

class qIterator;
class myQueue: public ADTQueue {
	friend class qIterator;
private:
    std::vector<int> mainS;
    std::vector<int> auxS;
public:
    myQueue();
    void push(int data);
    void pop();
    int front();
    int back();
    int size();
    bool empty();
	qIterator* elements();
};

class qIterator {
private:
	std::vector<int> *v;
	std::vector<int>::iterator it;
public:
	qIterator(myQueue *cola);
	bool hasNext();
	int next();
	void reset();
	// bool hasPrev();
	// int prev();
};
