// https://hack.codingblocks.com/app/practice/1/300/problem

#include<iostream>
#include<climits>
using namespace std;

#define ll long long

bool isPossible(ll n, ll m, ll x, ll y, ll curr_max) {

	return (curr_max * x) <= (m + (n - curr_max) * y);
}



ll findStudents(ll n, ll m, ll x, ll y) {

	ll s = 0;
	ll e = n;
	ll ans = 0;

	while(s <= e) {

		ll mid = (s + e) / 2;
		
		if(isPossible(n, m, x, y, mid)) {
			// cout << mid << endl;
			s = mid + 1;
			ans = max(ans, mid);
		}

		else {
			e = mid - 1;
		}
	}

	return ans;

}



int main() {

	ll n, m, x, y;
	cin >> n >> m >> x >> y;

	cout << findStudents(n, m, x, y);

	return 0;
} 