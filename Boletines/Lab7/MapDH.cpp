#include "MapDH.h"
#include <string>
#include <iostream>

using namespace std;

//Private Methods
int MapDH::goodhashCode(string key) {
	int hash = 13;
	for (int i = 0; i < key.length(); i++) {
		hash += key.at(i) * (1 << i);
	}
	return hash;
}

int MapDH::secondHash(string key) {
	int prime = primeSizes[pIndex - 2];
	int hash = prime - (goodhashCode(key) % prime);
	return hash;
}

void MapDH::rehash() {
	pIndex++;
	int newCapacity = primeSizes[pIndex];
	box *newMap = new box[newCapacity];
	for (int i = 0; i < capacity; i++) {
		if (myMap[i].available) {
			continue;
		} else {
			int pos = goodhashCode(myMap[i].key) % newCapacity;
			while (!newMap[pos].available) {
				pos += secondHash(myMap[i].key); //double hashing
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

bool MapDH::isFull() {
	return _size == capacity;
}

float MapDH::loadFactor() { //I may not even use this
	return (float)_size/capacity;
}

//Public Methods
MapDH::MapDH() {
    capacity = primeSizes[pIndex];
    myMap = new box[capacity];
}

void MapDH::insert(pair<string, int> data) {
	int pos = goodhashCode(data.first) % capacity;
	while (!myMap[pos].available) {
		pos += secondHash(data.first); //double hashing
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

void MapDH::erase(string key) {
	bool error_404 = false; //key not found

	int pos = goodhashCode(key) % capacity;
	int startingPos = pos;
	while (myMap[pos].key.compare(key) != 0) { //linear probing
		if (myMap[pos].key.empty() || pos == startingPos) {
			error_404 = true;
			break;
		}
		pos += secondHash(key); //double hashing
		pos %= capacity;
	}

	if (error_404) {
		// cout << "Error 404: String not found\n";
	} else {
		myMap[pos].available = true;
		_size--;
	}
}

int MapDH::at(string key) {
	bool error_404 = false; //key not found

	int pos = goodhashCode(key) % capacity;
	int startingPos = pos;
	while (myMap[pos].available || myMap[pos].key.compare(key) != 0) { //linear probing
		if (myMap[pos].key.empty() || pos == startingPos) {
			error_404 = true;
			break;
		}
		pos += secondHash(key); //double hashing
		pos %= capacity;
	}

	if (error_404) {
		// cout << "Error 404: String not found\n";
		return -1;
	} else {
		return myMap[pos].val;
	}
}

int MapDH::size() {
    return _size;
}

bool MapDH::empty() {
    return !_size;
}
