#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int kadane(vector<int> a) {

	int n = a.size();
	int currSum = 0, maxSum = INT_MIN;

	for(int i = 0; i < n; i++) {
		currSum += a[i];

		if(currSum > maxSum) {
			maxSum = currSum;
		}

		if(currSum < 0) {
			currSum = 0;
		}
	}

	return maxSum;
}

int maxSubmatrixSum(vector <vector<int>> v) {

	int n = v.size();
	int m = v[0].size();

	vector <vector<int>> prefix(n, vector<int>(m, 0));

	// this is finding the sum along all columns like
	// 1 2 3 4
	// 5 6 7 8
	// will make the prefix array as
	// 1 3  6  10
	// 5 11 18 26
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(j == 0) {
				prefix[i][j] = v[i][j];
			}
			else {
				prefix[i][j] = v[i][j] + prefix[i][j - 1];
			}
		}
	}

	int mxsum = INT_MIN;

	for(int i = 0; i < m; i++) {
		for(int j = i; j < m; j++) {
			vector<int> a;
			for(int k = 0; k < n; k++) {
				int val = prefix[k][j];
				
				if(i != 0) {
					val -= prefix[k][i- 1];
				}
				a.push_back(val);
			}
			mxsum = max(mxsum, kadane(a));
		}
	}

	return mxsum;
}

// Driver Code
int main()
{
    vector<vector<int> > matrix = { { 0, -2, -7, 0 },
                                    { 9, 2, -6, 2 },
                                    { -4, 1, -4, 1 },
                                    { -1, 8, 0, -2 } };
 
    // Function Call
   	cout << maxSubmatrixSum(matrix);
 
    return 0;
}