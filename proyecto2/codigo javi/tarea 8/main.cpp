#include "MapBST.h"
#include <bits/stdc++.h>
using namespace std;

void paresAleatorios(int n, vector<pair<string, int> >& v){
	char str[10];
	srand(time(NULL));
	int num;
	string palabra;
	pair<string, int> par;
	for(int i=0; i<n; i++){
		for(int j=0; j<9; j++){
			str[j] = 97+rand()%(123-97);
		}
		num = 1+rand()%(500-1);
		palabra = str;
		par.first = palabra;
		par.second = num;
		v.push_back(par);
	}
}

int main(){
	cout<< "INGRESE LA CANTIDAD DE PARES A CREAR: ";
	int n;
	cin>>n;
	vector<pair<string, int> > pares;
	cout<<"PARES DESORDENADOS"<<endl;
	//paresAleatorios(n, pares);
	for(int i=0; i<n; i++){//desordenados
	//	cout<<"("<<pares[i].first<<", "<<pares[i].second<<")"<<endl;
	}
	cout<<"PARES ORDENADOS"<<endl;
	vector<pair<string, int> > data;
	pair<string, int> entry;
	string key;
	int val_limit = 1000;
	int range = (int)ceil(pow(n, 1.f/5));
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

	for(int i=0; i<n; i++){
		//cout<<"("<<data[i].first<<", "<<data[i].second<<")"<<endl;
	}

	MapBST m;
	cout<<"size..."<< m.size() <<endl;
	cout<<"empty..."<< m.empty() <<endl<<endl;
	cout<<"AÑADIENDO TODO"<<endl;
	for(int i=0; i<n; i++){
		//cout<<"ingresando: ("<<pares[i].first<<", "<<pares[i].second<<")"<<endl;
		cout<<i<<endl;
		m.insert(data[i]);
		
		//cout<<"size..."<< m.size() <<endl;
	}
	cout<<"size..."<< m.size() <<endl;
	cout<<"empty..."<< m.empty() <<endl<<endl;
	cout<<"BUSCANDO TODO"<<endl;
	for(int i=0; i<n; i++){
		m.at(data[i].first);
		
		//cout<<m.at(pares[i].first)<<endl;
	}
	//cout<<"añade la clave del elemento a buscar"<<endl;
	//string clave;
	//cin>>clave;
	//m.at(clave);
	return 0;
}