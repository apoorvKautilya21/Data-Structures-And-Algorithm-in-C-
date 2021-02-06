#include<bits/stdc++.h>
using namespace std;


bool checkSum(int a[], int n) {
	unordered_set<int> s;
	int pre = 0;	// For calculating running prefux sum

	for(int i = 0; i < n; i++) {
		pre += a[i];

		if(pre == 0 or s.find(pre) != s.end()) {
			return true;
		}

		s.insert(pre);
	}
	return false;
}


int main() {

	int n;
	cin >> n;

	int arr[n];
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	if(checkSum(arr, n)) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}

	return 0;
}