#include <iostream>
#include "ADTPriorityQueue.h"
#include "PriorityQueueHeap.h"
#include "PriorityQueueSorted.h"
#include "PriorityQueueUnsorted.h"

using namespace std;

void heapSort(vector<int> &v);
void selectionSort(vector<int> &v);
void insertionSort(vector<int> &v);

int main(int argc, char const *argv[]) {
	vector<int> numbers;
	int n = 30;
	for (int i = 0; i < n; i++) {
		int num = rand() % 50;
		numbers.push_back(num);
		cout << num << " ";
	}

	cout << '\n';
	selectionSort(numbers);

	for (int i = 0; i < numbers.size(); i++) {
		cout << numbers[i] << " ";
	}
	cout << '\n';

    return 0;
}

void heapSort(vector<int> &v) {
	PriorityQueueHeap heapQ;
	int len = v.size();
	for (int i = 0; i < len; i++) {
		heapQ.push(v[i]);
	}
	for (int i = 0; i < len; i++) {
		v[i] = heapQ.top();
		heapQ.pop();
	}
}

void selectionSort(vector<int> &v) {
	PriorityQueueSorted sortedQ;
	int len = v.size();
	for (int i = 0; i < len; i++) {
		sortedQ.push(v[i]);
	}
	for (int i = 0; i < len; i++) {
		v[i] = sortedQ.top();
		sortedQ.pop();
	}
}

void insertionSort(vector<int> &v) {
	PriorityQueueUnsorted unsortedQ;
	int len = v.size();
	for (int i = 0; i < len; i++) {
		unsortedQ.push(v[i]);
	}
	for (int i = 0; i < len; i++) {
		v[i] = unsortedQ.top();
		unsortedQ.pop();
	}
}
