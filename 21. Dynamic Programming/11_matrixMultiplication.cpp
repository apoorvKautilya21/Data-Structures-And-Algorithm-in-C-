#include<iostream>
#include<climits>
using namespace std;

// int minCostOfMultiplication(int p[], int n) {
// 	// here n is the number of matrix
// 	int dp[100][100] = {0};

// 	// Indexing of matrix starts from 1
// 	for(int k = 1; k <= n - 1; k++) {
// 		// i always starts from 1
// 		// j always starts from 2, 3, 4, ... n
// 		int i = 1;
// 		int j = k + 1;

// 		while(j <= n) {
// 			dp[i][j] = INT_MAX;
// 			for(int l = i; l < j; l++) {
// 				dp[i][j] = min(dp[i][j], dp[i][l] + dp[l + 1][j] + p[i - 1] * p[l] * p[j]);
// 			}
// 			j++;
// 			i++;
// 		}
// 	}

// 	return dp[1][n];
// }

int minCostOfMultiplication2(int p[], int n) {
	// here n is the number of matrix
	int dp[200][200] = {0};

	// Indexing of matrix starts from 0
	for(int i = 1; i < n; i++) {
		int r = 0;
		int c = i;
		while(c < n) {
			// r always starts from 0
			// c always starts from 1, 2, 3... n
			dp[r][c] = INT_MAX;
			for(int k = r; k < c; k++) {
				dp[r][c] = min(dp[r][c], dp[r][k] + dp[k + 1][c] + p[r] * p[k + 1] * p[c + 1]);
			}
			r++;c++;
		}
	}

	return dp[0][n - 1];
}


int main() {

	int p[] = {40, 20, 30, 10, 30};
	int n = sizeof(p) / sizeof(int);

	cout << minCostOfMultiplication2(p, n - 1);

	return 0;
}