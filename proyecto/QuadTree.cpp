#include "QuadTree.h"
#include <bits/stdc++.h>

using namespace std;

QuadTree::QuadTree() {
	root = NULL;
}


void QuadTree::construir(vector<pair<int, int> > v) {


	if (v.size() == 0) {
		root = new node;
		root->x = -1;
		root->y = -1;
		NW = NULL;
		NE = NULL;
		SW = NULL;
		SE = NULL;
	} else if (v.size() == 1) {
		root = new node;
		root->x = v[0].first;
		root->y = v[0].second;
		NW = NULL;
		NE = NULL;
		SW = NULL;
		SE = NULL;
	} else {
		root = new node;
		root->x = -1;
		root->y = -1;
		NW = construirR();
		NE = construirR();
		SW = construirR();
		SE = construirR();
	}

}

node * QuadTree::construirR(vector<pair<int, int> > v, node* nodo, RANGE) {

}


vector<pair<int, int> > QuadTree::buscar(int x1, int y1, int x2, int y2) {

}
