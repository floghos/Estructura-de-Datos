#include "KdTree.h"
#include <bits/stdc++.h>

using namespace std;

KdTree::KdTree() {
    root = NULL;
}

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) {
    return (a.second < b.second);
}

void KdTree::construir(vector<pair<int, int> > v) {
/*
	FALTA INCLUIR CASOS PARA CONJUNTO DE PUNTOS <= 1!!!!!!!!!!!!!!!!!!!!!!!
*/
	if(v.size() == 0){//significa que no hay puntos en el vector
		root = new nodeK;
		root->x = -1;//no guarda punto
		root->y = -1;
		root->left = NULL;//no tiene hijos
		root->right = NULL;
	}else if(v.size() == 1){//si vector tiene un solo punto
		root = new nodeK;
		root->x = v[0].first;//guarda el punto en la raiz
		root->y = v[0].second;
		root->left = NULL;//no tiene hijos
		root->right = NULL;
	}else{//vector tiene más de un punto
		sort(v.begin(), v.end());//ordena el vector con respecto a x
	    int median = (v.size() - 1) / 2;

		// cout << "Primer ordenamiento:" << endl; //debug
		// cout << "x  y" << '\n'; //debug
		// for (int i = 0; i < v.size(); i++) { //debug
		// 	cout << v[i].first << "  " << v[i].second << '\n';//debug
		// }//debug

	    vector<pair<int, int> > l; // mitad izquierda
	    for (int i = 0; i <= median; ++i) { //llenamos l con los puntos de la primera mitad del vector (ordenado respecto a v.frist)
	        l.push_back(v[i]);
	    }

	    vector<pair<int, int> > r; // mitad derecha
	    for (int i = median+1; i < v.size(); ++i) { //llenamos r con los puntos de la segunda mitad del vector (ordenado respecto a v.frist)
	        r.push_back(v[i]);
	    }

	    root = new nodeK; //creamos el primer nodo
	    root->x = v[median].first; //indica que contamos el es espacio respecto a la fila del punto v[median] (fila = x, columna = y)
	    root->y = -1; // Dato basura

		// cout << "Corta en x=" << root->x << '\n'; //debug

	    root->left = construir(l, 1);
	    root->right = construir(r, 1);
	}

}

nodeK * KdTree::construir(vector<pair<int, int> > v, int depth) { //recibimos una de las dos mitades del paso anterior
    int axis = depth % 2; //0, 1 dependiendo si es par o impar (0 = x, 1 = y)
    if (axis) {
        sort(v.begin(), v.end(), sortbysec);//ordena el vector con respecto a y
    } else {
        sort(v.begin(), v.end());//ordena el vector con respecto a x
    }

    int median = (v.size() - 1) / 2;

	// cout << "Profundidad " << depth << '\n'; //debug
	// cout << "x  y" << '\n'; //debug
	// for (int i = 0; i < v.size(); i++) { //debug
	// 	cout << v[i].first << "  " << v[i].second << '\n';//debug
	// }//debug

    if (v.size() > 1) {//si vector tiene más de un punto
        vector<pair<int, int> > l; //mitad izquierda
        for (int i = 0; i <= median; ++i) {
            l.push_back(v[i]);
        }

        vector<pair<int, int> > r; //mitad derecha
        for (int i = median+1; i < v.size(); ++i) {
            r.push_back(v[i]);
        }

        nodeK *nuevoNodo = new nodeK;
        if (axis) { //division en eje y
            nuevoNodo->y = v[median].second;
            nuevoNodo->x = -1;
        } else { //division en eje x
            nuevoNodo->x = v[median].first;
            nuevoNodo->y = -1;
        }

		// cout << "Corta en "; //debug
		// if (axis) {//debug
		// 	cout << "y=" << v[median].second << '\n';//debug
		// } else {//debug
		// 	cout << "x=" << v[median].first << '\n';//debug
		// }//debug

        nuevoNodo->left = construir(l, depth+1);
        nuevoNodo->right = construir(r, depth+1);

        return nuevoNodo;
    } else {//si vector tiene un solo punto
        nodeK *nuevoNodo = new nodeK;
        nuevoNodo->x = v[0].first;
        nuevoNodo->y = v[0].second;
        nuevoNodo->left = NULL;
        nuevoNodo->right = NULL;

		// cout << "Punto guardado: x=" << v[median].first << "  y=" << v[median].second << '\n';//debug
		//debug

        return nuevoNodo;
    }
}

vector<pair<int, int> > KdTree::buscar(int x1, int y1, int x2, int y2) {
	vector<pair<int, int> > puntosEncontrados;
	if (x2 < x1) swap(x1, x2);
	if (y2 < y1) swap(y1, y2);

	if(root->x == -1 && root->y == -1){//el vector no tenía puntos, raiz no guarda nada, no tiene hijos
		//DECIR QUE NO HACE NADA ???.................................................................................!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	}else if(root->x !=-1 && root->y !=-1){//vector tenía un punto, lo guadó en raiz, no tiene hijos
		if(root->x >= x1 && root->x <= x2 && root->y >= y1 && root->y <= y2){//si el punto cumple con el intervalo
			pair<int, int> punto;
			punto.first = root->x;
			punto.second = root->y;
			puntosEncontrados.push_back(punto);
		}
	}else{//si el vactor tenía más de dos puntos se puede buscar en los hijos...
		vector<pair<int, int> > puntosPrevios;
		if (root->x <= x2) {
			puntosPrevios = buscarR(x1, y1, x2, y2, root->left);
			for (int i = 0; i < puntosPrevios.size(); i++) {
				puntosEncontrados.push_back(puntosPrevios[i]);
			}
		}
		if  (root->x >= x1) {
			puntosPrevios = buscarR(x1, y1, x2, y2, root->right);
			for (int i = 0; i < puntosPrevios.size(); i++) {
				puntosEncontrados.push_back(puntosPrevios[i]);
			}
		}
	}
	return puntosEncontrados;
}

vector<pair<int, int> > KdTree::buscarR(int x1, int y1, int x2, int y2, nodeK * nodo) {
	vector<pair<int, int> > puntosEncontrados;
	vector<pair<int, int> > puntosPrevios;
	if (nodo->x == -1) {
		if (nodo->y <= y2) {
			puntosPrevios = buscarR(x1, y1, x2, y2, nodo->right);
			for (int i = 0; i < puntosPrevios.size(); i++) {
				puntosEncontrados.push_back(puntosPrevios[i]);
			}
		}
		if  (nodo->y >= y1) {
			puntosPrevios = buscarR(x1, y1, x2, y2, nodo->left);
			for (int i = 0; i < puntosPrevios.size(); i++) {
				puntosEncontrados.push_back(puntosPrevios[i]);
			}
		}
	} else if (nodo->y == -1){
		if (nodo->x <= x2) {
			puntosPrevios = buscarR(x1, y1, x2, y2, nodo->right);
			for (int i = 0; i < puntosPrevios.size(); i++) {
				puntosEncontrados.push_back(puntosPrevios[i]);
			}
		}
		if  (nodo->x >= x1) {
			puntosPrevios = buscarR(x1, y1, x2, y2, nodo->left);
			for (int i = 0; i < puntosPrevios.size(); i++) {
				puntosEncontrados.push_back(puntosPrevios[i]);
			}
		}
	} else {
		if (nodo->x >= x1 && nodo->x <= x2 && nodo->y >= y1 && nodo->y <= y2) {
			pair<int, int> punto;
			punto.first = nodo->x;
			punto.second = nodo->y;
			puntosEncontrados.push_back(punto);
		}
	}

	return puntosEncontrados;
}

// void KdTree::sort(vector<pair<int, int> > * v, int axis) {
	//     for (int i = 1; i < v->size(); ++i) {
		//         int j = i;
		//         pair<int, int> aux;
		//         if (axis) {//eje y
			//             while (v[j].second < v[j-1].second) {
				//                 KdTree::swap(&v[j], &v[j-1]);
				//                 j--;
				//                 if (j == 0) break;
				//             }
				//         } else { //equivale a: axis == 0 (eje x
					//             while (v[j].first < v[j-1].first) {
						//                 KdTree::swap(&v[j], &v[j-1]);
						//                 j--;
						//                 if (j == 0) break;
						//             }
						//         }
						//     }
						// }
						//
// void KdTree::swap(pair<int, int> *a, pair<int, int> *b) {
	//     //queremos cambiar los contenidos de a con los de b, no las direcciones de memoria
	//     pair<int, int> aux;
	//     aux = *a;
	//     *a = *b;
	//     *b = aux;
	// }