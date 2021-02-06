#include<iostream>
#include<climits>
using namespace std;


int main() {

	int a[1000], n, csum[1000] = {0};

	cin >> n;

	cin >> a[0];
	csum[1] = a[0];

	for(int i = 1; i < n; i++) {
		cin >> a[i];
		csum[i+1] = csum[i] + a[i];
	}

	int maxSum = INT_MIN;
	int currSum = 0;
	int left = -1, right = -1;

	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			currSum = csum[j+1] - csum[i];

			if (currSum > maxSum) {
				maxSum = currSum;
				left = i;
				right = j;
			}
		}
	}
	
	cout << "\nMaximum Sum is " << maxSum << endl;
	for (int i = left; i <= right; i++) 
		cout << a[i] << ",";

	return 0;
}




