#include <bits/stdc++.h>
#include "myQueue.h"

using namespace std;

int main(int argc, char const *argv[]) {
    myQueue q;
    int n = 20;

    cout << q.empty() << "\n\n";
    for (int i = 0; i < n; i++) { //llenar la queue
        q.push(i);
    }
    cout << "size? " << q.size() << '\n';
	cout << "empty? " << q.empty() << "\n\n";


	qIterator *it = q.elements();
	for (int i = 0; i < n; i++) {
		cout << "tiene siguiente? " << it->hasNext() << '\n';
		if (it->hasNext()) {
			cout << it->next() << '\n';
		}
	}


    return 0;
}


// for (int i = 0; i < n; i++) { //vaciar la queue
	//     cout << q.front();
	//     q.pop();
	//     cout << "(" << q.size() << ") ";
	// }
	// cout << '\n';
	// cout << q.size() << '\n';
	// cout << q.empty() << '\n';
