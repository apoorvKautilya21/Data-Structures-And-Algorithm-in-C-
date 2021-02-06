#include<iostream>
#include<vector>
using namespace std;



class Heaps {

	vector<int> v;
	bool minHeap;

	bool compare(int a, int b) {
		if(minHeap) {
			return a > b;
		}
		else {
			return a < b;
		}
	}

	void heapify_rec(int idx) {

		int left = 2 * idx;
		int right = 2 * idx + 1;
		int last = v.size() - 1;
		int min_idx = idx;

		if(left <= last and compare(v[idx] ,v[left])) {
			min_idx = left;
		}

		if(right <= last and compare(v[min_idx], v[right])) {
			min_idx = right;
		}

		if(min_idx != idx) {
			swap(v[min_idx], v[idx]);
			heapify_rec(min_idx);
		}
	}


public:

	Heaps(int default_size = 10, bool type = true) {
		v.reserve(default_size);
		minHeap = type;
		v.push_back(-1);
	}

	void push(int element) {

		v.push_back(element);
		int idx = v.size() - 1;  // index at which element is present
		int parent = idx / 2;

		while(idx > 1 and compare(v[parent], v[idx])) {
			swap(v[parent], v[idx]);
			idx = parent;
			parent = parent / 2;
		}	
	}

	int top() {
		return v[1];
	}

	void pop() {

		swap(v[1], v[v.size() - 1]);
		v.pop_back();

		heapify_rec(1);
	}

	bool isEmpty() {
		return v.size() == 1;
	}

};

int main() {

	Heaps h;
	int n;
	cin >> n;

	for(int i = 0; i < n; i++) {
		int no;
		cin >> no;
		h.push(no);
	}

	while(!h.isEmpty()) {

		cout << h.top() << " ";
		h.pop();
	}




	return 0;
}