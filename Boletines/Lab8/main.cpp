#include <iostream>
#include <vector>
#include <time.h>
#include <math.h>
#include "ADTMap.h"
#include "MapBST.h"

using namespace std;

int main(int argc, char const *argv[]) {
	static int val_limit = 1000;

    MapBST mymap;
    string key;
    int n, val;
    pair<string, int> entry;
	vector<pair<string, int> > data;

	srand(time(NULL));

    cin >> n;
    // for (int i = 0; i < n; i++) { //creacion manual de datos
    //     cin >> key >> val;
    //     entry.first = key;
    //     entry.second = val;
    //     mymap.insert(entry);
    // }

	// n = n^(1/5)

	int range = (int)round(pow(n, 1.f/5));
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

	// char carac;
	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < 5; j++) {
	// 		carac = 'a' + rand() % ('z' - 'a' + 1);
	// 		key.push_back(carac);
	// 	}
	// 	entry.first = key;
	// 	entry.second = rand() % val_limit;
	//
	// 	data.push_back(entry);
	// 	key.clear();
	// }

	cout << "list of entries:" << '\n';
	for (int i = 0; i < data.size(); i++) {
		cout << data[i].first << " " << data[i].second << '\n';
	}

	for (int i = 0; i < data.size(); i++) { //insercion de un vector con datos
        mymap.insert(data[i]);
    }


    // char c;
    // cout << "Desea buscar un elemento? (y/n)" << '\n';
    // cin >> c;
    // while (c == 'y') {
    //     cout << "Ingrese la clave a buscar: ";
    //     cin >> key;
	// 	if (mymap.at(key) > 0) {
	// 		cout << key << " es " << mymap.at(key) << '\n';
	// 	} else {
	// 		cout << "'" << key << "' doesn't exist" << '\n';
	// 	}
    //     cout << "Desea buscar otro elemento? (y/n)" << '\n';
    //     cin >> c;
    // }

	while (true) {
        cout << "Ingrese la clave a buscar: ";
        cin >> key;
		if (mymap.at(key) > 0) {
			cout << key << " es " << mymap.at(key) << '\n';
		} else {
			cout << "'" << key << "' doesn't exist" << '\n';
		}
    }


    return 0;
}
