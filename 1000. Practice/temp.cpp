#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int minCostOfMultiplication2(int p[], int n) {

	int dp[200][200] = {0};

	for(int i = 1; i < n; i++) {
		int r = 0, c = i;

		while(c < n) {
			dp[r][c] = INT_MAX;
			for(int k = r; k < c; k++) {
				dp[r][c] = min(dp[r][c], dp[r][k] + dp[k + 1][c] + p[r] * p[k+1] * p[c+1]);
			}
		}
	}
	return dp[0][n-1];
}


int main() {

	int p[] = {40, 20, 30, 10, 30};
	int n = sizeof(p) / sizeof(int);

	cout << minCostOfMultiplication2(p, n - 1);

	return 0;
}
