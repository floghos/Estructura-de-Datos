#include <string>
#include "ADTMap.h"
using namespace std;

struct nodo{
	pair<string, int> par;//informacion guardada
	nodo *left = NULL;//puntero al hijo izquierdo
	nodo *right = NULL;//puntero al hijo derecho
	nodo *padre = NULL;
	int height = 0; //representa la altura de su sub-arbol
};

class MapAVL:public ADTMap{
	private:
		int tam;
		nodo *raiz;
		void aumentarAlturas(nodo *);
		void disminuirAlturas(nodo *);
		void recPreOrder(nodo *);
	public:
		MapAVL();
		void insert(pair<string, int>); //Insertar un valor que tiene asociado una llave k
		void erase(string); //Eliminar el valor asociado a una llave k
		int at(string); //Encontrar el valor asociado a una llave k
		int size(); //Obtener cantidad de elementos almacenados
		bool empty(); //Verificar si estávacía
		void recPreOrder();
};
