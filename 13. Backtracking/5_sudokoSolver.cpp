#include<iostream>
#include<math.h>
using namespace std;

bool canPlace(int mat[][9], int i, int j, int n, int num) {
	// check in the respective row and column in one go
	for(int x = 0; x < n; x ++) {
		if(mat[i][x]==num or mat[x][j]==num) {
			return false;
		}
	}
	// check in the box
	int rn = sqrt(n);
	int sx = (i/rn) * rn;
	int sy = (j/rn) * rn;

	for(int x = sx; x < sx + rn; x++) {
		for(int y = sy; y < sy + rn; y++) {
			if(mat[x][y] == num) {
				return false;
			}
		}
	}
	return true;
}


bool solveSudoko(int mat[][9], int i, int j, int n) {
	// Base Case
	if(i == n) {
		// Print the matrix
		int rn = sqrt(n);
		for(int x = 0; x < n; x++) {
// ------------ design ------- --------- ---------- - ------ ---- - -----  ------ --
			if(x!=0 and x%rn == 0) cout << "________________________" << endl;
// ------------ design ------- --------- ---------- - ------ ---- - -----  ------ --
			for(int y = 0; y < n; y++) {
// ------------ design ------- --------- ---------- - ------ ---- - -----  ------ --
				if(y!=0 and y%rn==0) cout << " | ";
// ------------ design ------- --------- ---------- - ------ ---- - -----  ------ --
				cout << mat[x][y] << " ";				
			}
			cout << endl;
		}
		// Since the sudoko is solved hence return true
		return true;
	}
	if(j == n) {
		return solveSudoko(mat, i + 1, 0, n);
	}
	if(mat[i][j] != 0) {
		return solveSudoko(mat, i, j + 1, n);
	}
	// Recursive case
	for(int num = 1; num <= n; num ++) {
		if(canPlace(mat, i, j, n, num)) {
			mat[i][j] = num;
			bool could_we_solve = solveSudoko(mat, i, j + 1, n);
			if(could_we_solve) {
				return true;
			}
		} 
	}
	// if we come out of the loop it means we tried each and every combination of number
	// there which means we have to return false here
	mat[i][j] = 0;
	return false;
}


int main() {

	int mat[9][9] = {
		{5,3,0,0,7,0,0,0,0},
		{6,0,0,1,9,5,0,0,0},
		{0,9,8,0,0,0,0,6,0},
		{8,0,0,0,6,0,0,0,3},
		{4,0,0,8,0,3,0,0,1},
		{7,0,0,0,2,0,0,0,6},
		{0,6,0,0,0,0,2,8,0},
		{0,0,0,4,1,9,0,0,5},
		{0,0,0,0,8,0,0,7,9}
	};

	bool is_solved = solveSudoko(mat, 0, 0, 9);
	return 0;
}