#include "QuadTree.h"
#include <bits/stdc++.h>

using namespace std;

QuadTree::QuadTree() {
	root = NULL;
}


void QuadTree::construir(vector<pair<int, int> > v) {
// //////////////////////////////////////////////
	int max_x = 0;
	int max_y = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].first > max_x) max_x = v[i].first;
		if (v[i].second > max_y) max_y = v[i].second;
	}
	N = max(max_x, max_y);
// //////////////////////////////////////////////
	if (v.size() == 0) {
		root = new nodeQ;
		root->x = -1;
		root->y = -1;
		root->NW = NULL;
		root->NE = NULL;
		root->SW = NULL;
		root->SE = NULL;
	} else if (v.size() == 1) {
		root = new nodeQ;
		root->x = v[0].first;
		root->y = v[0].second;
		root->NW = NULL;
		root->NE = NULL;
		root->SW = NULL;
		root->SE = NULL;
	} else {
		root = new nodeQ;
		root->x = -1;
		root->y = -1;
		vector<pair<int, int> > north;
		vector<pair<int, int> > south;

		for (int i = 0; i < v.size(); i++) {
			if (v[i].first <= N/2) {
				north.push_back(v[i]);
			} else {
				south.push_back(v[i]);
			}
		}

		vector<pair<int, int> > west;
		vector<pair<int, int> > east;
		for (int i = 0; i < v.size(); i++) {
			if (north[i].second <= N/2) {
				west.push_back(north[i]); // oeste del norte
			} else {
				east.push_back(north[i]); // este del norte
			}
		}


		root->NW = construirR(west, 0, N/2, 0, N/2);//(x1,x2,y1,y2)
		root->NE = construirR(east, 0, N/2, (N/2) + 1, N);

		west.clear();
		east.clear();
		for (int i = 0; i < v.size(); i++) {
			if (south[i].second <= N/2) {
				west.push_back(south[i]); // oeste del sur
			} else {
				east.push_back(south[i]); // este del sur
			}
		}
		root->SW = construirR(west, (N/2) + 1, N, 0, N/2);
		root->SE = construirR(east, (N/2) + 1, N, (N/2) + 1, N);
	}
}

nodeQ * QuadTree::construirR(vector<pair<int, int> > v, int x1, int x2, int y1, int y2) {
	nodeQ *nuevoNodo = new nodeQ;

	if(v.size() == 1){
		nuevoNodo->x = v[0].first;
		nuevoNodo->y = v[0].second;
		nuevoNodo->NW = NULL;
		nuevoNodo->NE = NULL;
		nuevoNodo->SW = NULL;
		nuevoNodo->SE = NULL;
	} else { //hay mas de un punto, seguimos dividiendo
		nuevoNodo->x = -1;
		nuevoNodo->y = -1;
		//OJO, HAY QUE VER SI EL RANGO ES SUFICIENTEMENTE GRANDE PARA AGREGAR HIJOS
		if (x1 == x2) {
			//nuevoNodo->NW = construirR();//hay que ponerle los intervalos para probar
			//nuevoNodo->NE = construirR();
			nuevoNodo->SW = NULL;
			nuevoNodo->SE = NULL;
		} else if (y1 == y2) {
			nuevoNodo->NW = NULL;
			nuevoNodo->NE = NULL;
			//nuevoNodo->SW = construirR();
			//nuevoNodo->SE = construirR();
		}


	}
	return nuevoNodo;
}


vector<pair<int, int> > QuadTree::buscar(int x1, int y1, int x2, int y2) {

}
