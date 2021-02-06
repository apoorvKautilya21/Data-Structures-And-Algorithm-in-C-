#include<iostream>
using namespace std;


int friendsProblem(int n, int dp[]) {

	if(n == 0 || n == 1) {
		return 1;
	}

	if(dp[n] != 0) {
		return dp[n];
	}

	dp[n] = friendsProblem(n - 1, dp) + (n - 1) * friendsProblem(n - 2, dp);
	return dp[n];
}	

int main() {

	int n;
	cin >> n;

	int dp[1000] = {0};
	cout << friendsProblem(n, dp);

	return 0;
}