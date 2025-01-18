#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph {

	int V;
	list<int>*l;
public:

	Graph(int V) {
		this -> V = V;
		l = new list<int>[V];
	}

	void addEdge(int x, int y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}

	bool cycle_helper(int node, bool *visited, int parent) {

		visited[node] = true;

		for(auto nbr:l[node]) {
			// go and recursively visit the nbr
			if(!visited[nbr]) {
				bool cycle_mila = cycle_helper(nbr, visited, node);
				if(cycle_mila) {
					return true;
				}
			}
			else if(parent != nbr) {
				return true;
			}
		}
		return false;
	}

	bool containsCycle() {
		bool *visited = new bool[V];
		for(int i = 0; i < V; i++) {
			visited[i] = false;
		}
		return cycle_helper(0, visited, -1);
	}


};

int main() {

	Graph g(5);

	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 0);

	if(g.containsCycle()) {
		cout << "Yes, it contains a cycle";
	}
	else {
		cout << "No, it doesn't contains a cycle";
	}

	return 0;
}