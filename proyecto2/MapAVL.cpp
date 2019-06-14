#include <iostream>
#include <string>
#include "MapAVL.h"
using namespace std;

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
	}else{
		nodo *hijo;
		hijo = raiz;//comienzo apuntando en la raiz
		while(1){
			if((hijo->par.first).compare(p.first) == 0) {
				cout<<"Hay valor asociado a la clave: "<<p.second<<")"<<endl;
				break;
			}else if((hijo->par.first).compare(p.first) < 0) {//debe ir a la derecha
				//cout<<"der"<<endl;
				if(hijo->right == NULL){//si es nulo, puedo añadir
					//cout<<"der null, añado despues de: "<<hijo->par.first<<endl;
					nodo *nuevoNodo = new nodo;//creo un nodo nuevo
					nuevoNodo->par.first = p.first;
					nuevoNodo->par.second = p.second;
					hijo->right = nuevoNodo;
					tam++;//aumento tamaño
					break;
				}else hijo = hijo->right; //apunta al hijo derecho
			}else if((hijo->par.first).compare(p.first) > 0) {//debe ir a la izquierda
				//cout<<"izq"<<endl;
				if(hijo->left == NULL){//si es nulo, puedo añadir
					//cout<<"izq null, añado antes de: "<<hijo->par.first<<endl;
					nodo *nuevoNodo = new nodo;//creo un nodo nuevo
					nuevoNodo->par.first = p.first;
					nuevoNodo->par.second = p.second;
					hijo->left = nuevoNodo;
					tam++;//aumento tamaño
					break;
				}else hijo = hijo->left;//apunta al hijo izquierdo
			}
		}
	}
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
