#include "ListADT.h"

struct node {
	int data;
	node *next;
};

class LinkedList: public ListADT {
private:
	int _size;
	node *last;
public:
	LinkedList();
	//requeridas
	void push_back(int num);
	int at(int i);
	int size();

	//adicionales
	void remove(int i);
};
