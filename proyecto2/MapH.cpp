#include "MapH.h"
#include <string>
#include <iostream>

using namespace std;

//Private Methods
int MapH::goodhashCode(string key) {
	int hash = 13;
	for (int i = 0; i < key.length(); i++) {
		hash += key.at(i) * (1 << i);
	}
	return hash;
}

int MapH::secondHash(string key) {
	int prime = primeSizes[pIndex - 2];
	int hash = prime - (goodhashCode(key) % prime);
	return hash;
}

void MapH::rehash() {
	pIndex++;
	int newCapacity = primeSizes[pIndex];
	bucket *newMap = new bucket[newCapacity];
	for (int i = 0; i < capacity; i++) {
		if (hashTable[i].available) {
			continue;
		} else {
			int pos = goodhashCode(hashTable[i].key) % newCapacity;
			while (!newMap[pos].available) {
				pos += secondHash(hashTable[i].key); //double hashing
				pos %= newCapacity;
			}
			newMap[pos].key = hashTable[i].key;
			newMap[pos].val = hashTable[i].val;
			newMap[pos].available = false;
		}
	}
	delete[] hashTable;
	hashTable = newMap;
	capacity = newCapacity;
}

bool MapH::isFull() {
	return _size == capacity;
}

float MapH::loadFactor() { //I may not even use this
	return (float)_size/capacity;
}

//Public Methods
MapH::MapH() {
	_size = 0;
	pIndex = 2;
    capacity = primeSizes[pIndex];
    hashTable = new bucket[capacity];
}

void MapH::insert(pair<string, int> data) {
	int pos = goodhashCode(data.first) % capacity;
	while (!hashTable[pos].available) {
		pos += secondHash(data.first); //double hashing
		pos %= capacity;
	}

	hashTable[pos].key = data.first;
	hashTable[pos].val = data.second;
	hashTable[pos].available = false;
	_size++;
	if (isFull()) {
		rehash();
	}
}

void MapH::erase(string key) {
	bool error_404 = false; //key not found

	int pos = goodhashCode(key) % capacity;
	int startingPos = pos;
	while (hashTable[pos].key.compare(key) != 0) { //linear probing
		if (hashTable[pos].key.empty() || pos == startingPos) {
			error_404 = true;
			break;
		}
		pos += secondHash(key); //double hashing
		pos %= capacity;
	}

	if (error_404) {
		// cout << "Error 404: String not found\n";
	} else {
		hashTable[pos].available = true;
		_size--;
	}
}

int MapH::at(string key) {
	bool error_404 = false; //key not found

	int pos = goodhashCode(key) % capacity;
	int startingPos = pos;
	while (hashTable[pos].available || hashTable[pos].key.compare(key) != 0) { //linear probing
		if (hashTable[pos].key.empty() || pos == startingPos) {
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
		return hashTable[pos].val;
	}
}

int MapH::size() {
    return _size;
}

bool MapH::empty() {
    return !_size;
}
