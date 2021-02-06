#include<iostream>
using namespace std;

// Normal Recursion - TC - O(2^n), SC - O(n)
int fibo(int n) {
	// base case
	if(n <= 1) {
		return n;
	}
	// recursive case
	return fibo(n - 1) + fibo(n - 2);
}

// Top Down Approach - TC - O(n), SC - O(n)
int fiboTopDown(int n, int dp[]) {
	// base case
	if(n <= 1) {
		return n;
	}
	// recursive case

	if(dp[n] != 0) {
		return dp[n];
	}
	int ans = fiboTopDown(n - 1, dp) + fiboTopDown(n - 2, dp);
	return dp[n] = ans;
}

// Bottom Up Approach - TC - O(n), SC - O(n)
int fiboBottomUp(int n) {
	int dp[100] = {0};
	dp[1] = 1;
	for(int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}

// Space Optimized - TC - O(n), SC - O(1)
int fiboSpaceOptimized(int n) {
	int a = 0;
	int b = 1;
	if(n <= 1) {
		return n;
	}

	int c;
	for(int i = 2; i <= n; i++) {
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}

int main() {

	int n;
	cin >> n;

	// cout << fibo(n) << endl;

	int dp[100] = {0};
	cout << fiboTopDown(n, dp) << endl;

	cout << fiboBottomUp(n) << endl;

	cout << fiboSpaceOptimized(n) << endl;

	return 0;
}