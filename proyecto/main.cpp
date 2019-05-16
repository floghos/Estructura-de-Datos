#include "ADTSearchTree.h"
#include "KdTree.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	KdTree kT;
	vector<pair<int, int> > puntos;
	int n, m, p;
	cin >> n >> m >> p;

	for (int i = 0; i < p; i++) {
		pair<int, int> pto;
		int f, c;
		cin >> f >> c;
		pto.first = f;
		pto.second = c;
		puntos.push_back(pto);
	}

	kT.construir(puntos);
	
	// int x1, y1, x2, y2;
	// cin >> x1 >> y1 >> x2 >> y2;

	return 0;
}
