#include<iostream>
using namespace std;

int totalBSTs(int n) {
	// dp[i] stores total number of ways of making the BSTs with total i nodes with values
	// in increasing order like {num, num+1, ...., num+i-1}
	int dp[1000];
	dp[0] = dp[1] = 1;

	int ans = 0;
	for(int num = 2; num <= n; num++) {
		dp[num] = 0;
		for(int i = 1; i <= num; i++) {
			dp[num] += dp[i - 1] * dp[num - i];
		}
	}
	return dp[n];
}

int main() {

	int n;
	cin >> n;

	cout << totalBSTs(n);

	return 0;
}