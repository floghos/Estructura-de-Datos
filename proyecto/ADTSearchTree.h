#ifndef TREE_H
#define TREE_H
#include <vector>

using namespace std;

class ADTSearchTree {
public:
    virtual void construir(vector<pair<int, int> >) = 0;
    virtual vector<pair<int, int> > * buscar(int, int, int, int) = 0;
};

#endif
