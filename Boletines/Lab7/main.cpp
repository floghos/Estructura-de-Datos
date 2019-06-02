#include <iostream>
#include <string>
#include "ADTMap.h"
#include "MapB.h"
#include "MapG.h"

using namespace std;

int main(int argc, char const *argv[]) {
	MapB badMap;
	MapG goodMap;

	string key;
	int n, val;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> key >> val;

		pair<string, int> data;
		data.first = key;
		data.second = val;

		goodMap.insert(data);
	}
	cout << "size of our hashtable: " << goodMap.size() << '\n';

	std::cout << "Printing full table" << '\n';
	for (int i = 0; i < goodMap.capacity; i++) {
		cout << i << " " << goodMap.myMap[i].key << '\n';
	}
	std::cout << "This was it...\n" << '\n';
	std::cout << "Now on to removing elements" << '\n';
	while (key.compare("stop") != 0) {
		cin >> key;
		cout << goodMap.at(key) << '\n';
		goodMap.erase(key);

	}

	// cout << goodMap.at(key) << '\n';
    return 0;
}
