#include <bits/stdc++.h>
#include "MapADT.h"
using namespace std;

struct nodo{
	pair<string, int> par;//informacion guardada
	nodo *hIzq = NULL;//puntero al hijo izquierdo
	nodo *hDer = NULL;//puntero al hijo derecho
};

class MapBST:public MapADT{
	private:
		int tam;
		nodo *raiz;
	//	void insertR(pair<string, int>, nodo*&);
	//	int atR(string, nodo*);
	public:
		MapBST();
		void insert(pair<string, int>); //Insertar un valor que tiene asociado una llave k
		//void erase(string); //Eliminar el valor asociado a una llave k
		int at(string); //Encontrar el valor asociado a una llave k
		int size(); //Obtener cantidad de elementos almacenados
		bool empty(); //Verificar si estávacía
};