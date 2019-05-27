#include "ADTMap.h"
#include <string>

struct box {
    int val;
    bool available;
};

class MapB: public ADTMap {
private:
    box *myMap;
    int N; //current size of our array
    int _size; //occupied spaces in our array
    int badhash(std::string key);
    void rehash();
    bool isFull();
    float loadFactor();
public:
    MapB();
    void insert(pair<std::string, int> data);
    void erase(std::string key);
    int at(std::string key);
    int size();
    bool empty();
};
