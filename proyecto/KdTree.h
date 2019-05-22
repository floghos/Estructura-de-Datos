#include "ADTSearchTree.h"
#include <bits/stdc++.h>

using namespace std;

struct node {
    int x, y;
    node *left, *right;
};

class KdTree: public ADTSearchTree {
private:
    node *root;
    node * construir(vector<pair<int, int> > v, int depth);
	vector<pair<int, int> > buscarR(int x1, int y1, int x2, int y2, node * nodo);
public:
    KdTree();
    void construir(vector<pair<int, int> > v);
    vector<pair<int, int> > buscar(int x1, int y1, int x2, int y2);
};
