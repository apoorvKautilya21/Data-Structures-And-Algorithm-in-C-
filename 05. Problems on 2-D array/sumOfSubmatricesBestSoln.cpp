#include<iostream>
using namespace std;

void display(int a[][100], int n, int m) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int sumSubMat(int a[][100], int n, int m) {
	int sum = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			int tl = (i+1)*(j+1);
			int br = (n-i)*(n-j);
			sum += a[i][j] * tl * br;
		}
	}
	return sum;
}	



int main() {

	int a[100][100];
	int n, m;
	cin >> n >> m;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m ; j++) {
			cin >> a[i][j];
		}
	}

	display(a, n, m);

	cout << sumSubMat(a, n, m) << endl;

	return 0;
}