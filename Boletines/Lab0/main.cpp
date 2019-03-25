#include <iostream>
#include "clase.h"
#include "myClass.h"

using namespace std;

int main() {
	// clase c(5);
	// c.incInt(3);
	myClass b(3);

	b.mostrar();
	cout << b.suma() << endl;
}
