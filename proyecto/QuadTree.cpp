#include "QuadTree.h"
#include <bits/stdc++.h>

using namespace std;

QuadTree::QuadTree() {
	root = NULL;
}


void QuadTree::construir(vector<pair<int, int> > v) {
// ////////////////////////////////////////////// para cambiar en caso de que agreguemos N x M como argumentos
	int max_x = 0;
	int max_y = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].first > max_x) max_x = v[i].first;
		if (v[i].second > max_y) max_y = v[i].second;
	}
	N = max(max_x, max_y);
	// cout << "Dimensiones acotadas del espacio: " << N << '\n'; //debug
// //////////////////////////////////////////////
	root = new nodeQ;
	if (v.size() == 0) {
		// cout << "Raiz guarda un nodo vacio, no hay puntos" << '\n'; //debug
		// root->x = -1;
		// root->y = -1;
		// root->NW = NULL;
		// root->NE = NULL;
		// root->SW = NULL;
		// root->SE = NULL;
	} else if (v.size() == 1) { //guarda el punto
		// cout << "Raiz guarda un solo punto: (" << v[0].first << ", " << v[0].second << ")" << '\n'; //debug
		root->x = v[0].first;
		root->y = v[0].second;
		// root->NW = NULL;
		// root->NE = NULL;
		// root->SW = NULL;
		// root->SE = NULL;
	} else { //Tiene mas de un punto, guarda las coordenadas de la division
		// cout << "Raiz contiene mas de un punto. Tiene hijos" << '\n'; //debug
		// cout << "Raiz corta en: (" << N/2 << ", " << N/2 << ")" << '\n'; //debug
		root->x = N/2; //Sabremos que no es un punto si existe un hijo en NW
		root->y = N/2; //
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
		for (int i = 0; i < north.size(); i++) {
			if (north[i].second <= N/2) {
				west.push_back(north[i]); // oeste del norte
			} else {
				east.push_back(north[i]); // este del norte
			}
		}
		// cout << "puntos en NW: " << '\n';
		// for (int i = 0; i < west.size(); i++) {
		// 	// cout << "(" << west[i].first << ", " << west[i].second << ")" << '\n'; //debug
		// }
		// cout << "puntos en NE: " << '\n';
		// for (int i = 0; i < east.size(); i++) {
		// 	// cout << "(" << east[i].first << ", " << east[i].second << ")" << '\n'; //debug
		// }

		root->NW = construirR(west, 0, N/2, 0, N/2); //(x1,x2,y1,y2)
		root->NE = construirR(east, 0, N/2, (N/2) + 1, N);

		west.clear();
		east.clear();
		for (int i = 0; i < south.size(); i++) {
			if (south[i].second <= N/2) {
				west.push_back(south[i]); // oeste del sur
			} else {
				east.push_back(south[i]); // este del sur
			}
		}

		// cout << "En la raiz" << '\n';
		// cout << "puntos en SW: " << '\n';
		// for (int i = 0; i < west.size(); i++) {
		// 	// cout << "(" << west[i].first << ", " << west[i].second << ")" << '\n'; //debug
		// }
		// cout << "puntos en SE: " << '\n';
		// for (int i = 0; i < east.size(); i++) {
		// 	// cout << "(" << east[i].first << ", " << east[i].second << ")" << '\n'; //debug
		// }
		root->SW = construirR(west, (N/2) + 1, N, 0, N/2);
		root->SE = construirR(east, (N/2) + 1, N, (N/2) + 1, N);
	}
}

nodeQ * QuadTree::construirR(vector<pair<int, int> > v, int x1, int x2, int y1, int y2) {
	nodeQ *nuevoNodo = new nodeQ;

	if (v.size() == 0) {
		// cout << "Nodo guarda un nodo vacio, no hay puntos" << '\n'; //debug

		//es un nodo vacio
	} else if(v.size() == 1){ //guardamos el punto
		// cout << "Nodo guarda un solo punto: (" << v[0].first << ", " << v[0].second << ")" << '\n'; //debug

		nuevoNodo->x = v[0].first;
		nuevoNodo->y = v[0].second;
		// nuevoNodo->NW = NULL;
		// nuevoNodo->NE = NULL;
		// nuevoNodo->SW = NULL;
		// nuevoNodo->SE = NULL;
	} else { //hay mas de un punto, seguimos dividiendo
		nuevoNodo->x = (x1+x2)/2; //guardando las coordenadas de la division
		nuevoNodo->y = (y1+y2)/2;
		// cout << "Nodo contiene mas de un punto. Tiene hijos" << '\n'; //debug
		// cout << "Nodo corta en: (" << nuevoNodo->x << ", " << nuevoNodo->y << ")" << '\n'; //debug

		vector<pair<int, int> > north;
		vector<pair<int, int> > south;

		for (int i = 0; i < v.size(); i++) {
			if (v[i].first <= (x1+x2)/2) {
				north.push_back(v[i]);
			} else {
				south.push_back(v[i]);
			}
		}
		//VEMOS SI EL RANGO ES SUFICIENTEMENTE GRANDE PARA AGREGAR HIJOS
		if (x1 == x2) {
			// cout << "Nodo demasiado corto en X, no tiene hijos al Sur" << '\n';
			vector<pair<int, int> > west;
			vector<pair<int, int> > east;
			for (int i = 0; i < north.size(); i++) {
				if (north[i].second <= (y1+y2)/2) {
					west.push_back(north[i]); // oeste del norte
				} else {
					east.push_back(north[i]); // este del norte
				}
			}
			// cout << "puntos en NW: " << '\n';
			// for (int i = 0; i < west.size(); i++) {
			// 	cout << "(" << west[i].first << ", " << west[i].second << ")" << '\n'; //debug
			// }
			// cout << "puntos en NE: " << '\n';
			// for (int i = 0; i < east.size(); i++) {
			// 	cout << "(" << east[i].first << ", " << east[i].second << ")" << '\n'; //debug
			// }
			nuevoNodo->NW = construirR(west, x1, (x1+x2)/2, y1, (y1+y2)/2);//hay que ponerle los intervalos para probar
			nuevoNodo->NE = construirR(east, x1, (x1+x2)/2, ((y1+y2)/2)+1, y2);
			// nuevoNodo->SW = NULL;
			// nuevoNodo->SE = NULL;
		} else if (y1 == y2) {
			vector<pair<int, int> > west;
			// cout << "Nodo demasiado corto en Y, no tiene hijos al Este" << '\n';

			for (int i = 0; i < north.size(); i++) {
				if (north[i].second <= (y1+y2)/2) {
					west.push_back(north[i]); // oeste del norte
				}
			}
			// cout << "puntos en NW: " << '\n';
			// for (int i = 0; i < west.size(); i++) {
			// 	cout << "(" << west[i].first << ", " << west[i].second << ")" << '\n'; //debug
			// }
			nuevoNodo->NW = construirR(west, x1, (x1+x2)/2, y1, (y1+y2)/2);
			// nuevoNodo->NE = NULL;

			west.clear();
			for (int i = 0; i < south.size(); i++) {
				if (south[i].second <= (y1+y2)/2) {
					west.push_back(south[i]); // oeste del sur
				}
			}
			// cout << "puntos en SW: " << '\n';
			// for (int i = 0; i < west.size(); i++) {
			// 	cout << "(" << west[i].first << ", " << west[i].second << ")" << '\n'; //debug
			// }
			nuevoNodo->SW = construirR(west, ((x1+x2)/2)+1, x2, y1 , (y1+y2)/2);
			// nuevoNodo->SE = NULL;
		} else {
			// cout << "Tiene 4 hijos" << '\n';
			vector<pair<int, int> > west;
			vector<pair<int, int> > east;
			for (int i = 0; i < north.size(); i++) {
				if (north[i].second <= (y1+y2)/2) {
					west.push_back(north[i]); // oeste del norte
				} else {
					east.push_back(north[i]); // este del norte
				}
			}
			// cout << "puntos en NW: " << '\n';
			// for (int i = 0; i < west.size(); i++) {
			// 	cout << "(" << west[i].first << ", " << west[i].second << ")" << '\n'; //debug
			// }
			// cout << "puntos en NE: " << '\n';
			// for (int i = 0; i < east.size(); i++) {
			// 	cout << "(" << east[i].first << ", " << east[i].second << ")" << '\n'; //debug
			// }
			nuevoNodo->NW = construirR(west, x1, (x1+x2)/2, y1, (y1+y2)/2);//hay que ponerle los intervalos para probar
			nuevoNodo->NE = construirR(east, x1, (x1+x2)/2, ((y1+y2)/2)+1, y2);

			west.clear();
			east.clear();
			for (int i = 0; i < south.size(); i++) {
				if (south[i].second <= (y1+y2)/2) {
					west.push_back(south[i]); // oeste del norte
				} else {
					east.push_back(south[i]); // este del norte
				}
			}
			// cout << "puntos en SW: " << '\n';
			// for (int i = 0; i < west.size(); i++) {
			// 	cout << "(" << west[i].first << ", " << west[i].second << ")" << '\n'; //debug
			// }
			// cout << "puntos en SE: " << '\n';
			// for (int i = 0; i < east.size(); i++) {
			// 	cout << "(" << east[i].first << ", " << east[i].second << ")" << '\n'; //debug
			// }
			nuevoNodo->SW = construirR(west, ((x1+x2)/2)+1, x2, y1 , (y1+y2)/2);
			nuevoNodo->SE = construirR(east, ((x1+x2)/2)+1, x2, ((y1+y2)/2)+1, y2);
		}


	}
	return nuevoNodo;
}


vector<pair<int, int> > QuadTree::buscar(int x1, int y1, int x2, int y2) {
	vector<pair<int, int> > puntosEncontrados;
	if (x2 < x1) swap(x1, x2); //nos aseguramos de que x1 < x2 && y1 < y2
	if (y2 < y1) swap(y1, y2);

	if (root->x == -1) {//no guarda punto, no tiene hijos
		//no hacemos nada
	} else if (root->x != -1 && root->NW == NULL){//guarda un punto en la raiz, no tiene hijos
		if (root->x >= x1 && root->x <= x2 && root->y >= y1 && root->y <= y2) {
			pair<int, int> punto;
			punto.first = root->x;
			punto.second = root->y;
			puntosEncontrados.push_back(punto);
		}
	} else {//hay más de un punto, tiene al menos dos hijos
		if (x1 <= root->x) { //buscar en el NORTE
			if (y1 <= root->y) buscarR(x1, y1, x2, y2, root->NW, puntosEncontrados);
			if (y2 > root->y) buscarR(x1, y1, x2, y2, root->NE, puntosEncontrados);
		}
		if (x2 > root->x) { //buscar en el SUR
			if (y1 <= root->y) buscarR(x1, y1, x2, y2, root->SW, puntosEncontrados);
			if (y2 > root->y) buscarR(x1, y1, x2, y2, root->SE, puntosEncontrados);
		}
	}
	return puntosEncontrados;
}

void QuadTree::buscarR(int x1, int y1, int x2, int y2, nodeQ * nodo, vector<pair<int, int> > &puntosEncontrados) {
	if (nodo->NW == NULL && nodo->x == -1) {//no guarda punto, no tiene hijos (NW es el unico que existe siempre al hacer divisiones)
		//no hacemos nada
	} else if (nodo->NW == NULL && nodo->x != -1){//guarda un punto en la raiz, no tiene hijos
		if (nodo->x >= x1 && nodo->x <= x2 && nodo->y >= y1 && nodo->y <= y2) {
			pair<int, int> punto;
			punto.first = nodo->x;
			punto.second = nodo->y;
			puntosEncontrados.push_back(punto);
		}
	} else {//hay division. Tiene al menos 2 hijos
		if (x1 <= nodo->x) { //buscar en el NORTE
			if (y1 <= nodo->y) buscarR(x1, y1, x2, y2, nodo->NW, puntosEncontrados);
			if (y2 > nodo->y && nodo->NE != NULL) buscarR(x1, y1, x2, y2, nodo->NE, puntosEncontrados);
		}
		if (x2 > nodo->x) { //buscar en el SUR
			if (y1 <= nodo->y && nodo->SW != NULL) buscarR(x1, y1, x2, y2, nodo->SW, puntosEncontrados);
			if (y2 > nodo->y && nodo->SE != NULL) buscarR(x1, y1, x2, y2, nodo->SE, puntosEncontrados);
		}
	}
}
