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
    sort(v.begin(), v.end());
    int median = (v.size() - 1) / 2;
	cout << "Primer ordenamiento:" << endl; //debug
	cout << "x  y" << '\n'; //debug
	for (int i = 0; i < v.size(); i++) { //debug
		cout << v[i].first << "  " << v[i].second << '\n';//debug
	}//debug

    vector<pair<int, int> > l; // mitad izquierda
    for (int i = 0; i <= median; ++i) { //llenamos l con los puntos de la primera mitad del vector (ordenado respecto a v.frist)
        l.push_back(v[i]);
    }

    vector<pair<int, int> > r; // mitad derecha
    for (int i = median+1; i < v.size(); ++i) { //llenamos r con los puntos de la segunda mitad del vector (ordenado respecto a v.frist)
        r.push_back(v[i]);
    }

    root = new node; //creamos el primer nodo
    root->x = v[median].first; //indica que contamos el es espacio respecto a la fila del punto v[median] (fila = x, columna = y)
    root->y = -1; // Dato basura

	cout << "Corta en x=" << root->x << '\n'; //debug


    root->left = construir(l, 1);
    root->right = construir(r, 1);
}

node * KdTree::construir(vector<pair<int, int> > v, int depth) { //recibimos una de las dos mitades del paso anterior
    int axis = depth % 2; //0, 1 dependiendo si es par o impar (0 = x, 1 = y)
    if (axis) {
        sort(v.begin(), v.end(), sortbysec);
    } else {
        sort(v.begin(), v.end());
    }

    int median = (v.size() - 1) / 2;

	cout << "Profundidad " << depth << '\n'; //debug
	cout << "x  y" << '\n'; //debug
	for (int i = 0; i < v.size(); i++) { //debug
		cout << v[i].first << "  " << v[i].second << '\n';//debug
	}//debug


    if (v.size() > 1) {
        vector<pair<int, int> > l; //mitad izquierda
        for (int i = 0; i <= median; ++i) {
            l.push_back(v[i]);
        }

        vector<pair<int, int> > r; //mitad derecha
        for (int i = median+1; i < v.size(); ++i) {
            r.push_back(v[i]);
        }

        node *nuevoNodo = new node;
        if (axis) { //division en eje y
            nuevoNodo->y = v[median].second;
            nuevoNodo->x = -1;
        } else { //division en eje x
            nuevoNodo->x = v[median].first;
            nuevoNodo->y = -1;
        }

		cout << "Corta en "; //debug
		if (axis) {//debug
			cout << "y=" << v[median].second << '\n';//debug
		} else {//debug
			cout << "x=" << v[median].first << '\n';//debug
		}//debug

        nuevoNodo->left = construir(l, depth+1);
        nuevoNodo->right = construir(r, depth+1);


        return nuevoNodo;
    } else {
        node *nuevoNodo = new node;
        nuevoNodo->x = v[0].first;
        nuevoNodo->y = v[0].second;
        nuevoNodo->left = NULL;
        nuevoNodo->right = NULL;


		cout << "Punto guardado: x=" << v[median].first << "  y=" << v[median].second << '\n';//debug
		//debug

        return nuevoNodo;
    }

}

vector<pair<int, int> > * KdTree::buscar(int x1, int y1, int x2, int y2) {
	vector<pair<int, int> > puntosEncontrados = new vector<pair<int, int> >;
	if (x2 < x1) swap(x1, x2);
	if (y2 < y1) swap(y1, y2);

	if (root->x < x2) {
		buscar(x1, y1, x2, y2, root->left, puntosEncontrados);
	}
	if  (root->x > x1) {
		buscar(x1, y1, x2, y2, root->right, puntosEncontrados);
	}
	 //falta implementar la llamada recursiva de buscar() que sobrecarga este metodo

	return puntosEncontrados;
}

void KdTree::buscar(int x1, int y1, int x2, int y2, node * nodo, vector<pair<int, int> > &puntosEncontrados) {
	if (nodo->x == -1) {
		if (nodo->y < y2) {
			buscar(x1, y1, x2, y2, nodo->left, puntosEncontrados);
		}
		if  (nodo->y > y1) {
			buscar(x1, y1, x2, y2, nodo->right, puntosEncontrados);
		}
	} else if (nodo->y == -1){
		if (nodo->x < x2) {
			buscar(x1, y1, x2, y2, nodo->left, puntosEncontrados);
		}
		if  (nodo->x > x1) {
			buscar(x1, y1, x2, y2, nodo->right, puntosEncontrados);
		}
	} else {
		pair<int, int> punto;
		punto.first = nodo->x;
		punto.second = nodo->y;
		puntosEncontrados.push_back(punto);
	}
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
