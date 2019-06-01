#include <iostream>
#include <string>
#include "ADTMap.h"
#include "MapB.h"

using namespace std;

int main(int argc, char const *argv[]) {
	MapB badMap;
	string key;
	int val;

	cin >> key >> val;

	pair<string, int> data;
	data.first = key;
	data.second = val;

	badMap.insert(data);

	cout << badMap.at(key) << '\n';

	badMap.erase(key);

	cout << badMap.at(key) << '\n';



    return 0;
}
