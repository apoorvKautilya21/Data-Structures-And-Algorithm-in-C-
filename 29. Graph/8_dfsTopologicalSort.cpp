#include <iostream>
#include <queue>
#include <map>
#include <list>
using namespace std;

template<typename T>
class Graph {

	map<T, list<T> > l;

public:

	void addEdge(T x, T y) {
		l[x].push_back(y);
	}

	void dfs_helper(T src, map<T, bool>&visited, list<T> &ordering) {

		// cout << src << " ";
		visited[src] = true;

		for(auto p:l[src]) {
			if(!visited[p]) {
				dfs_helper(p, visited, ordering);
			}
		}
		ordering.push_front(src);
	}

	void dfs() {
		map<T, bool> visited;
		list<T> ordering;

		for(auto p:l) {
			visited[p.first] = false;
		}

		for(auto p:l) {
			T node = p.first;
			if(!visited[node]) {
				dfs_helper(node, visited, ordering);
			}
		}

		for(auto p : ordering) {
			cout << p << endl;
		}
	}



};

int main() {

	Graph<string> g;

	g.addEdge("Python", "DataPreprocessing");
	g.addEdge("Python", "Pytorch");
	g.addEdge("Python", "ML");
	g.addEdge("DataPreprocessing", "ML");
	g.addEdge("Pytorch", "DL");
	g.addEdge("ML", "DL");
	g.addEdge("DL", "FaceRecog");
	g.addEdge("Dataset", "FaceRecog");

	g.dfs();

	return 0;
}