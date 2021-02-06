#include<iostream>
using namespace std;

void stairSearch(int a[][4], int n, int num) {

	int i = 0;
	int j = n - 1;

	while(i < n && j >= 0) {
		if(a[i][j] == num) {
			cout << "Found at a[" << i << "][" << j <<"]" <<  endl;
			return;
		}
		else if (a[i][j] > num) {
			j--;
		}
		else {
			i++;
		}	
	}

	cout << "Not Found" << endl;

}


int main() {

	int mat[4][4] = { {10, 20, 30, 40},
                      {15, 25, 35, 45},
                      {27, 29, 37, 48},
                      {32, 33, 39, 50}};

    for(int i = 0; i < 4; i++) {
    	for(int j = 0; j < 4; j++)
    		cout << mat[i][j] << " ";
    	cout << endl;
    }

    int num;
    cin >> num;

    stairSearch(mat, 4, num);

	return 0;
}