#include <bits/stdc++.h>
#include "myQueue.h"

using namespace std;

int main(int argc, char const *argv[]) {
    myQueue q;
    int n;

	cin >> n;
	cout << "n = " << n << '\n';
	
	clock_t t1 = clock();
    for (int i = 0; i < n; i++) { //llenar la queue
        q.push(i);
    }
	clock_t t2 = clock();
	double tiempo = (double)(t2-t1)/CLOCKS_PER_SEC;
	printf("push(): %.10f\n", tiempo);
	///////////////////////////////////////////////////////////////////////

	t1 = clock();
    for (int i = 0; i < 100; i++) {
        q.front();
    }
	t2 = clock();
	tiempo = (double)(t2-t1)/CLOCKS_PER_SEC;
	tiempo /= 100;
	printf("front(): %.10f\n", tiempo);

	///////////////////////////////////////////////////////////////////////

	t1 = clock();
    for (int i = 0; i < 100; i++) {
        q.back();
    }
	t2 = clock();
	tiempo = (double)(t2-t1)/CLOCKS_PER_SEC;
	tiempo /= 100;
	printf("back(): %.10f\n", tiempo);

	///////////////////////////////////////////////////////////////////////

	t1 = clock();
    for (int i = 0; i < 100; i++) {
        q.size();
    }
	t2 = clock();
	tiempo = (double)(t2-t1)/CLOCKS_PER_SEC;
	tiempo /= 100;
	printf("size(): %.10f\n", tiempo);

	///////////////////////////////////////////////////////////////////////

	t1 = clock();
    for (int i = 0; i < n; i++) { //llenar la queue
        q.push(i);
    }
	t2 = clock();
	tiempo = (double)(t2-t1)/CLOCKS_PER_SEC;
	printf("pop(): %.10f\n", tiempo);

	///////////////////////////////////////////////////////////////////////

	// void push(int data);
	// int front();
	// int back();
	// int size();
	// void pop();


	// qIterator *it = q.elements();
	// for (int i = 0; i < n; i++) {
	// 	cout << "tiene siguiente? " << it->hasNext() << '\n';
	// 	if (it->hasNext()) {
	// 		cout << it->next() << '\n';
	// 	}
	// 	if (i == 6) {
	// 		it->reset();
	// 	}
	// }


    return 0;
}
