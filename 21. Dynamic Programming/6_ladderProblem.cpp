#include<iostream>
using namespace std;


int noOfWays(int n, int k, int dp[]) {
	if(n <= 1) {
		return 1;
	}
	// Lookup
	if(dp[n] != 0) {
		return dp[n];
	}

	int ans = 0;
	for(int i = 1; i <= k; i++) {
		if(n - i < 0) {
			break;
		}
		ans += noOfWays(n - i, k, dp);
	}

	return dp[n] = ans;
}

int noOfWaysBU(int n, int k) {
	int dp[100] = {0};
	dp[0] = dp[1] = 1;
	for(int i = 2; i <= n; i++) {
		for(int j = 1; j <= k; j++) {
			if(i - j < 0) break;
			dp[i] += dp[i - j];
		}
	}

	return dp[n];
}

int noOfWaysOptimized(int n, int k) {
	int dp[100] = {0};
	dp[0] = dp[1] = 1;
	for(int i = 2; i <= k; i++) {
		dp[i] = 2 * dp[i - 1];
	}

	for(int i = k + 1; i <= n; i++) {
		dp[i] = dp[i - 1] - dp[i - k - 1] + dp[i - 1];
	}

	return dp[n];
}


int main() {

	int n, k;
	cin >> n >> k;
	int dp[100] = {0};
	cout << noOfWays(n, k, dp) << endl;
	cout << noOfWaysBU(n, k) << endl;
	cout << noOfWaysOptimized(n, k);

	return 0;
}