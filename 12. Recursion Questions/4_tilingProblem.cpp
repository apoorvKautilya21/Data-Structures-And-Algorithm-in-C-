// https://www.geeksforgeeks.org/tiling-problem/

// except that here board length is 4xN  with dimensions of tiles 1x4 or 4x1
#include<iostream>
using namespace std;
# define ll long long
#define C 1000000007

ll totalNoWaysBuildingWall(ll *a, int n, int m) {

	if(n >= 0 and n < m) {
		return 1;
	}

	if(a[n] != 0) {
		return a[n];
	}

	a[n - 1] = totalNoWaysBuildingWall(a, n - 1, m);
	a[n - m] = totalNoWaysBuildingWall(a, n - m, m);
	a[n] = (a[n - 1] + a[n - m]) % C;

	return a[n];
}

int main() {

	// int n;
	// cin >> n;

	// cout << totalNoWaysBuildingWall(n, 4);
	int n, m;
	int t;
	cin >> t;
	
	while(t--) {
		cin >> n >> m;

		ll a[n+m] = {0};
		for(int i = 0; i < m; i++) {
			a[i] = 0;
		}
		cout << totalNoWaysBuildingWall(a,n, m) % C << endl;


	}

	return 0;
}

