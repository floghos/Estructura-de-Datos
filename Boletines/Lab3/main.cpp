#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ListADT.h"
#include "ArrayList.h"
#include "LinkedList.h"

using namespace std;

int main(int argc, char const *argv[]) {
	int elementos;

	cout << "Ingrese el numero de elementos que tendran las listas: ";
	cin >> elementos;
	cout << '\n';

	ArrayList aList;
	LinkedList lList;


	cout << "Prueba de agregar elemento con push_back(int):\n";

	double time;
	cout << "ArrayList: ";
	clock_t start = clock();
	for (int i = 0; i < elementos; i++) {
		aList.push_back(i);
	}
	time = ((double)clock() - start) / CLOCKS_PER_SEC;
	printf("%.10f\n",time);

	cout << "LinkedList: ";
	start = clock();
	for (int i = 0; i < elementos; i++) {
		lList.push_back(i);
	}
	time = ((double)clock() - start) / CLOCKS_PER_SEC;
	printf("%.10f\n\n",time);

	/*########################################################*/
	/*########################################################*/

	int rep = 100;

	cout << "Prueba de acceso (peor caso) con at(int):\n";

	cout << "ArrayList: ";
	start = clock();
	for (int i = 0; i < rep; i++) {
		aList.at(elementos-1);
	}
	time = ((double)clock() - start) / CLOCKS_PER_SEC;
	printf("%.10f\n",time/(double)rep);


	cout << "LinkedList: ";
	start = clock();
	for (int i = 0; i < rep; i++) {
		lList.at(0);
	}
	time = ((double)clock() - start) / CLOCKS_PER_SEC;
	printf("%.10f\n\n",time/(double)rep);
	/*########################################################*/
	/*########################################################*/

	cout << "Prueba de metodo size():\n";

	cout << "ArrayList: ";
	start = clock();
	for (int i = 0; i < rep; i++) {
		aList.size();
	}
	time = ((double)clock() - start) / CLOCKS_PER_SEC;
	printf("%.10f\n",time/(double)rep);


	cout << "LinkedList: ";
	start = clock();
	for (int i = 0; i < rep; i++) {
		lList.size();
	}
	time = ((double)clock() - start) / CLOCKS_PER_SEC;
	printf("%.10f\n",time/(double)rep);

	return 0;
}


// clock_t start = clock();
// time = ((double)clock() - start) / CLOCKS_PER_SEC;
// printf("Lineal: %d\n%.10f\n\n",pos, time/(double)rep);


// for (int i = 0; i < lList.size(); i++) {
	// 	cout << lList.at(i) << '\n';
	// }
	//
	// int x = 0;
	// cout << "removing item " << x << '\n';
	// lList.remove(x);
