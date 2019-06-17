#include <iostream>
#include <string>
#include "MapAVL.h"
using namespace std;


void MapAVL::recPreOrder() {
	recPreOrder(raiz);

}

void MapAVL::recPreOrder(nodo* nodoActual) {
	cout << nodoActual->par.first <<" se encuentra a altura " << nodoActual->height << '\n';
	if (nodoActual->left != NULL) {
		cout<<nodoActual->left->par.first<<" es hijo Izq de: "<<nodoActual->par.first<<endl;
		recPreOrder(nodoActual->left);
	}
	if (nodoActual->right != NULL) {
		cout<<nodoActual->right->par.first<<" es hijo Der de: "<<nodoActual->par.first<<endl;
		recPreOrder(nodoActual->right);
	}
}

MapAVL::MapAVL(){
	tam = 0;
	raiz = NULL;
}

void MapAVL::insert(pair<string, int> p){
	if(tam == 0){//si no hay elementos añadidos
		raiz = new nodo;
		raiz->par.first = p.first;//añado en la raiz
		raiz->par.second = p.second;
		tam++;//aumento el tamaño
		// std::cout << "insertando nodo "<< tam << '\n';
	}else{
		nodo *hijo;
		hijo = raiz;//comienzo apuntando en la raiz
		while(true){
			if((hijo->par.first).compare(p.first) == 0) {
				cout<<"Hay valor asociado a la clave: "<< p.second << ")" <<endl;
				break;
			}else if((hijo->par.first).compare(p.first) < 0) {//debe ir a la derecha
				//cout<<"der"<<endl;
				if(hijo->right == NULL){//si es nulo, puedo añadir
					nodo *nuevoNodo = new nodo;//creo un nodo nuevo
					nuevoNodo->par.first = p.first;
					nuevoNodo->par.second = p.second;
					nuevoNodo->padre = hijo;
					hijo->right = nuevoNodo;
					tam++;//aumento tamaño
					// std::cout << "insertando nodo "<< tam << '\n';
					aumentarAlturas(nuevoNodo);
					break;
				} else {
					hijo = hijo->right;
				}

			}else if((hijo->par.first).compare(p.first) > 0) {//debe ir a la izquierda
				//cout<<"izq"<<endl;
				if(hijo->left == NULL){//si es nulo, puedo añadir
					nodo *nuevoNodo = new nodo;//creo un nodo nuevo
					nuevoNodo->par.first = p.first;
					nuevoNodo->par.second = p.second;
					nuevoNodo->padre = hijo;
					hijo->left = nuevoNodo;
					tam++;//aumento tamaño
					// std::cout << "insertando nodo "<< tam << '\n';
					aumentarAlturas(nuevoNodo);
					break;
				} else {
					hijo = hijo->left;
				}
			}
		}
	}
}

void MapAVL::aumentarAlturas(nodo *nodoActual) {
	while (nodoActual->padre != NULL && nodoActual->height == nodoActual->padre->height) {
		nodoActual->padre->height++;
		nodoActual = nodoActual->padre;
	}
}

void MapAVL::disminuirAlturas(nodo *nodoActual) {
	nodo *dad = nodoActual->padre;
	nodo *bro;
	if (dad != NULL) {
		if (dad->left == nodoActual) {
			bro = dad->right;
		} else {
			bro = dad->left;
		}

		if (bro->height <= nodoActual->height) {
			dad->height--;
			disminuirAlturas(dad);
		}
	}
}

void MapAVL::checkBalance(nodo *nodoActual) {
	nodo *dad = nodoActual->padre;
	nodo *bro;
	if (dad != NULL) {
		if (dad->left == nodoActual) { //determinamos si nuestro hermano es left o right
			bro = dad->right;
		} else {
			bro = dad->left;
		}

		if (bro == NULL) {
			if (nodoActual->height == 0) {
				checkBalance(dad);
			} else if(nodoActual->height >= 1) {
				rotar(nodoActual);
			}
		} else {
			if (abs(bro->height - nodoActual->height) > 1) {
				rotar(nodoActual);
			} else {
				checkBalance(dad);
			}
		}
	}
}

void MapAVL::rotar(nodo *nodoActual) {
	nodo *parent = nodoActual->padre;
	nodo *child;
	if((nodoActual->left->height) > (nodoActual->right->height)) {
		child = nodoActual->left;
	} else {
		child = nodoActual->right;
	}

	if (parent->left == nodoActual) {
		if (nodoActual->left == child) {
			rotateLeftLeft(child);
		} else {
			rotateLeftRight(child);
		}
	} else {
		if(nodoActual->left == child) {
			rotateRightLeft(child);
		} else {
			rotateRightRight(child);
		}
	}

}


void MapAVL::rotateLeftLeft(nodo *nodoActual) {
	nodo *r = nodoActual->padre->padre->padre;
	nodo *z = nodoActual->padre->padre;
	nodo *y = nodoActual->padre;
	nodo *x = nodoActual;

//guardando sub-arboles
	nodo *t1 = x->left;
	nodo *t2 = x->right;
	nodo *t3 = y->right;
	nodo *t4 = z->right;

	if (r != NULL) {
		if (r->left == z) r->left = y; //estamos al lado izq
		else r->right = y; //estamos al lado der
	} else {
		raiz = y;
	}
//rotando
	y->right = z;
//reasignando sib-arboles
	// x->left = t1; //no cambia
	// x->right = t2; //no cambia
	z->left = t3;
	// z->right = t4; //no cambia

}

void MapAVL::rotateLeftRight(nodo *nodoActual) {
	nodo *r = nodoActual->padre->padre->padre;
	nodo *z = nodoActual->padre->padre;
	nodo *y = nodoActual->padre;
	nodo *x = nodoActual;

//guardando sub-arboles
	nodo *t1 = y->left;
	nodo *t2 = x->left;
	nodo *t3 = x->right;
	nodo *t4 = z->right;

	if (r != NULL) {
		if (r->left == z) r->left = x;
		else r->right = x;
	} else {
		raiz = x;
	}
//rotando
	x->left = y;
	x->right = z;
//reasignandoo sub-arboles
	// y->left = t1;
	y->right = t2;
	z->left = t3;
	// z->right = t4;
}

void MapAVL::rotateRightLeft(nodo *nodoActual) {
	nodo *r = nodoActual->padre->padre->padre;
	nodo *z = nodoActual->padre->padre;
	nodo *y = nodoActual->padre;
	nodo *x = nodoActual;

//guardando sub-arboles
	nodo *t1 = z->left;
	nodo *t2 = x->left;
	nodo *t3 = x->right;
	nodo *t4 = y->right;
}

void MapAVL::rotateRightRight(nodo *nodoActual) {
	nodo *r = nodoActual->padre->padre->padre;
	nodo *z = nodoActual->padre->padre;
	nodo *y = nodoActual->padre;
	nodo *x = nodoActual;

//guardando sub-arboles
	nodo *t1 = z->left;
	nodo *t2 = y->left;
	nodo *t3 = x->left;
	nodo *t4 = x->right;

}

int MapAVL::at(string clave){
	if(tam == 0){
		// cout<<"No hay valor asociado a la clave: ("<<clave<<")"<<endl;
		return -1;
	}else{
		nodo *hijo;
		hijo = raiz;//comienzo apuntando en la raiz
		while(1){
			if((hijo->par.first).compare(clave) == 0) return hijo->par.second;
			else if((hijo->par.first).compare(clave) < 0) {//debe ir a la derecha
				if(hijo->right == NULL){
					// cout<<"No hay valor asociado a la clave: ("<<clave<<")"<<endl;
					return -1;
				}else hijo = hijo->right; //apunta al hijo derecho
			}else if((hijo->par.first).compare(clave) > 0) {//debe ir a la izquierda
				if(hijo->left == NULL){
					// cout<<"No hay valor asociado a la clave: ("<<clave<<")"<<endl;
					return -1;
				}else hijo = hijo->left;//apunta al hijo izquierdo
			}
		}
	}
}


void MapAVL::erase(string key) {

}

int MapAVL::size(){
	return tam;
}

bool MapAVL::empty(){
	return !tam;
}
