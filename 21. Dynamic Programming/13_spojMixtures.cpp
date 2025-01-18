// https://www.spoj.com/problems/MIXTURES/
#include<iostream>
#include<climits>
using namespace std;

long long findMinSmoke(int color[], int n) {

	long long dp[200][200] = {0};

	for(int i = 1; i < n; i++) {
		int r = 0, c = i;

		while(c < n) {
			dp[r][c] = INT_MAX;
			for(int k = r; k < c; k++) {
				long long addn = ((color[k + 1] - color[r]) % 100) * ((color[c + 1] - color[k + 1]) % 100);
				dp[r][c] = min(dp[r][c], dp[r][k] + dp[k + 1][c] + addn);
			}
			r++, c++;
		}
	}

	return dp[0][n - 1];
}
 


int main() {

	int n;
	while(scanf("%d", &n) != EOF) {
		int color[200];
		//consecutively we will try to find the csum
		color[0] = 0;
		for(int i = 1; i <= n; i++) {
			cin >> color[i];
			color[i] += color[i - 1];
		}

		cout << findMinSmoke(color, n) << endl;
	}

	return 0;
}