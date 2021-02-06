#include<iostream>
using namespace std;

int main() {

	int n = 15;
	// PROPERTY 1 -- n ^ n = 0 ... eg. 5 ^ 5 = 0
	int ans;
	ans = n ^ n;
	cout << ans << endl;
	ans = 5 ^ 5;
	cout << ans << endl;

	// PROPERTY 2 -- LEFT SHIFT ----- a << b = a * (2^b)
	ans = (5 << 1);
	cout << ans << endl;
	ans = (5 << 2);
	cout << ans << endl;
	ans = (6 << 2);
	cout << ans << endl;

	// PROPERTY 3 -- RIGHT SHIFT ----- a >> b = a / (2^b)
	ans = (5 >> 1);
	cout << ans << endl;
	ans = (20 >> 2);
	cout << ans << endl;
	
	return 0;
}