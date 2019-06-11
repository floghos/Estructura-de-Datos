#include <string>
#include <iostream>
#include "MapH.h"

using namespace std;

int MapH::primos[] = {53,97,193,389,769,1543,3079,6151,12289,24593,49157,98317,196613,393241,786433,1572869,3145739,6291469,12582917,25165843,50331653,100663319,201326611,402653189,805306457,1610612741};

MapH::MapH(){
	indice = 0;
	capacidad = primos[0];
	array = new pair<string, int> [capacidad];
	tam = 0;
	for(int i=0; i<capacidad; i++){
		array[i].first = "\n";
	}
}

void MapH::insert(pair<string, int> par){
	if(tam == capacidad) rehashing();
	int pos = fPol1(par.first);
	int desp = fPol2(par.first);
	for(int i=0; i<capacidad; i++){
		if(array[pos].first == "\n" || array[pos].first == "1"){
			array[pos].second = par.second;
			array[pos].first = par.first;
			tam++;
			break;
		}else if(array[pos].first == par.first){
			cout<<"Ya hay un elemento con la clave ingresada, no se puede añadir: ("<<par.second<<", "<<par.first<<")"<<endl;
			break;
		}
		pos = (pos+desp)%capacidad;
	}
}

void MapH::erase(string clave){
	int pos = fPol1(clave);
	int desp = fPol2(clave);
	for(int i=0; i<capacidad; i++){
		if(array[pos].first == clave){
			array[pos].second = 0;
			array[pos].first = "1";
			tam--;
			break;
		}else if(array[pos].first == "\n") break;
		pos = (pos+desp)%capacidad;
	}
}

int MapH::at(string clave){
	int pos = fPol1(clave);
	int desp = fPol2(clave);
	for(int i=0; i<capacidad; i++){
		if(array[pos].first == clave){
			return array[pos].second;
		}else if(array[pos].first == "\n"){
			return -1;
		}
		pos = (pos+desp)%capacidad;
	}
	return -1;
}

int MapH::size(){
	return tam;
}

bool MapH::empty(){
	return !tam;
}

int MapH::fPol1(string clave){
	int pos = 0;
	int z = 33;
	for(int i=0; i<clave.size(); i++){
		pos = (z*pos)%capacidad + clave[i];
	}
	pos = pos%capacidad;
	return pos;
}

int MapH::fPol2(string clave){
	int pos = 0;
	int z = 7;
	for(int i=0; i<clave.size(); i++){
		pos = (z*pos)%capacidad + clave[i];
	}
	pos = (pos%(capacidad-2))+1;
	return pos;
}

void MapH::rehashing(){
	indice++;
	capacidad = primos[indice];
	pair<string, int>* aux = new pair<string, int> [capacidad];
	for(int i=0; i<capacidad; i++){
		aux[i].first = "\n";
	}
	int pos, desp;
	for(int i=0; i<tam; i++){
		pos = fPol1(array[i].first);
		desp = fPol2(array[i].first);
		for(int j=0; j<capacidad; j++){
			if(aux[pos].first == "\n"){
				aux[pos] = array[i];
				break;
			}
			pos = (pos+desp)%capacidad;
		}
	}
	delete[] array;
	array = aux;
}
