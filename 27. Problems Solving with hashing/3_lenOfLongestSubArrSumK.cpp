#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


int lenOfSubArrSumK(int a[], int n, int k) {

	unordered_map<int, int> m;
	int len = 0;
	int pre = 0;

	for(int i = 0; i < n; i++) {
		pre += a[i];

		if(pre == k) {
			len = max(len, i + 1);
		}

		if(m.find(pre - k) != m.end()) {
			len = max(len, i - m[pre]);
		}
		else {
			m[pre] = i;
		}
	}

	return len;
}


int main() {

	int n, k;
	cin >> n >> k;

	int a[100];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << lenOfSubArrSumK(a, n, k);

	return 0;
}