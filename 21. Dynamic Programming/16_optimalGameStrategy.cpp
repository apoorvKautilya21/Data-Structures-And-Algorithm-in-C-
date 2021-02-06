#include<iostream>
using namespace std;


int findMaxPointsOfMe(int cards[], int i, int j, int dp[][100]) {
	// Base Case
	if(i > j) {
		return 0;
	}	
	if(j == i+1) {
		return dp[i][j] = max(cards[i], cards[j]);
	}
	// Recursive Case
	if(dp[i][j] != 0) {
		return dp[i][j];
	}

	int first = cards[i] + min(findMaxPointsOfMe(cards, i + 2, j, dp), findMaxPointsOfMe(cards, i + 1, j - 1, dp));
	int last = cards[j] + min(findMaxPointsOfMe(cards, i + 1, j - 1, dp), findMaxPointsOfMe(cards, i, j - 2, dp));

	return dp[i][j] = max(first, last);
}

int main() {

	int cards[] = {7, 3, 1, 6, 2, 8, 10, 11};
	int n = sizeof(cards) / sizeof(int);
	int dp[100][100] = {0};
	cout << findMaxPointsOfMe(cards, 0, n - 1, dp); 

	return 0;
}