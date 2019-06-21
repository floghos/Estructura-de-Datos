#include <iostream>
#include <math.h>
#include <time.h>
#include "ADTMap.h"
#include "MapSV.h"
#include "MapH.h"
#include "MapAVL.h"

using namespace std;

void borrarTodo(vector<pair<string, int> >& data, MapAVL &map, int n);
void buscarTodo(vector<pair<string, int> >& data, MapAVL &map, int n);

void borrarTodo(vector<pair<string, int> >& data, MapH &map, int n);
void buscarTodo(vector<pair<string, int> >& data, MapH &map, int n);

void borrarTodo(vector<pair<string, int> >& data, MapSV &map, int n);
void buscarTodo(vector<pair<string, int> >& data, MapSV &map, int n);

void paresOrdenados(int n, vector<pair<string, int> >& v);
void paresAleatorios(int n, vector<pair<string, int> >& v);
void imprimirDatos(vector<pair<string, int> >& data, int n);

int main(int argc, char const *argv[]) {
	int val_limit = 1000;
	vector<pair<string, int> > data;
	pair<string, int> dato;
	string key;
	int val;
	int n;
	// MapSV myMap;
	// MapH myMap;
	MapAVL myMap;

	cerr << "INGRESE LA CANTIDAD DE PARES A INGRESAR"<<endl;
	do {
		cin >> n;
	} while(n <= 0);

	paresAleatorios(n, data); //creacion aleatoria de datos
	// paresOrdenados(n, data); //creacion de datos ordenados alfabeticamente

// impresion de los pares generados
	// imprimirDatos(data, n);


	//ingreso manual de datos
	// for (int i = 0; i < n; i++) {
	// 	cin >> dato.first >> dato.second;
	// 	data.push_back(dato);
	// }

	//Insertar elementos
	cout << "is empty: " << myMap.empty() << '\n';
	for (int i = 0; i < n; i++) {
		// std::cout << "insertando elemento " << i << '\n';
		// cout << "Insertndo " << data[i].first <<endl;
		myMap.insert(data[i]);
		// cout << '\n';
	}
	cerr << "_size: " << myMap.size() << '\n';

	// buscarTodo(data, myMap, n);

//borrar un elemento aleatorio
	// int aBorrar = rand()%n;
	// std::cout << "Borraremos el elemento " << data[aBorrar].first << '\n';
	// myMap.erase(data[aBorrar].first);

	//myMap.recPreOrder();

//borrar todo
	borrarTodo(data, myMap, n);
	std::cout << "real size: " << myMap.size() << '\n';
	// myMap.recPreOrder(); //imprimir recorrido pre-order

	// std::cout << "Datos en el mapa:" << '\n';
	// for (int i=0; i<myMap.map.size(); i++){
	// 	cout<< i << ": " << "("<<myMap.map[i].first<<","<<myMap.map[i].second<<")"<<endl;
	// }

// Busqueda automatica de todos los elementos
	buscarTodo(data, myMap, n);

//Busqueda manual de elementos
	// cout << "Ingrese el dato que desea buscar: ";
	// // cout << "Ingrese el dato que desea borrar: ";
	// cin >> n;
	// while(n >= 0 && n < data.size()) {
	// 	cout << '\n'; //test at()
	// 	if (myMap.at(data[n].first) != -1) {
	// 		cout << myMap.at(data[n].first) << '\n';
	// 	} else {
	// 		cout << data[n].first << " not found" << '\n';
	// 	}
	// 	cout << "Ingrese el dato que desea buscar: ";
	// 	cin >> n;
	//
	// 	// cout << '\n'; // test erase()
	// 	// myMap.erase(data[n].first);
	// 	// cout << "_size: " << myMap.size() << '\n';
	// 	// cout << "Ingrese el dato que desea borrar: ";
	// 	// cin >> n;
	//
	// }

	return 0;
}

void imprimirDatos(vector<pair<string, int> >& data, int n) {
	cout << "los datos creados son:" << '\n';
	for (int i=0; i<n; i++){
		cout<< i << ": " << "("<<data[i].first<<","<<data[i].second<<")"<<endl;
	}
}

void borrarTodo(vector<pair<string, int> >& data, MapH &map, int n) {
	std::cerr << "borrando" << '\n';
	for (int i = 0; i < n; i++) {
	 	// cerr << "borrando " << data[i].first <<endl;
		// cerr << '\n';
		// map.recPreOrder();
		// std::cerr << "borrando elemento " << i << " " << data[i].first <<endl;
		map.erase(data[i].first);
	}
	cerr << "_size: " << map.size() << '\n';
}
void buscarTodo(vector<pair<string, int> >& data, MapH &map, int n) {
	std::cout << "Buscando todos los elementos" << '\n';
	for (int i = 0; i < n; i++) {
		// cout << "Dato " << i <<" encontrado. Valor = " << myMap.at(data[i].first) <<'\n';
		if (map.at(data[i].first) == -1) {
			cout << "Dato " << i <<" NO encontrado (" << data[i].first << ")" << '\n';
		}
	}
}

void borrarTodo(vector<pair<string, int> >& data, MapSV &map, int n) {
	std::cerr << "borrando" << '\n';
	for (int i = 0; i < n; i++) {
	 	// cerr << "borrando " << data[i].first <<endl;
		// cerr << '\n';
		// myMap.recPreOrder();
		// std::cerr << "borrando elemento " << i << " " << data[i].first <<endl;
		map.erase(data[i].first);
	}
	cerr << "_size: " << map.size() << '\n';
}
void buscarTodo(vector<pair<string, int> >& data, MapSV &map, int n) {
	std::cout << "Buscando todos los elementos" << '\n';
	for (int i = 0; i < n; i++) {
		if (map.at(data[i].first) == -1) {
			cout << "Dato " << i <<" NO encontrado (" << data[i].first << ")" << '\n';
		} else {
			// cout << "Dato " << i <<" encontrado. Valor = " << map.at(data[i].first) <<'\n';
		}
	}
}

void borrarTodo(vector<pair<string, int> >& data, MapAVL &map, int n) {
	std::cerr << "borrando" << '\n';
	for (int i = 0; i < n; i++) {
	 	// cerr << "borrando " << data[i].first <<endl;
		// cerr << '\n';
		// map.recPreOrder();
		// std::cerr << "borrando elemento " << i << " " << data[i].first <<endl;
		map.erase(data[i].first);
	}
	cerr << "_size: " << map.size() << '\n';
}
void buscarTodo(vector<pair<string, int> >& data, MapAVL &map, int n) {
	std::cout << "Buscando todos los elementos" << '\n';
	for (int i = 0; i < n; i++) {
		// cout << "Dato " << i <<" encontrado. Valor = " << myMap.at(data[i].first) <<'\n';
		if (map.at(data[i].first) == -1) {
			cout << "Dato " << i <<" NO encontrado (" << data[i].first << ")" << '\n';
		}
	}
}

void paresOrdenados(int n, vector<pair<string, int> >& v) {
	pair<string, int> entry;
	int range = (int)ceil(pow(n, 1.f/5));
	int val_limit = 1000;
	// cout << "range: " << range << '\n';
	char c1, c2, c3, c4 ,c5;
	for (int i = 0; i < range; i ++) { //creacion automatica de datos ordenados
		c1 = 'a' + i;
		for (int j = 0; j < range; j++) {
			c2 = 'a' + j;
			for (int k = 0; k < range; k++) {
				c3 = 'a' + k;
				for (int l = 0; l < range; l++) {
					c4 = 'a' + l;
					for (int m = 0; m < range; m++) {
						string key;
						c5 = 'a' + m;

						key.push_back(c1);
						key.push_back(c2);
						key.push_back(c3);
						key.push_back(c4);
						key.push_back(c5);

						entry.first = key;
						entry.second = rand() % val_limit;

						v.push_back(entry);
						// key.clear();
					}
				}
			}
		}
	}

}

void paresAleatorios(int n, vector<pair<string, int> >& v){
	char str[10];
    srand(time(NULL));
    int num;
    string palabra;
    pair<string, int> par;
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < 9; j++){
    		str[j] = 97 + rand() % (123 - 97);
    	}
    	num =  1 + rand() % (500 - 1);
		par.second = num;
    	palabra = str;
		par.first = str;
    	v.push_back(par);
    }
}
