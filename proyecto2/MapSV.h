#include "ADTMap.h"
#include <string>
#include <vector>

using namespace std;

class MapSV: public ADTMap {
private:
	vector<pair<string, int> > map;
	int _size;
	int busquedaBinaria(string key);
public:
	MapSV();
	void insert(pair<string, int> entry);
	int at(string key);
	void erase(string key);
	bool empty();
	int size();
};
