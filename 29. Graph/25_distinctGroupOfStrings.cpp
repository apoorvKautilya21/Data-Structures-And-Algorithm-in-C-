// GFG
// https://www.geeksforgeeks.org/count-of-distinct-groups-of-strings-formed-after-performing-equivalent-operation/

#include <bits/stdc++.h>
using namespace std;

int find_dsu (int i, int parent[]) {

	if (parent[i] == -1)
		return i;

	return parent[i] = find_dsu (parent[i], parent);
}

void union_dsu (int x, int y, int parent[], int rank[]) {

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

void solve (vector <string>&v) {

	int n = v.size();

	int parent[27];
	int rank[27];

	for (int i = 0; i < 27; i++) {
		parent[i] = -1;
		rank[i] = 1;
	}

	vector <bool> total(26, false);
	for (int i = 0; i < n; i++) {

		vector <bool> current(26, false);
		for (char c : v[i])
			current[c - 'a'] = true;

		for (int j = 0; j < 26; j++) {

			if (current[j]) {
				total[j] = true;

				union_dsu (v[i][0] - 'a', j, parent, rank);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < 26; i++) {
		if (total[i] and parent[i] == -1) ++ans;
	}

	cout << ans << endl;
}

int main() {

	int n;
	cin >> n;

	vector<string> v;

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;

		v.push_back (s);
	}

	solve (v);

	return 0;
}