#include<iostream>
using namespace std;

// Command:=>
// 14_floodFillAlgo.exe < apple.txt

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int n, m;

void floodFill(char mat[][30], int i, int j, char ch, char color) {

	// Base Case
	if(i < 0 or	j < 0 or i >= n or j >= m) {
		return;
	}
	// figure boundary conditions
	if(mat[i][j] != ch) {
		return;
	}
	// Recursive call
	mat[i][j] = color;

	for(int k = 0; k < 4; k++) {
		floodFill(mat, i + dx[k], j + dy[k], ch, color);
	}
}

int main() {

	cin >> n >> m;

	char input[15][30];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> input[i][j];
		}
	}

	floodFill(input, 8, 13, '.', 'r');
	cout << endl << endl;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cout << input[i][j];
		}
		cout << endl;
	}

	return 0;
}