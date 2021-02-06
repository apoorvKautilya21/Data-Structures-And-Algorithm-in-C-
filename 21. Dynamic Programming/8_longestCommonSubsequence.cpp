#include<iostream>
#include<string>
#include<vector>
using namespace std;

int longestCommonSubseq(string s1, string s2, int i, int j, vector<vector<int>> dp) {
	// Base Case
	if(s1[i] == '\0' or s2[j] == '\0') {
		return 0;
	}
	// Recursive Case
	if(dp[i][j] != -1) {
		return dp[i][j];
	}
	if(s1[i] == s2[j]) {
		return dp[i][j] = 1 + longestCommonSubseq(s1, s2, i + 1, j + 1, dp);
	}

	int op1 = longestCommonSubseq(s1, s2, i, j + 1, dp);
	int op2 = longestCommonSubseq(s1, s2, i + 1, j, dp);

	return dp[i][j] = max(op1, op2);
}

int longestCommonSubseqBU(string s1, string s2) {
	int n1 = s1.length();
	int n2 = s2.length();
	int dp[n1 + 1][n2 + 1] = {0};

	for(int i = n1 -1; i >= 0; i--) {
		for(int j = n2 - 1; j >= 0; j--) {
			if(s1[i] == s2[j]) {
				dp[i][j] = 1 + dp[i + 1][j + 1];
			}
			else {
				dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
			}
		}
	}

	return dp[0][0];
}



int main() {

	string s1 = "ABCD";
	string s2 = "ABGDE";
	int l1 = s1.length();
	int l2 = s2.length();
	// Initializing all elements with -1
	vector< vector<int> > dp(l1, vector<int>(l2, -1));

	cout << longestCommonSubseq(s1, s2, 0, 0, dp) << endl;
	cout << longestCommonSubseqBU(s1, s2);


	return 0;
}