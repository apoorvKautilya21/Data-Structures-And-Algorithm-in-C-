#include<iostream>
#define INTMX 1000000000
using namespace std;

int main() {

	int t;
	cin >> t;

	while(t--) {

		int a, b;
		cin >> a >> b;

		int ans = INTMX;

		for(int i = 2; i * i <= b; i++) {
			if(b % i == 0) {
				int cnt = 0;
				while(b % i == 0) {
					cnt++;
					b = b / i;
				}
				long long p = i;
				int occ = 0;
				while(a / p) {
					occ += a / p;
					p *= i;
				}			
				ans = min(ans, occ / cnt);	
			}
		}

		if(b > 1) {
			// cnt here is 1
			long long p = b; 
			int occ = 0;
			while(a / p) {
				occ += a / p;
				p *= b;
			}
			ans = min(ans, occ);
		}

		if(ans == INTMX) {
			ans = 0;
		}

		cout << ans << endl;

	}







	return 0;
}