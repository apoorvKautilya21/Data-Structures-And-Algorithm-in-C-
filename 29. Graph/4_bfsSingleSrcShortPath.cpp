#include <iostream>
#include <queue>
#include <map>
#include <list>
#include <climits>
using namespace std;

template<typename T>
class Graph {

	map<T, list<T> > l;

public:

	void addEdge(T x, T y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void bfsPrint(T src) {

		map<T, int> dist;
		queue<T> q;

		// Put INT_MAX as distance of the each node from the source
		for(auto p:l) {
			dist[p.first] = INT_MAX;
		}

		q.push(src);
		dist[src] = 0;

		while(!q.empty()) {

			T node = q.front();
			q.pop();

			for(auto nbr : l[node]) {
				if(dist[nbr] == INT_MAX) {
					q.push(nbr);
					// mark that nbr visited
					dist[nbr] = dist[node] + 1;
				}
			}

		}

		// print the distance to every node
		for(auto node_pair: l) {
			cout << node_pair.first << " " << dist[node_pair.first] << endl;
		}
	}

};

int main() {

	Graph<int> g;
	g.addEdge(0, 1);
	g.addEdge(0, 3);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);

	g.bfsPrint(0);


	return 0;
}