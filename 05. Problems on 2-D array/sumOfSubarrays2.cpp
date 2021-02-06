#include<iostream>
using namespace std;

void display(int a[][100], int n) {
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}

int sumMatrices(int a[][100], int n) {

	int sum = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 1; j < n; j++) {
			a[i][j] += a[i][j-1];
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 1; j < n; j++) {
			a[j][i] += a[j-1][i];
		}
	}

	// display(a,n);

	for(int li = 0; li < n; li++) {
		for(int lj = 0; lj < n; lj++) {
			for(int bi = li; bi < n; bi++) {
				for(int bj = lj; bj < n; bj++) {
					if(li == 0 && lj == 0){
						sum += a[bi][bj];
						continue;
					}
					else if(lj == 0) {
						sum += a[bi][bj] - a[li-1][bj];
						continue;
					}
					else if(li == 0) {
						sum += a[bi][bj] - a[bi][lj-1];
						continue;
					}
					else{					
						sum += a[bi][bj] - a[li-1][bj] - a[bi][lj-1] + a[li-1][lj-1];
					}
				}
			}
		}
	}
	return sum;

}

int main() {

	int a[100][100];
	int n;
	cin >> n;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n ; j++) {
			cin >> a[i][j];
		}
	}

	display(a, n);
 
 	cout << sumMatrices(a, n) << endl;

	return 0;
}