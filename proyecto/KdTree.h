#include "ADTSearchTree.h"
#include <bits/stdc++.h>

using namespace std;

struct nodeK {
    int x = -1;
	int y = -1;
    nodeK *left = NULL;
	nodeK *right = NULL;
};

class KdTree: public ADTSearchTree {
private:
    nodeK *root;
    nodeK * construirR(vector<pair<int, int> > v, int depth);
	void buscarR(int x1, int y1, int x2, int y2, nodeK * nodo, vector<pair<int, int> > &puntosEncontrados);
public:
    KdTree();
    void construir(vector<pair<int, int> > v);
    vector<pair<int, int> > buscar(int x1, int y1, int x2, int y2);
};
