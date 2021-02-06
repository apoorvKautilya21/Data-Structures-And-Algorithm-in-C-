#include<iostream>
#include<deque>
using namespace std;

int main() {

	int n;
	cin >> n;
	int a[100000];

	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int k;
	cin >> k;

	deque<int> q(k);
	for(int i = 0; i < k; i++) {
		while(!q.empty() and a[i] >= a[q.back()]) {
			q.pop_back();	
		}
		q.push_back(i);
	}

	for(int i = k; i < n; i++) {
		cout << a[q.front()] << " ";
		// Remove the elements which are not in subarray
		while(!q.empty() and q.front() <= i-k) {
			q.pop_front();
		}
		// remove the elements that are smaller than current one
		while(!q.empty() and a[i] >= a[q.back()]) {
			q.pop_back();
		}
		// add the current element
		q.push_back(i);
	}

	cout << a[q.front()];



	return 0;
}