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
    void insert(std::pair<string, int> entry, box *&node);
    void erase(std::string key, box *node);
    int at(std::string key, box *node);
public:
    MapBST();
    void insert(std::pair<string, int> entry);
    void erase(std::string key);
    int at(std::string key);
    int size();
    bool empty();
};
