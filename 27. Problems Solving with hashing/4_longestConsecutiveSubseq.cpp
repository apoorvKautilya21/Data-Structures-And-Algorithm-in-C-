#include<iostream>
#include<unordered_map>
using namespace std;
	

int findLargestSeq(int a[], int n) {

	unordered_map<int, int> m;	// number, streak_size
	int ans = 1;

	for(int i = 0; i < n; i++) {

		int no = a[i];
		auto prev = m.find(no - 1);
		auto next = m.find(no + 1);

		if(prev != m.end() and next != m.end()) {
			int l1 = m[no - 1];
			int l2 = m[no + 1];
			// we will modify only end coordinates of a streak
			m[no - l1] = l1 + l2 + 1;
			m[no + l2] = l1 + l2 + 1;
		}
		else if(prev != m.end()) {
			int l1 = m[no - 1];
			m[no - l1] = l1 + 1;
			m[no] = l1 + 1;
		}
		else if(next != m.end()) {
			int l2 = m[no + 1];
			m[no + l2] = l2 + 1;
			m[no] = l2 + 1;	
		}
		else {
			m[no] = 1;
		}
	}

	for(auto p : m) {
		ans = max(ans, p.second);
	}

	return ans;
}

int main() {

	int arr[] = {14,5,1,2,6,3,7,8,9,13,15,11,12,13,17,10};
	int n = sizeof(arr) / sizeof(int);

	cout << findLargestSeq(arr, n);

	return 0;
}