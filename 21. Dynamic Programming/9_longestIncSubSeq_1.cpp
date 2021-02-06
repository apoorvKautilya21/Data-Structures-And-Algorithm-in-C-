#include<iostream>
using namespace std;


int lenOfLongestIncSubseq(int a[], int n) {
	int dp[100] = {0};
	int ans = 1;// length of LIS will be atleast 1

	for(int i = 0; i < n; i++) {
		dp[i] = 1;
		for(int j = i - 1; j >= 0; j--) {
			if(a[i] > a[j]) dp[i] = max(dp[i], dp[j] + 1);
		}
		ans = max(ans, dp[i]);
	}
	return ans;
}

int main() {

	int a[] = {1, 5, 2, 3, 4, 9, 6, 10};
	int n = sizeof(a) / sizeof(int);

	cout << lenOfLongestIncSubseq(a, n);

	return 0;
}