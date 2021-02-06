#include<iostream>
using namespace std;

int countBits(int n) {

	int ans = 0;
	while(n > 0) {
		ans += (n & 1);
		n = (n>>1);
	}
	return ans;
}

int countBitsFast(int n) {
	int ans = 0;
	while(n > 0) {
		n = (n & (n-1));
		ans++;
	}
	return ans;
}

int main() {

	cout << countBits(5) << endl;
	cout << countBits(15) << endl;
	
	cout << countBitsFast(5) << endl;
	cout << countBitsFast(15) << endl;

	cout << __builtin_popcount(5) << endl;
	cout << __builtin_popcount(15) << endl;

	return 0;
}