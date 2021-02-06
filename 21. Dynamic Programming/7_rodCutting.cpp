#include<iostream>
#include<climits>
using namespace std;


int maxPrice(int prices[], int n, int dp[]) {
	// Base case
	if(n <= 0) {
		return 0;
	}
	// lookup
	if(dp[n] != 0) {
		return dp[n];
	}

	int ans = INT_MIN;
	for(int i = 0; i < n; i++) {
		int cut = i + 1;
		int current_price = prices[i] + maxPrice(prices, n - cut, dp);
		ans = max(ans, current_price);
	}

	return dp[n] = ans;
}


int maxPrice_dpBU(int a[], int n) {
	int dp[100] = {0};

	for(int len = 1; len <= n; len++) {
		int ans = INT_MIN;
		for(int i = 0; i < len; i++) {
			int cut = i + 1;
			int current_price = a[i] + dp[len - cut];
			ans = max(ans, current_price);
		}
		dp[len] = ans;
	}
	return dp[n];
}


int main() {

	int prices[] = {3, 5, 8, 9, 10, 17, 17, 20};
	int n = sizeof(prices) / sizeof(n);

	cout << maxPrice_dpBU(prices, n) << endl;
	int dp[100] = {0};
	cout << maxPrice(prices, n, dp) << endl;


	return 0;
}