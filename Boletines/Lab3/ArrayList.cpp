#include "ArrayList.h"
#include <iostream>
#include <cstddef>
#include <new>

// properties:
// int _size;
// int *array;
//
//
// methods:
// ArrayList(int n);
// void push_back(int num);
// int at(int i);
// int size();


// Don't forget to 'delete' (or 'delete[]') every array you allocate with 'new'.
ArrayList::ArrayList() {
	tam = 0;
	capacity = 64;
	array = new (std::nothrow) int[capacity]; //arbitrary starting capacity
}

void ArrayList::push_back(int num) {
	if (tam == capacity) {
		int *newarr = new (std::nothrow) int[capacity*2];
		if (newarr == NULL) {
			std::cout << "Error alocando memoria para ampliar la lista.\nElemento no agregado." << '\n';
		} else {
			capacity *= 2;
			for (int i = 0; i < tam; i++) {
				newarr[i] = array[i];
			}
			delete[] array;
			array = newarr;
			array[tam] = num;
			tam++;
		}
	} else {
		array[tam] = num;
		tam++;
	}
}

int ArrayList::at(int i) {
	return array[i];
}

int ArrayList::size() {
	return tam;
}
