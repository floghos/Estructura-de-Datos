#ifndef MAP_H
#define MAP_H

#include <string>

class ADTMap {
public:
    virtual void insert(pair) = 0;
    virtual void erase(std::string) = 0;
    virtual int at(std::string) = 0;
    virtual int size() = 0;
    virtual bool empty() = 0;
};

#endif
