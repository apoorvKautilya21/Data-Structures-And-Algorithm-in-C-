#include<iostream>
using namespace std;

bool isSafe(int mat[][10], int n, int i, int j) {
	// safe for the column above it
	for(int row = 0; row < i; row++) {
		if(mat[row][j] == 1) {
			return false;
		}
	}
	// for left diagonal
	int x = i;
	int y = j;
	while(x >= 0 and y >= 0) {
		if(mat[x][y] == 1) {
			return false;
		}
		x --;
		y --;
	}
	// for upper right diagonal
	x = i;
	y = j;
	while(x >= 0 and y < n) {
		if(mat[x][y] == 1) {
			return false;
		}
		x --;
		y ++;
	}

	// now the position is safe
	return true;
}

bool n_queen(int mat[][10], int n, int i) {
	// Base Case
	if(i == n) {
		// print the matrix
		for(int x = 0; x < n; x++) {
			for(int y = 0; y < n; y++) {
				cout << mat[x][y] << " ";
			}
			cout << endl;
		}
		cout << endl;
		// now return true for printing only one configurations
		// return true;
		// return false to print all the configurations
		return false;
	}
	// Recursive case
	
	for(int j = 0; j < n; j++) {
		// Check if it is safe to place the queen there or not
		if(isSafe(mat, n, i, j)){
			// place the queen
			mat[i][j] = 1;
			bool down  = n_queen(mat, n, i + 1);
			if(down) {
				return true;
			} 
			mat[i][j] = 0;	// Backtrack
		
		}
	}
	// we have tried to place the queen in the current row but couldn't place it there.
	return false;
}

int main() {

	int n;
	cin >> n;

	int mat[10][10] = {0};

	bool is_possible = n_queen(mat, n, 0);




	return 0;
}