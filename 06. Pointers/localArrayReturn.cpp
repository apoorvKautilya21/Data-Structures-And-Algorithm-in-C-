#include<iostream>
using namespace std;


/*
******************   READ THIS FUNCTION  ***********************
int* func() {
	int a[] = {1,2,3,4};
	cout << a << endl;
	cout << a[0] << endl;

	// You should never return a local variable
	// Since after the function call is over, the memory used by the function in the stack will be cleared 
	// and when we try to access that element we will get a garbage value.
	return a;
}

*/


int *func2() {
	int *a = new int[5]{0};
	a[0] = 11;
	a[1] = 2;
	a[2] = 3;
	cout << a << endl;
	cout << a[0] << endl;

	return a;
}


int main() {

	// int *b = func();

	// cout << b << endl;
	// cout << b[0];

	int *b = func2();
	cout << b << endl;
	cout << b[0] << "  " << b[3];

	delete [] b;

	// OUTPUT :- 
	// 0x10613c8
	// 11
	// 0x10613c8
	// 11

	return 0;
}