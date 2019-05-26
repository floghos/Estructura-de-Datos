#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char const *argv[]) {
	int n, x, y;
	char a, b, c;

	scanf("%c%d%c %d%c\n", &a, &x, &b, &y, &c);
	cout << x << " " << y << '\n';
	scanf("%d\n", &n);
	cout << n << '\n';
	for (int i = 0; i < n; i++) {
		scanf("%c%d%c %d%c\n", &a, &x, &b, &y, &c);
		cout << x << " " << y << '\n';
	}

	return 0;
}
