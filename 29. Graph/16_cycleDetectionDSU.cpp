#include <iostream>
#include <list>
using namespace std;

class Graph {

	int V;
	list<pair<int, int> > l;

public:

	Graph(int V) {
		this -> V = V;
	}

	void addEdge(int x, int y) {
		l.push_back(make_pair(x, y));
	}

	// Finding set function of DSU
	int find_set(int i, int parent[]) {

		if(parent[i] == -1) {
			return i;
		}

		return find_set(parent[i], parent);	
	}

	void union_set(int x, int y, int parent[]) {

		int s1 = find_set(x, parent);
		int s2 = find_set(y, parent);

		if(s1 != s2) {
			parent[s2] = s1;
		}
	}

	bool contains_cycle() {

		int *parent = new int[V];
		for(int i = 0; i < V; i++) {
			parent[i] = -1;
		}

		for(auto edge : l) {
			int x = edge.first;
			int y = edge.second;

			int s1 = find_set(x, parent);
			int s2 = find_set(y, parent);

			if(s1 != s2) {
				union_set(s1, s2, parent);
			}
			else {
				return true;
			}
		}

		delete [] parent;
		return false;
	}

};


int main() {

	Graph g(4);

	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	// g.addEdge(0, 3);

	if(g.contains_cycle())
		cout << "Yes";
	else 
		cout << "No";

	return 0;
}