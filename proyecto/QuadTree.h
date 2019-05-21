#include "ADTSearchTree.h"
#include <bits/stdc++.h>

using namespace std;

struct node {
    int x, y;
    node *NE, *NW, *SE, *SW;
};

class KdTree: public ADTSearchTree {
private:
    node *root;
	node * construirR(vector<pair<int, int> > v);
public:
    QuadTree();
    void construir(vector<pair<int, int> > v);
    vector<pair<int, int> > buscar(int x1, int y1, int x2, int y2);
};
