// https://hack.codingblocks.com/app/practice/6/1051/problem

#include<iostream>
#include<cstring>
using namespace std;

void finalStrength(char input[][100], int n, int m, int k, int s) {

	int finalSt = s;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(finalSt < k) {
				cout << "No" << endl;
				return;
			}

			if(input[i][j] == '.') {
				finalSt = finalSt - 2;
			}
			else if(input[i][j] == '*') {
				finalSt = finalSt + 5;
			}
			else {
				break;
			}
			
			finalSt =  j != m-1? finalSt - 1:finalSt;
		}
	}

	if(finalSt > k) {
		cout << "Yes" << endl;
		cout << finalSt;
	}
	else
		cout << "No";
}

int main() {

	int n, m, k, s;
	char path[100][100];

	cin >> n;
	cin >> m;
	cin >> k;
	cin >> s;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> path[i][j];
		}
	}	

	finalStrength(path, n, m, k, s);
}








