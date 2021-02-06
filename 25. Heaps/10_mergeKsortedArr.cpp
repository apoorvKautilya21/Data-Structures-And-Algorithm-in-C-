#include<iostream>
#include<vector>
#include<queue>
#define mp make_pair
using namespace std;

typedef pair<int, pair<int, int>> node;

vector<int> mergeKsorted(vector< vector<int> > v) {

	vector<int> result;
	priority_queue<node, vector<node> , greater<node> > pq; // arrange the element on the basis of first element of node

	for(int i = 0; i < v.size(); i++) {
		pq.push(mp(v[i][0], mp(i, 0)));
	}

	while(!pq.empty()) {

		node current = pq.top();
		pq.pop();
		int element = current.first;
		int x = current.second.first;
		int y = current.second.second;

		result.push_back(element);

		if(y + 1 < v[x].size()) {
			pq.push(mp(v[x][y + 1], mp(x, y + 1)));
		}
	}

	return result;
}


int main() {

	vector< vector<int> > v {
		{2, 6, 12, 15},
		{1, 3, 14, 20}, 
		{3, 5, 8, 10}
	};

	vector<int> ans = mergeKsorted(v);

	for(int x:ans) 
		cout << x << " ";



	return 0;
}