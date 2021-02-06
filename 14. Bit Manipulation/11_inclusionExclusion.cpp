#include<iostream>
# define ll long long
using namespace std;

int main() {

	int n;
	cin >> n;

	int primes[] = {2, 3, 5, 7, 11, 13, 17, 19};
	ll subsets = (1 << 8) - 1;
	int ans = 0;

	for(int i = 1; i <= subsets; i++) {
		ll setBits = __builtin_popcount(i);
		ll denom = 1;

		for(int j = 0; j <= 7; j++) {
			if(i&(1<<j)) {
				denom *= primes[j];
			}
		}
		if(setBits&1) {
			ans += n / denom;
		}
		else {
			ans -= n / denom;
		}
	}	
	cout << ans;
	return 0;
}