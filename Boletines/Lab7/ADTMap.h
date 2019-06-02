#ifndef MAP_H
#define MAP_H

#include <string>

using namespace std;

struct box {
    int val;
	string key = string();
    bool available = true;
};

class ADTMap {
public:
    virtual void insert(pair<string, int>) = 0;
    virtual void erase(string) = 0;
    virtual int at(string) = 0;
    virtual int size() = 0;
    virtual bool empty() = 0;
};

#endif
