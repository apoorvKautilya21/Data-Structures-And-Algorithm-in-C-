#include<iostream>
#include<vector>
#define ll long long
using namespace std;
	
const int N = 100000;
int p[N] = {0};

void seive(vector<int> &primes) {
	for(ll i = 3; i <= N; i+=2) {
		p[i] = 1;
	}
	primes.push_back(2);
	p[2] = 1;
	for(ll i = 3; i <= N; i+=2) {
		if(p[i] == 1) {
			primes.push_back(i);
			for(ll j = i*i; j <= N; j+=i) {
				p[j] = 0;
			}
		}
	}
}

int main() {

	vector<int> primes;
	primes.reserve(30000);
	seive(primes);
	int t;
	cin >> t;

	while(t--) {

		ll n, m;	// <= 10^9
		cin >> m >> n;

		bool segment[n-m+1] = {0};

		for(auto x:primes) {
			if(x*x > n) {
				break;
			}

			ll start = (m / x) * x;

			if(x >= m and x <= n) {
				start = x * 2;
			}

			if(start < m) {
				start += x;
			}

			for(ll i = start; i <= n; i+=x) {
				segment[i - m] = 1;
			}
		}
		for(int i = m; i <= n; i++) {
			if(segment[i - m] == 0 and i != 1) {
				cout << i << endl;
			}
		}
	}

	return 0;
}