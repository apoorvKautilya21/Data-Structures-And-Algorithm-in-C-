#include<iostream>
#include<vector>
#define ll long long
using namespace std;

const int N = 10000;
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

vector<int> factorize(int n, vector<int> primes) {

	vector<int> factors;
	factors.clear();

	int i = 0;
	int p = primes[0];

	while(p*p <= n) {
		if(n % p == 0) {
			factors.push_back(p);
			while(n % p == 0) {
				n = n / p;
				// cout << n << " ";
			}
		}
		// go to the next position
		i++;
		p = primes[i];
	}

	if(n != 1) {
		factors.push_back(n);
	}
	
	return factors;
}





int main() {

	vector<int> primes;
	primes.reserve(3000);
	seive(primes);
	int t;
	cin >> t;

	while(t--) {
		int no;
		cin >> no;

		vector<int> factors = factorize(no, primes);

		for(auto f : factors) {
			cout << f << " ";
		}
		cout << endl;
	}

	return 0;
}