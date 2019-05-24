#include "ADTSearchTree.h"
#include "KdTree.h"
#include "QuadTree.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	KdTree kT;
	// QuadTree qT;

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

	kT.construir(puntos);
	// qT.construir(puntos);

	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	vector<pair<int, int> > puntosEncontrados = kT.buscar(x1,y1, x2, y2);
	// vector<pair<int, int> > puntosEncontrados = qT.buscar(x1,y1, x2, y2);
	cout << "Puntos fuera de rango: " << out_of_bounds << '\n';
	cout << "El total de puntos en el arbol es: " << puntos.size() << '\n';
	cout << "Los puntos encontrados dentro de el rango dado son: " << '\n';

	for (int i = 0; i < puntosEncontrados.size(); i++) {
		cout << "(" << puntosEncontrados[i].first << ", " << puntosEncontrados[i].second << ")\n";
	}
	// cout << '\n';


	return 0;
}
