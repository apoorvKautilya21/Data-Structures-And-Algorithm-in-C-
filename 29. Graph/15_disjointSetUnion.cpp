#include <iostream>
#include <list>
using namespace std;

class DisjoinSet {

	int *parent;
	int v;

public:

	DisjoinSet(int v) {
		this -> v = v;
		parent = new int[v];

		for(int i = 0; i < v; i++) {
			parent[i] = -1;
		}
	} 

	int find(int i) {
		// Base Case
		if(parent[i] == -1) {
			return i;
		}

		return find(parent[i]);
	} 

	void dsu_union(int a, int b) {

		int s1 = find(a);
		int s2 = find(b);

		cout << s1 << " " << s2 << endl;

		if(s1 != s2) {
			parent[s2] = s1;
		}
	}
};

int main() {

	DisjoinSet d(5);

	d.dsu_union(3, 4);
	d.dsu_union(1, 2);
	d.dsu_union(2, 4);
	d.dsu_union(2, 3);



	return 0;
}