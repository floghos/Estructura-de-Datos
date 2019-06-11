#include "ADTMap.h"
#include <string>
using namespace std;

class MapH : public ADTMap {
	private:
		static int primos[];
		pair<string, int>* array;
		int tam;
		int capacidad;
		int indice;
		void rehashing();
		int fPol1(string s);
		int fPol2(string s);
	public:
		MapH();
		void insert(pair<string, int>);
		void erase(string);
		int at(string);
		int size();
		bool empty();
};
