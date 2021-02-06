#include<iostream>
#include<cstring>
using namespace std;

# define MOD 1000000007
int dp[1001][1001];

int noOfWays(int n, int m) {

	for(int i = 0; i < n; i++) {
		if(dp[i][0] == -1) {
			break;
		}
		dp[i][0] = 1;
	}

	for(int i = 0; i < m; i++) {
		if(dp[0][i] == -1) {
			break;
		}
		dp[0][i] = 1;
	}

	for(int i = 1; i < n; i++) {
		for(int j = 1; j < m; j++) {
			if(dp[i][j] == -1) {
				continue;
			}
			dp[i][j] = 0;
 			if(dp[i - 1][j] != -1) {
				dp[i][j] = dp[i - 1][j] % MOD;
			}
			if(dp[i][j - 1] != -1) {
				dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
			}
		}
	}

	return dp[n - 1][m - 1];
}

int main() {
	memset(dp, 0, sizeof dp);
	int m, n, p;	
	cin >> m >> n >> p;

	for(int i = 0; i < p; i++) {
		int x, y;
		cin >> x >> y;
		dp[x - 1][y - 1] = -1;
	}

	cout << noOfWays(m, n);	

	return 0;
}