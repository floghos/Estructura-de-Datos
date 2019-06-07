#include "MapSV.h"
#include <vector>
#include <string>
#include <iostream>
#include <iterator>

int MapSV::busquedaBinaria(string key) {
	int lower = 0;
	int upper = _size - 1;
	int mid;

	while (upper >= lower) {
		mid = (upper + lower)/2;
		if (map[mid].first.compare(key) < 0) {
			lower = mid + 1;
		} else if (map[mid].first.compare(key) > 0) {
			upper = mid - 1;
		} else { //encontramos la aparicion en "mid"
			return mid;
		}
	}
	return lower; //key no se encuentra en el vector, pero devolvemos la posicion dende deberia estar
}

MapSV::MapSV() {
	_size = 0;
}

void MapSV::insert(pair<string, int> entry) {
	if (empty()) {
		map.push_back(entry);
		_size++;
	} else {
		int pos = busquedaBinaria(entry.first);
		// cout << "debemos insertar en: " << pos << '\n';
		if (pos < _size && map[pos].first.compare(entry.first) == 0) { //la clave ingresada ya existe
			cout << "'" << entry.first <<  "' ya existe" << '\n';
		} else if (pos == _size) {
			map.push_back(entry);
			_size++;
		} else {
			map.push_back(map[_size-1]);
			for (int i = _size-2; i >= pos; i--) {
				map[i+1] = map[i];
			}
			map[pos] = entry;
			_size++;
		}
	}
}

int MapSV::at(string key) {
	int pos = busquedaBinaria(key);
	if (pos < _size && map[pos].first.compare(key) == 0) { //la clave ingresada ya existe
		return map[pos].second;
	} else {
		cout << "'" << key <<  "' no existe" << '\n';
		return 0;
	}
}

void MapSV::erase(string key) {
	int pos = busquedaBinaria(key);
	if (pos < _size && map[pos].first.compare(key) == 0 && !empty()) { //la clave ingresada ya existe
		map.erase(map.begin() + pos);
		_size--;
	} else {
		cout << "'" << key <<  "' no existe" << '\n';
	}
}

bool MapSV::empty() {
	return !_size;
}

int MapSV::size() {
	return _size;
}
