// 1. Path compression Optimization in DSU (in find function)
// 2. Union by rank Optimization in DSU (in union_find function)
// After applying above 2 optimizations the complexity of the find and union will 
// be reduced to O(1)

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

		return parent[i] = find_set(parent[i], parent);	
	}

	void union_set(int x, int y, int parent[], int rank[]) {

		int s1 = find_set(x, parent);
		int s2 = find_set(y, parent);

		if(s1 != s2) {
			if(rank[s1] < rank[s2]) {
				parent[s1] = s2;
				rank[s2] += rank[s1];
			}
			else {
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}
		}
	}

	bool contains_cycle() {

		int *parent = new int[V];
		int *rank = new int[V];

		for(int i = 0; i < V; i++) {
			parent[i] = -1;
			rank[i] = 1;
		}

		for(auto edge : l) {
			int x = edge.first;
			int y = edge.second;

			int s1 = find_set(x, parent);
			int s2 = find_set(y, parent);

			if(s1 != s2) {
				union_set(s1, s2, parent, rank);
			}
			else {
				cout << "Same Parent " << s1 << " and " << s2 << endl; 
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