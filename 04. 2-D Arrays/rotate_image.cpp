// https://hack.codingblocks.com/app/practice/2/1012/problem
#include<iostream>
using namespace std;

void rotate1(int a[][1000], int n) {

	// Revere each row
	for(int i = 0; i < n; i++) {
		int start = 0, end = n - 1;
		while(start < end) {
			swap(a[i][start], a[i][end]);
			start ++;
			end --;
		}
	}

	// Now you can find the transpose of the given matrix
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			swap(a[i][j], a[j][i]);
		}
	}

	// Display Nows
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	
	int n;
	cin >> n;
	int a[1000][1000];

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >>a[i][j];
		}
	}

	rotate1(a, n);
	return 0;
}