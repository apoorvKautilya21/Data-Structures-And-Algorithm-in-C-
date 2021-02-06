// https://www.spoj.com/problems/PRATA/
#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

bool isPossible(int a[], int n, int p, int curr_min) {

	int parata_made = 0;
	for(int i = 0; i < n; i++) {
		int time_spent_per_cook = 0;
		int n_parata_per_cook = 1;
		while(time_spent_per_cook + n_parata_per_cook * a[i] <= curr_min) {
			time_spent_per_cook += n_parata_per_cook * a[i];
			parata_made += 1;
			n_parata_per_cook += 1;

			if(parata_made >= p) {
				return true;
			}
		}
	}

	return false;
}


int findTime(int rank[], int n, int p) {

	sort(rank, rank+n);
	int s = 0;
	int e = rank[0] * p * (p + 1) / 2;
	if(n == 1) {
		return e;
	}
	int ans = INT_MAX;

	while(s <= e) {

		int mid = (s + e) / 2;

		if(isPossible(rank, n, p, mid)) {
			e = mid - 1;
			ans = min(ans, mid);
		}

		else {
			s = mid + 1;
		}

	}

	return ans;
}



int main() {

	int t;
	cin >> t;

	while(t--) {

		int p;
		int n;
		int rank[1000];
		cin >> p;
		cin >> n;

		for(int i = 0; i < n; i++) 
			cin >> rank[i];

		cout << findTime(rank, n, p) << endl;
	}

	return 0;
}