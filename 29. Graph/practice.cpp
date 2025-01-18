#include <bits/stdc++.h>
using namespace std;

class Graph {

	vector <int>*adj;

public:

	void solve (int n, vector <vector <int>> edges) {

		adj = new vector <int>[n + 1];
		vector <int> ans (n + 1, 0);
		vector <int> indeg (n + 1, 0);
		for (auto edge : edges) {
			adj[edge[0]].push_back (edge[1]);
			indeg[edge[1]]++;
		}

		queue <int> q;
		for (int i = 1; i <= n; i++) {
			if (indeg[i] == 0)  q.push (i);
		}

		int lvl = 1;
		while (q.size ()) {
			
			int size = q.size ();

			while (size --) {

				int node = q.front (); q.pop ();
				ans[node] = lvl;
				for (auto nbr : adj[node]) {
					indeg[nbr]--;
					if (indeg[nbr] == 0) q.push (nbr);
				}
			}
			lvl++;
		}

		for (int i = 1; i <= n; i++)
			cout << ans[i] << " ";
		cout << endl;
	}


};

int main () {

	vector <vector <int>> edges = {
		{1, 3},
		{1, 4},
		{1, 5},
		{2, 3},
		{2, 8},
		{2, 9},
		{3, 6},
		{4, 6},
		{4, 8},
		{5, 8},
		{6, 7},
		{7, 8},
		{8, 10}
	};

	Graph g;
	g.solve (10, edges);


	return 0;
}