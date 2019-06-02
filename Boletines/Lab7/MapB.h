#include "ADTMap.h"
#include <string>

using namespace std;

class MapB: public ADTMap {
private:
    box *myMap;
    int capacity; //current size of our array
    int _size = 0; //occupied spaces in our array
    int badhashCode(string key);
    void rehash();
    bool isFull();
    float loadFactor();
public:
    MapB();
    void insert(pair<string, int> data);
    void erase(string key);
    int at(string key);
    int size();
    bool empty();
};
