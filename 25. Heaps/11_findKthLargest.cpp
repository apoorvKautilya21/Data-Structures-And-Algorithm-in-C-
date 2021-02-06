#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#define mp make_pair
using namespace std;

typedef pair<int, pair<int, int>> node;

int kthSmallest(vector< vector<int> > arr, int k) {

	int n = arr.size();
	int m = arr[0].size();

	unordered_set<int> s;
	priority_queue<node, vector<node>, greater<node> > pq;

	// for(int i = 0; i < m; i++) {
	// 	if(s.find(arr[0][i]) == s.end()) {
	// 		pq.push(mp(arr[0][i], mp(0, i)));
	// 		s.insert(arr[0][i]);
	// 	}
	// }

	pq.push(mp(arr[0][0], mp(0, 0)));
	s.insert(arr[0][0]);


	int counter = 0;

	while(!pq.empty() and counter != k) {

		node current = pq.top();
		pq.pop();
		int element = current.first;
		int x = current.second.first;
		int y = current.second.second;
		counter++;

		if(counter == k) {
			return element;
		}

		if(y + 1 < m and s.find(arr[x][y + 1]) == s.end()) {
			pq.push(mp(arr[x][y + 1], mp(x, y + 1)));
			s.insert(arr[x][y + 1]);
		}

		if(x + 1 < n and s.find(arr[x + 1][y]) == s.end()) {
			pq.push(mp(arr[x + 1][y], mp(x + 1, y)));
			s.insert(arr[x + 1][y]);
		}
	}		

	return 0;
}



int main() {

	vector< vector<int> > v {
		{10,20,30,40},
		{15,25,35,45}, 
		{24,29,37,48},
		{32,33,39,50}
	};

	for(int i = 1; i <= 10; i++) {
		cout << kthSmallest(v, i) << endl;
	}



	return 0;
}