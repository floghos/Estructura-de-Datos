#include "clase.h"

clase::clase(int myInt) {
	_myInt = myInt;
}

int clase::getMyInt() {
	return _myInt;
}

void clase::incInt(int val) {
	_myInt += val;
}
