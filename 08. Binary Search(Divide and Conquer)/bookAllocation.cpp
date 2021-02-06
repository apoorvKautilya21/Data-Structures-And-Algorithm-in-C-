// https://www.geeksforgeeks.org/allocate-minimum-number-pages/
// https://hack.codingblocks.com/app/practice/1/1365/problem

#include<iostream>
#include<climits>
using namespace std;

bool isDistributed(int a[], int n, int m, int curr_min) {

	int curr_pages = 0;
	int count = 1;
	for(int i = 0; i < n; i++) {

		curr_pages += a[i];
		if(curr_pages > curr_min) {
			count += 1;
			curr_pages = a[i];

			if(count > m) {
				return false;
			}
		}

	} 
	return true;
}


int main() {

	int t;
	cin >> t;

	while(t--) {
		int n, m;
		cin >> n >> m;
		int sum = 0;
		int a[1000];

		for(int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}

		int s = a[n-1]; 
		int e = sum;
		int ans = INT_MAX;
		while(s <= e) {

			int mid = (s + e) / 2;
			// cout << mid << endl;

			if(isDistributed(a, n, m, mid)) {
				ans = min(ans,mid);
				e = mid - 1;
			}

			else {
				s = mid + 1; 
			}

		}

		cout << ans << endl;
	}

	return 0;
}