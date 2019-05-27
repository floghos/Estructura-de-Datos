#include "ADTMap.h"
#include <string>

class MapG: public ADTMap {
private:
    int _size;
    void rehash();
public:
    int insert(pair<std::string, int> data);
    void erase(std::string str);
    int at(int i);
    int size();
    bool empty();
};
