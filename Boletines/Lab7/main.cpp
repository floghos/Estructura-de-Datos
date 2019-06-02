#include <iostream>
#include <string>
#include "ADTMap.h"
#include "MapB.h"
#include "MapG.h"
#include "MapDH.h"

using namespace std;

int main(int argc, char const *argv[]) {
	MapB badMap;
	MapG goodMap;
	MapDH dhMap;

	string key;
	int n, val;

	cin >> n

	for (int i = 0; i < n; i++) {
		cin >> key >> val;

		pair<string, int> data;
		data.first = key;
		data.second = val;

		dhMap.insert(data);
	}
	cout << "size of our hashtable: " << dhMap.size() << '\n';

	while (key.compare("stop") != 0) {
		cin >> key;
		cout << dhMap.at(key) << '\n';
		dhMap.erase(key);
	}

    return 0;
}
