#include<iostream>
using namespace std;

int minCost(int cost[][3], int n, int m) {

	int dp[100][100] = {0};
	dp[0][0] = cost[0][0];
	for(int i = 1; i < m ;i++) {
		dp[0][i] = dp[0][i - 1] + cost[0][i];
	}

	for(int i = 1; i < n; i++) {
		dp[i][0] = dp[i - 1][0] + cost[i][0];
	}

	for(int i = 1; i < n; i++) {
		for(int j = 1; j < m; j++) {
			dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + cost[i][j];
		}
	}

	return dp[n - 1][m - 1];
}

int main() {

	int cost[][3] = {
			{1, 2, 3},
		    {4, 8, 2},
		    {1, 5, 3}
                };
   
   cout << "  " << minCost(cost, 3, 3);
   return 0;




	return 0;
}