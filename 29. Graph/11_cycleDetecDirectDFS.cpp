#include <iostream>
#include <list>
#include <queue>
using namespace std;

// In order to check whether a graph is a tree or not we have to detect a cycle
// if cycle is present in graph then return false otherwise true

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
	}

	bool cycle_helper(int node, bool *visited, bool *stack) {
		visited[node] = true;
		stack[node] = true;

		for(auto nbr:l[node]) {
			// 2 cases
			if(stack[nbr]) {
				return true;
			}
			else if(!visited[nbr]) {
				bool cycle_mila = cycle_helper(nbr, visited, stack);
				if(cycle_mila) {
					return true;
				}
			}

		}
		// leave a node
		stack[node] = false;
		return false;
	}	

	bool isCycle() {

		bool *visited = new bool[V];
		bool *stack = new bool[V];

		for(int i = 0; i < V; i++) {
			visited[i] = stack[i] = false;
		}

		for(int i = 0; i < V; i++) {
			if(cycle_helper(i, visited, stack)) {
				return true;
			}
		}
		return false;
	}

	
};

int main() {

	Graph g(7);

	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.addEdge(1, 5);
	g.addEdge(5, 6);
	g.addEdge(4, 2);  // Back edge

	if(g.isCycle()) {
		cout << "Yes, it contains a cycle";
	}
	else {
		cout << "No, it doesn't contains a cycle";
	}
	
	return 0;
}