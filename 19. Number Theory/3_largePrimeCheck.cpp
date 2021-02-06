#include<iostream>
#include<vector>
#include<bitset>
#define ll long long
using namespace std;

const int n = 1000000;
bitset<1000005> p;
int csum[1000005];

void generatePrime(vector<int> &primes) {
	for(ll i = 3; i <= n; i+=2) {
		p[i] = 1;
	} 
	primes.push_back(2);
	p[2] = 1;
	p[0] = p[1] = 0;

	for(ll i = 3; i <= n; i+=2) {
		if(p[i] == 1) {
			primes.push_back(i);
			for(ll j = i*i; j <= n; j+=i) {
				p[j] = 0;
			}
		}
	}

}

bool isPrime(ll N, vector<int> &primes) {
	if(N < n)  {
		return p[N]? true:false;
	}

	for(int i = 0; primes[i] * (ll)primes[i] <= N; i++) {
		if(N % primes[i] == 0) {
			return false;
		}
	}
	return true;
}

int main() {


	vector<int> primes;
	primes.reserve(1000005);

	generatePrime(primes);

	// for(int i = 0; i < 50; i++) {
	// 	cout << primes[i] << " ";
	// }

	if(isPrime(2147483647, primes)) {
		cout << "Yes it is" << endl;
	}
	else{ 
		cout << "NO\n";
	}









	return 0;
}