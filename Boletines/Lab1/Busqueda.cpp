#include <bits/stdc++.h>
#include "Busqueda.h"

using namespace std;

Busqueda::Busqueda(int n) {
  this->vec = new int[n];

  srand(time(NULL));

  for(int i=0;i<n;i++) {
    this->vec[i] = rand() % n + 1;
  }
  this->tam = n;
  sort(this->vec,this->vec + this->tam);

  // DESCOMENTAR ESTAS LINEAS PARA IMPRIMIR
  for(int i=0;i<this->tam;i++) cout<<this->vec[i]<<" ";
  puts("");

}

Busqueda::~Busqueda(){
 	delete this->vec;
}
int Busqueda::size(){
 	return this->tam;
}

int Busqueda::lineal(int num){
	int *pos = this->vec;
	for (int i = 0; i < this->tam; i++) {
		if (*(pos+i) == num) return i;
	}
	return -1;
}

int Busqueda::binaria(int num){
	int lower = 0;
	int higher = this->tam - 1;
	int mid = (higher - lower)/2;
	bool in_progress = true;

	while (higher >= lower) {
		mid = (higher + lower)/2;

		// cout << "middle = " << *((this->vec) + mid) << endl;
		if (*((this->vec) + mid) < num) {
			lower = mid + 1;
		} else if (*((this->vec) + mid) > num) {
			higher = mid - 1;
		} else if (*((this->vec) + mid) == num) { //encontramos una aparicion en "mid"

			if (mid == 0) { //si "mid" es 0, sabemos que es la primera
				return mid;
			} else {

				if (*((this->vec) + mid - 1) != num) {
					return mid;
				} else {
					higher = mid - 1;
				}

			}

		}
	}
	return -1;
}

int Busqueda::testSTL(int num){
  //http://www.cplusplus.com/reference/algorithm/lower_bound/
  int *iter = lower_bound(this->vec,this->vec+this->tam,num);
  int pos = iter-vec;
  if(pos>=this->tam){
    return -1;
  }else if(vec[pos]!=num){
    return -1;
  }else{
    return pos;
  }
}
