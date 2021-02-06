#include<iostream>
using namespace std;

long long fastPower(long long a, int n) {
	long long ans = 1;
	while(n > 0) {
		int last_bit = n & 1;
		if(last_bit) {
			ans = ans * a;
		}	
		a *= a;
		n = n>>1;
	}
	return ans;
}

int main() {

	long long a, n;
	cin >> a >> n;

	cout << fastPower(a, n) << endl;
	return 0;
}