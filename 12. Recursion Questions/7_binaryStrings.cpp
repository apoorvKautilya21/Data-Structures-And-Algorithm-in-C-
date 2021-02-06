#include<iostream>
using namespace std;


int noBinStrings(int n) {
	// Base Case
	if(n == 0) {
		return 1;
	}
	if(n == 1) {
		return 2;
	}

	// Recursive Case
	// when 0 is placed
	int n0 = noBinStrings(n - 1);
	// when 1 is placed
	int n1 = noBinStrings(n - 2);

	return n0 + n1;
}


int main() {

	int n;
	cin >> n;

	cout << noBinStrings(n);


	return 0;
}