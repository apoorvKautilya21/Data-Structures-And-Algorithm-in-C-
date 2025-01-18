#include <bits/stdc++.h>
using namespace std;

class Graph {

	list<int>*l;
	int V;

	bool helperBipartite(int node, vector<int>&colors) {

		for(int nbr : l[node]) {
			if(colors[nbr] == -1) {
				colors[nbr] = !colors[node];
				int ans = helperBipartite(nbr, colors);
				if(!ans) return ans;
			} else if (colors[nbr] == colors[node])
				return false;
		}

		return true;
	}

public:

	Graph(int v) {
		this -> V = v;
		l = new list<int>[V];
	}

	void addEdge(int x, int y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}

	bool isBipartiteDFS() {
		vector<int> colors(V, -1);

		for(int i = 0; i < V; i++) {
			if(colors[i] == -1) {
				colors[i] = 1;
				int ans = helperBipartite(i, colors);
				if(!ans) return false;
			}
		}
		return true;
	}


};

int main() {

	// Graph g(10);
	// g.addEdge(1, 2);
	// g.addEdge(2, 3);
	// g.addEdge(8, 9);
	// g.addEdge(9, 2);
	// g.addEdge(3, 4);
	// g.addEdge(8, 5);
	// g.addEdge(4, 5);
	// g.addEdge(5, 6);
	// g.addEdge(6, 7);

	Graph g(9);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(2, 8);
	g.addEdge(3, 4);
	g.addEdge(8, 5);
	g.addEdge(4, 5);
	g.addEdge(5, 6);
	g.addEdge(6, 7);

	cout << g.isBipartiteDFS() << endl;

	return 0;
}