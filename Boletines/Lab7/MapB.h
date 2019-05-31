#include "ADTMap.h"
#include <string>

struct box {
    int val;
	string key;
    bool available;
};

static int primeSizes[] = {53, 97, 193, 389, 769, 1543, 3079, 6151, 12289, 24593, 49157, 98317, 196613, 393241, 786433, 1572869, 3145739, 6291469, 12582917}

class MapB: public ADTMap {
private:
    box *myMap;
    int capacity; //current size of our array
	int pIndex = 0;
    int _size = 0; //occupied spaces in our array
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
