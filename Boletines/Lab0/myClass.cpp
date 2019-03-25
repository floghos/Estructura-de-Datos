#include "myClass.h"
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <time.h>

using namespace std;

myClass::myClass(int val) {
  n = val;
  arr = new int[val];
  srand(time(NULL));
  for (int i = 0; i < val; i++) {
    arr[i] = rand() % 100;
  }
}

void myClass::mostrar() {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int myClass::suma() {
  int total = 0;
  for (int i = 0; i < n; ++i) {
    total += arr[i];
  }
  return total;
}
