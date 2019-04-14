#include "ArrayList.h"
#include <iostream>
#include <cstddef>
#include <new>

// properties:
// int _size;
// int *array;
// int capacity;


// Don't forget to 'delete' (or 'delete[]') every array you allocate with 'new'.
ArrayList::ArrayList() {
	_size = 0;
	capacity = 64;
	array = new (std::nothrow) int[capacity]; //arbitrary starting capacity
}

void ArrayList::push_back(int num) {
	if (_size == capacity) {
		int *newarr = new (std::nothrow) int[capacity*2];
		if (newarr == NULL) {
			std::cout << "Error alocando memoria para ampliar la lista.\nElemento no agregado." << '\n';
		} else {
			capacity *= 2;
			for (int i = 0; i < _size; i++) {
				newarr[i] = array[i];
			}
			delete[] array;
			array = newarr;
			array[_size] = num;
			_size++;
		}
	} else {
		array[_size] = num;
		_size++;
	}
}

int ArrayList::at(int i) {
	return array[i];
}

int ArrayList::size() {
	return _size;
}

void ArrayList::remove(int i) {
	for (int k = i; k < _size-1; k++) {
		array[k] = array[k+1];
	}
}
