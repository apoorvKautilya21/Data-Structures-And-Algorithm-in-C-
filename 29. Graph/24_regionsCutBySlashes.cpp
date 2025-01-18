// LEETCODE
// https://leetcode.com/problems/regions-cut-by-slashes/

#include <bits/stdc++.h>
using namespace std;

class Solution {

public:

	int find_dsu (int i, int parent[]) {

		if (parent[i] == -1)
			return i;

		return parent[i] = find_dsu (parent[i], parent);
	}

	void union_dsu (int x, int y, int parent[], int rank[])  {

		int s1 = find_dsu (x, parent);
		int s2 = find_dsu (y, parent);

		if (s1 != s2) {
			if (rank[s1] < rank[s2]) {
				parent[s1] = s2;
				rank[s2] += rank[s1];
			} else {
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}
		}
	}

	int regionsBySlashes (vector <string>&v) {

		int n = v.size();
		int parent[n * n * 4];
		int rank[n * n * 4];

		for (int i = 0; i < n * n  * 4; i++) {
			parent[i] = -1;
			rank[i] = 1;
		}

		int cnt = 0;
		for (int i = 0; i < n; i++) {

			for (int j = 0; j < n; j++) {

				int st = 4 * cnt;

				if (v[i][j] == '\\')  {
					union_dsu (st, st + 3, parent, rank);
					union_dsu (st + 1, st + 2, parent, rank);
				} else if (v[i][j] == '/') {
					union_dsu (st, st + 1, parent, rank);
					union_dsu (st + 3 , st + 2, parent, rank);
				} else {
					union_dsu (st, st + 1, parent, rank);
					union_dsu (st, st + 2, parent, rank);
					union_dsu (st, st + 3, parent, rank);
				}

				if (j < n - 1) {
					union_dsu (st + 2, st + 4, parent, rank);
				}

				if (i < n - 1) {
					union_dsu (st + 3, st + 4 * n + 1, parent, rank);
				}

				cnt++;
			}
		}



		int ans = 0;

		for (int i = 0; i < n * n * 4; i++) {
			if (parent[i] == -1) ans ++;
		}
		return ans;
	}


};


int main() {

	int n;
	cin >> n;

	vector<string> v;

	for (int i = 0; i < n; i++) {
		string s;
		getline (cin, s);
		while (s.length () != n)
			s.push_back (' ');
		v.push_back (s);
	}

	Solution s;

	cout << s.regionsBySlashes(v) << endl;

	return 0;
}