#include "MapB.h"
#include <string>
#include <iostream>

using namespace std;

//Private Methods
int MapB::badhashCode(string key) {
	return (int)key.back();
}

void MapB::rehash() {
	int newCapacity = capacity * 2;
	box *newMap = new box[capacity];
	for (int i = 0; i < capacity; i++) {
		if (myMap[i].available) {
			continue;
		} else {
			int pos = badhashCode(myMap[i].key) % newCapacity;
			while (!newMap[pos].available) { //linear probing
				pos++;
				pos %= newCapacity;
			}
			newMap[pos].key = myMap[i].key;
			newMap[pos].val = myMap[i].val;
			newMap[pos].available = false;
		}
	}
	delete[] myMap;
	myMap = newMap;
	capacity = newCapacity;
}

bool MapB::isFull() {
	return _size == capacity;
}

float MapB::loadFactor() { //I may not even use this
	return (float)_size/capacity;
}

//Public Methods
MapB::MapB() {
    capacity = 10;
    myMap = new box[capacity];
}

void MapB::insert(pair<string, int> data) {
	int pos = badhashCode(data.first) % capacity;
	while (!myMap[pos].available) { //linear probing
		pos++;
		pos %= capacity;
	}

	myMap[pos].key = data.first;
	myMap[pos].val = data.second;
	myMap[pos].available = false;
	_size++;
	if (isFull()) {
		rehash();
	}
}

void MapB::erase(string key) {
	bool error_404 = false; //key not found

	int pos = badhashCode(key) % capacity;
	while (myMap[pos].key.compare(key) != 0) { //linear probing
		if (myMap[pos].key.empty()) {
			error_404 = true;
			break;
		}
		pos++;
		pos %= capacity;
	}

	if (error_404) {
		cout << "Error 404: String not found\n";
	} else {
		myMap[pos].available = true;
		_size--;
	}
}

int MapB::at(string key) {
	bool error_404 = false; //key not found

	int pos = badhashCode(key) % capacity;
	while (myMap[pos].available || myMap[pos].key.compare(key) != 0) { //linear probing
		if (myMap[pos].key.empty()) {
			error_404 = true;
			break;
		}
		pos++;
		pos %= capacity;
	}

	if (error_404) {
		cout << "Error 404: String not found\n";
		return 0;
	} else {
		return myMap[pos].val;
	}
}

int MapB::size() {
    return _size;
}

bool MapB::empty() {
    return !_size;
}
