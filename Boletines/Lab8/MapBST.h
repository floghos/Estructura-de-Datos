#include "ADTMap.h"
#include <string>
#include <cstddef>

using namespace std;

struct box {
    string key;
    int val = -1;
    box *left = NULL;
    box *right = NULL;
};

class MapBST: public ADTMap {
private:
    int _size = 0;
    box *root;
    void insert(pair<string, int> entry, box *&node);
    void erase(string key, box *&node); // WIP
	box * predecesor(box *node);
    int at(string key, box *node);
public:
    MapBST();
    void insert(pair<string, int> entry);
    void erase(string key);
    int at(string key);
    int size();
    bool empty();
};
