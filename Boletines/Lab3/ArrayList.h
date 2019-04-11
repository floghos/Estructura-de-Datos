#include "ListADT.h"


class ArrayList: public List {
private:
	int _size;
	int *array;

public:
	ArrayList(int n);
	void push_back(int num);
	int at(int i);
	int size();
};
