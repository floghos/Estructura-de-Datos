#include "ADTSearchTree.h"
#include <bits/stdc++>

using namespace std;

struct node {
    int x, y;
    // node *parent;
    node *left, *right;
};

class KdTree: public ADTSearchTree {
private:
    node *root;
    node * construir(vector<int> v, int depth);
public:
    KdTree();
    void construir(std::vector<int>);
    vector<pair<int, int> > buscar(int x1, int y1, int x2, int y2);
};


KdTree t;

t.construir(v);
