#include "ADTSearchTree.h"
#include <bits/stdc++.h>

using namespace std;

struct node {
    int x, y;
    // node *parent;
    node *left, *right;
};

class KdTree: public ADTSearchTree {
private:
    node *root;
    node * construir(vector<pair<int, int> > v, int depth);
    // bool sortbysec(const pair<int,int> &a, const pair<int,int> &b);
    // void sort(vector<pair<int, int> > * v, int axis);
    // void swap(pair<int, int> *a, pair<int, int> *b);
public:
    KdTree();
    void construir(vector<pair<int, int> > v);
    vector<pair<int, int> > * buscar(int x1, int y1, int x2, int y2);
};
