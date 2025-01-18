// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int moves[][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

class Solution {

private:
	int n, m;

private:
	void dfs (int i, int j, vector <vector <char>>&v, vector <vector <bool>>&visited) {

		
		if (i < 0 or j < 0 or i >= n or j >= m or visited[i][j] or v[i][j] == 'X')  {
			return;
		}

		visited[i][j] = true;

		for (int k = 0; k < 4; k++) {
			dfs (i + moves[k][0], j + moves[k][1], v, visited);
		}

	}

public:
	void solve (vector <vector <char> >&v) {

		n = v.size ();
		m = v[0].size ();

		vector <vector <bool>> visited (n, vector <bool>(m, false)) ;

		for (int i = 0; i < m; i++) {
			if (v[0][i] == 'O' and !visited[0][i]) {
				// cout << 1 << endl;
				dfs (0, i, v, visited);
			}
		}

		for (int i = 0; i < m; i++) {
			if (v[n - 1][i] == 'O' and !visited[n - 1][i]) {
				// cout << 2 << endl;
				dfs (n - 1, i, v, visited);
			}
		} 

		for (int i = 0; i < n; i++) {
			if (v[i][0] == 'O' and !visited[i][0]) {
				// cout << 3 << endl;
				dfs (i, 0, v, visited);
			}
		}

		for (int i = 0; i < n; i++) {
			if (v[i][m - 1] == 'O' and !visited[i][m - 1]) {
				// cout << 4 << endl;
				dfs (i, m - 1, v, visited);
			}
		}

		for (int i = 1; i < n - 1; i++) {
			for (int j = 1; j < m - 1; j++) {
				if (v[i][j] == 'O' and !visited[i][j])
					v[i][j] = 'X';
			}
		} 

	}


};

int main () {

	int n, m;
	cin >> n >> m;

	vector < vector <char> > v;
	for (int i = 0; i < n; i++) {
		vector <char> x;
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			x.push_back (c);
		}

		v.push_back (x);
	}

	for (int i = 0; i < n; i++) {
		
		for (int j = 0; j < m; ++j) {
			cout << v[i][j] << " ";
		}

		cout << endl;
	}

	cout << endl << endl << endl;

	Solution s;
	s.solve (v);

	for (int i = 0; i < n; i++) {
		
		for (int j = 0; j < m; ++j) {
			cout << v[i][j] << " ";
		}

		cout << endl;
	}

	return 0;
}