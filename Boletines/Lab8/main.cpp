#include <iostream>
#include <vector>
#include <time.h>
#include "ADTMap.h"
#include "MapBST.h"

using namespace std;

int main(int argc, char const *argv[]) {
    MapBST mymap;

    string key;
    int n, val;
    pair<string, int> entry;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> key >> val;
        entry.first = key;
        entry.second = val;
        mymap.insert(entry);
    }

    char c;
    cout << "Desea buscar un elemento? (y/n)" << '\n';
    cin >> c;
    while (c == 'y') {
        cout << "Ingrese la clave a buscar: ";
        cin >> key;
		if (mymap.at(key) > 0) {
			cout << key << " es " << mymap.at(key) << '\n';
		} else {
			cout << "'" << key << "' doesn't exist" << '\n';
		}
        cout << "Desea buscar otro elemento? (y/n)" << '\n';
        cin >> c;
    }


    return 0;
}
