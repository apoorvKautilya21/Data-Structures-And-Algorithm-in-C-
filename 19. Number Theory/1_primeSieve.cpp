#include<iostream>
using namespace std;

void generatePrimes(bool p[], int n) {

	// making the assumption that all odd numbers are prime number
	for(int i = 3; i <= n; i+=2) {
		p[i] = 1;
	}

	// Now Distinguishing the odd number which prime and which are not
	for(long long int i = 3; i <= n; i += 2) {
		if(p[i] == 1) {
			for(long long int j = i*i; j <= n; j += i) {
				p[j] = 0;
			}
		}
	}

	p[2] = 1;
	p[1] = p[0] = 0;
}

int main() {

	int n;
	bool p[2000];
	cin >> n;

	generatePrimes(p, n);

	for(int i = 2; i <= n; i++) {
		if(p[i] == 1) {
			cout << i << " ";
		}
	}



	return 0;
}