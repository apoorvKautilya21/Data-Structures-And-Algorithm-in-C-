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
	}

	void topologicalSort() {
		// Make an array that stores the indegree of each vertex
		int *inDegree = new int[V]{0};
		// Now update the indegree array
		for(int i = 0; i < V; i++) {
			for(int a:l[i]) {
				inDegree[a]++;
			}
		}

		// Now do your Normal BFS
		queue<int> q;
		// Now put those elements whose indegree is 0
		for(int i = 0; i < V; i++) {
			if(inDegree[i] == 0) {
				q.push(i);
			}
		}

		while(!q.empty()) {
			int node = q.front();
			q.pop();
			cout << node << " ";

			for(auto p: l[node]) {
				inDegree[p]--;
				if(inDegree[p] == 0) {
					q.push(p);
				}
			}
		}

	}


};

int main() {

	Graph g(6);

	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(1, 4);
	g.addEdge(2, 3);
	g.addEdge(2, 5);
	g.addEdge(4, 5);
	g.addEdge(3, 5);

	g.topologicalSort();

	return 0;
}