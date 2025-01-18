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
	// in this approach we are nothing but summing the last k elements
	/*
	0 1 2 3 4 5 6 7 8 9
	k = 3
	dp[4] = dp[3] + dp[2] + dp[1]
	dp[5] = dp[4] + dp[3] + dp[2] = dp[4] + (dp[4] - dp[1])
	or
	for(int i = k + 1; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 1] - dp[i - k - 1]
	
	but before that we need make the dp array till 0 -- k
	let k = 5
	dp[0] = dp[1] = 1;
	dp[2] = dp[0] + dp[1] = 2 * dp[1]
	dp[2] = 2;
	dp[3] = dp[2] + dp[1] + dp[0] = dp[2] + dp[2] = 2 * dp[2]
	dp[4] = dp[3] + dp[2] + dp[1] + dp[0] = dp[3] + dp[3] = 2 * dp[3]

	for(int i = 2; i <= k; i++) 
		dp[i] = dp[i - 1] * 2
	because when i <= k
	then to calculate dp[i] we do dp[i - 1] + (before terms)
	same before terms we used to calculate the dp[i - 1]
	=> dp[i - 1] = (before terms)	
	*/
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

	int n, k;	// n is the number of stairs and k - max no of steps that can be taken
	cin >> n >> k;
	int dp[100] = {0};
	cout << noOfWays(n, k, dp) << endl;
	cout << noOfWaysBU(n, k) << endl;
	cout << noOfWaysOptimized(n, k);

	return 0;
}