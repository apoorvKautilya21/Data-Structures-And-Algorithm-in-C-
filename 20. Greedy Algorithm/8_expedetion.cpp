// https://www.spoj.com/problems/EXPEDI/
#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int findMinStopages(vector< pair<int,int> > fuel_tank, int n, int l, int p) {

	priority_queue<int> pq;

	int distance_covered = 0;
	if(p < fuel_tank[0].first) {
		return -1;
	}

	distance_covered += p;

	int stops = 0;
	int i = 0;
	while(i < n and distance_covered < l) {
		if(distance_covered >= fuel_tank[i].first) {
			pq.push(fuel_tank[i].second);
			i++;
		}
		else {
			if(!pq.empty()) {
				distance_covered += pq.top();
				pq.pop();
				stops++;
			}
			else {
				return -1;
			}
		}
	}

	while(!pq.empty() and distance_covered < l) {
		distance_covered += pq.top();
		pq.pop();
		stops++;
	}

	if(distance_covered < l) {
		return -1;
	}

	return stops;
}


int main() {

	int n;
	cin >> n;
	
	vector< pair<int,int> > fuel_tank;
	int d, f;
	for(int i = 0; i < n; i++) {
		cin >> d >> f;
		fuel_tank.push_back(make_pair(d, f));
	}

	int l, p;
	cin >> l >> p;

	for(int i = 0; i < n; i++) {
		fuel_tank[i].first = l - fuel_tank[i].first;
	}

	sort(fuel_tank.begin(), fuel_tank.end(), compare);
	// for(int i = 0; i < n; i++) {
	// 	cout << fuel_tank[i].first << " " << fuel_tank[i].second << endl;
	// }

	cout << findMinStopages(fuel_tank, n, l, p) << endl;





	return 0;
}
