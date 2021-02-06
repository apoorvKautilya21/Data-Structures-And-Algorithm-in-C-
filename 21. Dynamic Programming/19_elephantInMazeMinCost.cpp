#include<iostream>
using namespace std;
#define R 4
#define C 4

int countPaths() {

	int dp[100][100] = {0};
	dp[0][0] = 1;
	for(int i = 0; i < R; i++) {
		for(int j = 0; j < i; j++) {
			dp[i][0] += dp[j][0];
		}
	}

	for(int i = 0; i < C; i++) {
		for(int j = 0; j < i; j++) {
			dp[0][i] += dp[0][i];
		} 
	}

	for(int i = 1; i < R; i++) {
		for(int j = 1; j < C; j++) {
			for(int k = 0; k < i; k++) {
				dp[i][j] += dp[k][j];
			}
			for(int k = 0; k < j; k++) {
				dp[i][j] += dp[i][k];
			}
		}
	}
	return dp[R - 1][C - 1];
}

int main() {
 
    cout << countPaths(); 

	return 0;
}