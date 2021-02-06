#include<iostream>
#include<climits>
using namespace std;

// Top Down
int minCoins(int n, int dp[], int coins[], int t) {
	if(n == 0) {
		return 0;
	}
	// Recursive Case
	if(dp[n] != 0) {
		return dp[n];
	}

	int ans = INT_MAX;
	for(int i = 0; i < t; i++) {
		if(n - coins[i] < 0) break;

		ans = min(ans, minCoins(n - coins[i], dp, coins, t));
	}
	return dp[n] = ans + 1;
}

// Bottom up
int minCoinsBU(int n, int coins[], int t) {

	int dp[1000] = {0};
	for(int i = 1; i <= n; i++) {
		int ans = INT_MAX;
		for(int j = 0; j < t; j++) {
			if(i - coins[j] < 0) break;
			ans = min(ans, dp[i - coins[j]]);
		}
		dp[i] = ans + 1;
	}
	return dp[n];
}



int main() {

	int n;
	cin >> n;
	int coins[] = {1, 7, 10};
	int t = sizeof(coins) / sizeof(int);

	int dp[1000] = {0};
	cout << minCoins(n, dp, coins, t) << endl;
	cout << minCoinsBU(n, coins, t) << endl;

	return 0;
}