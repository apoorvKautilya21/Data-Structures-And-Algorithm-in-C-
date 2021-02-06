#include<iostream>
using namespace std;
#define R 5
#define C 6

int countPaths() {

	int dp[100][100] = {0};
	for(int i = 0; i < R; i++) {
		dp[i][0] = 1;
	}

	for(int i = 0; i < C; i++) {
		dp[0][i] = 1; 
	}

	for(int i = 1; i < R; i++) {
		for(int j = 1; j < C; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	return dp[R - 1][C - 1];
}
	
long long factorial(int n) {
	long long ans = 1;
	for(int i = 2; i <= n; i++) {
		ans *= i;
	}
	return ans;
}


long long countPathsFormulaBased() {

	return factorial(R - 1 + C - 1) / factorial(C - 1) / factorial(R - 1);
}


int main() {
 
    cout << countPaths() << " " << countPathsFormulaBased(); 

	return 0;
}