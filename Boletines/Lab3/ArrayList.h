#include "ListADT.h"


class ArrayList: public ListADT {
private:
	int tam;
	int *array;
	int capacity;
public:
	ArrayList();
	void push_back(int num);
	int at(int i);
	int size();
};
