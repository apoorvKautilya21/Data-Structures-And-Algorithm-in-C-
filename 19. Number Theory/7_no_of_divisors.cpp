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

int no_of_divisors(int n, vector<int> primes) {

	int i = 0;
	int p = primes[0];
	int ans = 1;

	while(p*p <= n) {
		if(n % p == 0) {
			int cnt = 0;
			while(n % p == 0) {
				cnt++;
				n = n / p;			
			}
			ans *= (cnt + 1);
		}
		// go to the next position
		i++;
		p = primes[i];
	}

	if(n != 1) {
		ans = ans * 2;
	}
	
	return ans;
}





int main() {

	vector<int> primes;
	primes.reserve(3000);
	seive(primes);
	int n; 
	cin >> n;

	cout << no_of_divisors(n, primes);

	return 0;
}