#include <iostream>
#include <unordered_map>
#include <string>
#include <list>
#include <climits>
#include <set>
using namespace std;

template<typename T>
class Graph {

	unordered_map<T, list<pair<T, int>> > m;
public:

	void addEdge(T x, T y, int dist, bool bider = true) {
		m[x].push_back(make_pair(y, dist));
		if(bider) {
			m[y].push_back(make_pair(x, dist));
		}
	}

	void printAdj() {

		for(auto p: m) {
			cout << p.first << "->";
			for(auto j:p.second) {
				cout << "(" << j.first << ", " << j.second << "), ";
			}
			cout << endl;
		}
	}

	void dijkstraSSSP(T src) {

		unordered_map<T, int> dist;

		for(auto j:m) {
			dist[j.first] = INT_MAX;
		} 

		set<pair<int, T> > s;

		dist[src] = 0;
		s.insert(make_pair(0, src));

		while(!s.empty()) {

			auto p = *(s.begin());
			s.erase(s.begin());
			T node = p.second;
			int d = p.first;

			for(auto j:m[node]) {
				int new_d = d + j.second;
				if(dist[j.first] > new_d) {

					// In the set or priority queue updation is not possible
					// hence we need to first remove the node then insert the 
					// new node with updated distance
					T dest = j.first;
					auto f = s.find(make_pair(dist[dest], dest));
					if(f != s.end()) {
						s.erase(f);
					}

					dist[dest] = new_d;
					s.insert(make_pair(new_d, dest));
				}	
			}
		}

		for(auto j:dist) {
			cout << j.first << " " << j.second << endl;
		}
	}
};

int main() {

	Graph<int> g;
	g.addEdge(1,2,1);
	g.addEdge(1,3,4);
	g.addEdge(2,3,1);
	g.addEdge(3,4,2);
	g.addEdge(1,4,7);
	g.printAdj();
	g.dijkstraSSSP(1);


	// Graph<string> g;
	// g.addEdge("Amritsar", "Delhi", 1);
	// g.addEdge("Amritsar", "Jaipur", 4);
	// g.addEdge("Jaipur", "Delhi", 2);
	// g.addEdge("Jaipur", "Mumbai", 8);
	// g.addEdge("Bhopal", "Agra", 2);
	// g.addEdge("Mumbai", "Bhopal", 3);
	// g.addEdge("Agra", "Delhi", 1);
	// g.printAdj();
	// g.dijkstraSSSP("Jaipur");

	return 0;
}

/*
youtube.com
youtube.com
youtube.com
youtube.com
instagram.com
instagram.com
instagram.com
facebook
facebook
*/