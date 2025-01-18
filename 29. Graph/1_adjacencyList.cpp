#include <iostream>
#include <list>
using namespace std;

class Graph {
	int V;
	list<int> *l;

public:
	Graph(int v) {
		V = v;
		l = new list<int>[V];
	}

	void addEdge(int x, int y, bool bidir) {
		l[x].push_back(y);
		if(bidir) {
			l[y].push_back(x);
		}
	}

	void printGraph() {

		for(int i = 0; i < V; i++) {
			cout << "Vertex " << i << " -> ";
			for(int j:l[i]) {
				cout << j << ",";
			}
			cout << endl;
		}
	}



};


int main() {

	Graph g(4);

	g.addEdge(0, 1, true);
	g.addEdge(0, 2, true);
	g.addEdge(1, 2, true);
	g.addEdge(3, 2, false);

	g.printGraph();

	return 0;
}