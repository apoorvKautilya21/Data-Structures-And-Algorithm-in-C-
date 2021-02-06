#include<iostream>
using namespace std;

void make_sub_arrays(int a[], int n) {

	for(int i = 0; i < n ; i++) {

		for(int j = i; j < n; j++) {
			// Generate 1 subarray this 3rd loop for every value of (i, j)
			for(int k = i; k <= j; k++) {
				cout << a[k] << ",";
			}
			cout << endl;
		}
	}
}

int main() {

	int a[] = {1, 2, 3, 4, 5};
	int n = sizeof(a) / sizeof(int);

	make_sub_arrays(a, n);

	return 0;
}