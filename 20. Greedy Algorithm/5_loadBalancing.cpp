// https://www.spoj.com/problems/BALIFE/
#include<iostream>
#include<climits>
using namespace std;
#define ll long long

ll balanceLoad(int a[], int n, ll sum_n) {

	if(sum_n % n != 0) {
		return -1;
	}

	int finalLoad = sum_n / n;
	int l_sum = 0;
	int ans = INT_MIN;
	for(int i = 0; i < n - 1; i++) {
		l_sum += a[i];
		int reqTransfer = abs(l_sum - (i + 1) * finalLoad);
		ans = max(ans, reqTransfer);
	} 

	return ans;
}

int main() {

	int a[1000];

	while(1) {
		int n;
		cin >> n;

		if(n == -1) {
			break;
		}

		ll sum_n = 0;
		for(int i=0; i<n; i++) {
			cin >> a[i];
			sum_n += a[i];
		}

		int ans = balanceLoad(a, n, sum_n);
		cout << ans << endl;

	}

	return 0;
}