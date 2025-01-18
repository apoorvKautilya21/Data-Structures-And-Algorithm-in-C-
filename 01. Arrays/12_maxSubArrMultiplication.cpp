#include <bits/stdc++.h>
using namespace std;

int maxProductSubset(int a[], int n) {

	int prod = 1;
	int tot_neg = 0, tot_zero = 0;
	int max_neg = INT_MIN;

	for(int i = 0; i < n; i++) {
		if(a[i] == 0) {
			tot_zero++;
			continue;
		}

		if (a[i] < 0) {
			tot_neg++;
			max_neg = max(max_neg, a[i]);
		}
		prod *= a[i];
	}

	if(tot_zero == n) return 0;

	// if odd
	if(tot_neg & 1) {
		if(tot_neg == 1 and tot_zero > 0 and tot_zero + tot_neg == n) return 0;
		return prod / max_neg;
	}

	return prod;
}

int main() {

    int a[] = {  -1, -1, -2, 4, 3  };
    int n = sizeof(a) / sizeof(a[0]);
    cout << maxProductSubset(a, n);

	return 0;
}