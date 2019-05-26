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
	root = new nodeK;
	if(v.size() == 0){//significa que no hay puntos en el vector
		//no hace nada
	}else if(v.size() == 1){//si vector tiene un solo punto
		root->x = v[0].first;//guarda el punto en la raiz
		root->y = v[0].second;
	}else{//vector tiene más de un punto
		vector<pair<int, int> > vX = v;//creamos un vector para ordenar respecto a x
		vector<pair<int, int> > vY = v;//creamos un vector para ordenar respecto a y

		sort(vX.begin(), vX.end());//ordena el vector con respecto a x
		sort(vY.begin(), vY.end(), sortbysec);//ordenamos vector con respecto a y

		vector<pair<int, int> > vX_l;//creamos un vector para pasar al recursivo
		vector<pair<int, int> > vX_r;//creamos un vector para pasar al recursivo

		vector<pair<int, int> > vY_l;//creamos un vector para pasar al recursivo
		vector<pair<int, int> > vY_r;//creamos un vector para pasar al recursivo

	    int median = vX[(v.size() - 1) / 2].first;

	    for(int i=0; i<vY.size(); i++){//recorremos los ordenados respecto a y, comparando con la media en x
	    	if(vY[i].first <= median){//si su x es menor o igual a la media va a la izquierda
	    		vY_l.push_back(vY[i]);
	    	}else{//si su x es mayor va a la derecha
	    		vY_r.push_back(vY[i]);
	    	}
	    }


	    for(int i=0; i<vX.size(); i++){//recorremos los ordenados respecto a x, comparando con la media en x
	    	if(vX[i].first <= median){//si su x es menor o igual a la media va a la izquierda
	    		vX_l.push_back(vX[i]);
	    	}else{//si su x es mayor va a la derecha
	    		vX_r.push_back(vX[i]);
	    	}
	    }
	    //root = new nodeK; //creamos el primer nodo
	    root->x = median; //indica que cortamos el espacio respecto a la fila median (fila = x, columna = y)
	    if(vX_l.size()) root->left = construirR(vX_l, vY_l, 1);
	    if(vX_r.size()) root->right = construirR(vX_r, vY_r, 1);
	}

}

nodeK * KdTree::construirR(vector<pair<int, int> > &vX, vector<pair<int, int> > &vY, int depth) { //recibimos una de las dos mitades del paso anterior
    int axis = depth % 2; //0, 1 dependiendo si es par o impar (0 = x, 1 = y)
    int median;
    if (axis) {
    	//debemos cortar en y...
    	median = vY[(vY.size()-1)/2].second;//el punto medio es el valor guardado en la posición y media del vector vY
    } else {
    	//cortamos con respecto a x...
    	median = vX[(vX.size()-1)/2].first;//el punto medio es el valor guardado en la posicion x media del vector vX
    }
    if (vX.size() > 1) {//si vector tiene más de un punto, podemos comparar respecto a vY tambien, tienen igual tamaño
        //vector<pair<int, int> > l; //mitad izquierda
        vector<pair<int, int> > vX_l;//creamos un vector para pasar
		vector<pair<int, int> > vX_r;//creamos un vector para pasar

		vector<pair<int, int> > vY_l;//creamos un vector para pasar
		vector<pair<int, int> > vY_r;//creamos un vector para pasar

		//sabemos antes de entrar al if cual es la media, segun en cual partimos...
		if(axis){//partimos respecto a y
			for(int i=0; i<vX.size(); i++){//recorremos los ordenados respecto a X, comparando con la media en Y
	    		if(vX[i].second <= median){//si su y es menor o igual a la media va a la izquierda
	    			vX_l.push_back(vX[i]);
	    		}else{//si su y es mayor va a la derecha
	    			vX_r.push_back(vX[i]);
	    		}
	    	}
	    	for(int i=0; i<vY.size(); i++){//recorremos los ordenados respecto a y, comparando con la media en y
	    		if(vY[i].second <= median){//si su y es menor o igual a la media va a la izquierda
	    			vY_l.push_back(vY[i]);
	    		}else{//si su y es mayor va a la derecha
	    			vY_r.push_back(vY[i]);
	    		}
	    	}

		}else{//partimos respecto a x
			for(int i=0; i<vY.size(); i++){//recorremos los ordenados respecto a Y, comparando con la media en X
	    		if(vY[i].first <= median){//si su x es menor o igual a la media va a la izquierda
	    			vY_l.push_back(vY[i]);
	    		}else{//si su x es mayor va a la derecha
	    			vY_r.push_back(vY[i]);
	    		}
	    	}
	    	for(int i=0; i<vX.size(); i++){//recorremos los ordenados respecto a X, comparando con la media en x
	    		if(vX[i].first <= median){//si su x es menor o igual a la media va a la izquierda
	    			vX_l.push_back(vX[i]);
	    		}else{//si su x es mayor va a la derecha
	    			vX_r.push_back(vX[i]);
	    		}
	    	}
		}
        nodeK *nuevoNodo = new nodeK;
        if (axis) { //division en eje y
            nuevoNodo->y = median;
        } else { //division en eje x
            nuevoNodo->x = median;
        }

        if(vX_l.size()) nuevoNodo->left = construirR(vX_l, vY_l, depth+1);//si el vector no tiene puntos, no construye hijos
        if(vX_r.size()) nuevoNodo->right = construirR(vX_r, vY_r, depth+1);

        return nuevoNodo;
    } else {//si vector tiene un solo punto
        nodeK *nuevoNodo = new nodeK;
        nuevoNodo->x = vX[0].first;
        nuevoNodo->y = vX[0].second;

        return nuevoNodo;
    }
}

vector<pair<int, int> > KdTree::buscar(int x1, int y1, int x2, int y2) {
	vector<pair<int, int> > puntosEncontrados;
	if (x2 < x1) swap(x1, x2);
	if (y2 < y1) swap(y1, y2);

	if(root->x == -1 && root->y == -1){//el vector no tenía puntos, raiz no guarda nada, no tiene hijos
		//DECIR QUE NO HACE NADA ???.................................................................................!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	} else if (root->x !=-1 && root->y !=-1){//vector tenía un punto, lo guadó en raiz, no tiene hijos
		if(root->x >= x1 && root->x <= x2 && root->y >= y1 && root->y <= y2){//si el punto cumple con el intervalo
			pair<int, int> punto;
			punto.first = root->x;
			punto.second = root->y;
			puntosEncontrados.push_back(punto);
		}
	} else {//si el vactor tenía más de dos puntos se puede buscar en los hijos...
		if (root->x < x2 && root->left != NULL) buscarR(x1, y1, x2, y2, root->right, puntosEncontrados);
		if (root->x >= x1 && root->right != NULL) buscarR(x1, y1, x2, y2, root->left, puntosEncontrados);
	}
	return puntosEncontrados;
}

void KdTree::buscarR(int x1, int y1, int x2, int y2, nodeK * nodo, vector<pair<int, int> > &puntosEncontrados) {
	if (nodo->x == -1) { //hay division en y
		if (nodo->y < y2 && nodo->right != NULL) buscarR(x1, y1, x2, y2, nodo->right, puntosEncontrados);
		if (nodo->y >= y1 && nodo->left != NULL) buscarR(x1, y1, x2, y2, nodo->left, puntosEncontrados);
	} else if (nodo->y == -1){ //hay division en x
		if (nodo->x < x2 && nodo->right != NULL) buscarR(x1, y1, x2, y2, nodo->right, puntosEncontrados);
		if (nodo->x >= x1 && nodo->left != NULL) buscarR(x1, y1, x2, y2, nodo->left, puntosEncontrados);
	} else { //hay un punto en el nodo
		if (nodo->x >= x1 && nodo->x <= x2 && nodo->y >= y1 && nodo->y <= y2) { //revisa si pretenece al intervalo de busqueda
			pair<int, int> punto;
			punto.first = nodo->x;
			punto.second = nodo->y;
			puntosEncontrados.push_back(punto);
		}
	}
}
