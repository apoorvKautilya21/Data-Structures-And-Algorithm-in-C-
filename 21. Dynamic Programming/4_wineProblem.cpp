#include<iostream>
using namespace std;

// Q. We are the wines bottles prices in an array
// wines[] = {2, 3, 5, 1, 4};
// we can sold only 1 bottle each year and we can sold only either the first or last element
// of the wines array. And in each year it's price becomes original_price * no_of_year
// find the maximum price

int profit(int wines[], int i, int j, int y, int dp[][100]) {
	// Base Case
	if(i > j) {
		return 0;
	}
	// Recursive case
	if(dp[i][j] != 0) {
		return dp[i][j];
	}

	int op1 = wines[i] * y + profit(wines, i + 1, j, y + 1, dp);
	int op2 = wines[j] * y + profit(wines, i, j - 1, y + 1, dp);

	return dp[i][j] = max(op1, op2);
}

int profitBU(int wines[], int n) {

	int dp[100][100] = {0};

	// For nth year
	for(int i = 0; i < n; i++) {
		dp[i][i] = wines[i] * n;
	}
	// From (n - 1)th year
	int y = n - 1;

	for(int dg_no = 1; dg_no < n; dg_no++) {
		int i = 0;
		int j = dg_no;
		while(j < n and i < n) {
			int op1 = wines[i] * y + dp[i + 1][j];
			int op2 = wines[j] * y + dp[i][j - 1];
			dp[i][j] = max(op1, op2);
			j++;i++;
		}
		y--;	
	}
	return dp[0][n - 1];
}


int main() {

	int wines[] = {2, 3, 5, 1, 4};
	int n = sizeof(wines) / sizeof(int);
	int y = 1;
	int dp[100][100] = {0};
	cout << profit(wines, 0, n - 1, y, dp) << endl;
	cout << profitBU(wines, n);

	return 0;
}