#include<iostream> 
using namespace std;
# define n 3
# define m 3

void display(int a[][m]) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void suffixSum(int a[][m], int suff[][m]) {

	suff[n-1][m-1] = a[n-1][m-1];

	for(int i = n - 2; i >= 0; i--) {
		suff[i][m-1] = suff[i+1][m-1] + a[i][m-1];
	}

	for(int i = m - 2; i >= 0; i--) {
		suff[n-1][i] = suff[n-1][i+1] + a[n-1][i];
	}

	for(int i = n-2; i >= 0; i--) {
		for(int j = m-2; j >= 0; j--) {
			suff[i][j] = a[i][j] + suff[i+1][j] + suff[i][j+1] - suff[i+1][j+1];
		}
	}
	display(suff);
}

void maxSumSubMatrix(int b[][m],int a[][m]) {
	int cs=0, ms = 0, imax, jmax;
	for(int i = n - 1; i >= 0; i--) {
		for(int j = m - 1; j >= 0; j--) {
			cs = a[i][j];
			if(cs > ms) {
				ms = cs;
				imax = i;
				jmax = j;
			}
		}
	}

	cout << endl << ms << endl;
	for(int i = imax; i < n; i++) {
		for(int j = jmax; j < m; j++) {
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {

	int a[n][m] = { { -6, -4, -1 }, {-3, 2, 4}, { 2, 5, 8 } };
	int suff[n][m];
	suffixSum(a, suff);

	maxSumSubMatrix(a, suff);

	return 0;
}