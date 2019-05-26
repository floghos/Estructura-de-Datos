#include "ADTSearchTree.h"
#include "KdTree.h"
#include "QuadTree.h"
#include <bits/stdc++.h>

using namespace std;

int checkeoFuerzaBruta(vector<pair<int, int> > &puntos, int x1, int y1, int x2, int y2);
int main(int argc, char const *argv[]) {
	// KdTree kT;
	QuadTree qT;

	vector<pair<int, int> > puntos;

	int n, m, p;
	int out_of_bounds = 0;
	cin >> n >> m >> p;


	for (int i = 0; i < p; i++) {
		pair<int, int> pto;
		int f, c;
		cin >> f >> c;
		if(f < 0 || c < 0 || f > n-1 || c > m-1) { //verificamos que los puntos esten dentro del rango
			out_of_bounds++;
		} else {
			pto.first = f;
			pto.second = c;
			puntos.push_back(pto);
		}

	}

	// kT.construir(puntos);
	qT.construir(puntos);

	int x1 = 0,
		y1 = 0,
		x2 = 0,
		y2 = 0;

	cin >> x1 >> y1 >> x2 >> y2;


	//crearemos un rectangulo de busqueda con area entre 1 y 20% del total


	int cant_puntos_dentro_del_rango = checkeoFuerzaBruta(puntos, x1, y1, x2, y2);
	cout << "Puntos fuera del espacio definido: " << out_of_bounds << '\n';

	// clock_t t1 = clock();
	// for(int i = 0; i<n; i++){

	// }
	// clock_t t2 = clock();
	// double tiempo = (double)(t2-t1)/CLOCKS_PER_SEC;
	// printf("Busqueda %.10f\n", tiempo);

	// vector<pair<int, int> > puntosEncontrados = kT.buscar(x1, y1, x2, y2);
	vector<pair<int, int> > puntosEncontrados = qT.buscar(x1,y1, x2, y2);

	cout << "El total de puntos en el arbol es: " << puntos.size() << '\n';

	cout << "Cantidad de puntos dentro del rango (por fuerza bruta): " << cant_puntos_dentro_del_rango << '\n';
	cout << "Se encontraron " << puntosEncontrados.size() << " puntos dentro del rango.\n";

	if (puntosEncontrados.size()) {
		cout << "Estos son:\n";
		for (int i = 0; i < puntosEncontrados.size(); i++) {
			cout << "(" << puntosEncontrados[i].first << ", " << puntosEncontrados[i].second << ")\n";
		}
	}

	return 0;
}

int checkeoFuerzaBruta(vector<pair<int, int> > &puntos, int x1, int y1, int x2, int y2) {
	if (x2 < x1) swap(x1, x2);
	if (y2 < y1) swap(y1, y2);
	int cant = 0;

	for (int i = 0; i < puntos.size(); i++) {
		if (puntos[i].first >= x1 && puntos[i].first <= x2) {
			if (puntos[i].second >= y1 && puntos[i].second <= y2) cant++;
		}
	}

	return cant;
}
