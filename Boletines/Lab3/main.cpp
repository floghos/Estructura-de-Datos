#include <iostream>
#include <cstdlib>
#include "ListADT.h"
#include "ArrayList.h"
#include "LinkedList.h"

using namespace std;

int main(int argc, char const *argv[]) {
	ArrayList aList;

	for (int i = 0; i < 100; i++) {
		aList.push_back(i);
	}
	for (int i = 0; i < 100; i++) {
		cout << aList.at(i) << '\n';
	}

	return 0;
}


// int main() {
// 	// clase c(5);
// 	// c.incInt(3);
// 	myClass b(3);
//
// 	b.mostrar();
// 	cout << b.suma() << endl;
// }
