#include "ADTMap.h"
#include <string>

using namespace std;

static int primeSizes[] = {53, 97, 193, 389, 769, 1543, 3079, 6151, 12289, 24593, 49157, 98317, 196613, 393241, 786433, 1572869, 3145739, 6291469, 12582917};

class MapDH: public ADTMap {
private:
	box *myMap;
	int pIndex = 2; //keeps track of which primeSize[] we are currently using
    int capacity; //current size of our array
    int _size = 0; //occupied spaces in our array
    int goodhashCode(string key);
	int secondHash(string key);
    void rehash();
    bool isFull();
    float loadFactor();
public:
	MapDH();
    void insert(pair<string, int> data);
    void erase(string key);
    int at(string key);
    int size();
    bool empty();
};
