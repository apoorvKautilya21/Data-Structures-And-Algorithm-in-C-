#include<iostream>
using namespace std;

// Given N friends going to a party on bikes. Each guy can go as single or as a double.
// Find the number of ways in which N friends can go to the party

int numberOfWays(int n) {

	if(n <= 2) {
		return n;
	}	
	// fn = 1 * f(n-1) + (n-1)C1 {i.e., no of ways of finding 1 from n-1 cases} * f(n-2)
	int f_n = numberOfWays(n-1) + (n - 1) * numberOfWays(n-2);
	return f_n;
}

int main() {

	int n;
	cin >> n;
	cout << numberOfWays(n);
	
	return 0;
}