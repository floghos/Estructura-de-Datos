#include "MapG.h"
#include <string>
#include <iostream>

using namespace std;

//Private Methods
int MapG::goodhashCode(string key) {
	int hash = 13;
	for (int i = 0; i < key.length(); i++) {
		hash += key.at(i) * (1 << i);
	}
	return hash;
}

void MapG::rehash() {
	int newCapacity = capacity * 2;
	box *newMap = new box[newCapacity];
	for (int i = 0; i < capacity; i++) {
		if (myMap[i].available) {
			continue;
		} else {
			int pos = goodhashCode(myMap[i].key) % newCapacity;
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

bool MapG::isFull() {
	return _size == capacity;
}

float MapG::loadFactor() { //I may not even use this
	return (float)_size/capacity;
}

//Public Methods
MapG::MapG() {
    capacity = 10;
    myMap = new box[capacity];
}

void MapG::insert(pair<string, int> data) {
	int pos = goodhashCode(data.first) % capacity;
	while (!myMap[pos].available) {
		pos++; //linear probing
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

void MapG::erase(string key) {
	bool error_404 = false; //key not found

	int pos = goodhashCode(key) % capacity;
	int startingPos = pos;
	while (myMap[pos].key.compare(key) != 0) { //linear probing
		if (myMap[pos].key.empty() || pos == startingPos) {
			error_404 = true;
			break;
		}
		pos++;
		pos %= capacity;
	}

	if (error_404) {
		// cout << "Error 404: String not found\n";
	} else {
		myMap[pos].available = true;
		_size--;
	}
}

int MapG::at(string key) {
	bool error_404 = false; //key not found

	int pos = goodhashCode(key) % capacity;
	int startingPos = pos;
	while (myMap[pos].available || myMap[pos].key.compare(key) != 0) { //linear probing
		if (myMap[pos].key.empty() || pos == startingPos) {
			error_404 = true;
			break;
		}
		pos++;
		pos %= capacity;
	}

	if (error_404) {
		// cout << "Error 404: String not found\n";
		return -1;
	} else {
		return myMap[pos].val;
	}
}

int MapG::size() {
    return _size;
}

bool MapG::empty() {
    return !_size;
}
