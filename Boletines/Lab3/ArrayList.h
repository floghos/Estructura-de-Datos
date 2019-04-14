#include "ListADT.h"


class ArrayList: public ListADT {
private:
	int _size;
	int *array;
	int capacity;
public:
	ArrayList();
	//requeridas
	void push_back(int num);
	int at(int i);
	int size();
	//adicionales
	void remove(int i);

};
