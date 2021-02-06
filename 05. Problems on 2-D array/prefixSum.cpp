#include<iostream>
using namespace std;

void display(int a[][5], int n, int m) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {

	int a[4][5] = {{1, 2, 3, 4, 6}, 
                    {5, 3, 8, 1, 2}, 
                    {4, 6, 7, 5, 5}, 
                    {2, 4, 8, 9, 4} };
	
	int n = 4, m = 5;

	

	display(a, n, m);

	return 0;
}