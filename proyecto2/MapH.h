#include "ADTMap.h"

struct bucket {
	int val;
	// string key = string();
	string key;
	bool available = true;
};

static int primeSizes[] = {53, 97, 193, 389, 769, 1543, 3079, 6151, 12289, 24593, 49157, 98317, 196613, 393241, 786433, 1572869, 3145739, 6291469, 12582917};

class MapH: public ADTMap {
private:
	int pIndex;
	bucket *hashTable;
	int _size;
	int capacity;
	int goodhashCode(string key);
	int secondHash(string key);
    void rehash();
    bool isFull();
	float loadFactor();
public:
	MapH();
	void insert(pair<string, int> entry);
	int at(string key);
	void erase(string key);
	bool empty();
	int size();
};
