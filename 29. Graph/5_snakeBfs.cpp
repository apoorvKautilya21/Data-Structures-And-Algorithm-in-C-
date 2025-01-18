#include<iostream>
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
	}

	int bfsPrint(T src, T dest) {

		map<T, int> dist;
		map<T, T> parent;
		queue<T> q;

		// Put INT_MAX as distance of the each node from the source
		for(auto p:l) {
			dist[p.first] = INT_MAX;
		}
		// just an addition so that graph can atleast know that there is an 
		// node dest
		// dist[dest] = INT_MAX;

		q.push(src);
		dist[src] = 0;
		parent[src] = src;

		while(!q.empty()) {

			T node = q.front();
			q.pop();

			for(auto nbr : l[node]) {
				if(dist[nbr] == INT_MAX) {
					q.push(nbr);
					// mark that nbr visited
					dist[nbr] = dist[node] + 1;
					parent[nbr] = node;
				}
			}

		}
		// Print the path
		T temp = dest;
		while(temp != src) {
			cout << temp << "<--";
			temp = parent[temp];
		}
		cout << src << endl;
		return dist[dest];
	}

};

int main() {

	int board[50] = {0};

	// showssnakes & ladders, basically shows the number of jumps
	board[2] = 13;
	board[5] = 2;
	board[9] = 18;
	board[18] = 11;
	board[17] = -13;
	board[20] = -14;
	board[24] = -8;
	board[25] = 10;
	board[32] = -2;
	board[34] = -22;

	Graph<int> g;
	for(int i = 0; i < 36; i++) {
		for(int dice = 1; dice <= 6; dice++) {
			int finalPos = i + dice + board[i + dice];
			if(finalPos <= 36) {
				g.addEdge(i, finalPos);
			}
		}
	}
	// just an addition so that graph can atleast know that there is an 
	// node dest
	g.addEdge(36, 36); 

	// print the number of min. chances to reach dest
	cout << g.bfsPrint(0, 36) << endl;






	return 0;
}