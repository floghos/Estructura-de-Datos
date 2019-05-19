#include "ADTPriorityQueue.h"
#include <bits/stdc++.h>


class PriorityQueueUnsorted: public ADTPriorityQueue {
private:
	int _size;
    std::vector<int> unsortedQ;
public:
	PriorityQueueUnsorted();
    int top();
    void pop();
    void push(int newData);
    int size();
    bool empty();
};
