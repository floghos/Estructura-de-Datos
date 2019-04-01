#include <bits/stdc++.h>
#include "Busqueda.h"

using namespace std;

int main(){

  int n;
  cout<<"Ingrese la cantidad de números"<<endl;
  cin>>n;
  Busqueda b(n);


  int num,pos;
  double time;
  cout<<"Ingrese número a buscar"<<endl;
  cin>>num;

  int rep=100;

  clock_t start = clock();
  for(int i=0;i<rep;i++)  pos = b.lineal(num);
  time = ((double)clock() - start) / CLOCKS_PER_SEC;
  printf("Lineal: %d\n%.10f\n\n",pos, time/(double)rep);

  // start = clock();
  // for(int i=0;i<rep;i++)  pos = b.binaria(num);
  // time = ((double)clock() - start) / CLOCKS_PER_SEC;
  // printf("Binaria: %d\n%.10f\n\n",pos, time/(double)rep);

  start = clock();
  for(int i=0;i<rep;i++)  pos = b.testSTL(num);
  time = ((double)clock() - start) / CLOCKS_PER_SEC;
  printf("STL: %d\n%.10f\n\n",pos, time/(double)rep);


  return 0;
}
