#include "ADTQueue.h"
#include <vector>


class myQueue: public ADTQueue {
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
    std::vector<int>::iterator elements();
};
