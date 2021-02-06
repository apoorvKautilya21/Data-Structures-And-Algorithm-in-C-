#include<iostream>
#include<vector>
using namespace std;



void heapify(vector<int> &v, int idx, int size) {

	int left = 2 * idx;
	int right = left + 1;
	int min_idx = idx;
	int last = size - 1;

	if(left <= last and v[min_idx] < v[left]) {
		min_idx = left;
	}

	if(right <= last and v[min_idx] < v[right]) {
		min_idx = right;
	}

	if(min_idx != idx) {
		swap(v[min_idx], v[idx]);
		heapify(v, min_idx, size);
	}
}


// max heap
void buildHeap(vector<int> &v) {

	int n = v.size() - 1;

	for(int i = n / 2; i >= 1; i--) {

		heapify(v, i, n + 1);
	}
}


void heapSort(vector<int> &v) {

	int n = v.size();

	buildHeap(v);

	while(n > 1) {

		swap(v[1], v[n - 1]);
		n--;

		heapify(v, 1, n);
	}
}


int main() {

	int n;
	vector<int> v;
	v.push_back(-1);

	cin >> n;
	for(int i = 0; i < n; i++) {
		int no;
		cin >> no;
		v.push_back(no);
	}

	heapSort(v);

	for(int i = 1; i <= n; i++) {
		cout << v[i] << " ";
	}





	return 0;
}