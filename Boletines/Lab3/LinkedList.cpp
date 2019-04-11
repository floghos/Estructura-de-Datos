#include "LinkedList.h"


LinkedList:: LinkedList() {
	ini = NULL;
	// end = NULL;
	_size = 0;
}

LinkedList:: void push_back(int num) {
	node aux;
	aux.n = num;
	aux.next = NULL;

	ini.next = aux;
}

LinkedList:: int at(int i) {
	if (i < _size) {
		node aux = ini;
		for (int k = 0; k < i; k++) {

		}

	} else return NULL;

}

LinkedList:: int size() {
	return _size;
}
