#include <bits/stdc++.h>
#include "myQueue.h"

using namespace std;

int main(int argc, char const *argv[]) {
    myQueue q;
    int n = 20;

    cout << q.empty() << "\n\n";
    for (int i = 0; i < n; i++) {
        q.push(i);
    }
    cout << q.size() << '\n';
    cout << q.empty() << "\n\n";

    //vector<int>::iterator p = q.elements();

    myQueue::iterator p = q.elements();
    ++p;
    cout << *p << '\n';

    for (int i = 0; i < n; i++) {
        cout << q.front();
        q.pop();
        cout << "(" << q.size() << ") ";
    }
    cout << '\n';
    cout << q.size() << '\n';
    cout << q.empty() << '\n';


    return 0;
}
