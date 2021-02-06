#include<iostream>
#include<vector>
using namespace std;


void heapify(vector<int> &v, int idx) {

	int left = 2 * idx;
	int right = left + 1;
	int min_idx = idx;
	int last = v.size() - 1;

	if(left <= last and v[min_idx] < v[left]) {
		min_idx = left;
	}

	if(right <= last and v[min_idx] < v[right]) {
		min_idx = right;
	}

	if(min_idx != idx) {
		swap(v[min_idx], v[idx]);
		heapify(v, min_idx);
	}
}


// max heap
void buildHeap(vector<int> &v) {

	int n = v.size() - 1;

	for(int i = n / 2; i >= 1; i--) {

		heapify(v, i);
	}
}

int main() {

	vector<int> v{-1, 10, 20, 5, 6, 1, 8, 9, 4};

	buildHeap(v);

	for(int x:v) {
		cout << x << " ";
	}

	return 0;
}