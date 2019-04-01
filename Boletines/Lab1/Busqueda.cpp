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
	int * pos = this->vec;
  for (int i = 0; i < this->tam; i++) {
	  if (*(pos+i) == num) return i;
  }
  return -1;
}

int Busqueda::binaria(int num){
	return 0;
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
