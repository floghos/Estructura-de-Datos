#include "ListADT"

struct node {
	int n;
	node *next;
};

class LinkedList: public List {
private:
	node ini;
	// node end;
	int _size;

public:
	LinkedList();
	//requeridas
	void push_back(int num);
	int at(int i);
	int size();

	//adicionales
	void remove(int i);
}
