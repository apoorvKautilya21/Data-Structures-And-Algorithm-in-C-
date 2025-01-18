#include<iostream>
#include<unordered_map>
using namespace std;

int numberOfRightTraingle(int x[], int y[], int n) {

	unordered_map<int, int> xCor;
	unordered_map<int, int> yCor;

	for(int i = 0; i < n; i++) {
		xCor[x[i]]++;
		yCor[y[i]]++;
	}

	int ans = 0;
	for(int i = 0; i < n; i++) {
		ans += (xCor[x[i]] - 1) * (yCor[y[i]] - 1);
	}

	return ans;
}


int main() {

	int n;
	int x[100], y[100];
	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}

	cout << numberOfRightTraingle(x, y, n) << endl;

	return 0;
}