#include <iostream>
#include <string>
#include "MapAVL.h"
using namespace std;


void MapAVL::recPreOrder() {
	recPreOrder(raiz);
}

void MapAVL::recPreOrder(nodo* nodoActual) {
	if (nodoActual != NULL) {
		cerr << nodoActual->par.first <<" se encuentra a altura " << nodoActual->height << '\n';
		if (nodoActual->left != NULL) {
			cerr<<nodoActual->left->par.first<<" es hijo Izq de: "<<nodoActual->par.first<<endl;
			recPreOrder(nodoActual->left);
		}
		if (nodoActual->right != NULL) {
			cerr<<nodoActual->right->par.first<<" es hijo Der de: "<<nodoActual->par.first<<endl;
			recPreOrder(nodoActual->right);
		}
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
		// std::cerr << "insertando nodo "<< tam << '\n';
	} else {
		nodo *hijo;
		hijo = raiz;//comienzo apuntando en la raiz
		while(true){
			if((hijo->par.first).compare(p.first) == 0) {
				cout<<"Ya hay un valor asociado a la clave: "<< p.second << ")" <<endl;
				break;
			}else if((hijo->par.first).compare(p.first) < 0) {//debe ir a la derecha
				// cout<<"der"<<endl;
				if(hijo->right == NULL){//si es nulo, puedo añadir
					nodo *nuevoNodo = new nodo;//creo un nodo nuevo
					nuevoNodo->par.first = p.first;
					nuevoNodo->par.second = p.second;
					nuevoNodo->padre = hijo;
					hijo->right = nuevoNodo;
					tam++; //aumento tamaño
					// std::cerr << "insertando nodo "<< tam << '\n';
					aumentarAlturas(nuevoNodo);
					checkBalance(nuevoNodo);

					break;
				} else {
					hijo = hijo->right;
				}

			}else if((hijo->par.first).compare(p.first) > 0) {//debe ir a la izquier	da
				// cout<<"izq"<<endl;
				if(hijo->left == NULL){//si es nulo, puedo añadir
					nodo *nuevoNodo = new nodo;//creo un nodo nuevo
					nuevoNodo->par.first = p.first;
					nuevoNodo->par.second = p.second;
					nuevoNodo->padre = hijo;
					hijo->left = nuevoNodo;
					tam++;//aumento tamaño
					// std::cerr << "insertando nodo "<< tam << '\n';
					aumentarAlturas(nuevoNodo);
					checkBalance(nuevoNodo);

					break;
				} else {
					hijo = hijo->left;
				}
			}
		}
	}
}

void MapAVL::aumentarAlturas(nodo *nodoActual) {
	// std::cerr << "aumentarAlturas" << '\n';
	while (nodoActual->padre != NULL && nodoActual->height == nodoActual->padre->height) {
		nodoActual->padre->height++;
		nodoActual = nodoActual->padre;
	}
}

void MapAVL::disminuirAlturas(nodo *nodoActual) {
	// std::cerr << "disminuirAlturas" << '\n';
	nodo *dad = nodoActual->padre;
	nodo *bro;
	if (dad != NULL) {
		if (dad->left == nodoActual) {
			bro = dad->right;
		} else {
			bro = dad->left;
		}
		if (bro != NULL) {
			if (bro->height <= nodoActual->height) {
				dad->height--;
				disminuirAlturas(dad);
			}
		} else {
			dad->height--;
			disminuirAlturas(dad);
		}
	}
}


void MapAVL::checkBalance(nodo *nodoActual) {
	// std::cerr << "checkeando balance" << '\n';
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
				checkBalance(dad);
			}
		} else {
			if (abs(bro->height - nodoActual->height) > 1) {
				if (bro->height <= nodoActual->height) {
					rotar(nodoActual);
				} else {
					//para que pueda funcionar al eliminar nodos
					//hay veces en las que llamamos la funcion rotar() con el hermano de menor altura
					rotar(bro);
				}
				checkBalance(dad);
			} else {
				checkBalance(dad);
			}
		}
	}
}

void MapAVL::rotar(nodo *nodoActual) { //necesita ajustar alturas
	// std::cerr << "rotando" << '\n';
	nodo *parent = nodoActual->padre;
	nodo *child;


	if(nodoActual->left != NULL) {
		if (nodoActual->right != NULL) {
			if((nodoActual->left->height) > (nodoActual->right->height)) {
				child = nodoActual->left;
			} else {
				child = nodoActual->right;
			}
		} else {
			child = nodoActual->left;
		}
	} else {
		if (nodoActual->right != NULL) {
			child = nodoActual->right;
		} else {
			child = NULL;
		}
	}
	// cout<<"nodo actual: "<<nodoActual->par.first<<" hijo de: "<<parent->par.first<<endl;

	if (child != NULL) {
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
}

void MapAVL::recalcularAltura(nodo *nodoActual) {
	// std::cerr << "recalcularAltura" << '\n';
	if(nodoActual->left != NULL) {
		if (nodoActual->right != NULL) {
			if (nodoActual->left->height > nodoActual->right->height) {
				nodoActual->height = nodoActual->left->height + 1;
			} else {
				nodoActual->height = nodoActual->right->height + 1;
			}
		} else {
			nodoActual->height = nodoActual->left->height + 1;
		}
	} else {
		if (nodoActual->right != NULL) {
			nodoActual->height = nodoActual->right->height + 1;
		} else {
			nodoActual->height = 0;
		}
	}
}

void MapAVL::rotateLeftLeft(nodo *nodoActual) {
	// std::cerr << "rLL" << '\n';
	nodo *x = nodoActual;
	nodo *y = x->padre;
	nodo *z = y->padre;
	nodo *r = z->padre;

//guardando sub-arboles
	nodo *t1 = x->left;
	nodo *t2 = x->right;
	nodo *t3 = y->right;
	nodo *t4 = z->right;

	if (r != NULL) {
		if (r->left == z) r->left = y; //estamos al lado izq
		else r->right = y; //estamos al lado der
		y->padre = r;
	} else {
		raiz = y;
		y->padre = NULL;
	}
//rotando
	y->right = z;
	z->padre = y;
//reasignando sib-arboles
	// x->left = t1; //no cambia
	// x->right = t2; //no cambia
	z->left = t3;
	if (t3 != NULL) t3->padre = z;
	// z->right = t4; //no cambia
//ajustando alturas
	recalcularAltura(x);
	recalcularAltura(z);
	recalcularAltura(y);

	disminuirAlturas(y);
}


void MapAVL::rotateLeftRight(nodo *nodoActual) {
	// std::cerr << "rLR" << '\n';
	nodo *x = nodoActual;
	nodo *y = x->padre;
	nodo *z = y->padre;
	nodo *r = z->padre;

//guardando sub-arboles
	nodo *t1 = y->left;
	nodo *t2 = x->left;
	nodo *t3 = x->right;
	nodo *t4 = z->right;

	if (r != NULL) {
		if (r->left == z) r->left = x;
		else r->right = x;
		x->padre = r;
	} else {
		raiz = x;
		x->padre = NULL;
	}
//rotando
	x->left = y;
	y->padre = x;
	x->right = z;
	z->padre = x;
//reasignandoo sub-arboles
	// y->left = t1; //no cambia
	y->right = t2;
	if (t2 != NULL) t2->padre = y;
	z->left = t3;
	if (t3 != NULL) t3->padre = z;
	// z->right = t4; //no cambia
//ajustando alturas
	recalcularAltura(y);
	recalcularAltura(z);
	recalcularAltura(x);

	disminuirAlturas(x);
}

void MapAVL::rotateRightLeft(nodo *nodoActual) {
	// std::cerr << "rRL" << '\n';
	nodo *x = nodoActual;
	nodo *y = x->padre;
	nodo *z = y->padre;
	nodo *r = z->padre;

//guardando sub-arboles
	nodo *t1 = z->left;
	nodo *t2 = x->left;
	nodo *t3 = x->right;
	nodo *t4 = y->right;

	if (r != NULL) {
		if (r->left == z) r->left = x;
		else r->right = x;
		x->padre = r;
	} else {
		raiz = x;
		x->padre = NULL;
	}

//rotando
	x->left = z;
	z->padre = x;
	x->right = y;
	y->padre = x;
//reasignando sub-arboles
	// z->left = t1; //no cambia
	z->right = t2;
	if (t2 != NULL) t2->padre = z;
	y->left = t3;
	if (t3 != NULL) t3->padre = y;
	// y->right = t4; //no cambia
//ajustando alturas
	recalcularAltura(y);
	recalcularAltura(z);
	recalcularAltura(x);

	disminuirAlturas(x);
}

void MapAVL::rotateRightRight(nodo *nodoActual) {
	// std::cerr << "rRR" << '\n';
	nodo *x = nodoActual;
	nodo *y = x->padre;
	nodo *z = y->padre;
	nodo *r = z->padre;

//guardando sub-arboles
	nodo *t1 = z->left;
	nodo *t2 = y->left;
	nodo *t3 = x->left;
	nodo *t4 = x->right;

	if (r != NULL) {
		if (r->left == z) r->left = y;
		else r->right = y;
		y->padre = r;
	} else {
		raiz = y;
		y->padre = NULL;
	}
//rotando
	y->left = z;
	z->padre = y;
//reasignando sub-arboles
	// z->left = t1;
	z->right = t2;
	if (t2 != NULL)	t2->padre = z;
	// x->left = t3;
	// x->right = t4;
//ajustando alturas
	recalcularAltura(z);
	recalcularAltura(x);
	recalcularAltura(y);

	disminuirAlturas(y);
}

int MapAVL::at(string clave){
	if(tam == 0){
		// cout<<"No hay valor asociado a la clave: ("<<clave<<")"<<endl;
		return -1;
	}else{
		nodo *hijo;
		hijo = raiz;//comienzo apuntando en la raiz
		while(true){
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
	if(tam == 0){
		// cout<<"No hay valor asociado a la clave: ("<<clave<<")"<<endl;
	} else {
		nodo *hijo;
		hijo = raiz;//comienzo apuntando en la raiz
		while(true){
			if((hijo->par.first).compare(key) == 0) {
				std::cerr << "elemento encontrado" << '\n';
				//debemos borrarlo
				if (hijo->left != NULL && hijo->right != NULL) { //"hijo" es nodo externo (hoja)
					nodo *aux = hijo->right;
					while (aux->left != NULL) {
						aux = aux->left;
					}
					hijo->par = aux->par;
					hijo = aux;
				}
				if (hijo->left == NULL && hijo->right == NULL) {
					if (hijo->padre->left == hijo) hijo->padre->left = NULL;
					else hijo->padre->right == NULL;
					//balancear
					disminuirAlturas(hijo);
					checkBalance(hijo);
					delete hijo;
				} else {
					nodo *porBorrar = hijo;
					if (hijo->left == NULL) { //solo existe el derecho
						if (hijo->padre->left == hijo) hijo->padre->left = hijo->right;
						else hijo->padre->right == hijo->right;

						hijo->right->padre = hijo->padre;
						// hijo = hijo->right;
					} else {
						if (hijo->padre->left == hijo) hijo->padre->left = hijo->left;
						else hijo->padre->right == hijo->left;

						hijo->left->padre = hijo->padre;
						// hijo = hijo->left;
					}
					disminuirAlturas(porBorrar);
					checkBalance(porBorrar);
					delete porBorrar;
				}
				// else { // "hijo" es nodo interno
				// 	// break;
				// }


			} else if((hijo->par.first).compare(key) < 0) {//debe ir a la derecha
				if(hijo->right == NULL){
					break;// no está
				} else hijo = hijo->right; //sigue buscando por la derecha
			}else if((hijo->par.first).compare(key) > 0) {//debe ir a la izquierda
				if(hijo->left == NULL){
					break;// no está
				}else hijo = hijo->left; //sigue buscando por la izq
			}
		}
	}

}

int MapAVL::size(){
	return tam;
}

bool MapAVL::empty(){
	return !tam;
}
