#include "ADTPriorityQueue.h"
#include <bits/stdc++.h>


class PriorityQueueUnsorted: public ADTPriorityQueue {
private:
    std::vector<int> unsortedQ;
public:
    int top();
    void pop();
    void push(int newData);
    int size();
    bool empty();
};
