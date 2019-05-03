#include <bits/stdc++.h>
#include "ArrayStack.h"
#include "LinkedStack.h"

using namespace std;

int main(){
	int n;
	srand(time(NULL));
	ArrayStack as;
	LinkedStack ls;

	do {
		cout<<"Cantidad de numeros a insertar"<<endl;
		cin>>n;
	} while(n < 0);
	cout << n << '\n';

	clock_t t1 = clock();
	for(int i = 0; i<n; i++){
		as.push(rand()%100);
	}

	clock_t t2 = clock();
	double tiempo = (double)(t2-t1)/CLOCKS_PER_SEC;
	printf("Insercion ArrayStack: %.10f\n", tiempo);

	t1 = clock();
	for(int i = 0; i<n; i++){
		ls.push(rand()%100);
	}
	t2 = clock();
	tiempo = (double)(t2-t1)/CLOCKS_PER_SEC;
	printf("Insercion LinkedStack: %.10f\n", tiempo);

	t1 = clock();
	while(!as.isEmpty()){
		as.pop();
	}
	t2 = clock();
	tiempo = (double)(t2-t1)/CLOCKS_PER_SEC;
	printf("Pop ArrayStack: %.10f\n", tiempo);

	t1 = clock();
	while(!ls.isEmpty()){
		ls.pop();
	}
	t2 = clock();
	tiempo = (double)(t2-t1)/CLOCKS_PER_SEC;
	printf("Pop LinkedStack: %.10f\n", tiempo);

	return 0;
}
