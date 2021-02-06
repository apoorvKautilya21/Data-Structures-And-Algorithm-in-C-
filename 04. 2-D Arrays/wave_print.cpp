#include<iostream>
using namespace std;

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

	for(int i = 0; i < col; i++) {
		if(i % 2 == 0) {
			for(int j = 0; j < row; j++) {
				cout << a[j][i] << " ";
			}
		}

		else {
			for(int j = row - 1; j >= 0; j--) {
				cout << a[j][i] << " ";
			}
		}
		
	}




	return 0;
}






