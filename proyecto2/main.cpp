#include <iostream>
#include <math.h>
#include <time.h>
#include "ADTMap.h"
#include "MapSV.h"
#include "MapH.h"
#include "MapAVL.h"

using namespace std;

void paresAleatorios(int n, vector<pair<string, int> >& v);
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
	cin >> n;
	// paresAleatorios(n, data); //creacion aleatoria de datos

	cout<<"PARES ORDENADOS"<<endl;
	pair<string, int> entry;

	int range = (int)ceil(pow(n, 1.f/5));
	cout << "range: " << range << '\n';
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
						c5 = 'a' + m;

						key.push_back(c1);
						key.push_back(c2);
						key.push_back(c3);
						key.push_back(c4);
						key.push_back(c5);

						entry.first = key;
						entry.second = rand() % val_limit;

						data.push_back(entry);
						key.clear();
					}
				}
			}
		}
	}

//impresion de los pares generados
	// cout << "los datos creados son:" << '\n';
	// for (int i=0; i<n; i++){
	// 	cout<< i << ": " << "("<<data[i].first<<","<<data[i].second<<")"<<endl;
	// }

	// for (int i = 0; i < n; i++) { //ingreso manual de datos
	// 	cin >> dato.first >> dato.second;
	// 	data.push_back(dato);
	// }

//Insertar elementos
	cout << "is empty: " << myMap.empty() << '\n';
	for (int i = 0; i < n; i++) {
		std::cout << "insertando elemento " << i << '\n';
		myMap.insert(data[i]);
	}
	cout << "_size: " << myMap.size() << '\n';

	// myMap.recPreOrder();

	// cout << "is empty: " << myMap.empty() << '\n';

	// std::cout << "Datos en el mapa:" << '\n';
	// for (int i=0; i<myMap.map.size(); i++){
	// 	cout<< i << ": " << "("<<myMap.map[i].first<<","<<myMap.map[i].second<<")"<<endl;
	// }

//Busqueda automatica de todos los elementos
	// std::cout << "Buscando todos los elementos" << '\n';
	// for (int i = 0; i < data.size(); i++) {
	// 	// cout << "Dato " << i <<" encontrado. Valor = " << myMap.at(data[i].first) <<'\n';
	// 	if (myMap.at(data[i].first) == -1) {
	// 		cout << "Dato " << i <<" NO encontrado" << '\n';
	// 	}
	// }

//prueba de busqueda manual de elementos
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
