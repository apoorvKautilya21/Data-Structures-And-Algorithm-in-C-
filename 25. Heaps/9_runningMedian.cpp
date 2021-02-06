#include <iostream>
#include <queue>
using namespace std;

int main() {

	float a[] = {1, 1, 5, 4, 3, 0};
	int n = sizeof(a) / sizeof(int);
	float median = 0;	

	priority_queue<float> max_heap;
	priority_queue<float, vector<int>, greater<int> > min_heap;

	for(int i = 0; i < n; i++) {

		if(median < a[i]) {
			if(max_heap.size() < min_heap.size()) {
				max_heap.push(min_heap.top());
				min_heap.pop();
			}
			min_heap.push(a[i]);
		}

		else {
			if(max_heap.size() > min_heap.size()) {
				min_heap.push(max_heap.top());
				max_heap.pop();
			}
			max_heap.push(a[i]);
		}

		if(max_heap.size() == min_heap.size()) {
			median = (min_heap.top() + max_heap.top()) / 2;
		}
		else {
			median = max_heap.size() > min_heap.size() ? max_heap.top() : min_heap.top();
		}

		cout << median << " ";
	}





	return 0;
}