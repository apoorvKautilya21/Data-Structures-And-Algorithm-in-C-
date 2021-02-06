#include<iostream>
using namespace std;

void spiralPrint(int a[][100], int row, int col) {

	int sr = 0, sc = 0, er = row - 1, ec = col - 1;

	while(er >= sr && ec >= sc) {

		for(int i = sc; i <= ec; i++) {
			cout << a[sr][i] << " ";
		}
		sr++;

		for(int i = sr; i <= er; i++) {
			cout << a[i][ec] << " ";
		}
		ec--;

		if(er >= sr) {
			for(int i = ec; i >= sc; i--) {
				cout << a[er][i] << " ";
			}
			er--;
		}

		if(ec >= sc) {
			for(int i = er; i >= sr; i--) {
				cout << a[i][sc] << " ";
			}
			sc++;
		}
	}
	
}


int main() {

	int a[100][100];
	int row, col;
	cin >> row >> col;

	int val = 1;
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			a[i][j] = val;
			val++;
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}

	spiralPrint(a, row, col);

	return 0;
}