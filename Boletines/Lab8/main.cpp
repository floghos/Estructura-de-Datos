#include <iostream>
#include <vector>
#include <time.h>
#include <math.h>
#include "ADTMap.h"
#include "MapBST.h"

using namespace std;

int main(int argc, char const *argv[]) {
	static int val_limit = 1000;

    MapBST mymapRand, mymapSort;
    string key;
    int n, val;
    pair<string, int> entry;
	vector<pair<string, int> > dataRand, dataSort;

	srand(time(NULL));


	cin >> n;

	int range = (int)ceil(pow(n, 1.f/5));
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

						dataSort.push_back(entry);
						key.clear();
					}
				}
			}
		}
	}

	std::cout << "insertado en mymapSort..." << '\n';
	for (int i = 0; i < n; i++) { //insercion de un vector con datos
		mymapSort.insert(dataSort[i]);
	}

	char carac;
	for (int i = 0; i < n; i++) { //generacion de claves en orden aleatorio
		for (int j = 0; j < 5; j++) {
			carac = 'a' + rand() % ('z' - 'a' + 1);
			key.push_back(carac);
		}
		entry.first = key;
		entry.second = rand() % val_limit;

		dataRand.push_back(entry);
		key.clear();
	}

	std::cout << "insertado en mymapRand..." << '\n';
	for (int i = 0; i < n; i++) { //insercion de un vector con datos
		mymapRand.insert(dataRand[i]);
	}

	int fails = 0;
	clock_t t1 = clock();
	for(int i = 0; i < n; i++){
		mymapRand.at(dataRand[n].first;
	}
	clock_t t2 = clock();
	double tiempo = (double)(t2-t1)/CLOCKS_PER_SEC;
	printf("avrg at() time for mymapRand: %.10f\n", tiempo/n);


	t1 = clock();
	fails = 0;
	for(int i = 0; i < n; i++){
		mymapSort.at(dataSort[n].first;
	}
	t2 = clock();
	tiempo = (double)(t2-t1)/CLOCKS_PER_SEC;
	printf("avrg at() time for mymapSort: %.10f\n", tiempo/n);

    return 0;
}
