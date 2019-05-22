#include "ADTSearchTree.h"
#include <bits/stdc++.h>

using namespace std;

struct nodeQ {//le cambie el nombre porque decía que me estaba refiriendo al otro nodo :C
    int x, y;
    nodeQ *NE, *NW, *SE, *SW;
};

class QuadTree: public ADTSearchTree {
private:
    int N;
    nodeQ *root;
	nodeQ *construirR(vector<pair<int, int> > v, int x1, int y1, int x2, int y2);
public:
    QuadTree();
    void construir(vector<pair<int, int> > v);
    vector<pair<int, int> > buscar(int x1, int y1, int x2, int y2);
};
