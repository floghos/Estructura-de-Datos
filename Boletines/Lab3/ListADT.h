#ifndef LISTA_H
#define LISTA_H


class List {
public:
	virtual void push_back() = 0;
	virtual int at(int) = 0;
	virtual int size(int) = 0;
};

#endif
