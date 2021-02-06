#include<iostream>
#define ll long long
using namespace std;

int p[1000005] = {0};
int csum[1000005];

void generatePrime() {
	for(ll i = 3; i <= 1000005; i+=2) {
		p[i] = 1;
	} 

	for(ll i = 3; i <= 1000005; i+=2) {
		if(p[i] == 1) {
			for(ll j = i*i; j <= 1000005; j+=i) {
				p[j] = 0;
			}
		}
	}

	p[2] = 1;

}


int main() {

	int n;
	cin >> n;

	generatePrime();

	for(int i = 1; i < 1000005; i++) {
		csum[i] = csum[i - 1] + p[i];
	}
	
	while(n--) {
		ll a, b;
		cin >> a >> b;

		cout << csum[b] - csum[a - 1] << endl;
	}

	return 0;
}