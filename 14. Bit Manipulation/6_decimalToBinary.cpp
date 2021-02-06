#include<iostream>
using namespace std;

int decimal2Binary(int n) {
	int ans = 0;
	int p = 1;

	while(n > 0) {
		ans = ans + (n&1) * p;
		p *= 10;
		n = (n>>1);
	}
	return ans;
}

int main() {

	cout << decimal2Binary(7) << endl;
	cout << decimal2Binary(5) << endl;
	cout << decimal2Binary(11) << endl;


	return 0;
}