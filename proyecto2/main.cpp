#include <iostream>
#include "ADTMap.h"
#include "MapSV.h"
#include <time.h>

using namespace std;

void paresAleatorios(int n, vector<pair<string, int> >& v);
int main(int argc, char const *argv[]) {
	int n;
	vector<pair<string, int> > pares;
	MapSV myMap;

	cout << "INGRESE LA CANTIDAD DE PARES A INGRESAR"<<endl;
	cin >> n;
	paresAleatorios(n, pares);
	cout << "los datos creados son:" << '\n';
	for (int i=0; i<n; i++){
		cout<< i << ": " << "("<<pares[i].first<<","<<pares[i].second<<")"<<endl;
	}

	cout << "is empty: " << myMap.empty() << '\n';
	for (int i = 0; i < pares.size(); i++) {
		myMap.insert(pares[i]);
		cout << "_size: " << myMap.size() << '\n';
	}
	cout << "is empty: " << myMap.empty() << '\n';

	// std::cout << "Datos en el mapa:" << '\n';
	// for (int i=0; i<myMap.map.size(); i++){
	// 	cout<< i << ": " << "("<<myMap.map[i].first<<","<<myMap.map[i].second<<")"<<endl;
	// }

	// cout << "Ingrese el dato que desea buscar: ";
	cout << "Ingrese el dato que desea borrar: ";
	cin >> n;
	while(n >= 0 && n < pares.size()) {
		// cout << '\n'; //test at()
		// if (myMap.at(pares[n].first)) {
		// 	cout << myMap.at(pares[n].first) << '\n';
		// }
		// cout << "Ingrese el dato que desea buscar: ";
		// cin >> n;

		cout << '\n'; // test erase()
		myMap.erase(pares[n].first);
		cout << "_size: " << myMap.size() << '\n';
		cout << "Ingrese el dato que desea borrar: ";
		cin >> n;

	}

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
