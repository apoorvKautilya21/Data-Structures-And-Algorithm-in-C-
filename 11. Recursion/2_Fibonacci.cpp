/*

Golden rule for recusion
1. Figure out the BASE CASE
2. Assume that Sub problems can be solved by recursion (automatically)
3. Using the subproblems write the answer of the current problems.

*/

#include<iostream>
using namespace std;

int fibonacci(int n) {
	// Base Case
	if(n <= 1) {
		return n;
	}
	// Recursive Case 
	return fibonacci(n - 1) + fibonacci(n - 2);
	/*
	here i have assumed that fibonacci(n - 1) will solve the fibonacci of n-1 
	and fibonacci of n-2 will solve its part.. hence i am given with fibo(n-1) 
	and fibo(n-2) and using them fibo(n) can be calculated by adding fibo(n-1) and fibo(n-2)
	*/
}


int main() {
	int n;
	cin >> n;
	cout << fibonacci(n);


	return 0;
}