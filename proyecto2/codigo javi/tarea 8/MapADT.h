#ifndef MAP_H
#define MAP_H
#include "MapADT.h"
using namespace std;
class MapADT{
	public:
		virtual void insert(pair<string, int>) = 0; //Insertar un valor que tiene asociado una llave k
		//virtual void erase(string) = 0; //Eliminar el valor asociado a una llave k
		virtual int at(string) = 0; //Encontrar el valor asociado a una llave k
		virtual int size() = 0; //Obtener cantidad de elementos almacenados
		virtual bool empty() = 0; //Verificar si estávacía
};
#endif