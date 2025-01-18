#include <bits/stdc++.h>
using namespace std;

class Graph {

	list<int>*l;
	int V;

public:

	Graph(int v) {
		this -> V = v;
		l = new list<int>[V];
	}

	void addEdge(int x, int y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}

	bool isBipartiteBFS() {

		vector<int> colors(V, -1);
		queue<int> q;
		q.push(1);
		colors[1] = 1;

		while(!q.empty()) {
			
			int node = q.front();
			q.pop();

			for(int nbr : l[node]) {
				if(colors[nbr] == -1) {
					colors[nbr] = !colors[node];
					q.push(nbr);
				} else if(colors[nbr] == colors[node])
					return false;
			}
		}

		return true;
	}


};

int main() {

	Graph g(10);

	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(8, 9);
	g.addEdge(9, 2);
	g.addEdge(3, 4);
	g.addEdge(8, 5);
	g.addEdge(4, 5);
	g.addEdge(5, 6);
	g.addEdge(6, 7);

	cout << g.isBipartiteBFS() << endl;



	return 0;
}