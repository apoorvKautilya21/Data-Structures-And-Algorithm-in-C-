
#include<iostream>
using namespace std;

void dec(int n) {
	// Base Case
	if(n == 0) {
		return;
	}
	// Recursive case
	cout << n << ",";
	dec(n-1);
}

void inc(int n) {
	// Base case
	if(n==0)
		return;
	// Recursive Case
	inc(n-1);
	cout << n << ",";
}

int main() {
	int n;
	cin >> n;

	dec(n);
	cout << endl;

	inc(n);
	cout << endl;
	return 0;
}