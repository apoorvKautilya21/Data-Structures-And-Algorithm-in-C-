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

void prefMatrix(int a[][5], int pref[][5], int n, int m) {

	pref[0][0] = a[0][0];

	for(int i = 1; i < m; i++) {
		pref[0][i] = pref[0][i-1] + a[0][i];
	}

	for(int i = 1; i < n; i++) {
		pref[i][0] = pref[i-1][0] + a[i][0];
	}

	for(int i = 1; i < n; i++) {
		for(int j = 1; j < m; j++) {
			pref[i][j] = a[i][j] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
		}
	}

	display(pref, n, m);
}

int sumQuery(int pref[][5], int tli, int tlj, int rbi, int rbj) {

	int res = pref[rbi][rbj];
	if(tli > 0) {
		res = res - pref[tli-1][rbj];
	}

	if(tlj > 0) {
		res = res - pref[rbi][tlj-1];
	}

	if(tli > 0 && tlj > 0) {
		res += pref[tli-1][tlj-1];
	}
	return res;
}


int main() {

	int a[4][5] = {{1, 2, 3, 4, 6}, 
                    {5, 3, 8, 1, 2}, 
                    {4, 6, 7, 5, 5}, 
                    {2, 4, 8, 9, 4} };
	
	int n = 4, m = 5;

	int pref[4][5];

	display(a, n, m);
	cout << endl;

	prefMatrix(a, pref, n, m);

	int tli = 2, tlj = 2, rbi = 3, rbj = 4; 
	cout << "\nQuery1: " << sumQuery(pref, tli, tlj, rbi, rbj); 

	tli = 0, tlj = 0, rbi = 1, rbj = 1; 
	cout << "\nQuery2: " << sumQuery(pref, tli, tlj, rbi, rbj); 

	tli = 1, tlj = 2, rbi = 3, rbj = 3; 
	cout << "\nQuery3: " << sumQuery(pref, tli, tlj, rbi, rbj); 

	return 0;
}