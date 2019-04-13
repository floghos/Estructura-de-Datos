#include <iostream>
#include <cstdlib>
#include "ListADT.h"
#include "ArrayList.h"
#include "LinkedList.h"

using namespace std;

int main(int argc, char const *argv[]) {
//Array list test
	// ArrayList aList;

	// for (int i = 0; i < 100; i++) {
	// 	aList.push_back(i);
	// }
	// for (int i = 0; i < 100; i++) {
	// 	cout << aList.at(i) << '\n';
	// }


//Linked List test
	LinkedList lList;

	for (int i = 0; i < 10; i++) {
		lList.push_back(i);
	}

	for (int i = 0; i < lList.size(); i++) {
		cout << lList.at(i) << '\n';
	}

	int x = 0;
	cout << "removing item " << x << '\n';
	lList.remove(x);

	for (int i = 0; i < lList.size(); i++) {
		cout << lList.at(i) << '\n';
	}

	return 0;
}
