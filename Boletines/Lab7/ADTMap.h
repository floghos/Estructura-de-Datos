#ifndef MAP_H
#define MAP_H

#include <string>

class ADTMap {
public:
    virtual int insert(pair<std::string, int>) = 0;
    virtual void erase(std::string) = 0;
    virtual int at(int) = 0;
    virtual int size() = 0;
    virtual bool empty() = 0;
};

#endif
