#include<iostream>
using namespace std;


int main() {

	int **arr;
	int r, c;
	cin >> r >> c;

	arr = new int* [r];
	for(int i = 0; i < c; i++) {
		arr[i] = new int [c];
	}

	int val = 1;
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			arr[i][j] = val;
			val++;
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

	// DELETE
	for(int i = 0; i < r; i++) {
		delete []arr[i];		// Delete each row
	}

	delete []arr;

	return 0;
}



