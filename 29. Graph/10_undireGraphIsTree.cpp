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
		l[y].push_back(x);
	}

	bool isTree() {

		bool *visited = new bool[V];
		int *parent = new int[V];

		queue<int> q;

		for(int i = 0; i < V; i++) {
			visited[i] = false;
			parent[i] = i;
		}

		int src = 0;
		q.push(src);
		visited[src] = true;

		while(!q.empty()) {

			int node = q.front();
			q.pop();

			for(auto nbr : l[node]) {
				if(visited[nbr] and parent[node] != nbr) {
					return false;
				}
				else if(!visited[nbr]) {
					visited[nbr] = true;
					parent[nbr] = node;
					q.push(nbr);
				}
			}
		}
		return true;
	}
};	

int main() {

	Graph g(4);

	g.addEdge(0, 1);
	g.addEdge(3, 2);
	g.addEdge(1, 2);
	// g.addEdge(0, 3);

	if(g.isTree()) {
		cout << "It is a tree";
	}
	else {
		cout << "Not a tree";
	}
	
	return 0;
}