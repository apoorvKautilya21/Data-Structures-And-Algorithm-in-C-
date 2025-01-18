#include <bits/stdc++.h>
using namespace std;

int solve(int a[], int n) {

	vector<vector<int> > mat(3, vector<int>(3, 0));
	int freq_ind[3] = {0};
	int freq_num[3] = {0};
	for(int i = 0; i < n; i++) {
		if(a[i] % 3 != i % 3) mat[a[i] % 3][i % 3]++;
		freq_ind[i % 3]++;
		freq_num[a[i] % 3]++;
	}

	for(int i = 0; i < 3; i++) {
		if(freq_num[i] != freq_ind[i]) return -1;
	}

	for(int i = 0; i <= 2; i++) {
		for(int j = 0; j <= 2; j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}

	int t_s = 0;

	for(int i = 0; i <= 2; i++) {
		for(int j = 0; j <= 2; j++) {
			int t1 = i;
			int t2 = j;
			if(i != j) {
				t_s += min(mat[i][j], mat[j][i]);
				if(mat[i][j] == mat[j][i]) {
					mat[i][j] = mat[j][i] = 0;
				}
				else {
					if(mat[i][j] < mat[j][i]) swap(i, j);
					mat[i][j] -= mat[j][i];
					mat[j][i] = 0;

					int y = i;
					int x;
					if(j+i == 1) x = 2;
					else if(j+i == 2) x = 1;
					else if(j+i == 3) x = 0;

					mat[x][y] -= mat[i][j];
					mat[x][j] += mat[i][j];
					t_s += mat[i][j];
					mat[i][j] = 0;
				}
			}
			i = t1;
			j = t2;
		}
	}

	return t_s;
}


int main() {

	int a[] = {4, 6, 23, 34, 20, 9};
	int n = 6;
	cout << solve(a, n) << endl;

	int b[] = {2, 3, 1};
	n = 3;
	cout << solve(b, n) << endl;
}
