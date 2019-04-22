#include "ADTQueue.h"
#include <stack>

class myQueue: public ADTQueue {
private:
    std::stack<int> mainS;
    std::stack<int> auxS;
public:
    myQueue();
    void push(int data);
    void pop();
    int front();
    int back();
    int size();
    bool empty();
};
