#include "MapB.h"
#include <string>

//Private Methods
int MapB::badhash(std::string key) {
    
}

void MapB::rehash() {

}

bool MapB::isFull() {

}

float MapB::loadFactor() {

}

//Public Methods
MapB::MapB() {
    N = 10;
    mymap = new box[N];
    _size = 0;
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
