#include<iostream>
#include<queue>
#include<vector>
using namespace std;


int main() {

	// Max Heap
	priority_queue<int> pq_max_heap;
	// Min Heap
	priority_queue< int, vector<int>, greater<int> > pq;
	
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int no;
		cin >> no;
		pq.push(no);
	}

	while(!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}

	return 0;
}