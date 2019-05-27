#include "ADTMap.h"
#include <string>

class MapB: public ADTMap {
private:
    int *myMap;
    int N; //current size of our array
    int _size; //occupied spaces in our array
    int hash(std::string key);
    void rehash();
    bool isFull();
    double loadFactor();
public:
    MapB();
    int insert(pair<std::string, int> data);
    void erase(std::string str);
    int at(int i);
    int size();
    bool empty();
};
