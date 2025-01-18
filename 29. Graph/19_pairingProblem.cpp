/*
There are N cities numbered from 0 to N-1. You have to choose 2 cities such that there is no path from first city to second city.
You are given information in the form of M pairs (X,Y) i.e there is an undirected road between city X and city Y.
Find out the number of ways in which cities can be chosen.

Input Format
The first line contains two integers, N and M separated by a single space. 
M lines follow. Each line contains integers separated by a single space X and Y 
denoting road between X and Y.

Constraints
1 <= N <= 100000 1 <= M <= 100000 0 <= X,Y <= N-1

Output Format
An integer that denotes the number of permissible ways to choose a pair of cities.

Sample Input
5 3
0 1
2 3
0 4
Sample Output
6
Explanation
0 1 4 cannot be reached by 2 hence (2,0) (2,1) (2,4)
and also 0 1 4 cannot be reached by 3 so (3,0) (3,1) (3,4) hence 6 ways.
*/

#include <iostream>
#include <list>
using namespace std;

class Graph {

	int V;
	list <pair <int, int> > l;

public:

	Graph(int v) {
		this -> V = v;
	}

	void addEdge(int x, int y) {
		l.push_back(make_pair(x, y));
	}

	int find_set(int i, int parent[]) {

		if(parent[i] == -1) {
			return i;
		}

		return parent[i] = find_set(parent[i], parent);
	}

	void union_set(int x, int y, int parent[], int rank[]) {

		int s1 = find_set(x, parent);
		int s2 = find_set(y, parent);

		if(s1 != s2) {
			if(rank[s1] < rank[s2]) {
				parent[s1] = s2;
				rank[s2] += rank[s1];
			}
			else{
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}
		}
	}

	int num_of_pairs() {

		int *parent = new int[V];
		int *rank = new int[V];

		for(int i = 0; i < V; i++) {
			parent[i] = -1;
			rank[i] = 1;
		}

		for(auto p: l) {

			int x = p.first;
			int y = p.second;

			union_set(x, y, parent, rank);
		}

		int ans = 0;

		for(int i = 0; i < V; i++) {
			ans += V - rank[find_set(i, parent)];
		}

		return ans / 2;
	}


};

int main() {

	int n, m;
	cin >> n >> m;

	Graph g(n);

	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		g.addEdge(x, y);
	}

	cout << g.num_of_pairs();




	return 0;
}













 