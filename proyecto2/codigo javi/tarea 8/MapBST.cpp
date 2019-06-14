#include <bits/stdc++.h>
#include "MapBST.h"
using namespace std;
/*	private:
	public:
		MapBST();
		void insert(pair); //Insertar un valor que tiene asociado una llave k
		//void erase(string); //Eliminar el valor asociado a una llave k
		int at(string); //Encontrar el valor asociado a una llave k
		int size(); //Obtener cantidad de elementos almacenados
		bool empty(); //Verificar si estávacía
*/
MapBST::MapBST(){
	tam = 0;
	raiz = NULL;
}

void MapBST::insert(pair<string, int> p){
	if(tam == 0){//si no hay elementos añadidos
		raiz = new nodo;
		raiz->par.first = p.first;//añado en la raiz
		raiz->par.second = p.second;
		tam++;//aumento el tamaño
	}else{
		nodo *hijo;
		hijo = raiz;//comienzo apuntando en la raiz
		while(1){
			if((hijo->par.first).compare(p.first) == 0) {cout<<"Hay valor asociado a la clave: "<<p.second<<")"<<endl; break;}
			else if((hijo->par.first).compare(p.first) < 0) {//debe ir a la derecha
				//cout<<"der"<<endl;
				if(hijo->hDer == NULL){//si es nulo, puedo añadir
					//cout<<"der null, añado despues de: "<<hijo->par.first<<endl;
					nodo *nuevoNodo = new nodo;//creo un nodo nuevo
					nuevoNodo->par.first = p.first;
					nuevoNodo->par.second = p.second;
					hijo->hDer = nuevoNodo;
					tam++;//aumento tamaño
					break;
				}else hijo = hijo->hDer; //apunta al hijo derecho
			}else if((hijo->par.first).compare(p.first) > 0) {//debe ir a la izquierda
				//cout<<"izq"<<endl;
				if(hijo->hIzq == NULL){//si es nulo, puedo añadir
					//cout<<"izq null, añado antes de: "<<hijo->par.first<<endl;
					nodo *nuevoNodo = new nodo;//creo un nodo nuevo
					nuevoNodo->par.first = p.first;
					nuevoNodo->par.second = p.second;
					hijo->hIzq = nuevoNodo;
					tam++;//aumento tamaño
					break;
				}else hijo = hijo->hIzq;//apunta al hijo izquierdo
			}
		}
	}
}

int MapBST::at(string clave){
	if(tam == 0){
		cout<<"No hay valor asociado a la clave: ("<<clave<<")"<<endl;
		return -1;
	}else{
		nodo *hijo;
		hijo = raiz;//comienzo apuntando en la raiz
		while(1){
			if((hijo->par.first).compare(clave) == 0) {return hijo->par.second;}
			else if((hijo->par.first).compare(clave) < 0) {//debe ir a la derecha
				if(hijo->hDer == NULL){
					cout<<"No hay valor asociado a la clave: ("<<clave<<")"<<endl;
					return -1;
				}elsehijo = hijo->hDer; //apunta al hijo derecho
			}else if((hijo->par.first).compare(clave) > 0) {//debe ir a la izquierda
				if(hijo->hIzq == NULL){
					cout<<"No hay valor asociado a la clave: ("<<clave<<")"<<endl;
					return -1;
				}elsehijo = hijo->hIzq;//apunta al hijo izquierdo
			}
		}
	}
}

int MapBST::size(){
	return tam;
}

bool MapBST::empty(){
	return !tam;
}
