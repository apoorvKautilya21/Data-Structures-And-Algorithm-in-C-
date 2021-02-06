#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

int lenOfLongestIncSubseq(int a[], int n) {

	int dp[n + 1];
	dp[0] = INT_MIN;
	
	for(int i = 1; i <= n; i++) {
		dp[i] = INT_MAX;
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= n; j++) {
			if(dp[j] < a[i] and a[i] < dp[j + 1]) {
				dp[j + 1] = a[i];
				break;
			}
		}
	}

	for(int i = 1; i <= n; i++) {
		if(dp[i] == INT_MAX) return i - 1;
	}
	return n;
}

int lenOfLongestIncSubseq_binarySearch(int a[], int n) {

	int dp[n + 1];
	dp[0] = INT_MIN;

	for(int i = 1; i <= n; i++) {
		dp[i] = INT_MAX;
	}

	for(int i = 0; i < n; i++) {
		int j = upper_bound(dp, dp + n + 1, a[i]) - dp;
		if(a[i] > dp[j - 1] and a[i] < dp[j])  {
			dp[j] = a[i];
		}
	}

	for(int i = 1; i <= n; i++) {
		if(dp[i] == INT_MAX) return i - 1;
	}
	return n;
}


int main() {

	int a[] = {1, 5, 3, 4, 5, 10, 2, 7, 11};
	int n = sizeof(a) / sizeof(int);

	cout << lenOfLongestIncSubseq_binarySearch(a, n);

	return 0;
}