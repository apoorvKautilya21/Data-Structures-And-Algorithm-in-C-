#include <iostream>
#include <unordered_map>
#include <list>
#include <string>
#include <cstring>
using namespace std;

class Graph {
	unordered_map<string, list<pair<string, int>>> l;
public:

	void addEdge(string x, string y, bool bider, int wt) {

		l[x].push_back(make_pair(y, wt));
		if(bider) {
			l[y].push_back(make_pair(x, wt));
		}

	}

	void printAdjList() {
		// Iterate over the map
		for(auto p : l) {
			string city = p.first;
			auto nbrs = p.second;
			cout << city << " -> ";
			for(auto nbr : nbrs) {
				cout << "(" << nbr.first << ", " << nbr.second << ")" << ", ";
			}
			cout << endl;
		}
	}

};


int main() {

	Graph g;

	g.addEdge("A", "B", true, 20);
	g.addEdge("B", "D", true, 40);
	g.addEdge("A", "C", true, 10);
	g.addEdge("C", "D", true, 40);
	g.addEdge("A", "D", false, 50);

	g.printAdjList();


	return 0;
}