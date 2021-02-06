#include<iostream>
#include<climits>
using namespace std;

/*
you are given a number n and you can perform the following operations at a time to 
convert it to 1
	1. n -> n / 3 ------ if(n % 3 == 0)
	2. n -> n / 2 ------ if(n % 2 == 0)  
	3. n -> n - 1
Find the minimum number of steps needed to reach at one

NOTE:- ----------------------------------------------------------------------
|||...Clearly here we can't apply greedy here so we have to apply DP here..|||
-----------------------------------------------------------------------------
*/

// Top Down
int minStepsTopDown(int n, int dp[]) {
	// Base Case
	if(n == 1) {
		return 0;
	}
	// Recursive case

	if(dp[n] != 0) {
		return dp[n];
	}

	int s_dvd_2, s_dvd_3, s_minus_1;
	s_dvd_2 = s_dvd_3 = s_minus_1 = INT_MAX;
	if(n % 2 == 0) {
		s_dvd_2 = minStepsTopDown(n / 2, dp);
	}

	if(n % 3 == 0) {
		s_dvd_3 = minStepsTopDown(n / 3, dp);
	}

	s_minus_1 = minStepsTopDown(n - 1, dp);

	int ans = min(min(s_dvd_2, s_dvd_3), s_minus_1) + 1;
	return dp[n] = ans;
}

// Bottom down
int minStepsBottomDown(int n) {
	if(n == 1) {
		return 0;
	}

	int dp[1000] = {0};

	for(int i = 2; i <= n; i++) {
		int a, b, c;
		a = b = c = INT_MAX;
		// n - 1
		a = dp[i - 1];
		// n / 2
		if(i % 2 == 0) {
			b = dp[i / 2];
		}
		// n / 3
		if(i % 3 == 0) {
			c = dp[i / 3];
		}
		dp[i] = min(min(a, b), c) + 1;
	}
	return dp[n];
}


int main() {

	int n;
	cin >> n;

	int dp[1000] = {0};
	cout << minStepsTopDown(n, dp) << endl;
	cout << minStepsBottomDown(n) << endl;

	return 0;	
}