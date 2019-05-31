#include "MapB.h"
#include <string>

//Private Methods
int MapB::badhash(std::string key) {
	return key.back();
}

void MapB::rehash() {

}

bool MapB::isFull() {
	return _size == capacity;
}

float MapB::loadFactor() {
	return _size/capacity;
}

//Public Methods
MapB::MapB() {
    capacity = primeSizes[pIndex];
    mymap = new box[capacity];
}

void MapB::insert(pair<std::string, int> data) {
	
}

void MapB::erase(std::string key) {

}

int MapB::at(std::string key) {

}

int MapB::size() {
    return _size;
}

bool MapB::empty() {
    return !_size;
}
