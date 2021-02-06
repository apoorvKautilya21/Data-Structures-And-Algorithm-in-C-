#include<iostream>
using namespace std;

int profit(int n, int c, int *w, int *p) {
	// Base Case
	if(n == 0 || c == 0) {
		return 0;
	}
	// Recursive case
	int ans = 0;
	int inc = 0;
	int exc = 0;
	if(c - w[n - 1] >= 0) {	
		inc = p[n - 1] + profit(n - 1, c - w[n - 1], w, p);
	}
	exc = profit(n - 1, c, w, p);	

	return max(inc, exc);
}


int main() {

	int weights[] = {1, 2, 3, 5};
	int prices[] = {40, 20, 30, 100};

	int N = 4;
	int C = 7;

	cout << profit(N, C, weights, prices);

	return 0;
}