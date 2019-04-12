#ifndef LISTA_H
#define LISTA_H


class ListADT {
public:
	virtual void push_back(int) = 0;
	virtual int at(int) = 0;
	virtual int size() = 0;
};

#endif
