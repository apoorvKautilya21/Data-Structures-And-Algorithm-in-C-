#include<iostream>
using namespace std;


int main() {

	int a[1000];
	int n;

	cin >> n;
	for(int i = 0 ; i < n ; i++) {
		cin >> a[i]; 
	}

	int maxSum = 0;
	int currSum = 0;
	int right = -1, left = -1;

	for(int i = 0; i < n ; i++) {

		for(int j = i; j < n; j++) {
			// Generate 1 subarray this 3rd loop for every value of (i, j)
			currSum = 0;
			for(int k = i; k <= j; k++) {
				currSum += a[k];
			}
			
			if(maxSum < currSum){
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


