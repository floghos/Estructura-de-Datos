#include "ADTSearchTree.h"
#include <bits/stdc++.h>

using namespace std;

struct nodeQ {//le cambie el nombre porque decía que me estaba refiriendo al otro nodo :C
    int x = -1;
	int y = -1;
	nodeQ *NW = NULL;
    nodeQ *NE = NULL;
	nodeQ *SW = NULL;
	nodeQ *SE = NULL;
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
