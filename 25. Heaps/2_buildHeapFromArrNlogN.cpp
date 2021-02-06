#include<iostream>
#include<vector>
using namespace std;

// max heap
void buildHeap(vector<int> &v) {

	int n = v.size();
	for(int i = 2; i < n; i++) {

		int idx = i;
		int parent = i / 2;

		while(idx > 1 and v[idx] > v[parent]) {
			swap(v[idx], v[parent]);
			idx = parent;
			parent = parent / 2;
		}
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