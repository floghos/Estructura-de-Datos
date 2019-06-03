#include <iostream>
#include <vector>
#include <time.h>
#include "ADTMap.h"
#include "MapBST.h"

using namespace std;

int main(int argc, char const *argv[]) {
    MapBST mymap;

    string key;
    int n, val;
    pair<string, int> entry;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> key >> val;
        entry.first = key;
        entry.second = val;
        mymap.insert(entry);
    }

    return 0;
}
