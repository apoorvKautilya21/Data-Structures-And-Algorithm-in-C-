#include<iostream>
#include<climits>
using namespace std;


int maxSubArrSum(int a[], int n) {
	int dp[1000] = {0};

	dp[0] = a[0] > 0 ? a[0] : 0;
	int max_so_far = dp[0];
	for(int i = 1; i < n; i++) {
		dp[i] = dp[i - 1] + a[i];
		// max_so_far line is here since if all elements will be negative it will return
		// least negative number
		// Moreover it will take into consideration of normal kadane algorithm as well
		max_so_far = max(max_so_far, dp[i]);
		if(dp[i] < 0) {
			dp[i] = 0;
		}		
	}
	return max_so_far;
}

// Space Optimized -- Also Known as kadane's algorithm
int maxSubArrSumSpaceOpt(int a[], int n) {

	int max_so_far = INT_MIN;
	int curr_sum = 0;
	for(int i = 0; i < n; i++) {
		curr_sum += a[i];
		// max_so_far line is here since if all elements will be negative it will return
		// least negative number
		// Moreover it will take into consideration of normal kadane algorithm as well
		max_so_far = max(max_so_far, curr_sum);
		if(curr_sum < 0) {
			curr_sum = 0;
		}
	}
	return max_so_far;
}


int main() {

	int a[] = {-3, 2, 5, -20, -1, 6, 3, -2, 7, -5, 2};
	int n = sizeof(a) / sizeof(int);

	cout << maxSubArrSum(a, n) << endl;
	cout << maxSubArrSumSpaceOpt(a, n) << endl;

	int b[] = {-34, -54, -12, -1, -2, -133};
	int m = sizeof(b) / sizeof(int);
	cout << maxSubArrSumSpaceOpt(b, m) << endl;

	return 0;
}