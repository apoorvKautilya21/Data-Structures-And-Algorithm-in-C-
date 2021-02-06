/*

Golden rule for recusion
1. Figure out the BASE CASE
2. Assume that Sub problems can be solved by recursion (automatically)
3. Using the subproblems write the answer of the current problems.

*/

#include<iostream>
using namespace std;

int fact(int n) {
	// Base case
	if(n == 0) {
		return 1;
	}
	// Recursive case
	return n * fact(n - 1);
}


int main() {
	int n; 
	cin >> n;
	cout << fact(n);

	return 0;
} 